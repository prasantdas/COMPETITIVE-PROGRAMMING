#include <bits/stdc++.h>
using namespace std;

void BuildSegTree(int ind,int low,int high,int arr[],int seg[]){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=low+(high-low)/2;
    BuildSegTree(2*ind+1,low,mid,arr,seg);
    BuildSegTree(2*ind+2,mid+1,high,arr,seg);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
int Query(int ind,int l,int r,int low,int high,int seg[]){
    // No Overlap  [L,R]=[2,4] and (low,high)=(0,1) Or (5,6)
    if(high<l || r<low){
        return INT_MAX;
    }
    // Complete Overlap [L,R]=[2,4] and (low,high)=(2,3)
    else if(l<=low && r>=high){
        return seg[ind];
    }
    // Partial Overlap [L,R]=[2,4] and (low,high)=(0,3) Or (low,high)=(3,6)
    else{
        int mid=low+(high-low)/2;
        return min(Query(2*ind+1,l,r,low,mid,seg),Query(2*ind+2,l,r,mid+1,high,seg));
    }
}
void Update(int ind,int low,int high,int i,int val,int seg[]){
    if(low==high){
        seg[ind]=val;
        return;
    }
    // Left [l,r]=[2,4] and i=3
    int mid=low+(high-low)/2;
    if(i<=mid){
        Update(2*ind+1,low,mid,i,val,seg);
    }
    // Right [l,r]=[2,4] and i=4
    else{
        Update(2*ind+2,mid+1,high,i,val,seg);
    }
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int seg[4*n];
    BuildSegTree(0,0,n-1,arr,seg);
    int Q;
    cin>>Q;
    while(Q--){
        // 1--> Query
        // 2--> Update
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<Query(0,l,r,0,n-1,seg)<<endl;
        }
        else{
            int i,val;
            cin>>i>>val;
            Update(0,0,n-1,i,val,seg);
        }
    }
    return 0;
}
