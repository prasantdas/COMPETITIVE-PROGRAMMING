#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
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
    ll doublearea=0;
    for(int i=0;i<n;i++){
        ll x1=vert[i].first,y1=vert[i].second;
        ll x2=vert[(i+1)%n].first,y2=vert[(i+1)%n].second;
        doublearea=doublearea+(x1*y2-x2*y1);
    }
    doublearea=abs(doublearea);
    cout<<doublearea<<endl;
    return 0;
}