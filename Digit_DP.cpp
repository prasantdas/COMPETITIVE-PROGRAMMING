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

// Count numbers in range [L, R] whose sum of digits is a Prime Number

bool check[200];

void BuildSeive(){
    check[0]=check[1]=false;
    for(int i=2;i<=200;i++){
        if(check[i]){
            for(int j=2*i;j<=200;j=j+i){
                check[j]=false;
            }
        }
    }
}

//  string s="2436"
//     18 * (18*9) * 2

ll G(string s,int ind=0,ll sum=0,int tight=1){
    if(ind==s.length()){
        if(check[sum])return 1;
        else return 0;
    }
    int num=s[ind]-'0';
    if(tight==1){
        ll res=0;
        for(int i=0;i<=num;i++){
            if(i<num)res=res+G(s,ind+1,sum+i,0);
            else res=res+G(s,ind+1,sum+i,1);
        }
        return res;
    }
    else{
        ll res=0;
        for(int i=0;i<=9;i++){
            res=res+G(s,ind+1,sum+i,0);
        }
        return res;
    }
}

void solve() {
    //Write Here
    int n;
    cin>>n;
    string s=to_string(n);
    cout<<G(s)-G("0")<<endl;
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
