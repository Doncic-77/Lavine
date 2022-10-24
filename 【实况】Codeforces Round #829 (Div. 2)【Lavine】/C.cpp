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
        vector<int> a(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
        if((n - count(a.begin() + 1 , a.end() , 0)) & 1)
        {
            cout << "-1\n" ;
            continue ;
        }
        vector<pair<int , int>> p ;
        for(int i = 1 ; i <= n ; i ++)
        {
            if(a[i] == 0)
            {
                p.push_back({i , i}) ;
                continue ;
            }
            int k = i + 1 ;
            assert(k <= n) ;
            while(a[k] == 0 && k + 1 <= n)  k += 1 ;
            if(a[i] != a[k])
            {
                for(int t = i ; t <= k ; t ++)  p.push_back({t , t}) ;
                i = k ;
            }
            else
            {
                if(i + 1 == k)
                {
                    p.push_back({i , k}) ;
                }
                else
                {
                    p.push_back({i , k - 2}) ;
                    p.push_back({k - 1 , k}) ;
                }
                i = k ;
            }
        }
        cout << p.size() << '\n' ;
        for(auto u : p)  cout << u.first << ' ' << u.second << '\n' ;
    }

    return 0 ;
}