#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;
 
ll nsum(ll n){
    ll a,b;
    if(n&1){
        a=n,b=(n+1)/2;
    }
    else{
        a=n/2,b=n+1;   
    }
    return ((a%mod)*(b%mod))%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll sum=0;
    for(ll i=1;i*i<=n;i++){
        ll cnt=n/i-i+1;
        sum=sum+(cnt%mod)*i;
        sum=sum%mod;
        sum=sum+nsum(n/i)-nsum(i);
        sum=sum+mod;
        sum=sum%mod;
    }
    sum=sum%mod;
    cout<<sum<<endl;
}