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
    map<long long , set<long long>> del ;
    map<long long , vector<long long>> v ;
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
            for(auto u : v[x])  del[u].erase(x) ;
        }
        else if(op[0] == '-')
        {
            long long x ;
            cin >> x ;
            s.erase(x) ;
            for(auto u : v[x])  del[u].insert(x) ;
        }
        else
        {
            long long x ;
            cin >> x ;
            if(!mp.count(x))  mp[x] = x ;
            if(del[x].empty())
            {
                long long now = mp[x] ;
                while(s.count(now))  v[now].push_back(x) , now += x ;
                mp[x] = now ;
                cout << mp[x] << '\n' ;
            }
            else
            {
                if(mp[x] <= (*del[x].begin()))
                {
                    cout << mp[x] << '\n' ;
                }
                else
                {
                    cout << (*del[x].begin()) << '\n' ;
                }
            }
        }
    }

    return 0 ;
}