#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100010
bool vis[2 * MAXN];
int dp[2 * MAXN];

int main()
{
#ifdef SHY
    freopen("e:\\1.txt", "r", stdin);
#endif
    int t;
    scanf("%d%*c", &t);
    while(t--)
    {
        int n, m, a, maxn = 0, p;
        scanf("%d %d%*c", &n, &m);
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
        {
            scanf("%d%*c", &a);
            vis[a] = true;
            if(maxn < a) maxn = a;
        }
        p = maxn + 1;
        for(int i = maxn; i >= 1; i--)
        {
            if(!vis[i])
                p = i;
            dp[i] = p;
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d%*c", &a);
            if(vis[a])
                printf("%d\n", dp[a]);
            else printf("%d\n", a);
        }
    }
    return 0;
}

