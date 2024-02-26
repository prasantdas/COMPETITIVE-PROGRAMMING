#include<bits/stdc++.h>
using namespace std;

/*
 * Author    : Prasant Das
 * Date      : 15:06:2023
 */

#define mod 1000000007
#define INF 1e18
#define inf 1e9
#define NINF -1e18
#define ninf -1e9
#define vi vector<int>
#define vll vector<long long>
#define vl vector<long>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef priority_queue<int> maxheap;
typedef priority_queue<int, vector<int>, greater<int>> minheap;
#define for0(i,n)  for(ll i=0; i<n; i++)
#define for1(i,n)  for(ll i=1; i<=n; i++) 
int d1[4] = { -1, 1, 0, 0};
int d2[4] = {0, 0, -1, 1};
int D1[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int D2[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 

bool check[10000001];

void BuildSeive(){
    check[0]=check[1]=false;
    for(int i=2;i<=10000001;i++){
        if(check[i]){
            for(int j=2*i;j<=10000001;j=j+i){
                check[j]=false;
            }
        }
    }
}

void solve() {
    //Write Here
   for(int i=1;i<=1000;i++){
       if(check[i])cout<<i<<endl;
   }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(check,true,sizeof(check));
    BuildSeive();
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}
