class DisjointSet{
    public:
    vector<int> par,size;
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
            size[i]=1;
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
        if(size[ulp_u]>size[ulp_v]){
            par[ulp_v]=ulp_u;
            size[ulp_u]=size[ulp_u]+size[ulp_v];
        }
        else{
            par[ulp_u]=ulp_v;
            size[ulp_v]=size[ulp_v]+size[ulp_u];
        }
    }
  };
