#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;
char seq[1010];
int type[1010];
int maz[20][20];
int LS;
int now;
int ans;
int N;

void init()
{
    memset(maz, 0, sizeof(maz));
}
void out(){
    return;
    getchar();
    system( "cls" );
    cout << now << " " << seq[now] <<  endl;
    for( int i = 12 ; i ; i -- )
    {
        for( int j = 1 ; j <= 9 ; j ++ )
            printf("%d ",maz[j][i] );
        puts("");
    }
}
int tmp[20][20];
void disappear()
{
out();
    memset(tmp, 0, sizeof(tmp));
    int nx = 1;
    for(int y = 1; y <= 12; y++)
    {
        int cnt = 0;
        for(int x = 1; x <= 9; x++)
            if(maz[x][y]) cnt++;
        if(cnt == 9)
        {
            ans++;
        }
        else
        {
            for(int i = 1; i <= 9; i++)
                tmp[i][nx] = maz[i][y];
            nx++;
        }
    }
    memset(maz, 0, sizeof(maz));
    for(int j = 1; j <= 9; j++)
        for(int i = 1; i < nx; i++)
            maz[j][i] = tmp[j][i];
out();
    return;
}

void OO()
{
    int midx = 4, midy = 9;//step 1
    maz[midx][midy] = maz[midx][midy + 1] = maz[midx + 1][midy] = maz[midx + 1][midy + 1] = 1;//square
    while(now < LS)//seq[now]
    {
out();
        if(seq[now] == 'w')//step2
        {
            ;//rotate
        }
        else if(seq[now] == 'a')
        {
            //move left
            if(midx - 1 >= 1 && !maz[midx - 1][midy] && !maz[midx - 1][midy + 1])
            {
                maz[midx - 1][midy] = maz[midx - 1][midy + 1] = 1;
                maz[midx + 1][midy] = maz[midx + 1][midy + 1] = 0;
                midx--;
            }
            else ;//do nothing
        }
        else if(seq[now] == 'd')
        {
            if(midx + 1 + 1 <= 9 && !maz[midx + 2][midy] && !maz[midx + 2][midy + 1])
            {
                maz[midx + 2][midy] = maz[midx + 2][midy + 1] = 1;
                maz[midx][midy] = maz[midx][midy + 1] = 0;
                midx++;
            }
            else ;//do nothing
        }
        else if(seq[now] == 's')
        {
            if(midy - 1 >= 1 && maz[midx][midy - 1] == 0 && maz[midx + 1][midy - 1] == 0)
            {
                maz[midx][midy - 1] = maz[midx + 1][midy - 1] = 1;
                maz[midx][midy + 1] = maz[midx + 1][midy + 1] = 0;//move down
                midy--;
            }
            else ;//do nothing
        }
        now++;//next command

        //fall a unit
        if(midy - 1 >= 1 && maz[midx][midy - 1] == 0 && maz[midx + 1][midy - 1] == 0)//step3
        {
            maz[midx][midy - 1] = maz[midx + 1][midy - 1] = 1;
            maz[midx][midy + 1] = maz[midx + 1][midy + 1] = 0;
            midy--;
        }
        else
        {
            break;//jump to step4
        }
    }
    disappear();//step4
    return;
}

void II()
{
    int midx = 4, midy = 9;
    for(int i = 0; i < 4; i++)
        maz[midx][midy + i] = 1;//Line
    int cas = 0;//shuzhe
    while(now < LS)
    {
out();
        if(seq[now] == 'w')
        {
            if(cas == 0)
            {
                bool ok = 1;
                for(int i = 1; i <= 3; i++)
                {
                    if(midx + i > 9 || maz[midx + i][midy] == 1)
                    {
                        ok = 0;
                        break;
                    }
                }
                if(!ok) ;//do nothing
                else//switch from 0 to 1
                {
                    for(int i = 1; i <= 3; i++)
                        maz[midx][midy + i] = 0;
                    for(int i = 1; i <= 3; i++)
                        maz[midx + i][midy] = 1;
                    cas = 1;
                }
            }
            else//cas == 1
            {
                bool ok = 1;
                for(int i = 1; i <= 3; i++)
                {
                    if(maz[midx][midy + i] == 1)
                    {
                        ok = 0;
                        break;
                    }
                }
                if(!ok);//do nothing
                else//switch from 1 to 0
                {
                    for(int i = 1; i <= 3; i++)
                        maz[midx][midy + i] = 1;
                    for(int i = 1; i <= 3; i++)
                        maz[midx + i][midy] = 0;
                    cas = 0;
                }
            }
        }
        else if(seq[now] == 'a')//move left
        {
            if(cas == 0)//
            {
                bool ok = 1;
                for(int i = 0; i < 4; i++)
                    if(midx - 1 < 1 || maz[midx - 1][midy + i] == 1)
                    {
                        ok = 0;
                        break;
                    }
                if(!ok);//do nothing
                else//cas 0 move left
                {
                    for(int i = 0; i < 4; i++)
                    {
                        maz[midx - 1][midy + i] = 1;
                        maz[midx][midy + i] = 0;
                    }
                    midx--;
                }
            }
            else//cas == 1
            {
                if(midx - 1 < 1 || maz[midx - 1][midy] == 1);
                else
                {
                    maz[midx - 1][midy] = 1;
                    maz[midx + 3][midy] = 0;
                    midx--;
                }

            }
        }
        else if(seq[now] == 'd')//move right
        {
            if(cas == 0)//
            {
                bool ok = 1;
                for(int i = 0; i < 4; i++)
                    if(midx + 1 > 9 || maz[midx + 1][midy + i] == 1)
                    {
                        ok = 0;
                        break;
                    }
                if(!ok);//do nothing
                else//cas 0 move right
                {
                    for(int i = 0; i < 4; i++)
                    {
                        maz[midx + 1][midy + i] = 1;
                        maz[midx][midy + i] = 0;
                    }
                    midx++;
                }
            }
            else//cas == 1
            {
                if(midx + 4 > 9 || maz[midx + 4][midy] == 1);
                else
                {
                    maz[midx + 4][midy] = 1;
                    maz[midx][midy] = 0;
                    midx++;
                }
            }
        }
        else if(seq[now] == 's')//move down
        {
            if(cas == 0)//shuzhe
            {
                if(midy - 1 < 1 || maz[midx][midy - 1] == 1);//do nothing
                else
                {
                    maz[midx][midy + 3] = 0;
                    maz[midx][midy - 1] = 1;
                    midy--;
                }
            }
            else//cas == 1
            {
                int ok = 1;
                for(int i = 0; i < 4; i++)
                    if(midy - 1 < 1 || maz[midx + i][midy - 1] == 1)
                    {
                        ok = 0;
                        break;
                    }
                if(!ok);//do nothing
                else
                {
                    for(int i = 0; i < 4; i++)
                        maz[midx + i][midy - 1] = 1;
                    for(int i = 0; i < 4; i++)
                        maz[midx + i][midy] = 0;
                    midy--;
                }
            }
        }
        now++;//next command

        //fall a unit
        if(cas == 0)//step3
        {
            if(midy - 1 < 1 || maz[midx][midy - 1] == 1)
                break;//jump to step4
            else
            {
                maz[midx][midy + 3] = 0;
                maz[midx][midy - 1] = 1;
                midy--;
            }
        }
        else//cas == 1
        {
            int ok = 1;
            for(int i = 0; i < 4; i++)
                if(midy - 1 < 1 || maz[midx + i][midy - 1] == 1)
                {
                    ok = 0;
                    break;
                }
            if(!ok)
                break;//jump to step4
            else
            {
                for(int i = 0; i < 4; i++)
                    maz[midx + i][midy - 1] = 1;
                for(int i = 0; i < 4; i++)
                    maz[midx + i][midy] = 0;
                midy--;
            }
        }
    }
    disappear();//step4
}

void JJ()
{
    int midx = 4, midy = 9;//step1
    int cas = 0;
    maz[midx][midy] = maz[midx + 1][midy] = maz[midx + 2][midy] = maz[midx][midy + 1] = 1;
    while(now < LS)
    {
out();
        //step2
        if(seq[now] == 'w')//change
        {
            if(cas == 0)//0 to 1
            {
                if(maz[midx][midy + 2] == 1 || maz[midx + 1][midy + 2] == 1);
                else//can change
                {
                    maz[midx + 1][midy] = maz[midx + 2][midy] = 0;
                    maz[midx][midy + 2] = maz[midx + 1][midy + 2] = 1;
                    cas = 1;
                }

            }
            else if(cas == 1)//1 to 2
            {
                if(maz[midx + 1][midy + 1] == 1 || maz[midx + 2][midy + 1] == 1 || maz[midx + 2][midy] == 1);
                else
                {
                    maz[midx][midy] = maz[midx][midy + 2] = maz[midx + 1][midy + 2] = 0;
                    maz[midx + 1][midy + 1] = maz[midx + 2][midy] = maz[midx + 2][midy + 1] = 1;
                    cas = 2;
                }
            }
            else if(cas == 2)//2 to 3
            {
                if(maz[midx][midy] == 1 || maz[midx + 1][midy] == 1 || maz[midx + 1][midy + 2] == 1);
                else
                {
                    maz[midx][midy] = maz[midx + 1][midy] = maz[midx + 1][midy + 2] = 1;
                    maz[midx][midy + 1] = maz[midx + 2][midy] = maz[midx + 2][midy + 1] = 0;
                    cas = 3;
                }
            }
            else if(cas == 3)//3 to 0
            {
                if(maz[midx][midy + 1] == 1 || maz[midx + 2][midy] == 1);
                else
                {
                    maz[midx][midy + 1] = maz[midx + 2][midy] = 1;
                    maz[midx + 1][midy + 1] = maz[midx + 1][midy + 2] = 0;
                    cas = 0;
                }
            }
        }else if(seq[now] == 'a') //move left
        {
            if(cas == 0)//cas 0
            {
                if(midx - 1 < 1 || maz[midx - 1][midy] == 1 || maz[midx - 1][midy + 1] == 1);
                else
                {
                    maz[midx - 1][midy] = maz[midx - 1][midy + 1] = 1;
                    maz[midx][midy + 1] = maz[midx + 2][midy] = 0;
                    midx--;
                }
            }
            else if(cas == 1)
            {
                if(midx - 1 < 1 || maz[midx - 1][midy] || maz[midx - 1][midy + 1] || maz[midx - 1][midy + 2]);
                else
                {
                    maz[midx - 1][midy] = maz[midx - 1][midy + 1] = maz[midx - 1][midy + 2] = 1;
                    maz[midx][midy] = maz[midx][midy + 1] = maz[midx + 1][midy + 2] = 0;
                    midx--;
                }
            }
            else if(cas == 2)
            {
                if(midx - 1 < 1 || maz[midx - 1][midy + 1] || maz[midx + 1][midy]);
                else
                {
                    maz[midx - 1][midy + 1] = maz[midx + 1][midy] = 1;
                    maz[midx + 2][midy] = maz[midx + 2][midy + 1] = 0;
                    midx--;
                }
            }
            else if(cas == 3)
            {
                if(midx - 1 < 1 || maz[midx - 1][midy] || maz[midx][midy + 1] || maz[midx][midy + 2]);
                else
                {
                    maz[midx - 1][midy] = maz[midx][midy + 1] = maz[midx][midy + 2] = 1;
                    maz[midx + 1][midy] = maz[midx + 1][midy + 1] = maz[midx + 1][midy + 2] = 0;
                    midx--;
                }
            }
        }
        else if(seq[now] == 'd') //move right
        {
            if(cas == 0)
            {
                if(midx + 3 > 9 || maz[midx + 3][midy] || maz[midx + 1][midy + 1]);
                else
                {
                    maz[midx + 3][midy] = maz[midx + 1][midy + 1] = 1;
                    maz[midx][midy] = maz[midx][midy + 1] = 0;
                    midx++;
                }
            }
            else if(cas == 1)
            {
                if(midx + 2 > 9 || maz[midx + 2][midy + 2] || maz[midx + 1][midy] || maz[midx + 1][midy + 1]);
                else
                {
                    maz[midx + 2][midy + 2] = maz[midx + 1][midy] = maz[midx + 1][midy + 1] = 1;
                    maz[midx][midy] = maz[midx][midy + 1] = maz[midx][midy + 2] = 0;
                    midx++;
                }
            }
            else if(cas == 2)
            {
                if(midx + 3 > 9 || maz[midx + 3][midy] || maz[midx + 3][midy + 1]);
                else
                {
                    maz[midx + 3][midy] = maz[midx + 3][midy + 1] = 1;
                    maz[midx][midy + 1] = maz[midx + 2][midy] = 0;
                    midx++;
                }
            }
            else if(cas == 3)
            {
                if(midx + 2 > 9 || maz[midx + 2][midy] || maz[midx + 2][midy + 1] || maz[midx + 2][midy + 2]);
                else
                {
                    maz[midx + 2][midy] = maz[midx + 2][midy +1] = maz[midx + 2][midy + 2] = 1;
                    maz[midx][midy] = maz[midx + 1][midy + 1] = maz[midx +1][midy + 2] = 0;
                    midx++;
                }
            }
        }
        else if(seq[now] == 's') //move down
        {
            if(cas == 0)
            {
                bool ok = 1;
                for(int i = 0; i < 3; i++)
                    if(midy - 1 < 1 || maz[midx + i][midy - 1])
                    {
                        ok = 0;
                        break;
                    }
                if(!ok);
                else
                {
                    for(int i = 0; i < 3; i++)
                        maz[midx + i][midy - 1] = 1;
                    maz[midx + 1][midy] = maz[midx + 2][midy] = maz[midx][midy + 1] = 0;
                    midy--;
                }
            }
            else if(cas == 1)
            {
                if(midy - 1 < 1 || maz[midx][midy - 1] || maz[midx + 1][midy + 1]);
                else
                {
                    maz[midx][midy - 1] = maz[midx + 1][midy + 1] = 1;
                    maz[midx][midy + 2] = maz[midx + 1][midy + 2] = 0;
                    midy--;
                }
            }
            else if(cas == 2)
            {
                if(midy - 1 < 1 || maz[midx + 2][midy - 1] || maz[midx][midy] || maz[midx + 1][midy]);
                else
                {
                    maz[midx + 2][midy - 1] = maz[midx][midy] = maz[midx + 1][midy] = 1;
                    maz[midx][midy + 1] = maz[midx + 1][midy + 1] = maz[midx + 2][midy + 1] = 0;
                    midy--;
                }
            }
            else if(cas == 3)
            {
                if(midy - 1 < 1 || maz[midx][midy - 1] || maz[midx + 1][midy - 1]);
                else
                {
                    maz[midx][midy - 1] = maz[midx + 1][midy - 1] = 1;
                    maz[midx][midy] = maz[midx + 1][midy + 2] = 0;
                    midy--;
                }
            }
        }
        now++;//next command

        //fall a unit, step3
        if(4)
        {
            if(cas == 0)
            {
                bool ok = 1;
                for(int i = 0; i < 3; i++)
                    if(midy - 1 < 1 || maz[midx + i][midy - 1])
                    {
                        ok = 0;
                        break;
                    }
                if(!ok)
                    break;
                else
                {
                    for(int i = 0; i < 3; i++)
                        maz[midx + i][midy - 1] = 1;
                    maz[midx + 1][midy] = maz[midx + 2][midy] = maz[midx][midy + 1] = 0;
                    midy--;
                }
            }
            else if(cas == 1)
            {
                if(midy - 1 < 1 || maz[midx][midy - 1] || maz[midx + 1][midy + 1])
                    break;
                else
                {
                    maz[midx][midy - 1] = maz[midx + 1][midy + 1] = 1;
                    maz[midx][midy + 2] = maz[midx + 1][midy + 2] = 0;
                    midy--;
                }
            }
            else if(cas == 2)
            {
                if(midy - 1 < 1 || maz[midx + 2][midy - 1] || maz[midx][midy] || maz[midx + 1][midy])
                    break;
                else
                {
                    maz[midx + 2][midy - 1] = maz[midx][midy] = maz[midx + 1][midy] = 1;
                    maz[midx][midy + 1] = maz[midx + 1][midy + 1] = maz[midx + 2][midy + 1] = 0;
                    midy--;
                }
            }
            else if(cas == 3)
            {
                if(midy - 1 < 1 || maz[midx][midy - 1] || maz[midx + 1][midy - 1])
                    break;
                else
                {
                    maz[midx][midy - 1] = maz[midx + 1][midy - 1] = 1;
                    maz[midx][midy] = maz[midx + 1][midy + 2] = 0;
                    midy--;
                }
            }
        }

    }
    disappear();//step4
}

void start()
{
    init();
    for(int i = 1; i <= N; i++)
    {
        switch(type[i])
        {
            case 0: OO(); break;
            case 1: II(); break;
            case 2: JJ(); break;
        }
    }
}

int main()
{
//    freopen( "a.c" , "r" , stdin );
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &N);
        scanf("%s", seq);
        for(int i = 1; i <= N; i++)
            scanf("%d", &type[i]);

//freopen( "CON" , "r" , stdin );
        LS = strlen(seq);
        now = 0;
        ans = 0;
        start();
        printf("Case %d: %d\n", cas,  ans);
        /*
        for(int i = 12; i >= 1; i--)
        {
            for(int j = 1; j <= 9; j++)
            cout<<maz[j][i];
            cout<<endl;
        }
        */
    }
    return 0;
}