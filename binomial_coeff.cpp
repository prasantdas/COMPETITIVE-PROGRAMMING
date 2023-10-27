#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact[1000000];
ll mod=1000000007;
void BuildFact(){
    fact[0]=1;
    ll product=1;
    for(ll i=1;i<=1000000;i++){
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
ll ncr(int a,int b,int c){
    ll n1=fact[a];
    ll n2=fact[b];
    ll n3=fact[c];
    ll n4=(n2*n3)%mod;
    ll n5=power(n4,mod-2);
    return (n1*n5)%mod;
}
int main()
{
    memset(fact,0,sizeof(fact));
    BuildFact();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        int c=a-b;
        cout<<ncr(a,b,c)<<endl;
    }
    return 0;
}