    #include<bits/stdc++.h>
    using namespace std;
    //consider the graph G(n,e)
    // The graph G1 has the same number of Vertices that is n
    // Making directed graph which has n vertices but e1=No of directed edges=e-no of undirected edges
    // The only difference is the number of edges :
    unordered_map<int,vector<int>> g;
    vector<pair<int,int>> edges;
    vector<int> toposort(int n){
        vector<int> topo;
        vector<int> indeg(n+1,0);
        for(int i=1;i<=n;i++){
            for(auto x:g[i]){
                indeg[x]++;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto x:g[node]){
                indeg[x]--;
                if(indeg[x]==0)q.push(x);
            }
        }
        return topo;
    }
    int main(){
        int t;
        cin>>t;
        while(t--){
            int n,m;
            cin>>n>>m;
            g.clear();
            edges.clear();
            for(int i=0;i<m;i++){
                int t1,x,y;
                cin>>t1>>x>>y;
                edges.push_back({x,y});
                if(t1){
                    g[x].push_back(y);
                }
            }
            vector<int> order=toposort(n);
            if(order.size()<n)cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
                vector<int> idx(n+1);
                for(int i=0;i<order.size();i++){
                    idx[order[i]]=i;
                }
                for(auto e:edges){
                    if(idx[e.first]>idx[e.second])swap(e.first,e.second);
                    cout<<e.first<<" "<<e.second<<endl;
                }
            }
        }
    }