    #include <bits/stdc++.h>
    using namespace std;
    unordered_map<int,vector<int>> g;
    vector<int> tin,tout,parent,depth;
    int currtime=0;
    void dfs(int src,int par,int dist){
        tin[src]=currtime++;
        parent[src]=par;
        depth[src]=dist;
        for(auto x:g[src]){
            if(x!=par){
                dfs(x,src,dist+1);
            }
        }
        tout[src]=currtime++;
    }
    bool isancess(int node,int par){
        if(tin[par]<tin[node] && tout[node]<tout[par])return true;
        else if(tin[parent[par]]<tin[node] && tout[node]<tout[parent[par]])return true;
        else return false;
    }
    int main()
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        tin.resize(n+1,0);tout.resize(n+1,0);parent.resize(n+1,0);depth.resize(n+1,0);
        dfs(1,-1,0);
        for(int i=0;i<m;i++){
            int k;
            cin>>k;
            vector<int> q(k);
            int Mx=-1,node=1;;
            for(int i=0;i<k;i++){
                cin>>q[i];
                if(Mx<depth[q[i]]){
                    Mx=depth[q[i]];
                    node=q[i];
                }
            }
            bool flag=true;
            for(int i=0;i<k;i++){
                if(q[i]!=node){
                    if(!isancess(node,q[i])){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<depth[i]<<" "<<parent[i]<<" "<<tin[i]<<" "<<tout[i]<<" "<<endl;
        // }
        return 0;
    }