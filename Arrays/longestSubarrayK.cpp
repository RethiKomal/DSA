#include <bits/stdc++.h>
using namespace std;

int longestSubarrayKB(vector<int> &arr, int n, int k){
    int maxi = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum == k){
                maxi = max(maxi, j-i+1);
            }
        }
    }

    return maxi;
}

int longestSubarrayKM(vector<int> &arr, int n, int k){
    
    map<int, int> mpp;
    int sum = 0;
    int maxi = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum == k){
            maxi = max(maxi, i+1);
        }

        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            maxi = max(maxi, i-mpp[rem]);
        }

        if(mpp.find(sum) != mpp.end()){
            mpp[sum] = i;
        }
    }

    return maxi;
}

int longestSubarrayKO(vector<int> &arr, int n, int k){
    // Works for only positive integers
    int left = 0, right = 0;
    int sum = arr[0];
    int maxi = 0;

    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;

        }

        if(sum == k) maxi = max(maxi, right-left+1);

        right++;
        if(right<n) sum += arr[right];
    }

    return maxi;
}

int main(){

    vector<int> arr;
    int n, k;

    cin>>n>>k;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    int maxi = longestSubarrayKO(arr, n, k);
    cout<<maxi;
    
    return 0;
}