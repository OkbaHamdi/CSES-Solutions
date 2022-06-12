/************ Author :OKBA HAMDI**************/
 
#include<bits/stdc++.h>
using namespace std;
 
    /***************Typedef *************/
 
typedef         long long ll;
typedef         long double ld;
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pl;
typedef         priority_queue<ll>pq;
typedef         priority_queue<ll,vector<ll>,greater<ll>>pqg;
 
 
    /********** Constantes **************/
 
//const             ll MOD = LLONG_MAX;
//const           ll MOD = 998244353;
const           ll MOD = 1000000007;
const           ll eps=1e-9;
const           double PI=acos(-1);
const           ll N=3e5+2;
const           ll INF=1e10;
 
            /************  Define  ****************/
 
#define         F first
#define         S second
#define         pb push_back
#define         ppb pop_back
#define         pf push_front
#define         ppf pop_front
#define         rep(i,a,b) for(ll i=a;i<b;i++)
#define         KIRA ios_base::sync_with_stdio(false);cin.tie(0);
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
#define         READ freopen("input.txt", "r",stdin)
#define         WRITE freopen("output.txt", "w",stdout)
            /*****************Grid Move***************/
ll dx[] = { 0 , 1, 0 , -1 };
ll dy[] = {1 , 0 , -1 , 0 };
 
ll ddx[]={1,-1,0,0,1,1,-1,-1};
ll ddy[]={0,0,1,-1,1,-1,-1,1};
 
            /***************** Useful *********************/
/**Combination**/
ll C(ll n, ll r){
    ll p = 1, k = 1;
    if (n - r < r)r = n - r;
    if (r != 0) {
            while (r) {
                p *= n;k *= r;
                ll m = __gcd(p, k);
                p /= m;k /= m;n--;r--;
                }
            }
    else p = 1;
    return p;
    }
 
/**Permutation**/
ll A(ll n,ll k){
    ll P = 1;
    for (ll i = 0; i < k; i++)P *= (n-i) ;
    return P;
}
 
/**Power**/
ll binexp(ll a, ll k){
    ll ans = 1;
    while (k){
        if (k & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        k >>= 1;
        }
    return ans;
    }
/**Least Common Multiple**/
inline ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
 
/**Float with String**/
string yup(ll a,ll b){
    if(a%b==0)return to_string(a/b);
    string ch=to_string(a/b);
    ll c=a%b;
    ll g=__gcd(c,b);
    c/=g;b/=g;
    ch+="+"+to_string(c)+"/"+to_string(b);
    return ch;
}
 
/**Binary Conversion**/
string to_bin(ll n)
{
    string ch="";
    ll i = 0;
    while (n>0) {
        char a=n%2+'0';
        ch=a+ch;
        n = n / 2;
        i++;
    }
    return ch;
}
 
/**Decimal Conversion**/
ll to_dec(string ch){
    ll res=0;
    for (ll i=ch.size()-1;i>=0;i--){
        ll a=ch[i]-'0';
        ll p=ch.size()-i-1;
        if(a)res+=binexp(2,p);
        //DONT'T FORGET THE MOD
    }
    return res;
}
                /******************Code******************/
vector<string>grid(1001);
bool vis[1001][1001];
ll n,m;
bool isvalid(ll x,ll y){
    if(x>=n)return 0;
    if(y>=m)return 0;
    if(x<0)return 0;
    if(y<0)return 0;
    if(grid[x][y]=='#')return 0;
    return 1;
}
void dfs(ll x,ll y){
    if(vis[x][y])return;
    vis[x][y]=1;
    rep(i,0,4){
        if(isvalid(x+dx[i],y+dy[i])){
            dfs(x+dx[i],y+dy[i]);
        }
 
    }
}
void solve(){
    cin>>n>>m;
    rep(i,0,n)cin>>grid[i];
    ll ans=0;
    rep(i,0,n){
        rep(j,0,m){
            if(grid[i][j]=='.'&&!vis[i][j]){dfs(i,j);ans++;}
        }
    }
    cout<<ans<<endl;
}
 
int main()
    {
        KIRA;
        //READ;
        //WRITE;
        ll _=1;
        //cin >>_;
        //cout<< setprecision(5);
        while(_--)solve();
    }
 
/** NEVERMIND MY CODE **/
