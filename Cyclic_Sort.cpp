// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr={3,2,6,4,8,7,9,1,5,10};
    int n=arr.size();
    for(int i=0;i<n;i++){
        while((arr[i]-1)!=i){
            swap(arr[i],arr[arr[i]-1]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
