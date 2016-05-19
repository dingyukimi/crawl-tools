#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#define maxn 31
struct stone{
    int x;
    int y;
    int h;
}s[maxn*3];
int dp[maxn*3];
int cmp(stone a,stone b)  
{  
    if(a.x!=b.x)  
        return a.x>b.x?1:0;  
    else  
        return a.y>b.y?1:0;  
} 
using namespace std;
int main(int argc, char *argv[])
{
    int n,x,y,z,max,Case = 1;
    while(scanf("%d",&n)&&n!=0)
    {
        for(int i = 0; i < 3*n; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            s[i].x = x>y?x:y;
            s[i].y = x>y?y:x;
            s[i++].h = z;
            s[i].x = x>z?x:z;
            s[i].y = x>z?z:x;
            s[i++].h = y;
            s[i].x = z>y?z:y;
            s[i].y = z>y?y:z;
            s[i].h = x;
        }
        sort(s,s+3*n,cmp);
        dp[0] = s[0].h;
        int ans = dp[0];
        for(int i = 1; i < 3*n; i++)
        {
            max = 0;
            for(int j = i-1; j >= 0; j--)
            {
                if((s[j].x>s[i].x&&s[j].y>s[i].y)||(s[j].x>s[i].y&&s[j].y>s[i].x))
                {
                    if(dp[j]>max)
                        max = dp[j];
                }
            }
            dp[i] = max + s[i].h;
            if(ans<dp[i])
                ans = dp[i];
        }
        printf("Case %d: maximum height = %d\n",Case,ans);  
        Case++; 
    }
    return 0;
}