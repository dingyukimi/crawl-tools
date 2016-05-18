#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 205;
const int maxe = 20500;
const int INF = 0x3f3f3f;

struct Edge{
    int u,v,w;
    int next;
    void assign(int u_,int v_,int w_,int next_){
        u = u_;  v = v_;   w = w_;  next = next_;
    }
    bool operator < (const Edge& e) const {
        return w > e.w;    //这个地方害我WA了6次；这错太隐蔽了!!!!。
    }
}edges[maxe];

int head[maxn];
vector<int> G[maxn];
int cnt;
int N,M,P;
double PT[maxn][maxn/2];
double dp[maxn][maxn/2];  //dp[i][j]表示以i为根、部署j个警察逮到robber的最大概率；


void addedge(int u,int v,int w){
    edges[cnt].assign(u,v,w,head[u]);
    head[u] = cnt++;
    edges[cnt].assign(v,u,w,head[v]);
    head[v] = cnt++;
}
void Dijkstra(){
    priority_queue<Edge>  Q;
    int d[maxn];
    bool vis[maxn];
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<N;i++) G[i].clear();
    Q.push((Edge){0,0,0});
    d[0] = 0;
    while(!Q.empty()){
        Edge e = Q.top();  Q.pop();
        int u = e.u;
        if(vis[u]) continue;
        vis[u] = true;
        if(e.u != e.v){
            G[e.v].push_back(e.u);
        }
        for(int i=head[u];i!=-1;i=edges[i].next){
            int v = edges[i].v;
            if(d[v] > d[u] + edges[i].w){
                d[v] = d[u] + edges[i].w;
                Q.push((Edge){v,u,d[v]});  //把u存进去是为了方便建最短路图；
            }
        }
    }
}
void dfs(int u){
    int child = G[u].size();
    double son[maxn];                    //son[i]表示u的所有儿子节点总共部署i个人逮住robber的概率；
    for(int i=0;i<=P;i++)   son[i] = 0;
    if(child == 0){
        for(int i=1;i<=P;i++){
            dp[u][i] = PT[u][i];
        }
        return;
    }
    for(int i=0;i<child;i++){
        int v = G[u][i];
        dfs(v);                     // 求出了dp[v][...]的所有不同概率；
        for(int j=P;j>=0;j--)
          for(int k=0;k<=j;k++)
            son[j] = max(son[j],dp[v][k]/child+son[j-k]);  //u的v这个儿子及其子节点部署k个人的最大概率；
    }
    for(int i=P;i>=0;i--)         //总共i个人
      for(int j=0;j<=i;j++){      //u这个节点放j个人
        dp[u][i] = max(dp[u][i],PT[u][j] + (1-PT[u][j])* son[i-j]);
    }
}
int main()
{
    //freopen("E:\\acm\\input.txt","r",stdin);

    while(scanf("%d%d",&N,&M) == 2 && N+M){
        cnt = 0;
        memset(dp,0,sizeof(dp));
        memset(head,-1,sizeof(head));
        for(int i=1;i<=M;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a == b) continue;
            addedge(a,b,c);
        }
        scanf("%d",&P);
        for(int i=0;i<N;i++)  PT[i][0] = 0;
        for(int i=0;i<N;i++)
            for(int j=1;j<=P;j++){
                scanf("%lf",&PT[i][j]);
            }
        Dijkstra();  //形成以0为根的最短路树；存在G[u]中；

        dfs(0);
        double ans = 0;
        for(int i=0;i<=P;i++)
            ans = max(ans,dp[0][i]);
        printf("%.2lf\n",ans*100);
    }
}