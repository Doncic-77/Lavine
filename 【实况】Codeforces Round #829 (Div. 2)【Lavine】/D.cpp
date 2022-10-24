//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , x ;
    cin >> n >> x ;
    vector<int> a(n) ;
    for(int i = 0 ; i < n ; i ++)  cin >> a[i] ;
    sort(a.begin() , a.end()) ;
    int now = 0 ;
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i ++)
    {
        if(a[i] >= x)  
        {
            if(now != 0)
            {
                while(now < x)
                {
                    if(cnt % (now + 1) == 0)
                    {
                        cnt /= (now + 1) ;
                        now += 1 ;
                    }
                    else  break ;
                }
            }
            if(now < x)
            {
                cout << "No\n" ;
                return 0 ;
            }
            break ;
        }
        int j = i ;
        while(j + 1 < n && a[j + 1] == a[j])  j += 1 ;
        if(now != 0)
        {
            while(now < a[i])
            {
                if(cnt % (now + 1) == 0)
                {
                    cnt /= (now + 1) ;
                    now += 1 ;
                }
                else  break ;
            }
        }
        if(now != 0 && now != a[i])
        {
            cout << "No\n" ;
            return 0 ;
        }
        now = a[i] ;
        cnt += j - i + 1 ;
        i = j ;
    }
    if(now != 0)
    {
        while(now < x)
        {
            if(cnt % (now + 1) == 0)
            {
                cnt /= (now + 1) ;
                now += 1 ;
            }
            else  break ;
        }
        if(now < x)
        {
            cout << "No\n" ;
            return 0 ;
        }
    }
    cout << "Yes\n" ;


    return 0 ;
}