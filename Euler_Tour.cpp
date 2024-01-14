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
 
unordered_map<ll,vector<ll>> t;
vector<ll> ft;
vector<ll> val;
vector<ll> st;
vector<ll> et;
int timer;
 
void BuildSegTree(int ind,int low,int high,ll seg[]){
    if(low==high){
        seg[ind]=val[ft[low]];
        return;
    }
    int mid=low+(high-low)/2;
    BuildSegTree(2*ind+1,low,mid,seg);
    BuildSegTree(2*ind+2,mid+1,high,seg);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
 
ll Query(int ind,int l,int r,int low,int high,ll seg[]){
    // No Overlap  [L,R]=[2,4] and (low,high)=(0,1) Or (5,6)
    if(high<l || r<low){
        return 0;
    }
    // Complete Overlap [L,R]=[2,4] and (low,high)=(2,3)
    else if(l<=low && r>=high){
        return seg[ind];
    }
    // Partial Overlap [L,R]=[2,4] and (low,high)=(0,3) Or (low,high)=(3,6)
    else{
        int mid=low+(high-low)/2;
        return Query(2*ind+1,l,r,low,mid,seg)+Query(2*ind+2,l,r,mid+1,high,seg);
    }
}
 
void Update(int ind,int low,int high,int i,ll v,ll seg[]){
    if(low==high){
        seg[ind]=v;
        return;
    }
    // Left [l,r]=[2,4] and i=3
    int mid=low+(high-low)/2;
    if(i<=mid){
        Update(2*ind+1,low,mid,i,v,seg);
    }
    // Right [l,r]=[2,4] and i=4
    else{
        Update(2*ind+2,mid+1,high,i,v,seg);
    }
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
 
void dfs(int src,int par){
    ft.push_back(src);
    st[src]=timer++;
    for(auto x:t[src]){
        if(x!=par){
            dfs(x,src);
        }
    }
    ft.push_back(src);
    et[src]=timer++;
}
 
void solve() {
    //Write Here
    timer=0;
    t.clear();
    ft.clear();
    ll n,q;
    cin>>n>>q;
    st.resize(n+1);
    et.resize(n+1);
    val.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        t[u].pb(v);
        t[v].pb(u);
    }
    dfs(1,-1);
    ll N=2*n;
    ll seg[4*N];
    BuildSegTree(0,0,N-1,seg);
    while(q--){
        // 1--> Query
        // 2--> Update
        int type;
        cin>>type;
        if(type==2){
            int idx;
            cin>>idx;
            int l=st[idx],r=et[idx];
            cout<<Query(0,l,r,0,N-1,seg)/2<<endl;
        }
        else{
            ll i,v;
            cin>>i>>v;
            int idx1=st[i];
            int idx2=et[i];
            Update(0,0,N-1,idx1,v,seg);
            Update(0,0,N-1,idx2,v,seg);
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
