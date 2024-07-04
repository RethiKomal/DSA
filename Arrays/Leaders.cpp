#include <bits/stdc++.h>
using namespace std;

vector<int> leaderB(vector<int> &arr, int n){

    vector<int> ans;
    
    for(int i=0;i<n;i++){
        int flag = 1;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                flag = 0;
                break;
            }
        }

        if(flag) ans.push_back(arr[i]);
    }

    return ans;
}

vector<int> leaderO(vector<int> &arr, int n){
    
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(maxi < arr[i]){
            maxi = arr[i];
            ans.push_back(arr[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
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
    
    vector<int> res = leaderO(arr, n);
    for(auto i: res){
        cout<<i<<" ";
    }

    return 0;
}
