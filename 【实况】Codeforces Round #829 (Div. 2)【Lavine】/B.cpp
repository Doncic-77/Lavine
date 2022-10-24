//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int T ;
    cin >> T ;
    while(T --)
    {
        int n ;
        cin >> n ;
        int d = n / 2 ;
        vector<int> vis(n + 1 , 0) ;
        for(int i = n ; i >= 1 ; i --)
        {
            if(vis[i] == 1)  continue ;
            if(i - d >= 1 && vis[i - d] == 0)
            {
                vis[i - d] = 1 ;
                vis[i] = 1 ;
                cout << i - d << ' ' << i << ' ' ;
            }
        }
        for(int i = 1 ; i <= n ; i ++)
            if(vis[i] == 0)  cout << i << ' ' ;
        cout << '\n' ;
    }

    return 0 ;
}