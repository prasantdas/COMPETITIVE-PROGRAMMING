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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll u=0,d=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            u++;
        }
        else{
            d++;
        }
        if(u<d){
            cout<<0<<endl;
            return 0;
        }
    }
    ll up=u+d;
    ll down=u-d;
    if(u>n/2){
        cout<<0<<endl;
        return 0;
    }
    if(up==n){
        cout<<1<<endl;
        return 0;
    }
    ll f1=n,f2=0;
    ll Sumxy=f1-up;
    ll Diffxy=f2-down;
    ll xonly=(Sumxy+Diffxy)/2;
    ll up1=up,down1=-2-down;
    ll Sumxy1=f1-up1;
    ll Diffxy1=f2-down1;
    ll xonly1=(Sumxy1+Diffxy1)/2;
    cout<<(ncr(Sumxy,xonly)-ncr(Sumxy1,xonly1)+mod)%mod<<endl;
    return 0;
}