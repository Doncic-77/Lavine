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
        string s ;
        cin >> s ;
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i ++)
        {
            if(s[i] == 'Q')  cnt += 1 ;
            else
            {
                cnt -= 1 ;
                cnt = max(cnt , 0) ;
            }
        }
        if(cnt == 0)  cout << "Yes\n" ;
        else  cout << "No\n" ;
    }

    return 0 ;
}