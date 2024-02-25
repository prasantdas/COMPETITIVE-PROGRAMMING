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
     
    bool isleaf(int src,unordered_map<int,vector<int>>& g){
        if()
    } 
    
    void dfs(int src,int par,string& s,unordered_map<int,vector<int>>& g,vector<vector<int>>& dp){
        
        //Base case
        if(isleaf(src,g)){
            // Evaluate for leaf node and return
            
        }
        
        // Dfs Traversal for each node
        for(auto x:g[src]){
            if(x==par) continue;
            dfs(x,src,s,g,dp);
        }
        
        // Evaluate for each current node what will the ans from all its children node
       for(auto x:g[src]){
           if(x==par)continue;
           //Ans from the child
       }
    }
     
    void solve() {
        //Write Here
        int n;
        cin>>n;
        unordered_map<int,vector<int>> g;
        for(int i=2;i<=n;i++){
            int u=i;
            int v;
            cin>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        dfs(1,-1,s,g,dp);
        
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
