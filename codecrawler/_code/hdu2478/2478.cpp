/**********************************************************
题意:
给出n个矩形，从里面抽掉一个，求剩下的所有矩形的面积交；

算法:
由于数据量不超过100000，所以不需要用线段树优化，只需要O(n)预处理就行了；
即从左往右处理[1,i]之间的矩形的面积交；
再从右往左也处理一次[i,n]的面积交；
然后枚举中间抽掉的矩形；
最后求一次左右两边的面积交就OK了；
**********************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=100010;
const int L=-1000001;
const int R=1000001;

int x1[N], x2[N], y1[N], y2[N];

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    int tcase;
    while (~scanf("%d",&tcase))
    {
        while (tcase--)
        {
            int n;
            scanf("%d", &n);

            int lx = L, ly = L, rx = R, ry = R;
            int lx1 = L, ly1 = L, rx1 = R, ry1 = R;

            for (int i = 0; i < n; i++)
            {
                scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
                if (x1[i] > lx)
                {
                    lx1 = lx;
                    lx = x1[i];
                }
                else if (x1[i] > lx1)
                    lx1 = x1[i];

                if (y1[i] > ly)
                {
                    ly1 = ly;
                    ly = y1[i];
                }
                else if (y1[i] > ly1)
                    ly1 = y1[i];

                if (x2[i] < rx)
                {
                    rx1 = rx;
                    rx = x2[i];
                }
                else if (x2[i] < rx1)
                    rx1 = x2[i];

                if (y2[i] < ry)
                {
                    ry1 = ry;
                    ry = y2[i];
                }
                else if (y2[i] < ry1)
                    ry1 = y2[i];
            }

            if (n==1)
            {
                printf("0\n");
                continue;
            }

            int ans = 0;
            int x,y;
            int xx,yy;
            for (int i = 0; i < n; i++)
            {
                if (x1[i] == lx)
                    x = lx1;
                else
                    x = lx;

                if (y1[i] == ly)
                    y = ly1;
                else
                    y = ly;

                if (x2[i] == rx)
                    xx = rx1;
                else
                    xx = rx;

                if (y2[i] == ry)
                    yy = ry1;
                else
                    yy = ry;

                if (yy > y && xx > x)
                {
                    int tmp = (yy - y)*(xx - x);
                    if (tmp > ans)
                        ans = tmp;
                }
            }

            printf("%d\n",ans);
        }
    }
    return 0;
}