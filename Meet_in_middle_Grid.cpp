        #include <bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        ll mod=1e9+7;
        ll ans=0;
        //To avoid Memory Limit Exceeded, BFS from Start and end and meet in the middle.
        // MEET IN THE MIDDLE
        //lINK: https://heartlessly.github.io/problems/codeforces-1006f/
        // x=0,1,2,...19
        //Store count of Correspondong values in map 
        unordered_map<ll,ll> cnt[20];
        void bfs1(ll i,ll j,ll k,vector<vector<ll>> grid){
            ll n=grid.size(),m=grid[0].size();
            queue<pair<pair<ll,ll>,ll>> q;
            q.push({{0,0},grid[0][0]});
            while(!q.empty()){
                pair<pair<ll,ll>,ll> p=q.front();
                q.pop();
                ll x=p.first.first,y=p.first.second,d=p.second;
                if(x+y==(m+n)/2-1){
                    cnt[x][d]++;
                    continue;
                }
                if(x+1<n){
                    ll ds=d^grid[x+1][y];
                    q.push({{x+1,y},ds});
                }
                if(y+1<m){
                    ll ds=d^grid[x][y+1];
                    q.push({{x,y+1},ds});
                }
            }
        }
        
        void bfs2(ll i,ll j,ll k,vector<vector<ll>> grid){
            ll n=grid.size(),m=grid[0].size();
            queue<pair<pair<ll,ll>,ll>> q;
            q.push({{i,j},grid[i][j]});
            while(!q.empty()){
                pair<pair<ll,ll>,ll> p=q.front();
                q.pop();
                ll x=p.first.first,y=p.first.second,d=p.second;
                if(x+y==(m+n)/2-1){
                    ans+=cnt[x][d^grid[x][y]^k];
                    continue;
                }
                if(x-1>=0){
                    ll ds=d^grid[x-1][y];
                    q.push({{x-1,y},ds});
                }
                if(y-1>=0){
                    ll ds=d^grid[x][y-1];
                    q.push({{x,y-1},ds});
                }
            }
        }
        
        int main()
        {
            ll n,m,k;
            cin>>n>>m>>k;
            vector<vector<ll>> grid(n,vector<ll> (m));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    ll ele;
                    cin>>ele;
                    grid[i][j]=ele;
                }
            }
            bfs1(0,0,k,grid);
            bfs2(n-1,m-1,k,grid);
            cout<<ans<<endl;
            return 0;
        }