#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
using namespace std;
//平年和闰年的各月累计天数表
static int aMDays[] =  {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
static int aMDaysL[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
//根据指定的历法判定闰年。bNew为true代表新历法，fase代表旧历法
bool LeapYear(int Year, bool bNew) {
    if (bNew) {
        //标准的闰年判断
        return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
    }
    return (Year % 4 == 0);
}
//将年月日换算为从元年1月1日(第0天)到这一天的天数
int Date2Days(int Year, int Month, int Date, bool bNew) {
    --Year; //年份定为以0年起始
    //年份乘以365天，加上闰年数(总置闰天数)
    //如果为新历法，要减去百年中不能被400整除的置闰天数
    int Days = Year * 365 + Year / 4 + (bNew ? (Year / 400 - Year / 100) : 0);
    //如果为闰年且月分大于2，要闰1天
    Days += ((Month > 2) ? LeapYear(Year + 1, bNew) : 0);
    //返回：年累计天数+月累计天数+日期-新旧历法起点对齐
    return (Days + aMDays[Month - 1] + Date - 1 - (!bNew * 2));
}
//主函数
int main(void) {
    //月分和星期的字符串表，用于处理输入和输出
    const static string aDays[] = {"Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday", "Saturday"};
    const static string aMonths[] = {"January", "February", "March",
        "April", "May", "June", "July", "August", "September",
        "October", "November", "December"};
    //400年的天数，100年的天数，4年的天数和1年的天数常量
    const int nDays400Y = 400 * 365 + 100 - 3;
    const int nDays100Y = 100 * 365 + 25 - 1;
    const int nDays4Y = 4 * 365 + 1, nDays1Y = 365;
    //循环处理每一个输出的日期
    for (string str; cin >> str && str != "#";) {
        int Day, Date, Month, Year;
        //在字符串表中检索是周几
        Day = find(&aDays[0], &aDays[7], str) - &aDays[0];
        //读入年月日
        cin >> Date >> str >> Year;
        //在字符串表中检索是几月
        Month = find(&aMonths[0], &aMonths[12], str) - &aMonths[0] + 1;
        //将当前日期按旧历换算为天数
        int nDays = Date2Days(Year, Month, Date, false);
        bool bOld2New = true; //为真表示由旧历转新历
        //判定算得的星期是否与输入的相符，若相符则为旧历纪年
        if (Day == (nDays + 1) % 7) {
            //转新历时要先处理400年和100年的置闰
            Year = nDays / nDays400Y * 400; //算出第几个400年
            nDays %= nDays400Y;
            //算出400年中的第几个百年
            if (nDays == nDays100Y * 4) { //该400年的最后一天
                Year += 300;
                nDays -= nDays100Y * 3;
            }
            else {
                Year += nDays / nDays100Y * 100;
                nDays %= nDays100Y; //取零头
            }
        } //否则为亲历纪年，重新计算天数，并加2与旧历对齐
        else {
            nDays = Date2Days(Year, Month, Date, true) + 2;
            Year = bOld2New = 0;
        }
        //算出百年中的第几个4年
        Year += nDays / nDays4Y * 4;
        nDays %= nDays4Y; //取零头
        //算出4年中的第几年
        if (nDays == nDays1Y * 4) { //年4年的最后一天
            Year += 3;
            nDays -= nDays1Y * 3;
        }
        else {
            Year += nDays / nDays1Y;
            nDays %= nDays1Y; //取零头
        }
        //判定闰年，选取相应的各月累计天数表
        int *pMDays = (LeapYear(++Year, bOld2New) ? aMDaysL : aMDays);
        //按当年累计天数查找月份
        for (Month = 0; Month < 12 && pMDays[Month] <= nDays; ++Month);
        //计算当月日期
        Date = nDays - pMDays[Month - 1] + 1;
        //计算星期几
        Day = (Date2Days(Year, Month, Date, bOld2New) + 1) % 7;
        //按格式要求输出结果
        cout << aDays[Day] << ' ' << Date << (bOld2New ? " " : "* ");
        cout << aMonths[Month - 1] << ' ' << Year << endl;
    }
    return 0;
}