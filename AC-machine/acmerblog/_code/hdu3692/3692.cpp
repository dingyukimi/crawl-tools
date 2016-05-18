#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <time.h>



#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-6

#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORL0(i,a) for(i=a;i>=0;i--)
#define FORL1(i,a) for(i=a;i>=1;i--)
#define FORL(i,a,b)for(i=a;i>=b;i--)

#define rush() int CC;for(scanf("%d",&CC);CC--;)
#define Rush(n) while(scanf("%d",&n)!=-1)
using namespace std;

void RD(int &x){scanf("%d",&x);}
void RD(i64 &x){scanf("%lld",&x);}
void RD(u64 &x){scanf("%I64u",&x);}
void RD(u32 &x){scanf("%u",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(i64 &x,i64 &y){scanf("%lld%lld",&x,&y);}
void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(i64 &x,i64 &y,i64 &z){scanf("%lld%lld%lld",&x,&y,&z);}
void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}
void RD(char &x){x=getchar();}
void RD(char *s){scanf("%s",s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(i64 x) {printf("%lld\n",x);}
void PR(i64 x,i64 y) {printf("%lld %lld\n",x,y);}
void PR(u32 x) {printf("%u\n",x);}
void PR(u64 x) {printf("%llu\n",x);}
void PR(double x) {printf("%.2lf\n",x);}
void PR(double x,double y) {printf("%.5lf %.5lf\n",x,y);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

const int mod=10007;
const i64 inf=((i64)1)<<40;
const double dinf=1000000000000000000.0;
const int INF=100000000;
const int N=1005;

int sgn(double x)
{
 if(x>EPS) return 1;
 if(x<-EPS) return -1;
 return 0;
}

struct POINT
{
 int x,y;
 
 POINT(){}
 POINT(int _x,int _y)
 {
 x=_x;
 y=_y;
 }
 
 void get()
 {
 RD(x,y);
 }
};

struct point
{
 double x,y;
 
 
 point(){}
 point(double _x,double _y)
 {
 x=_x;
 y=_y;
 }
 
 void get()
 {
 RD(x); RD(y);
 }
 
 point operator+(point a)
 {
 return point(x+a.x,y+a.y);
 }
 
 point operator-(point a)
 {
 return point(x-a.x,y-a.y);
 }
 
 double operator*(point a)
 {
 return x*a.y-y*a.x;
 }
 
 point operator*(double t)
 {
 return point(x*t,y*t);
 }
 
 double operator^(point a)
 {
 return x*a.x+y*a.y;
 }
 
 double len()
 {
 return sqrt(x*x+y*y);
 }
 
 point zhuanShun(double t)
 {
 return point(x*cos(t)+y*sin(t),y*cos(t)-x*sin(t));
 }
 
 point zhuanNi(double t)
 {
 return point(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t));
 }
 
 point adjust(double L)
 {
 double d=len();
 L/=d;
 return point(x*L,y*L);
 }
 
 void print()
 {
 printf("%.3lf %.3lf\n",x+EPS,y+EPS);
 }
};

double len(point a)
{
 return a.len();
}

struct point3
{
 double x,y,z;
 
 point3(){}
 point3(double _x,double _y,double _z)
 {
 x=_x;
 y=_y;
 z=_z;
 }
 
 void get()
 {
 cin>>x>>y>>z;
 }
 
 point3 operator+(point3 a)
 {
 return point3(x+a.x,y+a.y,z+a.z);
 }
 
 point3 operator-(point3 a)
 {
 return point3(x-a.x,y-a.y,z-a.z);
 }
 
 point3 operator*(point3 a)
 {
 return point3(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
 }
 
 point3 operator*(double t)
 {
 return point3(x*t,y*t,z*t);
 }
 
 double operator^(point3 a)
 {
 return x*a.x+y*a.y+z*a.z;
 }
 
 point3 operator/(double t)
 {
 return point3(x/t,y/t,z/t);
 }
 
 double len()
 {
 return sqrt(x*x+y*y+z*z);
 }
 
 point3 adjust(double L)
 {
 double t=len();
 L/=t;
 return point3(x*L,y*L,z*L);
 }
 
 void print()
 {
 printf("%.10lf %.10lf %.10lf\n",x+EPS,y+EPS,z+EPS);
 }
};


double len(point3 a)
{
 return a.len();
}


double getArea(point3 a,point3 b,point3 c)
{
 double x=len((b-a)*(c-a));
 return x/2;
}
 
double getVolume(point3 a,point3 b,point3 c,point3 d)
{
 double x=(b-a)*(c-a)^(d-a);
 return x/6;
}

point3 pShadowOnPlane(point3 p,point3 a,point3 b,point3 c)
{
 point3 v=(b-a)*(c-a);
 if(sgn(v^(a-p))<0) v=v*-1;
 v=v.adjust(1);
 double d=fabs(v^(a-p));
 return p+v*d;
}

double lineToLine(point3 a,point3 b,point3 p,point3 q)
{
 point3 v=(b-a)*(q-p);
 return fabs((a-p)^v)/len(v);
}

int pInPlane(point3 p,point3 a,point3 b,point3 c)
{
 double S=getArea(a,b,c);
 double S1=getArea(a,b,p);
 double S2=getArea(a,c,p);
 double S3=getArea(b,c,p);
 return sgn(S-S1-S2-S3)==0;
}

int opposite(point3 p,point3 q,point3 a,point3 b,point3 c)
{
 point3 v=(b-a)*(c-a);
 double x=v^(p-a);
 double y=v^(q-a);
 return sgn(x*y)<0;
}

int segCrossTri(point3 p,point3 q,point3 a,point3 b,point3 c)
{
 return opposite(p,q,a,b,c)&&
 opposite(a,b,p,q,c)&&
 opposite(a,c,p,q,b)&&
 opposite(b,c,p,q,a);
}

double pToPlane(point3 p,point3 a,point3 b,point3 c)
{
 double v=((b-a)*(c-a)^(p-a))/6;
 double s=len((b-a)*(c-a))/2;
 return fabs(3*v/s);
}


double pToLine(point3 p,point3 a,point3 b)
{
 double S=len((a-p)*(b-p));
 return S/len(a-b);
}


double pToSeg(point3 p,point3 a,point3 b)
{
 if(sgn((p-a)^(b-a))<=0) return len(a-p);
 if(sgn((p-b)^(a-b))<=0) return len(b-p);
 return pToLine(p,a,b);
}

double pToPlane1(point3 p,point3 a,point3 b,point3 c)
{
 point3 k=pShadowOnPlane(p,a,b,c);
 if(pInPlane(k,a,b,c)) return pToPlane(p,a,b,c);
 double x=pToSeg(p,a,b);
 double y=pToSeg(p,a,c);
 double z=pToSeg(p,b,c);
 return min(x,min(y,z));
}


double getAng(point3 a,point3 b)
{
 double x=(a^b)/len(a)/len(b);
 return acos(x);
}

double segToSeg(point3 a,point3 b,point3 p,point3 q)
{
 point3 v=(b-a)*(q-p);
 
 double A,B,A1,B1;
 A=((b-a)*v)^(p-a);
 B=((b-a)*v)^(q-a);
 
 A1=((p-q)*v)^(a-q);
 B1=((p-q)*v)^(b-q);
 if(sgn(A*B)<=0&&sgn(A1*B1)<=0) 
 {
 return lineToLine(a,b,p,q);
 }

 double x=min(pToSeg(a,p,q),pToSeg(b,p,q));
 double y=min(pToSeg(p,a,b),pToSeg(q,a,b));
 return min(x,y);
}

struct face
{
 int a,b,c,ok;
 
 face(){}
 face(int _a,int _b,int _c,int _ok)
 {
 a=_a;
 b=_b;
 c=_c;
 ok=_ok;
 }
};

struct _3DCH
{
 face F[N<<2];
 int b[N][N],cnt,n;
 point3 p[N];
 
 int getDir(point3 t,face F)
 {
 double x=(p[F.b]-p[F.a])*(p[F.c]-p[F.a])^(t-p[F.a]);
 return sgn(x);
 }
 
 
 void deal(int i,int x,int y)
 {
 int f=b[x][y];
 if(!F[f].ok) return;
 if(getDir(p[i],F[f])==1) DFS(i,f);
 else
 {
 b[y][x]=b[x][i]=b[i][y]=cnt;
 F[cnt++]=face(y,x,i,1);
 }
 }
 
 void DFS(int i,int j)
 {
 F[j].ok=0;
 deal(i,F[j].b,F[j].a);
 deal(i,F[j].c,F[j].b);
 deal(i,F[j].a,F[j].c);
 }
 
 void construct()
 {
 int i,j,k=0;
 for(i=1;i<n;i++) if(sgn(len(p[i]-p[0])))
 {
 swap(p[i],p[1]);
 k++;
 break;
 }
 if(k!=1) return;
 for(i=2;i<n;i++) if(sgn(getArea(p[0],p[1],p[i])))
 {
 swap(p[i],p[2]);
 k++;
 break;
 }
 if(k!=2) return;
 for(i=3;i<n;i++) if(sgn(getVolume(p[0],p[1],p[2],p[i])))
 {
 swap(p[i],p[3]);
 k++;
 break;
 }
 if(k!=3) return;
 
 cnt=0;
 FOR0(i,4)
 {
 face k=face((i+1)%4,(i+2)%4,(i+3)%4,1);
 if(getDir(p[i],k)==1) swap(k.b,k.c);
 b[k.a][k.b]=b[k.b][k.c]=b[k.c][k.a]=cnt;
 F[cnt++]=k;
 }
 
 for(i=4;i<n;i++) FOR0(j,cnt)
 {
 if(F[j].ok&&getDir(p[i],F[j])==1)
 {
 DFS(i,j);
 break;
 }
 }
 j=0;
 FOR0(i,cnt) if(F[i].ok) F[j++]=F[i];
 cnt=j;
 }
 
 point3 getCenter()
 {
 point3 ans=point3(0,0,0),o=point3(0,0,0);
 double s=0,temp;
 int i;
 FOR0(i,cnt)
 {
 face k=F[i];
 temp=getVolume(o,p[k.a],p[k.b],p[k.c]);
 ans=ans+(o+p[k.a]+p[k.b]+p[k.c])/4*temp;
 s+=temp;
 }
 ans=ans/s;
 return ans;
 }
 
 double getMinDis(point3 a)
 {
 double ans=dinf;
 int i;
 FOR0(i,cnt) 
 {
 face k=F[i];
 ans=min(ans,pToPlane(a,p[k.a],p[k.b],p[k.c]));
 }
 return ans;
 }
 
};


double a,b,c,d;
int n;
point3 p[N],S;

void init()
{
 if(sgn(a)==0&&sgn(b)==0) return;
 p[n+1]=S;
 double sinC,cosC;
 int i;
 point3 temp;
 
 sinC=a/sqrt(a*a+b*b);
 cosC=b/sqrt(a*a+b*b);
 FOR1(i,n+1) 
 {
 temp=p[i];
 p[i].x=temp.x*cosC-temp.y*sinC;
 p[i].y=temp.x*sinC+temp.y*cosC;
 }
 sinC=sqrt(a*a+b*b)/sqrt(a*a+b*b+c*c);
 cosC=c/sqrt(a*a+b*b+c*c);
 FOR1(i,n+1) 
 {
 temp=p[i];
 p[i].y=temp.y*cosC-temp.z*sinC;
 p[i].z=temp.y*sinC+temp.z*cosC;
 }
 S=p[n+1];
}


int deal()
{
 double D=a*S.x+b*S.y+c*S.z;
 if(sgn(D-d)<0)
 {
 a*=-1; b*=-1; c*=-1; d*=-1;
 D*=-1;
 }
 int cnt=0,i;
 FOR1(i,n)
 {
 if(sgn(a*p[i].x+b*p[i].y+c*p[i].z-D)<0)
 {
 cnt++;
 }
 }
 if(cnt!=n) return cnt;
 point3 temp;
 double t;
 FOR1(i,n)
 {
 temp=p[i]-S;
 t=(d-(point3(a,b,c)^S))/(point3(a,b,c)^temp);
 p[i]=S+temp*t;
 }
 return cnt;
}

point A[N],B[N];
int Bnum;

point get(point3 p)
{
 p=p-S;
 double t=(d-S.z)/p.z;
 p=S+p*t;
 return point(p.x,p.y);
}

point H;

int cmp(point a,point b)
{
 int x=sgn((a-H)*(b-H));
 if(x) return x==1;
 return sgn(len(a-H)-len(b-H))<=0;;
}

int cross(point a,point b,point p)
{
 return sgn((b-a)*(p-a));
}

void Graham(point p[],int n,point q[],int &m)
{
 int i,k=0;
 int a,b;
 FOR0(i,n)
 {
 a=sgn(p[i].y-p[k].y);
 b=sgn(p[i].x-p[k].x);
 if(a==-1||a==0&&b==-1) k=i;
 }
 swap(p[0],p[k]); H=p[0]; sort(p,p+n,cmp);
 q[0]=p[0]; q[1]=p[1]; p[n]=p[0];
 m=2;
 for(i=2;i<=n;i++)
 {
 while(m>1&&cross(q[m-2],q[m-1],p[i])<=0) m--;
 q[m++]=p[i];
 }
 m--;
}

double cal()
{
 int i;
 FOR1(i,n) A[i-1]=point(p[i].x,p[i].y);
 Graham(A,n,B,Bnum);
 double ans=0;
 B[Bnum]=B[0];
 FOR1(i,Bnum) ans+=B[i]*B[i-1];
 return fabs(ans/2);
}

int main()
{
 while(scanf("%lf",&a)!=-1)
 {
 RD(b,c,d);
 if(!a&&!b&&!c&&!d) break;
 RD(n);
 int i;
 FOR1(i,n) p[i].get();
 S.get();
 
 int flag=deal();
 if(flag==0) puts("0.00");
 else if(flag!=n) puts("Infi");
 else 
 {
 init();
 PR(cal());
 }
 }
}