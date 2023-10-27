#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> g;
int sv,ev;
bool checkcycle(int src,int p,vector<int>& par,vector<int>& vis,vector<int>& dfsvis){
    vis[src]=1;
    dfsvis[src]=1;
    par[src]=p;
    for(auto x:g[src]){
        if(!vis[x]){
            if(checkcycle(x,src,par,vis,dfsvis)){
                return true;
            }
        }
        else if(dfsvis[x]){
            sv=x;
            ev=src;
            return true;
        }
    }
    dfsvis[src]=0;
    return false;
}
int main()
{
    g.clear();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    vector<int> vis(n+1,0);
    vector<int> par(n+1);
    vector<int> dfsvis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(checkcycle(i,-1,par,vis,dfsvis)){
                vector<int> temp;
                temp.push_back(sv);
                temp.push_back(ev);
                while(ev!=sv){
                    temp.push_back(par[ev]);
                    ev=par[ev];
                }
                cout<<temp.size()<<endl;
                for(int i=temp.size()-1;i>=0;i--){
                    cout<<temp[i]<<" ";
                }
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}