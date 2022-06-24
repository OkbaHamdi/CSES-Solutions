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

const             ll MOD = LLONG_MAX;
//const           ll MOD = 998244353;
//const           ll MOD = 1000000007;
const           ll eps=1e-9;
const           double PI=acos(-1);
const           ll N=2e5+2;
const           ll INF=1e18;
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
// map implementation
void solve(){
    ll n,k;
    cin>>n>>k;
    vl v(n);
    rep(i,0,n)cin>>v[i];
    vl vv=v;
    sort(all(vv));
    if(n>=3&&vv[n-1]+vv[n-2]+vv[n-3]<k){cout<<"IMPOSSIBLE"<<endl;return;}
    rep(i,0,n-1){
        map<ll,ll>mp;
        rep(j,i+1,n){
            ll a=k-v[i]-v[j];
            if(mp[a]){cout<<i+1<<" "<<min(mp[a],j)+1<<" "<<max(mp[a],j)+1<<endl;return;}
            mp[v[j]]=j;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
// binary search implementation
/*
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<pl>v(n);
    rep(i,1,n+1){
        ll a;
        cin>>a;
        v[i-1]={a,i};
    }
    sort(all(v));
    for(ll i=0;i<n-2;i++){
        for(ll j=i+1;j<n-1;j++){
            ll left=j+1,right=n-1;
        while(left<=right){
        ll mid=(left+right+1)/2;
        if(v[mid].F+v[i].F+v[j].F==k){
            cout<<v[i].S<<" "<<v[j].S<<" "<<v[mid].S<<endl;
            return;
        }
        if(v[mid].F+v[i].F+v[j].F>k)right=mid-1;
        else left=mid+1;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;

}
*/

int main(){
        //KIRA;
        //READ;
        //WRITE;
        ll _=1;
        //cin >>_;
        //cout<< setprecision(5);
        while(_--)solve();
}

/** NEVERMIND MY CODE **/
