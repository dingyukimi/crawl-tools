#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 9,limit = 6,INF = 1000;
const int dirx[4]={0,-1,0,1},diry[4]={1,0,-1,0};

//map[x][y][0]-map[x][y][3] åå«è¡¨ç¤ºåæ ä¸ºxï¼yçæ ¼å­çåä¸ªæ¹åå¢çæåµï¼0ä¸ºæ²¡å¢ï¼1ä¸ºæå¢
int map[MAX][MAX][4];
//pre[x][y][0]ç¨æ¥è®°å½xï¼yçåé©±æ ¼å­çxåæ ï¼pre[x][y][1]ç¨æ¥è®°å½xï¼yçåé©±æ ¼å­çyåæ 
int dist[MAX][MAX],pre[MAX][MAX][2];
int sx,sy,ex,ey,pax,pay,pbx,pby;
stack<char> st;

void init(){
    int i,j;

    for(i=0;i<MAX;++i){
        for(j=0;j<MAX;++j){
            dist[i][j] = INF;
            map[i][j][0] = map[i][j][1] = map[i][j][2] = map[i][j][3] = 0;
        }
    }
}

void dfs(int x,int y,int cnt){
    
    
    int i,tx,ty;

    for(i=0;i<4;++i){
        if(map[x][y][i]==1)continue;
        tx = x+dirx[i];
        ty = y+diry[i];
        if(tx<1 || ty<1 || tx>limit || ty>limit)continue;
        if(cnt+1>dist[tx][ty])continue;
        //æ´ç­å°±è¦æ´æ°ï¼å¹¶ä¸è®°å½åé©±
        dist[tx][ty] = cnt;
        pre[tx][ty][0] = x;
        pre[tx][ty][1] = y;
        dfs(tx,ty,cnt+1);
    }
}

void Path(){
    int px,py,x,y;

    x = ex,y = ey;
    px = pre[x][y][0];
    py = pre[x][y][1];

    while(1){
        //å¤æ­æ¹å
        if(x==px){//xåæ ç¸åçyåæ çæåµ
            if(py<y)st.push('E');
            else st.push('W');
        }else{//yåæ ç¸åçxåæ çæåµ
            if(px<x)st.push('S');
            else st.push('N');
        }
        if(px==sx && py==sy)break;
        x = px;
        y = py;
        px = pre[x][y][0];
        py = pre[x][y][1];
    }

    while(!st.empty()){
        printf("%c",st.top());
        st.pop();
    }
    printf("\n");
}

int main(){
    //freopen("in.txt","r",stdin);
    //(author : CSDN iaccepted)
    int i,j;
    while(scanf("%d %d",&sy,&sx)){
        if(sx==0 && sy==0)break;
        scanf("%d %d",&ey,&ex);
        
        init();
        for(i=0;i<3;++i){
            scanf("%d %d %d %d",&pay,&pax,&pby,&pbx);
            if(pax==pbx){
                for(j=pay+1;j<=pby;++j){
                    map[pax][j][3] = 1;
                    map[pax+1][j][1] = 1;
                }
            }else{
                for(j=pax+1;j<=pbx;++j){
                    map[j][pby][0] = 1;
                    map[j][pby+1][2] = 1;
                }
            }
        }

        dfs(sx,sy,0);

        Path();
    }
        
    return 0;
}
