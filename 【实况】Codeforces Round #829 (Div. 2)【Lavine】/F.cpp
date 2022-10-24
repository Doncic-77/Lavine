//记得看榜
//atcoder多个题一起写一起交 潜意识。。。
//codeforces ICPC不会做就换题
#include<bits/stdc++.h>
using namespace std ;
const long long inf = 1e18 ;
using ttt = tuple<long long , int , int> ;
int main()
{
    std::ios::sync_with_stdio(false) , cin.tie(0) ;

    int n , m ;
    cin >> n >> m ;
    int p , q ;
    cin >> p >> q ;
    vector<string> mp(n) ;
    for(int i = 0 ; i < n ; i ++)  cin >> mp[i] ;
    priority_queue<ttt , vector<ttt> , greater<ttt>> q2 ;
    vector<vector<long long>> dis(n , vector<long long>(m , inf)) ; 
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            if(mp[i][j] == '.')
            {
                dis[i][j] = 0 ;
                q2.push({0ll , i , j}) ;
            }
    vector<array<int , 2>> d = {{0 , -1} , {0 , 1} , {-1 , 0} , {1 , 0}} ;
    vector<vector<array<int , 2>>> nxt(n , vector<array<int , 2>>(m , {-1 , -1})) ;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
        {
            if(mp[i][j] == 'L')
            {
                nxt[i][j] = {i , j + 1} ;
                nxt[i][j + 1] = {i , j} ;
            }
            else if(mp[i][j] == 'U')
            {
                nxt[i][j] = {i + 1 , j} ;
                nxt[i + 1][j] = {i , j} ;
            }
        }
    while(!q2.empty())
    {
        auto [w , x , y] = q2.top() ;
        q2.pop() ;
        if(w != dis[x][y])  continue ;
        for(auto [d1 , d2] : d)
        {
            int nx = x + d1 ;
            int ny = y + d2 ;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)  continue ;
            auto [nnx , nny] = nxt[nx][ny] ;
            if(nxt[nx][ny][0] == -1)  continue ;
            int val = p ;
            if(nxt[nx][ny][0] == x || nxt[nx][ny][1] == y)  val = q ;
            long long val2 = dis[x][y] + val ;
            if(val2 < dis[nnx][nny])
            {
                dis[nnx][nny] = val2 ;
                q2.push({val2 , nnx , nny}) ;
            }
        }
    }
    long long res = inf ;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
        {
            if(i + 1 < n)  res = min(res , dis[i][j] + dis[i + 1][j]) ;
            if(j + 1 < m)  res = min(res , dis[i][j] + dis[i][j + 1]) ;
        }
    if(res == inf)  cout << "-1\n" ;
    else  cout << res << '\n' ;

    return 0 ;
}