#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
   int num[4],step;
};
node first,last;
bool visit[10][10][10][10],flag;
void bfs()
{
    int i;
   node p,q;
   queue<node> Q;
   memset(visit,false,sizeof(visit));
   flag=true;
   first.step=0;
   p=first;
   visit[p.num[0]][p.num[1]][p.num[2]][p.num[3]]=true;
   Q.push(p);
   while(!Q.empty())
   {
      p=Q.front();Q.pop();
      flag=true;
      for(i=0;i<4;i++)
      if(p.num[i]!=last.num[i])
      {
          flag=false;
          break;
      };
      if(flag)
      {
         printf("%d\n",p.step);
         return;
      }
      
      for(i=0;i<4;i++)//+1
      {
          q=p;
         if(p.num[i]==9) q.num[i]=1;
         else q.num[i]=p.num[i]+1;
         q.step=p.step+1;
         if(!visit[q.num[0]][q.num[1]][q.num[2]][q.num[3]])
         {
            visit[q.num[0]][q.num[1]][q.num[2]][q.num[3]]=true;
            Q.push(q);
         }
      }
      for(i=0;i<4;i++)//-1
      {
          q=p;
         if(p.num[i]==1) q.num[i]=9;
         else q.num[i]=p.num[i]-1;
         q.step=p.step+1;
         if(!visit[q.num[0]][q.num[1]][q.num[2]][q.num[3]])
         {
            visit[q.num[0]][q.num[1]][q.num[2]][q.num[3]]=true;
            Q.push(q);
         }
      }
      for(i=0;i<3;i++)//ç¸é»äº¤æ¢
      {
         q=p;
         q.num[i]=p.num[i+1];
         q.num[i+1]=p.num[i];
         q.step=p.step+1;
         if(!visit[q.num[0]][q.num[1]][q.num[2]][q.num[3]])
         {
            visit[q.num[0]][q.num[1]][q.num[2]][q.num[3]]=true;
            Q.push(q);
         }
      }
   }
}
int main()
{
   int cas,i;
   char chf[5],chl[5];
   scanf("%d",&cas);
   while(cas--)
   {
      scanf("%s%s",chf,chl);
      for(i=0;i<4;i++)
      {
         first.num[i]=chf[i]-'0';
         last.num[i]=chl[i]-'0';
      }
      bfs();
   }
   return 0;
}