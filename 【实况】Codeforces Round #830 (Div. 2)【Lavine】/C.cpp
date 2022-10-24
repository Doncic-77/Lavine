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
        int n , q ;
        cin >> n >> q ;
        vector<int> a(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
        vector<long long> pre(n + 1 , 0ll) ;
        for(int i = 1 ; i <= n ; i ++)  pre[i] = pre[i - 1] + a[i] ;
        vector<int> pre2(n + 1 , 0) ;
        for(int i = 1 ; i <= n ; i ++)  pre2[i] = (pre2[i - 1] ^ a[i]) ; 
        vector<int> lst(n + 1 , 0) ;
        vector<int> nxt(n + 1 , 0) ;
        int t = 0 ;
        for(int i = 1 ; i <= n ; i ++)
        {
            lst[i] = t ;
            if(a[i] != 0)  t = i ;
        }
        t = 0 ;
        for(int i = n ; i >= 1 ; i --)
        {
            nxt[i] = t ;
            if(a[i] != 0)  t = i ;
        }
        auto cal = [&](int l , int r)
        {
            if(l >= r)  return 0ll ;
            return (pre[r] - pre[l - 1]) - (pre2[r] ^ pre2[l - 1]) ;
        } ;
        while(q --)
        {
            int L , R ;
            cin >> L >> R ;
            int l = L , r = R ;
            long long mx = cal(l , r) ;
            if(mx == 0)
            {
                cout << L << ' ' << L << '\n' ;
                continue ;
            }
            int now = 0 ;
            vector<int> v1 ;
            int p = L ;
            v1.push_back(p) ;
            for(int _ = 1 ; _ <= 31 ; _ ++)
            {
                p = nxt[p] ;
                if(p == 0)  break ;
                v1.push_back(p) ;
            }
            vector<int> v2 ;
            p = R ;
            v2.push_back(p) ;
            for(int _ = 1 ; _ <= 31 ; _ ++)
            {
                p = lst[p] ;
                if(p == 0)  break ;
                v2.push_back(p) ;
            }
            reverse(v2.begin() , v2.end()) ;
            for(auto l2 : v1)
                for(auto r2 : v2)
                    if(l2 <= r2)
                    {
                        long long tt = cal(l2 , r2) ;
                        if(tt == mx)
                        {
                            if(r2 - l2 < r - l)
                            {
                                l = l2 ;
                                r = r2 ;
                            }
                        }
                    }
            cout << l << ' ' << r << '\n' ;
        }
    }

    return 0 ;
}