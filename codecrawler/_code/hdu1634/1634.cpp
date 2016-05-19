#include <iostream>
#include <cmath>
using namespace std;
//用于存储坐标的结构体
struct POINT{int x; int y;};
//主函数
int main(void) {
    //dRad为180/pi，用于弧度到角度的转换，
    const float fRad = 57.295779513082320876798154814105f;
    //dMax为cos(0.01)，任何大于此值的参数都不能进行acos
    const float fMax = 0.99999998476912904932780850903444f;
    //循环处理每一组输入的数据，d为直径，x和y为观查者坐标
    for (float d, x, y; cin >> d >> x >> y && d != 0; ) {
        //将所有值放大100倍并取整，一可加快运算，二可保证精度
        POINT Eye = {int(x * 100 + 0.5), int(y * 100 + 0.5)};
        int nDiam = (int)(d * 100 + 0.5), nCnt = 0;
        //依次由里圈向外层层遍例每棵树，检查是否被里面的树遮挡
        for (int iBeg = 0, iEnd = 100; iEnd <= 1000;
            iBeg -= 100, iEnd += 100) {
            //遍例外面这一圈的树
            for (int i = 0; i < iEnd - iBeg; i += 100) {
                POINT Out[4] = {//一圈分别为左边、上边
                    {iBeg, iBeg + i}, {iBeg + i, iEnd},
                    //右边和下边
                    {iEnd, iEnd - i}, {iEnd - i, iBeg}};
                //遍例四条边上的树
                for (int j = 0; j < 4; j++) {
                    //遍例圈里面所有的树，In为树的坐标
                    POINT In = {iBeg + 100, iBeg + 100};
                    for (; In.y <= iEnd - 100; In.y += 100) {
                        for (In.x = iBeg + 100; In.x <= iEnd - 100;
                            In.x += 100) {//以下算法判定两棵树是否遮挡
                            //分别建立里面树和处面树与眼睛坐标的向量
                            POINT NVec = {In.x - Eye.x, In.y - Eye.y};
                            POINT FVec = {Out[j].x - Eye.x, Out[j].y - Eye.y};
                            //两个向量求内积
                            int nProd = NVec.x * FVec.x + NVec.y * FVec.y;
                            //求两个向量的模
                            float fNMod = sqrt((float)(NVec.x * NVec.x +
                                NVec.y * NVec.y));
                            float fFMod = sqrt((float)(FVec.x * FVec.x +
                                FVec.y * FVec.y));
                            //内积公式求夹角
                            float fACOS = nProd / (fNMod * fFMod);
                            if (fACOS >= fMax) { //夹角不能大于cos(0.01)
                                break;
                            }
                            //求出夹角角度
                            float fAng = acos(fACOS) * fRad;
                            //分别计算两棵树干自身与眼睛形成的的夹角
                            fNMod = asin((float)nDiam / 2.0f / fNMod) * fRad;
                            fFMod = asin((float)nDiam / 2.0f / fFMod) * fRad;
                            //判断是否遮挡，如果有则跳出循环
                            if (fAng - fNMod - fFMod <= 0.01f) {
                                break;
                            }
                        }
                        //未完成内循环，说明存在遮挡，继续向外跳出
                        if (In.x <= iEnd - 100) {
                            break;
                        }
                    }
                    //累计可见树的个数
                    nCnt += (In.y > iEnd - 100);
                }
            }
        }
        //输出结果
        cout << nCnt << endl;
    }
    return 0;
}