class DisjointSet{
    public:
    vector<int> par,Size;
    DisjointSet(int n){
        par.resize(n+1);
        Size.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            Size[i]=1;
        }
    }
    int findUPar(int node){
        if(par[node]==node)return node;
        return par[node]=findUPar(par[node]);
    }
    void UnionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;
        if(Size[ulp_u]>Size[ulp_v]){
            par[ulp_v]=ulp_u;
            Size[ulp_u]=Size[ulp_u]+Size[ulp_v];
        }
        else{
            par[ulp_u]=ulp_v;
            Size[ulp_v]=Size[ulp_v]+Size[ulp_u];
        }
    }
  };

// Function to convert Grid coordinates to nodes for DSU
int node(int i,int j,int m){
    return i*m+j;
}
