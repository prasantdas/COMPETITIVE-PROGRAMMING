#include<bits/stdc++.h>
using namespace std;

/*
 * Author    : Prasant Das
 * Date      : 15:06:2023
 */

#define mod 1000000007
#define INF 1e18
#define inf 1e9
#define NINF -1e18
#define ninf -1e9
#define vi vector<int>
#define vll vector<long long>
#define vl vector<long>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef priority_queue<int> maxheap;
typedef priority_queue<int, vector<int>, greater<int>> minheap;
#define for0(i,n)  for(ll i=0; i<n; i++)
#define for1(i,n)  for(ll i=1; i<=n; i++) 
int d1[4] = { -1, 1, 0, 0};
int d2[4] = {0, 0, -1, 1};
int D1[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int D2[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
vector<vector<ll>> MultiplyMatrices(vector<vector<ll>>& a,vector<vector<ll>>& b){
    ll size=a.size();
    vector<vector<ll>> ans(size,vector<ll>(size,0));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}
vector<vector<ll>> MatrixExponentiation(vector<vector<ll>>& a,ll n){
    if(n==0){
        ll size=a.size();
        vector<vector<ll>> ans(size,vector<ll>(size,0));
        for(int i=0;i<size;i++){
            ans[i][i]=1;
        }
        return ans;
    }
    if(n==1){
        return a;
    }
    vector<vector<ll>> ans=MatrixExponentiation(a,n/2);
    vector<vector<ll>> res=MultiplyMatrices(ans,ans);
    if(n&1){
        return MultiplyMatrices(res,a);
    }
    else{
        return res;
    }
}

void solve() {
    //Write Here
    ll n;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
    }
    else if(n==1){
        cout<<1<<endl;
    }
    else{
        vector<vector<ll>> a={{1,1},{1,0}};
        vector<vector<ll>> c={{1},{1}};
        vector<vector<ll>> ans=MatrixExponentiation(a,n-2);
        ll res=0;
        for(int i=0;i<a.size();i++){
            res=(res+(ans[0][i]*c[i][0])%mod)%mod;
        }
        cout<<res<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}
