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
        vector<int> a(n , 0) ;
        for(int i = 0 ; i < n ; i ++)  cin >> a[i] ;
        a[0] -= 1 ;
        int x = a[0] ;
        sort(a.begin() , a.end()) ;
        if(a[0] == x)
        {
            if(a[1] > x)  cout << "Bob\n" ;
            else  cout << "Alice\n" ;
        }
        else
        {
            cout << "Alice\n" ;
        }
    }

    return 0 ;
}