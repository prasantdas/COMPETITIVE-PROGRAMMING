#include<bits/stdc++.h>
using namespace std;
 
  /*
   * Author    : Prasant Das
   * Date      : 15:06:2023
  */
 
        // MACROS
 
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
 
       //  DEBUGGING
 
#ifndef ONLINE_JUDGE
#define debug(x){cerr<<#x<<" ";_print(x);cerr<<endl;}
#else
#define debug(x)
#endif
void _print(int a){cerr<<a;}
void _print(ll a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr<<a;}
void _print(double a){cerr<<a;}
void _print(ull a){cerr<<a;}
void _print(lld a){cerr<<a;}
template <class T, class V> void _print(pair <T, V> p1);
template <class T> void _print(vector <T> v1);
template <class T> void _print(set <T> s1);
template <class T, class V> void _print(map <T, V> m1);
template<class T,class V> void _print(unordered_map<T,V> m2);
template <class T> void _print(multiset <T> s2);
template<class T> void _print(vector<T> v1){cerr<<"[";for(T i:v1){ _print(i);cerr<<" ";}cerr<<"]";}
template<class T> void _print(set<T> s1){cerr<<"[";for(T i:s1){ _print(i);cerr<<" ";} cerr<<"]";}
template<class T,class V> void _print(pair<T,V> p1){cerr<<"{";_print(p1.first);cerr<<","; _print(p1.second);cerr<<"}";}
template<class T> void _print(multiset<T> s2){cerr<<"[";for(T i:s2){ _print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V> void _print(map<T,V> m1){cerr<<"[";for(auto i:m1){ _print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V> void _print(unordered_map<T,V> m2){cerr<<"[";for(auto i:m2){_print(i);cerr<<" ";}cerr<<"]";}
 
        // DIRECTIONS
 
int d1[4] = { -1, 1, 0, 0};
int d2[4] = {0, 0, -1, 1};
int D1[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int D2[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
 
       // SOLVE FOR EACH TEST CASES HERE
 
void solve() {
    //Write Here
    ll n,m;
    cin>>n>>m;
    unordered_map<ll,set<ll>> g;
    vector<ll> deg(n+1,0);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
    for(ll i=1;i<=n;i++){
        if(deg[i]%2){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    stack<ll> st;
    vector<ll> path;
    st.push(1);
    while(st.size()){
        ll z=st.top();
        if(deg[z]==0){
            st.pop();
            path.push_back(z);
        }
        else{
            ll m=*(g[z].begin());
            g[z].erase(m);
            g[m].erase(z);
            deg[z]--;
            deg[m]--;
            st.push(m);
        }
    }
    if(path.size()!=(m+1)){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for(auto x:path){
        cout<<x<<" ";
    }
    cout<<endl;
}
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
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
