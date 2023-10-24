#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//  A=i+b/2-1 
//  i=A-b/2+1
ll countexceptendpoints(ll x1,ll y1,ll x2,ll y2){
    ll a=abs(y2-y1);
    ll b=abs(x2-x1);
    return __gcd(a,b)-1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<ll,ll>> vert(n);
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        vert[i]={x,y};
    }
    
    ll area=0;
    ll b=0;
    for(int i=0;i<n;i++){
        ll x1=vert[i].first,y1=vert[i].second;
        ll x2=vert[(i+1)%n].first,y2=vert[(i+1)%n].second;
        area=area+(x1*y2-x2*y1);
        b=b+countexceptendpoints(x1,y1,x2,y2);
    }
    b=b+n;
    area=abs(area);
    ll A=area/2;
    ll i=A-b/2+1;
    cout<<i<<" "<<b<<endl;
    return 0;
}