#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e17;
void dijkstra(ll src,vector<ll>& distance,unordered_map<ll,vector<pair<ll,ll>>>& g){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,src});
    distance[src]=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        ll node=p.second,dis=p.first;
        if(distance[node]<dis)continue;
        for(auto x:g[node]){
            ll n2=x.first,d=x.second;
            if(dis+d<distance[n2]){
                distance[n2]=dis+d;
                pq.push({dis+d,n2});
            }
        }
    }
}
int main()
{
    unordered_map<ll,vector<pair<ll,ll>>> g;
    unordered_map<ll,vector<pair<ll,ll>>> rg;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges;
    for(int i=0;i<m;i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        rg[v].push_back({u,wt});
        edges.push_back({u,v,wt});
    }
    vector<ll> dist(n+1,inf);
    vector<ll> rdist(n+1,inf);
    dijkstra(1,dist,g);
    dijkstra(n,rdist,rg);
    ll ans=inf;
    for(auto x:edges){
        ll u=x[0],v=x[1],w=x[2];
        if(u==1 && v==n){
            ans=min(ans,w/2);
        }
        else if(u==1){
            ans=min(ans,w/2+rdist[v]);
        }
        else if(v==n){
            ans=min(ans,w/2+dist[u]);
        }
        else if(!(u==1 && v==n)){
            ans=min(ans,w/2+dist[u]+rdist[v]);
        }
    }
    cout<<ans<<endl;
}