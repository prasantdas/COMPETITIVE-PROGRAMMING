#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int divisor[1000001];
const int N=1000000;
void solve(){
    for(int i=2;i<=N;i++){
        for(int j=i;j<=N;j=j+i){
            divisor[j]++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        cout<<divisor[x]+1<<endl;
    }
    return 0;
}