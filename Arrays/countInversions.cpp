#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> countInversionsB(vector<int> &arr, int n){
    //int cnt = 0;
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                // cnt++;
                ans.push_back({arr[i], arr[j]});
            }
        }
    }

    //return cnt;
    return ans;

}

int cnt = 0;

void merge(vector<int> &arr, int low, int mid, int high){

    int left = low;
    int right = mid+1;

    vector<int> ans;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            ans.push_back(arr[left]);
            left++;
        }

        else {
            ans.push_back(arr[right]);
            cnt += (mid-left+1);
            right++;
        }
    }

    while(left<=mid){
        ans.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        ans.push_back(arr[right]);
        right++;
    }

    for(int i = low;i<=high;i++){
        arr[i] = ans[i-low];
    }
    
}

void mergeSort(vector<int> &arr, int low, int high){
    if(low >= high) return;

    int mid = low +(high-low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int countInversionsO(vector<int> &arr, int n){
    mergeSort(arr, 0 , n);
    return cnt;
}

int main(){

    int n;
    vector<int> vec;
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vec.push_back(a);
    }

    // vector<vector<int>> res;
    // res = countInversionsB(vec, n);
    
    // for(auto i: res){
    //     for(auto it: i){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }

    int cnt = countInversionsO(vec, n);
    cout<<cnt;
    return 0;
}
