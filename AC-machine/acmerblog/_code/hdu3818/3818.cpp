#include<stdio.h>
#include<string.h>
#define MAX 1000000
int a[1000010];
int b[1000];
int main()
{
     int x,n,i,j,num,max=0,sum,ji=0;
     scanf("%d",&x);
     while(x--)    
     {
            ji++;
            memset( a, 0, sizeof(a) );  //输入数据
            for( i=1; i<=2; i++ )         
               {
                  scanf("%d",&n);
                  for( j=1; j<=n;j++ )          
                     {
                       scanf("%d",&num);
                       if( num>max )max=num;
                       a[num]++;
                     }  
               }
              
          
            for( i=max; i>=2; i--)  //对含有两个重复利用 2*f[n]=f[n+1]+f[n-2]
               {
                  if(a[i]>=2){
                              a[i]-=2;        
                              a[i+1]+=1; 
                              a[i-2]+=1;
                             }
               } 
               
               if(a[1]!=0)a[2]+=a[1];     //考虑 fibnaci数列中 序号 f[1]=f[2]这种特殊情况
   
            for( i=max+1; i>=3; i-- )     //连续两次调用f[n]=f[n-1]+f[n-2]
               {
                   if(a[i]==1&&a[i-1]==1)
                       {
                           a[i]=a[i-1]=0;
                           a[i+1]+=1;  ;
                       }             
               }
               
   
            for( i=max+2; i>=3; i-- )
               {
                   if(a[i]==1&&a[i-1]==1)
                       {
                           a[i]=a[i-1]=0;
                           a[i+1]+=1;  ;
                       }             
               }

   
            j=0;
            sum=0;
            for(i=2; i<=max+5; i++)   //输出结果
            {
              if(a[i]!=0){b[j++]=i;sum++;}         
            }
            printf("Case %d:\n",ji);
            printf("%d",sum);
            for( i=0; i<j; i++)
               printf(" %d",b[i]);
               printf("\n");               
     } 
}


