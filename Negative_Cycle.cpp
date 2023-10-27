#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e17;
void bellman_ford(vector<vector<ll>>& edges,vector<ll>& distance,int n,int m){
    vector<ll> relaxant(n+1,-1);
    int x;
    for(int i=1;i<=n;i++){
        x=-1;
        for(auto y:edges){
            ll u=y[0],v=y[1],wt=y[2];
            if(distance[u]+wt<distance[v]){
                distance[v]=distance[u]+wt;
                relaxant[v]=u;
                x=v;
            }
        }
    }
    if(x==-1){
        cout<<"NO"<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            x=relaxant[x];
        }
        vector<ll> cycle;
        ll v=relaxant[x];
        cycle.push_back(x);
        while(v!=x){
            cycle.push_back(v);
            v=relaxant[v];
        }
        cycle.push_back(x);
        reverse(cycle.begin(),cycle.end());
        cout<<"YES"<<endl;
        for(int i=0;i<cycle.size();i++){
            cout<<cycle[i]<<" ";
        }
        cout<<endl;
    }
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> edges(m);
    bool flag=false;
    ll W;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1 && b==1){
            W=c;
            flag=true;
        }
        edges[i]={a,b,c};
    }
    vector<ll> distance(n+1,inf);
    if(flag)distance[1]=W;
    else distance[1]=0;
    bellman_ford(edges,distance,n,m);
}