#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    vector<ll> prefix(n+1,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prefix[i+1]=prefix[i]^arr[i];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(prefix[b]^prefix[a-1])<<endl;
    }
    cout<<endl;
    return 0;
}