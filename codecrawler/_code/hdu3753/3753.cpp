/*
Pro: 0

Sol:

date:
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>//header
#include <cmath>
#include <sstream>//header
#include <queue>
#include <set>
#include <vector>
//istringstream对象可以绑定一行字符串，然后以空格为分隔符把该行分隔开来。
using namespace std;
string tmp,str[1111][190];
int len[190],T,num[1111];
int main(){
    scanf("%d",&T);
    while(T --){
        memset(len,0,sizeof(len));
        memset(num,0,sizeof(num));
        int nNum = 0;
        while(getline(cin,tmp) && tmp != "@"){
            if(tmp == "") continue; //empty
            istringstream strin(tmp);
            int j = 0;
            nNum ++;
            while(strin >> tmp){
                str[nNum][++ j] = tmp;
                if(tmp.size() > len[j]) len[j]= tmp.size();
            }
            num[nNum] = j;
        }
        cout << setiosflags(ios :: left);
        for(int i = 1; i <= nNum; i ++){
            for(int j = 1; j < num[i]; j ++){
                cout << setw(len[j] + 1) << str[i][j];
            }
            cout << str[i][num[i]] << endl;
        }
    }
	return 0;
}
