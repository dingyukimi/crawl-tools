var fs = require('fs'),
    cheerio = require('cheerio')
    , superagent = require('superagent')
    , globalCookie = undefined;


// 模拟代码提交
function post(code, problemId) {
    superagent
    // 代码 post 的 url
        .post('http://acm.hdu.edu.cn/submit.php?action=submit')
        .set('Content-Type', 'application/x-www-form-urlencoded')
        .set("Cookie", globalCookie)
        .send({"problemid": problemId})
        .send({"usercode": code})
        .end(function (err, sres) {
            console.log(problemId + " *");
        });
}


// 从 csdn 题解详情页获取代码
function getCode(solutionUrl, problemId) {

    superagent.get(solutionUrl, function (err, sres) {
        // 为防止该 solutionUrl 可能不是题解详情页
        // 可能会没有 class 为 cpp 的 dom 元素
        try {
            var $ = cheerio.load(sres.text);

            var code = $('.cpp').eq(0).text();

            if (!code) {
                return;
            }
            setTimeout(post(code, problemId));
        } catch (e) {

        }
    });
}


// 模拟百度搜索题解
function bdSearch(problemId) {
    var searchUrl = 'https://www.baidu.com/s?ie=UTF-8&wd=hdu' + problemId + '%20site%3Ablog.csdn.net%20';
    superagent
        .get(searchUrl)
        // 必带的请求头
        .set("User-Agent", "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.111 Safari/537.36")
        .end(function (err, sres) {
            var $ = cheerio.load(sres.text);
            var lis = $('.t a');
            for (var i = 0; i < 10; i++) {
                var node = lis.eq(i);

                // 获取那个小的 url 地址
                var text = node.parent().next().next().children("a").text();

                // 如果 url 不带有 csdn 字样，则返回
                if (text.toLowerCase().indexOf("csdn") === -1)
                    continue;
                // 题解详情页 url
                var solutionUrl = node.attr('href');
                getCode(solutionUrl, problemId);
            }

        });

}

function login() {
    superagent
    // get 请求任意 acm.hdu.edu.cn 域名下的一个 url
    // 获取 key 为 PHPSESSID 这个 Cookie
        .get('http://acm.hdu.edu.cn')
        .end(function (err, sres) {
            // 提取 Cookie
            var str = sres.header['set-cookie'][0];
            // 过滤响应头 Cookie 中的 path 字段
            var pos = str.indexOf(';');

            // 全局变量存储 Cookie，post 代码提交时候用
            globalCookie = str.substr(0, pos);

            // 模拟登录
            superagent
            // 登录 url
                .post('http://acm.hdu.edu.cn/userloginex.php?action=login')
                // post 用户名 & 密码
                .send({"username": "jsucoder"})
                .send({"userpass": "daydayup"})
                // 这个请求头是必须的
                .set("Content-Type", "application/x-www-form-urlencoded")
                // 请求携带 Cookie
                .set("Cookie", globalCookie)
                .end(function (err, sres) {
                    // 登录完成后，启动程序
                    start();
                });
        });
}

var solved = new Set();
function downSolved() {
    superagent
        .get('http://acm.hdu.edu.cn/userstatus.php?user=jsucoder')
        .end(function (err, sres) {
            var $ = cheerio.load(sres.text);
            var need1 = $('body table p').eq(2).text();
            var rs = need1.match(/\d{4}/g);
            var list = "";
            for (var i = 0; i < rs.length; ++i) {
                solved.add(rs[i]);
                list += array[i] + ",";
                if ((i + 1) % 25 == 0) {
                    list += "\n";
                }
            }
        });
    console.log(list);
    console.log("sovled total: " + solved.size + "\n");
}
// 程序启动
function start() {
    downSolved();
    var count = 0;
    for (var i = 3000; i >= 2000; --i) {
        if (solved.has(String(i))) {
            continue;
        }
        var problemId = i, delay = (++count) * 20000;
        (function (delay, problemId, count) {
            setTimeout(function () {
                bdSearch(problemId);
            }, delay);
        }(delay, problemId, count));
    }
}

login();
