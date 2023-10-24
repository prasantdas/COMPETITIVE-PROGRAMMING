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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll o1=orient(x1,y1,x2,y2,x3,y3);
        ll o2=orient(x1,y1,x2,y2,x4,y4);
        ll o3=orient(x3,y3,x4,y4,x1,y1);
        ll o4=orient(x3,y3,x4,y4,x2,y2);
        if(o1!=o2 && o3!=o4)cout<<"YES"<<endl;
        else if(o1==0 && onseg(x1,y1,x2,y2,x3,y3))cout<<"YES"<<endl;
        else if(o2==0 && onseg(x1,y1,x2,y2,x4,y4))cout<<"YES"<<endl;
        else if(o3==0 && onseg(x3,y3,x4,y4,x1,y1))cout<<"YES"<<endl;
        else if(o4==0 && onseg(x3,y3,x4,y4,x2,y2))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}