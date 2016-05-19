#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <cstdlib>

using namespace std;
const int MAX=2005,INF=1<<30;
int a[MAX],c[MAX],
 n,len;
int bsearchLDS(const int &v){
 int l=1,r=len+1,m;
 while(l<r){
 m=l+(r-l)/2;
 if(c[m]>v) l=m+1;
 else r=m;
 }
 return l;
}
int bsearchLIS(const int &v){
 int l=1,r=len+1,m;
 while(l<r){
 m=l+(r-l)/2;
 if(c[m]<v) l=m+1;
 else r=m;
 }
 return l;
}
int LDS(const int &i){
 int pos;
 len=1;
 c[len]=a[i];
 for(int j=i+1;j<n;j++){
 pos=bsearchLDS(a[j]);
 if(pos==1)
 continue;
 c[pos]=a[j];
 if(pos>len)
 len=pos;
 }
 return len;
}
int LIS(const int &i){
 int pos;
 len=1;
 c[len]=a[i];
 for(int j=i+1;j<n;j++){
 pos=bsearchLIS(a[j]);
 if(pos==1)
 continue;
 c[pos]=a[j];
 if(pos>len)
 len=pos;
 }
 return len;
}
int main()
{
// freopen("i.txt","r",stdin);
 int nCase,t1,t2,l,maxVal;
// cin>>nCase;
 while(cin>>n){
 maxVal=0;
 //memset(a,0,sizeof(a));
 //memset(c,0,sizeof(c));
 for(int i=0;i<n;i++)
 cin>>a[i];
 for(int i=0;i<n;i++){
 //LDS;
 t1=LDS(i);
 t2=LIS(i);
// cout<<i<<' '<<a[i]<<endl;
// cout<<t1<<' '<<t2<<endl<<endl;
 l=t1+t2-1;
 if(l>maxVal)
 maxVal=l;
 //break;
 }
 cout<<maxVal<<endl;
 }
 return 0;
}