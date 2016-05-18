/*
题意：
 给定一个无向图，和两对起点终点，求两条最短路上的最多公共交点数。
 反证法容易验证相交公共点比连续！！
 那么我们假设存在2组数据 s1,e1,s2,e2;
 我们用dp[i][j] 代表 从点i到点j最短路上最多有多少个点！
 那么 map[s1][i]+map[i][j]+map[j][e1]=map[s1][e1] 不就表示i到j的最短路为 s1到e1最短路的子路嘛；
 我们只需更新dp[i][j]中的最大值即可
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=502;
const int INF=1<<30;
int dp[maxn][maxn],map[maxn][maxn],ans,n,m;
void floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            if(map[i][k]!=INF&&i!=k)
            for(j=1;j<=n;j++)
            {
                if(i==j||j==k)continue;
                if(map[i][j]>map[i][k]+map[k][j])
                {
                    map[i][j]=map[i][k]+map[k][j];
                    dp[i][j]=dp[i][k]+dp[k][j]-1;
                }
                else if(map[i][j]==map[i][k]+map[k][j]&&dp[i][j]<dp[i][k]+dp[k][j])
                {
                    dp[i][j]=dp[i][k]+dp[k][j]-1;
                }
            }
        }
    }
}
int solve(int s1,int e1,int s2,int e2)
{
    int i,j,res=0;
    if(map[s1][e1]>=INF||map[s2][e2]>=INF)return 0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(map[s1][i]+map[i][j]+map[j][e1]==map[s1][e1]&&map[s2][i]+map[i][j]+map[j][e2]==map[s2][e2])
            {
                res=max(res,dp[i][j]);
            }
        }
    }
    return res;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        int i,j,u,v,w,s1,e1,s2,e2;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                map[i][j]=INF;
                dp[i][j]=2;
            }
            dp[i][i]=1;
            map[i][i]=0;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
             map[v][u]=map[u][v]=min(map[u][v],w);
        }
        floyd();
        scanf("%d%d%d%d",&s1,&e1,&s2,&e2);
        printf("%d\n",solve(s1,e1,s2,e2));
    }
    return 0;
}