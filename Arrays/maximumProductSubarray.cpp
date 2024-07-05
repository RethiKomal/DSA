#include <bits/stdc++.h>
using namespace std;

int maximumProductSubarrayB(vector<int> &arr, int n){
    int result = INT_MIN;
    for(int i=0;i<arr.size()-1;i++) {
        for(int j=i+1;j<arr.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= arr[k];
            result = max(result,prod);    
        }
    }
    return result;
}

int maximumProductSubarrayM(vector<int> &arr, int n){
    int result = arr[0];
    for(int i=0;i<arr.size()-1;i++) {
        int p = arr[i];
        for(int j=i+1;j<arr.size();j++) {
           result = max(result,p);
           p *= arr[j];
        }
    }
    return result;
}

int maximumProductSubarrayO(vector<int> &arr, int n){
    
    int prefix = 1, suffix = 1;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n-i-1];

        maxi = max(maxi, max(prefix, suffix));
    }

    return maxi;
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

    
    int res = maximumProductSubarrayO(vec, n);
    cout<<res; 


    return 0;
}
