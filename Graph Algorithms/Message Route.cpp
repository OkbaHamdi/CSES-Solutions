/************ Author :OKBA HAMDI**************/

#include<bits/stdc++.h>
using namespace std;

    /***************Typedef *************/

typedef         long long ll;
typedef         long double ld;
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pl;

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

    /********** Constantes **************/

//const             ll MOD = LLONG_MAX;
//const           ll MOD = 998244353;
const           ll MOD=1000000007;
const           ll TWO_INV_MOD=500000004;
const           ld eps=1e-7;
const           double PI=acos(-1);
const           ll N=2e5+5;
const           ll INF=1e18;
            /*****************Grid Move***************/

ll dx[] = {1,1,-1,-1};
ll dy[] = {1,-1,-1,1};

ll ddx[]={1,-1,0,0,1,1,-1,-1};
ll ddy[]={0,0,1,-1,1,-1,-1,1};

ll kx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
ll ky[] = { -1, -2, -2, -1, 1, 2, 2, 1 };


            /***************** Useful *********************/
/**KMP**/
void computeLPSArray(string pat, int M,int lps[]){
    int len = 0,i=1;
    lps[0] = 0;
    while (i < M){
            if (pat[i] == pat[len]){len++;lps[i] = len;i++;}
            else {if (len != 0){len = lps[len - 1];}
            else {lps[i] = len;i++;}}}}

int KMP(string pat, string txt){
    int M = pat.length(),N = txt.length(),lps[M],j=0,i=0,res=0;
    computeLPSArray(pat, M, lps);
    while (i < N){
            if (pat[j] == txt[i]){j++;i++;}
            if (j == M){j = lps[j - 1];res++;}
            else if (i < N && pat[j] != txt[i]){
                    if (j != 0)j = lps[j - 1];
                    else i = i + 1;}
                    }
            return res;}
/**Seive**/
bool prime[N+1] ;
void seive(){
    rep(i,2,N+1)prime[i]=1;
    for (ll p=2; p*p<=N;p++){
        if (prime[p]==1){
            for (ll i = p * p; i <= N; i += p)
                prime[i]=0;
        }
    }
}
/**Power**/
ll binexp(ll a, ll k,ll mod){
    ll ans = 1;
    while (k){
        if (k & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ans;
}
/**Least Common Multiple**/
inline ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
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
        if(a)res+=binexp(2,p,MOD);
        //DONT'T FORGET THE MOD
    }
    return res;
}
/******************Code******************/
vl g[N];
vl vis(N,0),parent(N,0);
void bfs(ll node){
    queue<ll>q;
    q.push(node);
    vis[node]=1;
    while(q.size()){
        ll top=q.front();
        q.pop();
        for(auto x:g[top]){
            if(!vis[x]){
                vis[x]=1;
                parent[x]=top;
                q.push(x);
            }
        }
    }
}
void solve(){
    ll n,m;cin>>n>>m;
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        g[a].pb(b);g[b].pb(a);
    }
    for(ll i=1;i<=n;i++)parent[i]=i;
    bfs(1);
    if(parent[n]==n){cout<<"IMPOSSIBLE"<<endl;return;}
    dq ans;ans.pb(n);
    ll cur=n;
    while(parent[cur]!=cur){
        ans.pf(parent[cur]);
        cur=parent[cur];
    }
    cout<<ans.size()<<endl;
    aff(ans);
}
int main(){
        KIRA;
        //READ;
        //WRITE;
        ll _=1;
        //cin >>_;
        //cout<<fixed;
        //cout<<setprecision(6);
        while(_--)solve();
}

/** NEVERMIND MY CODE **/
