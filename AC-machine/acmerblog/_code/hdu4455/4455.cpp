#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef __int64 LL;
const int maxn=1e6+10;
int c[maxn],a[maxn],pre[maxn],sum[maxn],num[maxn];
LL dp[maxn];
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        int i,j,k,t;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(c,0,sizeof(c));
        memset(pre,0,sizeof(pre));
        for(i=1;i<=n;i++)
        {
            c[i-pre[a[i]]]++;//pre[a[i]]=0的也是可以的
            pre[a[i]]=i;
        }
        sum[n]=c[n];
        for(i=n-1;i>=1;i--)
            sum[i]=sum[i+1]+c[i];
        memset(c,0,sizeof(c));
        num[1]=1;
        c[a[n]]++;
        for(i=2;i<=n;i++)
        {
            if(c[a[n-i+1]]==0)
            {
                num[i]=num[i-1]+1;
                c[a[n-i+1]]=1;
            }
            else
            num[i]=num[i-1];
        }
        dp[1]=n;
        for(i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]-num[i-1]+sum[i];
        }
        //for(i=1;i<=n;i++)
        //cout<<i<<":"<<num[i]<<" "<<sum[i]<<" "<<dp[i]<<endl;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&t);
            printf("%I64d\n",dp[t]);
        }
    }
    return 0;
}
/*
10
1 1 2 1 2 2 3 2 1 2
1:10
2:16
3:17
4:17
5:16
6:14
7:12
8:9
9:6
10:3

*/