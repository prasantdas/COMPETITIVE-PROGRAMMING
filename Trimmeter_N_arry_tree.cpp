    // The problem is to find the triameter of a tree. 
     
    // Here is what we will do. We will first find the diamter of the tree. 
     
    // We can do this by the following way - 
     
    // 1. Start from the root and go as far as possible using DFS. Let the point with the furthest depth be a.
    // 2. Start from a and do another DFS and go as far as possible. Let the point with the furthest depth be b.
     
    // a-b is the diamater of the tree. 
     
    // -----
     
    // Now, how to find the third point ? 
     
    // For every vertex in the graph, we have to calculate the distance to the diameter. 
     
    // To do this, we will first store all the vertices of the diameter in a Queue. 
     
    // Then, we will perform multi source BFS. 
     
    // This will help us in calculating the distance from the diameter to every vertex in the tree.
     
    // -----
    #include <bits/stdc++.h>
    using namespace std;
     
    unordered_map<int,vector<int>> g;
    vector<int> dpath,diam_path;
    pair<int,int> pa={1,0},pb={1,0};
    queue<pair<int,int>> q;
    vector<int> vis,distances;
     
    void dfs1(int node,int par,int dist){
        if(dist>pa.second)pa={node,dist};
        for(auto x:g[node]){
            if(x!=par){
                dfs1(x,node,dist+1);
            }
        }
    }
     
    void dfs2(int node,int par,int dist){
        if(dist>pb.second)pb={node,dist};
        for(auto x:g[node]){
            if(x!=par){
                dfs2(x,node,dist+1);
            }
        }
    }
     
    void path(int a,int b,int par){
        dpath.push_back(a);
        if(a==b){
            for(int i=0;i<dpath.size();i++){
                distances[dpath[i]]=0;
                q.push({dpath[i],0});
                vis[dpath[i]]=1;
                diam_path.push_back(dpath[i]);
            }
            return;
        }
        for(auto x:g[a]){
            if(x!=par){
                path(x,b,a);
            }
        }
        dpath.pop_back();
    }
    void multibfs(){
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int node=q.front().first;
                int dist=q.front().second;
                q.pop();
                for(auto x:g[node]){
                    if(!vis[x]){
                        vis[x]=1;
                        distances[x]=dist+1;
                        q.push({x,dist+1});
                    }
                }
            }
        }
    }
    int main()
    {
        int n;
        cin>>n;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vis.resize(n+1,0);
        distances.resize(n+1,0);
        dfs1(1,-1,0);
        dfs2(pa.first,-1,0);
        int a=pa.first,b=pb.first;
        path(a,b,-1);
        multibfs();
        int maxdist=0;
        int c=0;
        for(int i=1;i<=n;i++){
            if(distances[i]>maxdist){
                c=i;
                maxdist=distances[i];
            }
        }
        if(c==0){
            for(int i=1;i<=n;i++){
                if(a!=i && b!=i){
                    c=i;
                    break;
                }
            }
            cout<<diam_path.size()-1<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else{
            cout<<diam_path.size()-1+maxdist<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        return 0;
    }
    // 12
    // 1 2
    // 1 3
    // 2 4
    // 4 5
    // 5 6
    // 2 7
    // 7 8
    // 8 9
    // 8 10
    // 10 11
    // 11 12