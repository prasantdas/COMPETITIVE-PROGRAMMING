#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact[2000000];
ll mod=1000000007;
void BuildFact(){
    fact[0]=1;
    ll product=1;
    for(ll i=1;i<=2000000;i++){
        product=(product%mod*i)%mod;
        fact[i]=product%mod;
    }
}
ll power(ll a,ll b){
    if(b==0)return 1;
    ll res=power(a,b/2);
    if(b&1){
        return ((res*res)%mod*a)%mod;
    }
    else{
        return (res*res)%mod;
    }
}
ll ncr(ll a,ll b){
    ll n1=fact[a];
    ll n2=(fact[b]*fact[a-b])%mod;
    ll inv=power(n2,mod-2);
    return (n1*inv)%mod;
}
int main()
{
    memset(fact,0,sizeof(fact));
    BuildFact();
    ll n,m;
    cin>>n>>m;
    cout<<ncr(n+m-1,n-1)<<endl;
    return 0;
}