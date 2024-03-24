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

bool is_positive(int x){
    return x>0;
}

void solve() {
    //Write Here
    cout<<[](int x){return x+2;}(2)<<endl; // One liner lambda function one parameter
    cout<<[](int x,int y){return x+y;}(2,3)<<endl; // One liner lambda function two parameter
    auto sum=[](int x,int y){return x+y;};  // Assigning lambda function to a variable 
    cout<<sum(4,6)<<endl;

    int a=1,b=2;
    auto sum=[](int x,int& y){
        x++;
        y++;
        return x+y;
    };
    cout<<sum(a,b)<<endl; // 5
    cout<<a<<" "<<b<<endl; // 1 3

   function<void(int,int)> dfs=[&](int src,int par){
        cout<<src<<" ";
        for(auto x:g[src]){
            if(x==par)continue;
            dfs(x,src);
        }
    };
    dfs(1,-1);
    
    vector<int> v={1,2,-4};
    int arr[5]={1,2,3,4,5};
    int n=5;
    cout<<all_of(v.begin(),v.end(),is_positive)<<endl; // If all is satisfied
    cout<<all_of(arr,arr+n,is_positive)<<endl; // For arrays
    cout<<all_of(v.begin(),v.end(),[](int x){return x>0;})<<endl;
    cout<<any_of(v.begin(),v.end(),[](int x){return x!=0;})<<endl; // If any is satisfied
    cout<<none_of(v.begin(),v.end(),[](int x){return x>0;})<<endl; // If none is satisfied
    cout<<*min_element(v.begin(),v.end())<<endl;  // Finding minimum element
    cout<<*max_element(v.begin(),v.end())<<endl;  // Finding maximum element
    cout<<accumulate(v.begin(),v.end(),0)<<endl;  // Finding sum of elements whose initial sum=0
    cout<<count(v.begin(),v.end(),1)<<endl;       // Counting the frequency of the element
    auto it=find(v.begin(),v.end(),1);            // Searches for element and returns its iterator if not found returns end iterator
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}
