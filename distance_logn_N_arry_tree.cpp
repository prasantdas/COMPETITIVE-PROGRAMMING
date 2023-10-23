#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,vector<int>> g;
int uptable[200001][30];
int level[200001];
void calculate_level(int src,int par,int lev){
    level[src]=lev;
    for(auto x:g[src]){
        if(x!=par){
            calculate_level(x,src,lev+1);
        }
    }
}
void binary_lifting(int src,int par){
    uptable[src][0]=par;
    for(int i=1;i<30;i++){
        if(uptable[src][i-1]!=-1){
            uptable[src][i]=uptable[uptable[src][i-1]][i-1];
        }
        else uptable[src][i]=-1;
    }
    for(auto x:g[src]){
        if(x!=par){
            binary_lifting(x,src);
        }
    }
}
int lift_node(int node,int jump){
    for(int i=20;i>=0;i--){
        if(jump==0 || node==-1){
            break;
        }
        if(jump>=(1<<i)){
            jump=jump-(1<<i);
            node=uptable[node][i];
        }
    }
    return node;
}
int LCA(int u,int v){
    if(level[u]<level[v])swap(u,v);
    u=lift_node(u,level[u]-level[v]);
    if(u==v)return u;
    for(int i=20;i>=0;i--){
        if(uptable[u][i]!=uptable[v][i]){
            u=uptable[u][i];
            v=uptable[v][i];
        }
    }
    return lift_node(u,1);
}
int main()
{
   g.clear();
   int n,q;
   cin>>n>>q;
   for(int i=0;i<n-1;i++){
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   calculate_level(1,-1,0);
   binary_lifting(1,-1);
   while(q--){
       int u,v;
       cin>>u>>v;
       int lca=LCA(u,v);
       cout<<abs(level[lca]-level[u])+abs(level[lca]-level[v])<<endl;
   }
   return 0;
}