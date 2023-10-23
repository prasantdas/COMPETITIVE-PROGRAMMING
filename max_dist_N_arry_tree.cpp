#include <bits/stdc++.h>
using namespace std;
 
unordered_map<int,vector<int>> g;
vector<int> maxin,maxout;
int indfs(int src,int par){
    int dist=0;
    for(auto x:g[src]){
        if(x!=par)dist=max(dist,indfs(x,src));
    }
    maxin[src]=dist;
    return 1+dist;
}
void outdfs(int src,int par){
    multiset<int> ms;
    for(auto x:g[src]){
        if(x!=par){
            ms.insert(maxin[x]);
        }
    }
    for(auto x:g[src]){
        if(x!=par){
            int curr=maxin[x];
            ms.erase(ms.find(curr));
            int below=(ms.empty())?0:*(--ms.end())+2;
            maxout[x]=max(1+maxout[src],below);
            ms.insert(curr);
            outdfs(x,src);
        }
    }
}
int main()
{
   g.clear();
   int n;
   cin>>n;
   maxin.resize(n+1,0);
   maxout.resize(n+1,0);
   for(int i=0;i<n-1;i++){
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
    indfs(1,-1);
    outdfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<<max(maxin[i],maxout[i])<<" ";
    }
    // for(int i=1;i<=n;i++){
    //     cout<<maxin[i]<<" ";
    // }
   return 0;
}