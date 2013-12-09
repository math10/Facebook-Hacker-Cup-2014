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
#define INF 1<<29
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define mx 100005
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case #%d:",cs);
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
int k,x,y,pi,pu,pd;
double ps,pr,pw,pl;
double dp[110][110][1002];
bool vis[110][110][1002];
double call(int win,int lose,int wh){
    if(win == k || lose == k) return (win==k);
    db &ret = dp[win][lose][wh];
    if(vis[win][lose][wh]) return ret;
    vis[win][lose][wh] = true;

    ret = ps*pw*(wh/1000.)*call(win+1,lose,min(1000,wh+pu));
    ret += ps*(1-pw)*(wh/1000.)*call(win+1,lose,wh);
    ret += (1-ps)*pl*(wh/1000.)*call(win,lose+1,max(0,wh-pd));
    ret += (1-ps)*(1-pl)*(wh/1000.)*call(win,lose+1,wh);
    ret += pr*pw*(1-(wh/1000.))*call(win+1,lose,min(1000,wh+pu));
    ret += pr*(1-pw)*(1-(wh/1000.))*call(win+1,lose,wh);
    ret += (1-pr)*pl*(1-(wh/1000.))*call(win,lose+1,max(0,wh-pd));
    ret += (1-pr)*(1-pl)*(1-(wh/1000.))*call(win,lose+1,wh);
    return ret;

}

int main()
{
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("out.txt", "w", stdout);
#endif
    cout << setprecision(6) << fixed;
    int t = II;
    For(cs,t){
        memo(vis,false);
        k = II;
        cin >> ps >> pr;
        scanf("%d.%d",&x,&y);
        pi = x*1000 + y;
        scanf("%d.%d",&x,&y);
        pu = x*1000 + y;
        cin >> pw;
        scanf("%d.%d",&x,&y);
        pd = x*1000 + y;
        cin >> pl;

        OC;
        cout << " " << call(0,0,pi) + EPS << endl;
    }
}
