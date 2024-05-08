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

int breaks;

int dfs(int src,int par,int count,unordered_map<int,vector<int>>& g){
    int size=1;
    for(auto x:g[src]){
        if(x==par)continue;
        size=size+dfs(x,src,count,g);
    }
    if(size>=count){
        breaks++;
        size=0;
    }
    return size;
}

void solve() {
    //Write Here
    int n,k;
    cin>>n>>k;
    unordered_map<int,vector<int>> g;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start=1,end=n;
    int ans=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        breaks=0;
        dfs(1,-1,mid,g);
        if(breaks>k){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}
