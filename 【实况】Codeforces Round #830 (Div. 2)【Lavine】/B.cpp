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
        string s ;
        cin >> s ;
        int res = 0 ;
        int flag = -1 ;
        for(int i = n - 1 ; i >= 0 ; i --)
        {
            int j = i ;
            while(j - 1 >= 0 && s[j - 1] == s[j])  j -= 1 ;
            if(flag == -1)
            {
                flag = s.back() - '0' ;
            }
            else if(flag == 0)
            {
                assert(s[i] == '1') ;
                flag = 3 ; //10
            }
            else if(flag == 1)
            {
                assert(s[i] == '0') ;
                flag = 2 ; //10
            }
            else if(flag == 2) //01
            {
                if(s[i] == '1')
                {
                    flag = 3 ;
                    res += 1 ;
                }
            }   
            else
            {
                if(s[i] == '0') //10
                {
                    flag = 2 ;
                    res += 1 ;
                }
            }
            i = j ;
        }
        if(flag == 3)  res += 1 ;
        cout << res << '\n' ;
    }

    return 0 ;
}