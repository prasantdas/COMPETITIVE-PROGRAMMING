#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        ll val=(x3-x2)*(y2-y1)-(x2-x1)*(y3-y2);
        if(val<0)cout<<"LEFT"<<endl;
        else if(val>0)cout<<"RIGHT"<<endl;
        else cout<<"TOUCH"<<endl;
    }
    return 0;
}