#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
struct node
{
 int l,r,id,flag;
 bool operator < (const node &b) const
 {
 return r>b.r;
 }
};
priority_queue <node> q;
bool cmp(const node &a,const node &b)
{
 if (a.l!=b.l) return a.l<b.l;
 return a.id>b.id;
 //return a.r<b.r;
}
node a[100010];
int main()
{
 int T;

 //freopen("in.in","r",stdin);
 // freopen("out.out","w",stdout);
 scanf("%d",&T);
 while (T--)
 {
 int n;
 scanf("%d",&n);
 for (int i=0;i<n;i++)
 {
 scanf("%d%d",&a[i].l,&a[i].r);
 a[i].id=i+1;
 a[i].flag=0;
 }

 bool good=0;
 if (max(a[0].l,a[1].l)<min(a[0].r,a[1].r)) good=1;
 a[1].flag=1;
 a[0].flag=1;
 sort(a,a+n,cmp);
 while (!q.empty()) q.pop();

 int ans=0;
 int numa=0;
 int numb=0;
 int now=0;
 int bad=0;
 int maxs=0;
 for (int i=0;i<n;i++)
 {
 while(!q.empty()&&q.top().r<=a[i].l)
 {
 node s=q.top();
 q.pop();
 if (s.flag) numb++;
 else numa++;
 now--;
 }
// printf(" fisrt now=%d nowa=%d nowb=%d l=%d i=%d\n",
// now,numa,numb,a[i].l,i);
 if (bad!=1)
 {
 numa+=numb;
 numb=0;
 if (numa)
 {
 numa--;
 }
 } else
 {
 if (numa&&numb) good=1;
 if (numa)
 {
 numa--;
 if (a[i].flag) good=1;
 } else
 if (numb)
 {
 a[i].flag=1;
 numb--;
 } else
 if (a[i].flag) good=1;
 }

 q.push(a[i]);
 now++;
 if (a[i].id<=2) bad++;
// printf(" second now=%d nowa=%d nowb=%d l=%d i=%d good=%d\n\n",
// now,numa,numb,a[i].l,i,good);
 if (now+numa+numb>ans) ans=now+numa+numb;
 if (bad==1)
 if (now+numa+numb>maxs) maxs=now+numa+numb;
 }
 // printf("good=%d ",good);
 maxs+=!good;
 if (maxs>ans) ans=maxs;
 printf("%d\n",ans);
 }
 return 0;
}