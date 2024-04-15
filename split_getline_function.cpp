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

vector<string> splitfunction(string s1){
    stringstream ss(s1);
    string s;
    vector<string> v;
    while (getline(ss, s, ' ')) {
        v.push_back(s);
    }
    return v;
}

void solve() {
    //Write Here
    string str = "Geeks for Geeks";
    vector<string> ans=splitfunction(str);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    //Ans:-
      // Geeks
      // for 
      // Geeks
    
    // Getline function
    string str2;
    cout << "Please enter your fullname: \n";  // Prasant Kumar Das
    getline(cin, str);
    cout << "Hello, " << str << " welcome to GfG !\n";
    //Ans:-
      // Hello, Prasant Kumar Das welcome to GfG !
    cout<<endl;
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
