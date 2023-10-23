#include <bits/stdc++.h>
using namespace std;
int bit[11];
void update(int i,int x,int n){
    for(;i<=n;i=i+(i&(-i))){
        bit[i]=bit[i]+x;
    }
}
int sum(int i){
    int sm=0;
    for(;i>0;i=i-(i&(-i))){
        sm=sm+bit[i];
    }
    return sm;
}
int query(int l,int r){
    return sum(r)-sum(l-1);
}
int main()
{
    int arr[11]={-1,2,3,1,2,0,4,8,8,3,1};
    for(int i=1;i<=10;i++){
        update(i,arr[i],10);
    }
    update(8,4,10);
    cout<<query(2,7)<<endl;
    update(2,1,10);
    cout<<query(3,9)<<endl;
    return 0;
}
