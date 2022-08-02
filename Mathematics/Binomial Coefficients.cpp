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
const           ll MOD = 1000000007;
const           ld eps=1e-7;
const           double PI=acos(-1);
const           ll N=2e6+5;
const           ll INF=1e18;
            /*****************Grid Move***************/

ll dx[] = { 1 , 1, -1 , -1 };
ll dy[] = {1 , -1 , -1 , 1 };

ll ddx[]={1,-1,0,0,1,1,-1,-1};
ll ddy[]={0,0,1,-1,1,-1,-1,1};

ll kx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
ll ky[] = { -1, -2, -2, -1, 1, 2, 2, 1 };


            /***************** Useful *********************/
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
vl fact(N,1);
void work(){
    rep(i,2,N){
        fact[i]=(fact[i-1]*i)%MOD;
    }
}
void solve(){
    ll a,b;cin>>a>>b;
    ll k=fact[a];
    ll kk=binexp(fact[b],MOD-2,MOD);
    ll kkk=binexp(fact[a-b],MOD-2,MOD);
    ll ans=(((k*kk)%MOD)*kkk)%MOD;
    cout<<ans<<endl;
}
int main(){
        KIRA;
        //READ;
        //WRITE;
        ll _=1;
        cin >>_;
        work();
        //cout<<fixed;
        //cout<<setprecision(6);
        while(_--)solve();
}

/** NEVERMIND MY CODE **/
