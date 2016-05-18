#include <iostream>
#include <string>
#include <vector>
using namespace std;
//各种符号的枚举，后面的注释为题目中对应的符号
enum SYMBOL{A, MOD, LA, BA, DA, PREDA, NAM, SE, PC, P, PN, PS, ST, VP, PV, UN};
bool aVowel[] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0}; //元音表
static SYMBOL aConvTbl[14][4] = { //状态转换表，每四个状态为一组，顺序排列
    {PREDA, UN, PREDA, PREDA}, {PREDA, UN, UN, PS}, {NAM, UN, UN, PN},
    {LA, UN, PS, PN}, {MOD, UN, PS, VP}, {A, PS, PS, PS}, {PS, UN, UN, P},
    {DA, UN, P, PC}, {BA, PN, P, PC}, {VP, PN, UN, PV}, {PV, UN, PN, ST},
    {PV, UN, UN, ST}, {PC, UN, UN, SE}, {ST, UN, UN, SE}, //每组四个符号
}; //1：初始符号，2：前缀，3：后缀，4：推导出的符号
//将输入的字符串转换为符号的函数
SYMBOL Token2Status(const string &str) {
    int nNum = str.length(), cLast = str[nNum - 1];
    if (!islower(cLast) || !aVowel[cLast - 'a']) {
        return NAM; //末尾不是元音的为NAM
    }
    switch (nNum) {
    case 1: return A; //只有一位元音的只能是A
    case 5: //用位运算快速判断谓词是否符合规则CCVCV或CVCCV
        nNum = aVowel[str[4] - 'a'];
        nNum |= ((aVowel[str[0] - 'a'] << 4) | (aVowel[str[1] - 'a'] << 3));
        nNum |= ((aVowel[str[2] - 'a'] << 2) | (aVowel[str[3] - 'a'] << 1));
        return (nNum == 5 || nNum == 9) ? PREDA : UN;
    case 2: //两位的单词
        switch (str[0]) { //根据第一位判断是哪一组
        case 'g': return MOD;
        case 'b': return BA;
        case 'd': return DA;
        case 'l': return LA;
        }
    }
    return UN; //未能识别的错误符号
}
//主函数
int main(void) {
    vector<SYMBOL> Set;
    for (string str; cin >> str && str != "#";) { //循环读入每个单词
        int nDot = str.find('.'); //如果单词中发现句点，则认为句子结束
        if (nDot == str.npos) { //没有发现句点
            Set.push_back(Token2Status(str)); //将单词转为符号后存入语句
            continue;
        } //以下为发现句点，即遇到句子结束
        str.erase(str.length() - 1); //删除句点
        if (!str.empty()) { //单词不为空则加入语句
            Set.push_back(Token2Status(str));
        } //以下进行词法分析并输出结果
        for (int i = 0; i < 14; ++i) { //依次处理每一种状态
            SYMBOL *pTbl = aConvTbl[i]; //为加快运算，节省代码，设临时变量
            for (vector<SYMBOL>::iterator j = Set.begin(); j != Set.end();) {
                vector<SYMBOL>::iterator iBeg = Set.begin(), iEnd = Set.end();
                if (*j != pTbl[0]) {
                    ++j; //不是指定符号，遍例下一个
                    continue;
                } //如果指定了前面或后面相邻的符号则验证其是否存在
                if (pTbl[1] != UN && (j == iBeg || *(j - 1) != pTbl[1])) {
                    ++j; //存在的符号与指定的不符，结果错误
                    continue;
                }
                if (pTbl[2] != UN && (j == iEnd - 1 || *(j + 1) != pTbl[2])) {
                    ++j; //存在的符号与指定的不符，结果错误
                    continue;
                } //删除前后的符号(如果指定)
                j = pTbl[1] != UN ? Set.erase(j - 1) : j;
                j = pTbl[2] != UN ? Set.erase(j + 1) - 1 : j;
                *j = pTbl[3]; //当前符号变更为指定的目标符号
            }
        }
        cout << (Set.size() == 1 && Set[0] == SE ? "Good" : "Bad!") << endl;
        Set.clear(); //清空语句，准备处理下一条语句
    }
    return 0;
}