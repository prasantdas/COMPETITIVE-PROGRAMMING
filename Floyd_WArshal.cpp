#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
    
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> distance(n+1,vector<ll>(n+1,1e15));
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        distance[u][v]=min(distance[u][v],w);
        distance[v][u]=min(distance[u][v],w);
    }
    for(int i=0;i<=n;i++){
        distance[i][i]=0;
    }
    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                distance[i][j]=min(distance[i][j],distance[i][via]+distance[via][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        ll d=distance[u][v];
        if(d>=1e15)cout<<-1<<endl;
        else cout<<d<<endl;
    }
    return 0;
}