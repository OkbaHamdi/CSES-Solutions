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
const           ll N=1e5+2;
const           ll INF=1e18;

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

ll dx[] = { 1 , 1, -1 , -1 };
ll dy[] = {1 , -1 , -1 , 1 };

ll ddx[]={1,-1,0,0,1,1,-1,-1};
ll ddy[]={0,0,1,-1,1,-1,-1,1};

ll kx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
ll ky[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

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
ll dp[501][501];
void work(){
    for(ll i=1;i<=500;i++){
        for(ll j=1;j<=500;j++){
            if(i==j)continue;
            dp[i][j]=INF;
        }
    }
    for(ll i=1;i<=500;i++){
        for(ll j=1;j<=500;j++){
            if(i==1&&j==1)continue;
            if(i>1)for(ll k=i-1;k>=1;k--)dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            if(j>1)for(ll k=j-1;k>=1;k--)dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
        }
    }
}
void solve(){
    ll a,b;
    cin>>a>>b;
    cout<<dp[a][b]<<endl;
}
int main()
    {
        KIRA;
        //READ;
        //WRITE;
        ll _=1;
        //cin >>_;
        work();
        //cout<< setprecision(5);
        while(_--)solve();
    }

/** NEVERMIND MY CODE **/
