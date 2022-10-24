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
        int d = a[1] ;
        for(int i = 2 ; i <= n ; i ++)  d = __gcd(d , a[i]) ;
        if(d == 1)
        {
            cout << "0\n" ;
            continue ;
        }
        if(n == 1)
        {
            if(a[1] == 1)  cout << "0\n" ;
            else  cout << "1\n" ;
            continue ;
        }
        d = a[1] ;
        for(int i = 2 ; i <= n - 1 ; i ++)  d = __gcd(d , a[i]) ;
        d = __gcd(d , __gcd(a[n] , n)) ;
        if(d == 1)
        {
            cout << "1\n" ;
            continue ;
        }
        d = a[1] ;
        for(int i = 2 ; i <= n - 2 ; i ++)  d = __gcd(d , a[i]) ;
        d = __gcd(d , __gcd(n - 1 , a[n - 1])) ;
        d = __gcd(d , a[n]) ;
        if(d == 1)
        {
            cout << "2\n" ;
            continue ;
        }
        cout << "3\n" ;
    }

    return 0 ;
}