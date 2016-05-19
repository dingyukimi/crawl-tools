#include <stdio.h>
 
 int map[20][20];
 int Kinga,Kingb;//红王坐标 
 int Kingc,Kingd;//黑王坐标 
 int abs(int a){return a>0?a:-a;}
 int KingFaceToFace()//两王是否相对 
 {
     int i;
     if(Kingb==20||Kingd==20)return 0;
     if(Kingb==Kingd)
     {
         for(i=Kingc+1;i<Kinga;i++)
             if(map[i][Kingb]!=0)
                 return 0;
         return 1;
     }
     return 0;
 }
 int King(int a,int b,int c,int d)
 {
     if((abs(a-c)+abs(b-d))!=1)return 0;//王一次走一步 
     if(map[a][b]==1&&(a<8||b<4||b>6||c<8||d<4||d>6))//红王出九宫格 
         return 0;
     if(map[a][b]==8&&(a>3||b<4||b>6||c>3||d<4||d>6))//黑王出九宫格
         return 0;
     if(map[a][b]==1){
         Kinga=c;
         Kingb=d;
     }
     if(map[a][b]==8){
         Kingc=c;
         Kingd=d;
     }
     map[c][d]=map[a][b];
     map[a][b]=0; 
     if(KingFaceToFace())
         return 0;
     return 1;
 }
 int Mandarins(int a,int b,int c,int d)
 {
     if(abs(a-c)!=1||abs(b-d)!=1)return 0;//士走斜一格
     if(map[a][b]==2&&(c<8||c>10||d<4||d>6))//红士出九宫格 
         return 0;
     if(map[a][b]==9&&(c>3||c<1||d<4||d>6))//黑士出九宫格
         return 0;
     map[c][d]=map[a][b];
     map[a][b]=0; 
     if(KingFaceToFace())
         return 0;
     return 1;
 }
 int Elephants(int a,int b,int c,int d)
 {
     if(abs(a-c)!=2||abs(b-d)!=2)return 0;//象走田 
     if(map[a][b]==3&&(!(((a==6||a==10)&&(b==3||b==7))||(a==8&&(b==1||b==5||b==9)))||!(((c==6||c==10)&&(d==3||d==7))||(c==8&&(d==1||d==5||d==9)))))return 0;//红象非主流 
     if(map[a][b]==10&&(!(((a==5||a==1)&&(b==3||b==7))||(a==3&&(b==1||b==5||b==9)))||!(((c==5||c==1)&&(d==3||d==7))||(c==3&&(d==1||d==5||d==9)))))return 0;//黑象非主流 
     int x,y;
     x=(a+c)/2;
     y=(b+d)/2;
     if(map[x][y])//别象脚 
         return 0;
     map[c][d]=map[a][b];
     map[a][b]=0;
     if(KingFaceToFace())
         return 0;
     return 1; 
 } 
 int Knights(int a,int b,int c,int d)
 {
     int luoma[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};//落马的位置 
     int majiao[8][2]={{1,0},{1,0},{-1,0},{-1,0},{0,1},{0,-1},{0,1},{0,-1}};//马脚的位置 
     int i;
     for(i=0;i<8;i++)
     {
         if(a+luoma[i][0]==c&&b+luoma[i][1]==d)
         {
             if(map[a+majiao[i][0]][b+majiao[i][1]])//别马脚 
                 return 0;
             break;
         }
     }
     if(i==8)return 0;
     if(map[c][d]==1)Kinga=Kingb=20;
     if(map[c][d]==8)Kingc=Kingd=20;
     map[c][d]=map[a][b];
     map[a][b]=0;
     if(KingFaceToFace())
         return 0;
     return 1;
 }
 int Rooks(int a,int b,int c,int d)
 {
     int i;
     if(a!=c&&b!=d)return 0;//车走十字 
     if(a==c&&d>b)//车向右走中间不能有子 
         for(i=b+1;i<d;i++)
             if(map[a][i])
                 return 0;
     if(a==c&&d<b)//车向左走中间不能有子
         for(i=b-1;i>d;i--)
             if(map[a][i])
                 return 0;
     if(b==d&&a>c)//车向上走中间不能有子 
         for(i=a-1;i>c;i--)
             if(map[i][b])
                 return 0;
     if(b==d&&a<c)//车向下走中间不能有子 
         for(i=a+1;i<c;i++)
             if(map[i][b])
                 return 0;
     if(map[c][d]==1)Kinga=Kingb=20;
     if(map[c][d]==8)Kingc=Kingd=20;
     map[c][d]=map[a][b];
     map[a][b]=0;
     if(KingFaceToFace())
         return 0;
     return 1; 
 }
 int Cannons(int a,int b,int c,int d)
 {
     int i,cnt=0;
     if(a!=c&&b!=d)return 0;//炮走十字 
     if(a==c&&d>b) 
     {
         for(i=b+1;i<d;i++)
             if(map[a][i]!=0)
                 cnt++;
         if(cnt>1||(cnt==1&&map[c][d]==0)||(cnt==0&&map[c][d]))return 0;//中间有一子以上或有一子但不能完成吃子 
     }
     if(a==c&&d<b)
     {
         for(i=b-1;i>d;i--)
             if(map[a][i]!=0)
                 cnt++;
         if(cnt>1||(cnt==1&&map[c][d]==0)||(cnt==0&&map[c][d]))return 0;
     }
     if(b==d&&a>c) 
     {
         for(i=a-1;i>c;i--)
             if(map[i][b]!=0)
                 cnt++;
         if(cnt>1||(cnt==1&&map[c][d]==0)||(cnt==0&&map[c][d]))return 0;
     }
     if(b==d&&a<c)
     {
         for(i=a+1;i<c;i++)
             if(map[i][b]!=0)
                 cnt++; 
         if(cnt>1||(cnt==1&&map[c][d]==0)||(cnt==0&&map[c][d]))return 0;
     }
     if(map[c][d]==1)Kinga=Kingb=20;
     if(map[c][d]==8)Kingc=Kingd=20;
     map[c][d]=map[a][b];
     map[a][b]=0;
     if(KingFaceToFace())
         return 0;
     return 1;
 }
 int Pawns(int a,int b,int c,int d)
 {
     if(abs(a-c)+abs(b-d)!=1)return 0;
     if(map[a][b]==14&&a<=5)//黑兵没过河只能向前走一步 
         if(c-a!=1||b!=d)
             return 0;
     if(map[a][b]==7&&a>=6)//红兵没过河只能向前走一步
         if(c-a!=-1||b!=d)
             return 0;
     if(map[a][b]==14&&a>5)//黑兵过河后能向前或左或右走一步 
         if(c-a==-1)
             return 0; 
     if(map[a][b]==7&&a<6)//红兵过河后能向前或左或右走一步
         if(c-a==1)
             return 0;
     if(map[c][d]==1)Kinga=Kingb=20;
     if(map[c][d]==8)Kingc=Kingd=20;
     map[c][d]=map[a][b];
     map[a][b]=0;
     if(KingFaceToFace())
         return 0;
     return 1; 
 }
 int move(int a,int b,int c,int d,int k)
 {
     if(map[a][b]<=k*7||map[a][b]>k*7+7)//红黑方不按顺序走 
         return 0;
     if(a>10||b>9||c>10||d>9||a<1||b<1||c<1||d<1)return 0;//越界 
     if(map[a][b]==0)return 0;//无子
     if((map[a][b]==1||map[a][b]==2||map[a][b]==3||map[a][b]==4||map[a][b]==5||map[a][b]==6||map[a][b]==7)&&(map[c][d]==1||map[c][d]==2||map[c][d]==3||map[c][d]==4||map[c][d]==5||map[c][d]==6||map[c][d]==7)) 
         return 0;//红方吃自己的子
     if((map[a][b]==8||map[a][b]==9||map[a][b]==10||map[a][b]==11||map[a][b]==12||map[a][b]==13||map[a][b]==14)&&(map[c][d]==8||map[c][d]==9||map[c][d]==10||map[c][d]==11||map[c][d]==12||map[c][d]==13||map[c][d]==14))
         return 0;//黑方吃自己的子 
     if(map[a][b]==1||map[a][b]==8)//走王 
         return King(a,b,c,d);
     if(map[a][b]==2||map[a][b]==9)//走士 
         return Mandarins(a,b,c,d);
     if(map[a][b]==3||map[a][b]==10)//走象 
         return Elephants(a,b,c,d);
     if(map[a][b]==4||map[a][b]==11)//走马 
         return Knights(a,b,c,d);
     if(map[a][b]==5||map[a][b]==12)//走车 
         return Rooks(a,b,c,d);
     if(map[a][b]==6||map[a][b]==13)//走炮 
         return Cannons(a,b,c,d);
     if(map[a][b]==7||map[a][b]==14)//走兵 
         return Pawns(a,b,c,d);
 } 
 int main()
 {
     int t;
     int n,k;
     int a,b,c,d;
     int i,j;
     int nCase=1;
     int step;
     scanf("%d",&t);
     while(t--)
     {
         for(i=1;i<=10;i++)
         {
             for(j=1;j<=9;j++)
             {
                 scanf("%d",&map[i][j]);
                 if(map[i][j]==1){
                     Kinga=i;
                     Kingb=j;
                 }
                 if(map[i][j]==8){
                     Kingc=i;
                     Kingd=j;
                 }
             }
         }
         scanf("%d%d",&n,&k);
         step=0;
         for(i=1;i<=n;i++)
         {
             scanf("%d%d%d%d",&a,&b,&c,&d);
             if(!step)
             {
                 if(!move(a,b,c,d,k))//非法移动 
                     step=i;
                 if(i!=n&&(Kingb==20||Kingd==20))//吃王 
                     step=i+1;
             }
             k=!k;
         }
         printf("Case %d: ",nCase++);
         if(!step)
             printf("Legal move\n");
         else
             printf("Illegal move on step %d\n",step);
     }
     return 0;
 }