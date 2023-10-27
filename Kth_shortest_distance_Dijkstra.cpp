#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e15;
unordered_map<ll,vector<pair<ll,ll>>> g;
void dijkstra(vector<vector<ll>>& distance,int n,int k){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    distance[1][0]=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        ll dis=p.first,node=p.second;
        if(distance[node][k-1]<dis)continue;
        for(auto x:g[node]){
            ll n2=x.first,d=x.second;
            if(dis+d<distance[n2][k-1]){
                distance[n2][k-1]=dis+d;
                pq.push({dis+d,n2});
                sort(distance[n2].begin(),distance[n2].end());
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<distance[n][i]<<" ";
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    g.clear();
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    vector<vector<ll>> distance(n+1,vector<ll>(k,inf));
    dijkstra(distance,n,k);
    return 0;
}