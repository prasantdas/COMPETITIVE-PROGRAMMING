#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll power(ll a,ll b){
    if(b==0)return 1;
    ll res=power(a,b/2);
    if(b%2==1){
        return (res%mod*res%mod*a%mod)%mod;
    }
    else return (res%mod*res%mod)%mod;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        ll ans=power(a,b);
        cout<<ans<<endl;
    }
    return 0;
}