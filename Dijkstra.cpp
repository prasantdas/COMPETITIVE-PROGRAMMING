#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,vector<pair<int,ll>>> g;
void dijkstra(vector<ll>& distance,int n){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,1});
    distance[1]=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int node=p.second;
        ll dist=p.first;
        if(distance[node]<dist)continue;
        for(auto x:g[node]){
            int n=x.first;
            ll d=x.second;
            if(dist+d<distance[n]){
                distance[n]=dist+d;
                pq.push({dist+d,n});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    g.clear();
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    vector<ll> distance(n+1,1e15);
    dijkstra(distance,n);
    return 0;
}