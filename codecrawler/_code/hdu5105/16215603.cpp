#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
#define rep(i,a,n) for(int i = a; i < n; i++)
#define repe(i,a,n) for(int i = a; i <= n; i++)
#define per(i,n,a) for(int i = n; i >= a; i--)
#define clc(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f3f3f3f3f
double a,b,c,d; 
inline double f(double x) {
    return fabs(a*x*x*x+b*x*x+c*x+d);
}

int main()
{
#ifdef SHY
    freopen("e:\\1.txt", "r", stdin);
#endif
    double x1,x2;
    while(~scanf("%lf %lf %lf %lf %lf %lf%*c",&a,&b,&c,&d, &x1, &x2))
    {
        double ans = f(x1);
        while(x2-x1 >= 0.01){
            ans = max(ans, f(x1));
            x1 += 0.01;
        }
        ans = max(ans,f(x2));
        printf("%.2lf\n",ans);
    }
    return 0;
}
