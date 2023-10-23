#include <bits/stdc++.h>
using namespace std;
// n=7
// [2,3,1,4,5,2,9]
class SegmentTree{
    public:
    vector<int> seg;
    vector<int> lazy;
    SegmentTree(int n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1,0);
    }
    void BuildSegTree(int ind,int low,int high,int arr[]){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=low+(high-low)/2;
    BuildSegTree(2*ind+1,low,mid,arr);
    BuildSegTree(2*ind+2,mid+1,high,arr);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int Query(int ind,int l,int r,int low,int high){
    //Update the node if any updates are remaining
    //As the node will store fresh ansupdated
    if(lazy[ind]!=0){
        seg[ind]=seg[ind]+(high-low+1)*lazy[ind];
        if(low!=high){
            lazy[2*ind+1]=lazy[2*ind+1]+lazy[ind];
            lazy[2*ind+2]=lazy[2*ind+2]+lazy[ind];
        }
        lazy[ind]=0;
    }
    // No Overlap  [L,R]=[2,4] and (low,high)=(0,1) Or (5,6)
    if(high<l || r<low){
        return 0;
    }
    // Complete Overlap [L,R]=[2,4] and (low,high)=(2,3)
    else if(l<=low && r>=high){
        return seg[ind];
    }
    // Partial Overlap [L,R]=[2,4] and (low,high)=(0,3) Or (low,high)=(3,6)
    else{
        int mid=low+(high-low)/2;
        return Query(2*ind+1,l,r,low,mid)+Query(2*ind+2,l,r,mid+1,high);
    }
}
void Range_Update(int ind,int low,int high,int i,int j,int val){
    //Update the node if any updates are remaining
    //As the node will store fresh ansupdated
    if(lazy[ind]!=0){
        seg[ind]=seg[ind]+(high-low+1)*lazy[ind];
        if(low!=high){
            lazy[2*ind+1]=lazy[2*ind+1]+lazy[ind];
            lazy[2*ind+2]=lazy[2*ind+2]+lazy[ind];
        }
        lazy[ind]=0;
    }
    // No Overlap  [i,j]=[2,4] and (low,high)=(0,1) Or (5,6)
    if(high<i || j<low){
        return;
    }
    // Complete Overlap [i,j]=[2,4] and (low,high)=(2,3)
    else if(i<=low && j>=high){
        seg[ind]=seg[ind]+val*(high-low+1);
        if(low!=high){
            lazy[2*ind+1]=lazy[2*ind+1]+val;
            lazy[2*ind+2]=lazy[2*ind+2]+val;
        }
        return;
    }
    // Partial Overlap [i,j]=[2,4] and (low,high)=(0,3) Or (low,high)=(3,6)
    else{
        int mid=low+(high-low)/2;
        Range_Update(2*ind+1,low,mid,i,j,val);
        Range_Update(2*ind+2,mid+1,high,i,j,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
        return;
    }
}
};
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SegmentTree ST(n);
    ST.BuildSegTree(0,0,n-1,arr);
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
            cout<<ST.Query(0,l,r,0,n-1)<<endl;
        }
        else{
            int i,j,val;
            cin>>i>>j>>val;
            ST.Range_Update(0,0,n-1,i,j,val);
        }
    }
    return 0;
}
