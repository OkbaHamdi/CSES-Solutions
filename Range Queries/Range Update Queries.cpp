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
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define         all(v) v.begin(), v.end()
#define         rall(v) v.rbegin(), v.rend()
#define         rep(i,a,b) for(ll i=a;i<b;i++)
//const           ll MOD = 998244353;
const           ll MOD=1000000007;
const           ld eps=1e-7;
const           double PI=acos(-1);
const           ll N=2e5+5;
const           ll INF=1e18;
ll n,p=1,q;
vl tree,v,diff;
void make(){
    while(p<2*n)p*=2;
    tree.resize(2*p,0);
}
void update(ll ind,ll val){
    ind+=p;
    tree[ind]+=val;
    ind/=2;
    while(ind){
        tree[ind]=tree[ind*2]+tree[ind*2+1];
        ind/=2;
    }
}
ll query(ll l,ll r){
    l+=p;
    r+=p;
    ll ans=0;
    while(l<=r){
        if(l%2)ans+=tree[l++];
        if(r%2==0)ans+=tree[r--];
        r/=2;
        l/=2;
    }
    return ans;
}
void solve(){
    cin>>n>>q;
    v.resize(n);
    rep(i,0,n)cin>>v[i];
    make();
    while(q--){
        ll test;cin>>test;
        if(test==2){
            ll a;cin>>a;
            cout<<query(0,a-1)+v[a-1]<<endl;
        }
        else{
            ll a,b,val;cin>>a>>b>>val;
            update(a-1,val);
            update(b,-val);
        }
    }
}
int main(){
        ios_base::sync_with_stdio(false);cin.tie(0);
        ll _=1;
        //cin >>_;
        while(_--)solve();
}
