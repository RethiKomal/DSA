#include <bits/stdc++.h>
using namespace std;

int maxSubarrayB(vector<int> &arr, int n){
    int sum;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// kadane's algorithm
int maxSubarrayO(vector<int> &arr, int n){

    long long sum = 0;
    long long maxi = LONG_MIN;
    for(int i=0;i<n;i++){
        sum += arr[i];

        if(maxi < sum){
            maxi = sum;
        }

        if(sum < 0) sum = 0;
        
    }

    return maxi;
}

// Extended version
vector<int> maxSubarrayE(vector<int> &arr, int n){

    long long sum = 0;
    long long maxi = LONG_MIN;
    int start;
    int ansStart = -1, ansEnd = -1;
    for(int i=0;i<n;i++){

        if(sum == 0) start = i;
        sum += arr[i];


        if(maxi < sum){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0) sum = 0;
        
    }

    return {ansStart, ansEnd};
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

    vector<int> maxi = maxSubarrayE(arr, n);
    cout<<maxi[0]<<" "<<maxi[1];
    
    return 0;
}
