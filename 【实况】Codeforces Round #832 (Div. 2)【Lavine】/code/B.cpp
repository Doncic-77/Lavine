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
        cout << (n + 1) / 2 << '\n' ;
        if(n & 1)
        {
            int l = 2 , r = n ;
            while(l < r)
            {
                cout << (l - 1) * 3 + 2 << ' ' << (r - 1) * 3 + 3 << '\n' ;
                l += 1 ;
                r -= 1 ;
            }
            cout << 1 << ' ' << 3 * n << '\n' ;
        }
        else
        {
            int l = 1 , r = n ;
            while(l < r)
            {
                cout << (l - 1) * 3 + 2 << ' ' << (r - 1) * 3 + 3 << '\n' ;
                l += 1 ;
                r -= 1 ;
            }
        }
    }

    return 0 ;
}