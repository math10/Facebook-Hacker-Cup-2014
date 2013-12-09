/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case #%d: ",cs);
//}
//}
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (500000LL * 1000000000LL) + 7LL;
const int mx = 20000 + 7;
const db pi = PI;
int EQ(double d){
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int dp[502][502][6][2];
int vis[502][502][6][2];
string st[502];
int N,M;
int call(int x,int y,int prev,bool flag){
    int &ret = dp[x][y][prev][flag];
    if(vis[x][y][prev][flag]) return ret;
    vis[x][y][prev][flag] = true;
    ret = 1;
    if(prev == 0){
        if(y+1 < M && st[x][y+1] != '#') {
            ret = max(ret,call(x,y+1,0,flag)+1);
        }
        if(x+1 < N && st[x+1][y] != '#') ret = max(ret,call(x+1,y,1,flag)+1);
        int cnt = 0;
        while(x-1>=0 && st[x-1][y] != '#' && !flag){
            x--;
            cnt++;
            ret = max(ret,call(x,y,2,true)+cnt);
        }
    }
    else if(prev == 1){
        if(y+1 < M && st[x][y+1] != '#') ret = max(ret,call(x,y+1,0,flag)+1);
        if(x+1 < N && st[x+1][y] != '#') ret = max(ret,call(x+1,y,1,flag)+1);
        int cnt = 0;
        while(y-1>=0 && st[x][y-1] != '#' && !flag){
            y--;
            cnt++;
            ret = max(ret,call(x,y,3,true)+cnt);
        }
    }
    else if(prev == 2){
        if(y+1 < M && st[x][y+1] != '#') ret = max(ret,call(x,y+1,0,flag)+1);
        //if(x+1 < N && st[x+1][y] != '#') ret = max(ret,call(x+1,y,1,flag)+1);
    }
    else{
        //if(y+1 < M && st[x][y+1] != '#') ret = max(ret,call(x,y+1,0,flag)+1);
        if(x+1 < N && st[x+1][y] != '#') ret = max(ret,call(x+1,y,1,flag)+1);
    }

    return ret;
}



int main(){
#ifdef Sanim
    freopen ("aaaaaa.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t){
        memo(vis,false);
        N = II,M = II;
        rep(i,N) cin >> st[i];
        int ans = 1;
        if(1<M && st[0][1] != '#') ans = max(ans,call(0,1,0,0)+1);
        if(1<N && st[1][0] != '#') ans = max(ans,call(1,0,1,0)+1);
        OC;
        cout << ans << endl;
    }
}
