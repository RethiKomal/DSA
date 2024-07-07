#include<bits/stdc++.h>
using namespace std;

int BinarySubarraysWithSumK(vector<int> &arr, int k){

    if(k < 0) return 0;

    int cnt = 0;
    int l=0, r=0;
    int sum = 0;

    while(r < arr.size()){

        sum += arr[r];

        while(sum > k){
            sum -= arr[l];
            l++;
        }

        cnt += (r-l+1);
        r++;
    }

    return cnt;

}

int Solution(vector<int>&arr, int k){
    return (BinarySubarraysWithSumK(arr, k) - BinarySubarraysWithSumK(arr, k-1));
}

int main(){

    int n = 5;
    vector<int> arr = {1, 0, 1, 0, 1};
    int goal = 2;

    cout<<Solution(arr, goal);

    return 0;
}