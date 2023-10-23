#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,vector<int>> g;
int uptable[200001][30];
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
int main()
{
   g.clear();
   int n,q;
   cin>>n>>q;
   for(int i=2;i<=n;i++){
       int u;
       cin>>u;
       g[i].push_back(u);
       g[u].push_back(i);
   }
   binary_lifting(1,-1);
   while(q--){
       int node,jump;
       cin>>node>>jump;
       cout<<lift_node(node,jump)<<endl;
   }
   return 0;
}