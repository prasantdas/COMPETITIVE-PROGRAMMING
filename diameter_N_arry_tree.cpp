#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> g;
int dfs(int src,int par,int &diameter){
    int fd=0,sd=0;
    for(auto x:g[src]){
        if(x!=par){
            int d=dfs(x,src,diameter);
            if(d>fd){
                sd=fd;
                fd=d;
            }
            else if(d>sd){
                sd=d;
            }
        }
    }
    diameter=max(diameter,fd+sd);
    return 1+fd;
}
int main()
{
   g.clear();
   int n;
   cin>>n;
   for(int i=0;i<n-1;i++){
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   int diameter=0;
   dfs(1,-1,diameter);
   cout<<diameter<<endl;
   return 0;
}