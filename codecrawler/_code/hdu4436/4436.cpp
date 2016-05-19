#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 100000005
#define M 40
#define N 210005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL unsigned long long
#define MOD 2012
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((double)(a)*(a))
#define Key_value ch[ch[root][1]][0]
#define test puts("OK");
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
struct SAM
{
    SAM *pre,*son[11];
    int len,cnt,sum;
}*root,*tail,que[N],*b[N];
int tot;
char str[N/2];
void add(int c,int l)
{
    SAM *p=tail,*np=&que[tot++];
    np->len=l;
    while(p&&p->son[c]==NULL) p->son[c]=np,p=p->pre;
    if(p==NULL) np->pre=root;
    else
    {
        SAM *q=p->son[c];
        if(p->len+1==q->len) np->pre=q;
        else
        {
            SAM *nq=&que[tot++];
            *nq=*q;
            nq->len=p->len+1;
            np->pre=q->pre=nq;
            while(p&&p->son[c]==q) p->son[c]=nq,p=p->pre;
        }
    }
    tail=np;
}
bool cmp(int x,int y)
{
    return que[x].len<que[y].len;
}
int len,c[N];
int slove()
{
    mem(c,0);
    for(int i=0;i<tot;i++) c[que[i].len]++;
    for(int i=1;i<len;i++) c[i]+=c[i-1];
    for(int i=0;i<tot;i++) b[--c[que[i].len]]=&que[i];
    root->cnt=1;
    root->sum=0;
    int ans=0;
    for(int i=0;i<tot;i++)
    {
        SAM *p=b[i];
        for(int j=0;j<10;j++)
        {
            if(i==0&&j==0) continue;
            if(p->son[j])
            {
                SAM *q=p->son[j];
                q->cnt=(q->cnt+p->cnt)%MOD;
                q->sum=(q->sum+p->sum*10+p->cnt*j)%MOD;
            }
        }
        ans=(ans+p->sum)%MOD;
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        tot=0;
        root=tail=&que[tot++];
        len=1;
        while(n--)
        {
            scanf("%s",str);
            for(int i=0;str[i];i++) add(str[i]-'0',len++);
            add(10,len++);
        }
        printf("%d\n",slove());
        for(int i=0;i<tot;i++) que[i].sum=que[i].cnt=0,que[i].pre=NULL,mem(que[i].son,NULL);
    }
    return 0;
}