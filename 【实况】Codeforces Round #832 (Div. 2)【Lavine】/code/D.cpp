//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const int inf = 1e9 ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , q ;
    cin >> n >> q ;
    vector<int> a(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cin >> a[i] ;
    vector<int> pre = a ;
    for(int i = 1 ; i <= n ; i ++)  pre[i] ^= pre[i - 1] ;
    vector<int> cnt(n + 1 , 0) ;
    for(int i = 1 ; i <= n ; i ++)  cnt[i] = cnt[i - 1] + (a[i] == 0) ;
    vector<int> mn(n + 1 , inf) ;
    map<int , int> odd , even ;
    int now = 0 ;
    if(n & 1)  even[0] = n + 1 ;
    else  odd[0] = n + 1 ;
    for(int i = n ; i >= 1 ; i --)
    {
        now ^= a[i] ;
        if(i & 1)
        {
            if(even.count(now))  mn[i] = even[now] ;
            odd[now] = i ;
        }
        else
        {
            if(odd.count(now))  mn[i] = odd[now] ;
            even[now] = i ;
        }
    }
    while(q --)
    {
        int l , r ;
        cin >> l >> r ;
        if(pre[r] != pre[l - 1])  cout << "-1\n" ;
        else
        {
            if(cnt[r] - cnt[l - 1] == r - l + 1)  cout << "0\n" ;
            else
            {
                if((r - l + 1) & 1)  cout << "1\n" ;
                else if(a[l] == 0 || a[r] == 0)  cout << "1\n" ;
                else if(mn[l] - 1 <= r - 1)  cout << "2\n" ;
                else  cout << "-1\n" ;
            }
        }
    }

    return 0 ;
}