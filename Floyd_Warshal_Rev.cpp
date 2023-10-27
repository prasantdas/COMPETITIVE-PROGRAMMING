    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    // Run floyed wrashal in opposite fashion
    // Instead of removing nodes,we add nodes
    int main()
    {
        int n;
        cin>>n;
        vector<vector<ll>> cost(n+1,vector<ll>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ll ele;
                cin>>ele;
                cost[i][j]=ele;
            }
        }
        vector<int> order(n);
        vector<ll> ans;
        for(int i=0;i<n;i++){
            int ele;
            cin>>ele;
            order[i]=ele;
        }
        reverse(order.begin(),order.end());
        for(int k=0;k<n;k++){
            int via=order[k];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
                }
            }
            ll sum=0;
            for(int i=0;i<=k;i++){
                for(int j=0;j<=k;j++){
                    sum=sum+cost[order[i]][order[j]];
                }
            }
            ans.push_back(sum);
        }
        for(int i=0;i<n;i++){
            cout<<ans[n-i-1]<<" ";
        }
        cout<<endl;
        return 0;
    }