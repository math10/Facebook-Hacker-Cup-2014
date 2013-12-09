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

struct info{
    string name;
    int s_per,height,play,id;
}arr[33];
bool cmp_ph(info a,info b){
    return ((a.s_per>b.s_per) ||(a.s_per==b.s_per && a.height > b.height));
}

bool cmp_time(int i,int j){
    info a = arr[i],b = arr[j];
    return ((a.play < b.play) || (a.play == b.play && a.id < b.id));
}

vector<int >t1,t2,r1,r2;
vector<string >V;

int main()
{
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t){
        int n = II,m = II,p = II;
        rep(i,n){
            cin >> arr[i].name >> arr[i].s_per >> arr[i].height ;
            arr[i].play = 0;
        }
        sort(arr,arr+n,cmp_ph);
        int cnt1 = 0,cnt2 = 0;
        rep(i,n) {
            arr[i].id = i;
            if(i%2==0){
                if(t1.size() < p ) t1.pb(i);
                else r1.pb(i);
            }
            else{
                if(t2.size() < p) t2.pb(i);
                else r2.pb(i);
            }
        }
        if(r1.size()){
            For(i,m){
                forstl(it,t1) arr[*it].play++;
                sort(all(t1),cmp_time);
                sort(all(r1),cmp_time);
                int tmp = t1[p-1];
                t1.pop_back();
                t1.pb(r1[0]);
                r1.erase(r1.begin());
                r1.pb(tmp);
            }
        }
        forstl(it,t1) V.pb(arr[*it].name);
        if(r2.size()){
            For(i,m){
                forstl(it,t2) arr[*it].play++;
                sort(all(t2),cmp_time);
                sort(all(r2),cmp_time);
                int tmp = t2[p-1];
                t2.pop_back();
                t2.pb(r2[0]);
                r2.erase(r2.begin());
                r2.pb(tmp);
            }
        }
        forstl(it,t2) V.pb(arr[*it].name);
        sort(all(V));
        OC;
        forstl(it,V) cout << " " << *it;
        NL;
        t1.clear(),t2.clear(),r1.clear(),r2.clear(),V.clear();
    }
}
