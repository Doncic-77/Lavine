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
        long long sum1 = 0 , sum2 = 0 ;
        while(n --)
        {
            int x ;
            cin >> x ;
            if(x > 0)  sum1 += x ;
            else  sum2 += abs(x) ;
        }
        cout << abs(sum1 - sum2) << '\n' ;
    }

    return 0 ;
}