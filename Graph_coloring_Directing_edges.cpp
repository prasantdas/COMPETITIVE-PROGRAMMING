    #include <bits/stdc++.h>
    using namespace std;
    unordered_map<int,vector<int>> g;
    vector<int> color;
     
    bool bipartite(int node){
        if(color[node]==-1)color[node]=1;
        for(auto x:g[node]){
            if(color[x]==-1){
                color[x]=1-color[node];
                if(!bipartite(x)){
                    return false;
                }
            }
            else if(color[x]==color[node])return false;
        }
        return true;
    }
    int main()
    {
        int n,m;
        cin>>n>>m;
        vector<int> orient(m);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            orient[i]=u;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        color.resize(n+1,-1);
        if(bipartite(1)){
            cout<<"YES"<<endl;
            for(int i=0;i<m;i++){
                cout<<color[orient[i]];
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return 0;
    }