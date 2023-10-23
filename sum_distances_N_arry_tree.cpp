#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,vector<int>> g;
vector<ll> count_child,dist;
 
ll dfs1(int src,int par){
    ll count=0;
    for(auto x:g[src]){
        if(x!=par){
            count=count+dfs1(x,src);
        }
    }
    count_child[src]=count;
    return 1+count;
}
 
ll dfs2(int src,int par){
    ll d=0;
    for(auto x:g[src]){
        if(x!=par){
            d=d+dfs2(x,src);
        }
    }
    return d+count_child[src];
}
void dfs3(int src,int par,int n){
    for(auto x:g[src]){
        if(x!=par){
            dist[x]=dist[src]-(count_child[x]+1)+(n-(count_child[x]+1));
            dfs3(x,src,n);
        }
    }
}
int main()
{
   g.clear();
   int n;
   cin>>n;
   count_child.resize(n+1,0);
   dist.resize(n+1,0);
   for(int i=0;i<n-1;i++){
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   dfs1(1,-1);
   ll sum=dfs2(1,-1);
   dist[1]=sum;
   dfs3(1,-1,n);
   for(int i=1;i<=n;i++){
       cout<<dist[i]<<" ";
   }
   cout<<endl;
   return 0;
}