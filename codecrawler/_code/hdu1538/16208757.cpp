#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
//ä¿å­2çå¹
int fac[15]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
void slove(int n,int m,int p){
    //éå¸å¤è´¿èµçæåµ
    if(n<=2*m){
        //ä¸æ¯å³ç­èï¼èä¸å¥å¶æ§ç¸åï¼é½è½è¢«è´¿èµ
        if(n!=p&&(n%2==p%2))
            printf("1\n");
        //å©ä¸çé½æ¯å³ç­èæ¥æ
        else if(n==p)
            printf("%d\n",m-(n-1)/2);
        else
        //å¶ä½äººåä¸å°éå¸ï¼ä»ä»¬çå³ç­ä¸å½±åå¨å±
            printf("0\n");
        return ;
    }
    //è¿æ¶åçä¸åå¨äºå³ç­èä¸è½æ¿éå¸
    else if(n==2*m+1){
        if(p<2*m&&p&1)
            printf("1\n");
        else
            printf("0\n");
        return ;
    }
    int t=n-2*m,i;
    //è¿æ¯åå¥½ä¿å½çæåµï¼å¯¹äºå³ç­èæ¥è¯´ï¼è¯å®æ²¡æéå¸
    //å¯¹äºå¶å®äººæ¥è¯´ï¼è¦ä¹è¯å®æ²¡æéå¸ï¼è¦ä¹å¯è½æ²¡æéå¸ï¼ä¸ç¡®å®æ§
    for( i=0;i<14;i++){
        if(t==fac[i]){
            printf("0\n");
            return;
        }
    }
    for( i=1;i<14;i++)
        if(t<fac[i]){
            //å³ç­èå¿æ­»
            if(p>2*m+fac[i-1]&&p<2*m+fac[i])
                 printf("Thrown\n");
            else
                 printf("0\n");
            return ;
        }
}
int main(){
    int t,n,m,p;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&p);
        slove(n,m,p);
    }
    return 0;
}