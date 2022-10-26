/**Believe me, I can do it**/
#include<bits/stdc++.h>
using namespace std;
typedef         long long ll;
typedef         long double ld;
typedef         vector<ll>vl;
typedef         deque<ll>dq;
typedef         pair<ll,ll>pl;

#define         F first
#define         S second
#define         pb push_back
#define         ppb pop_back
#define         pf push_front
#define         ppf pop_front
#define         rep(i,a,b) for(ll i=a;i<b;i++)
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
//const             ll MOD = LLONG_MAX;
//const           ll MOD = 998244353;
const           ll MOD=1000000007;
const           ld eps=1e-7;
const           double PI=acos(-1);
const           ll N=2e5+5;
const           ll INF=1e18;
int dx[]={1,1,-1,-1};
int dy[]={1,-1,-1,1};
int ddx[]={1,-1,0,0,1,1,-1,-1};
int ddy[]={0,0,1,-1,1,-1,-1,1};
int kx[]={-2,-1,1,2,-2,-1,1,2};
int ky[]={-1,-2,-2,-1,1,2,2,1};
ll binexp(ll a, ll k,ll mod=MOD){
    ll ans = 1;
    while (k){
        if (k & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ans;
}
ll inv(ll n){
    return binexp(n,MOD-2);
}
ll s(ll l,ll r){
    return (((((l+r)%MOD)*((r-l+1)%MOD))%MOD)*inv(2)%MOD);
}
void solve(){
    ll n;cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll d=n/i;
        ll q=n/d;
        ans+=(d*s(i,q));
        i=q;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        //freopen("input.txt", "r",stdin);
        //freopen("output.txt", "w",stdout);
        ll _=1;
        //cin >>_;
        //cout<<fixed<<setprecision(6)<<endl;
        while(_--)solve();
}
