//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    set<long long> s ;
    map<long long , long long> mp ;
    int q ;
    cin >> q ;
    while(q --)
    {
        string op ;
        cin >> op ;
        if(op[0] == '+')
        {
            long long x ;
            cin >> x ;
            s.insert(x) ;
        }
        else
        {
            long long x ;
            cin >> x ;
            if(!mp.count(x))  mp[x] = x ;
            long long now = mp[x] ;
            while(s.count(now))  now += x ;
            mp[x] = now ;
            cout << mp[x] << '\n' ;
        }
    }

    return 0 ;
}