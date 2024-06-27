#include <bits/stdc++.h>
using namespace std;

int consectiveOnes(vector<int> &arr, int n){
    int cnt = 0;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt++;
        }

        else cnt = 0;
        maxi = max(maxi, cnt);
    }

    return maxi;
}

int main(){

    vector<int> arr;
    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    int cnt = consectiveOnes(arr,n);
    cout<<cnt;
    
    return 0;
}