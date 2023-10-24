#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//  p1----p2
//  p3----p4
ll orient(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    ll val=(x3-x2)*(y2-y1)-(x2-x1)*(y3-y2);
    if(val<0)return 1;      //left
    else if(val>0)return 2; //right
    else return 0;          //touch
}
bool onseg(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    return (x3>=min(x1,x2) && x3<=max(x1,x2) && y3>=min(y1,y2) && y3<=max(y1,y2));
}
bool intersect(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4){
    ll o1=orient(x1,y1,x2,y2,x3,y3);
    ll o2=orient(x1,y1,x2,y2,x4,y4);
    ll o3=orient(x3,y3,x4,y4,x1,y1);
    ll o4=orient(x3,y3,x4,y4,x2,y2);
    if(o1!=o2 && o3!=o4)return true;
    else if(o1==0 && onseg(x1,y1,x2,y2,x3,y3))return true;
    else if(o2==0 && onseg(x1,y1,x2,y2,x4,y4))return true;
    else if(o3==0 && onseg(x3,y3,x4,y4,x1,y1))return true;
    else if(o4==0 && onseg(x3,y3,x4,y4,x2,y2))return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> vert(n);
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        vert[i]={x,y};
    }
    for(int i=0;i<m;i++){
        ll x3,y3;
        cin>>x3>>y3;
        bool onbound=false;
        ll count_inter=0;
        for(int i=0;i<n;i++){
            ll x1=vert[i].first,y1=vert[i].second;
            ll x2=vert[(i+1)%n].first,y2=vert[(i+1)%n].second;
            if(orient(x1,y1,x2,y2,x3,y3)==0 && onseg(x1,y1,x2,y2,x3,y3)){
                onbound=true;
                break;
            }
            if(intersect(x1,y1,x2,y2,x3,y3,1e9-1,1e9+1)){
                count_inter++;
            }
        }
        if(onbound){
            cout<<"BOUNDARY"<<endl;
        }
        else if(count_inter&1)cout<<"INSIDE"<<endl;
        else cout<<"OUTSIDE"<<endl;
    }
    return 0;
}