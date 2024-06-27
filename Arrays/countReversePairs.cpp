#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> countReversePairsB(vector<int> &arr, int n){
    //int cnt = 0;
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(2*arr[j]<arr[i]){
                // cnt++;
                ans.push_back({arr[i], arr[j]});
            }
        }
    }

    //return cnt;
    return ans;

}

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

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low >= high) return cnt;

    int mid = low +(high-low)/2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int countReversePairsO(vector<int> &arr, int n){
    return mergeSort(arr, 0 , n);
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
    // res = countReversePairsB(vec, n);
    
    // for(auto i: res){
    //     for(auto it: i){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }

    int cnt = countReversePairsO(vec, n);
    cout<<cnt;
    return 0;
}
