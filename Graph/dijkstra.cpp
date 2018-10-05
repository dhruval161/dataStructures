#include<iostream>
#include<bits/stdc++.h>
// iteration and input/output stream
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define si(x) int x; scanf("%d", &x)
#define sll(x) LL x; scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pll(x) printf("%lld", x)
#define nl prinf("\n")
#define tr(cont,it) \
for(typeof(cont.begin()) it = cont.begin(); it!= cont.end() ; it++)

#define tc() int t; cin >> t ; while (t--)
//STL shortcuts
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define F first
#define S second
#define MP make_pair

// Error detection
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

using namespace std;

typedef long long int ll; // 64 bit integer
typedef unsigned long long int  ull; // 64 bit unsigned integer
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

inline void smax(int &x , int y) { x = max(x , y) ; }
inline void smin(int &x , int y) { x = min(x , y) ; }

vector< vector<pill> > gr;
int n;
void dijkstra(int s,vector< vector<pill> >& gr,vll &di)
{
    di.resize(n+1,1000000000);
    di[s] = 0;

    priority_queue<pii,vector<pii>,greater<pii> > pend;
    pend.push(MP(0,s));
    vi vis(n+1,0);

    while(!pend.empty())
    {

        pii cur = pend.top();
        pend.pop();

        int x = cur.S;
        if(vis[x]) continue;
        vis[x] = 1;
        rep(i,0,gr[x].size())
        {
            int ad = gr[x][i].F;
            int e = gr[x][i].S;
            if(di[ad] > di[x] + e)
            {
                di[ad] = di[x]+e;
                pend.push(MP(di[ad],ad));
            }

        }

    }
}

int main()
{
    int m;
    cin>>n>>m;
    cout<<n<<m<<endl;
    gr.resize(n+1,vector<pill>(0));

    rep(i,0,m)
    {
        int x,y;
        ll w;
        cin>>x>>y>>w;
        gr[x].pb(MP(y,w));
        gr[y].pb(MP(x,w));
    }

    vll di;
    dijkstra(1,gr,di);
    rep(i,1,n+1)
    cout<<di[i]<<" ";

}

