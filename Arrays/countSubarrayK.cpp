#include <bits/stdc++.h>
using namespace std;

int countSubarraysKB(vector<int> &arr, int n, int k){
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int K=i;K<=j;K++){
                sum += arr[K];
            }
            if(sum == k){
                cnt++;
            }
        }
    }

    return cnt;
}

int countSubarraysKM(vector<int> &arr, int n, int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            
            sum += arr[j];
            if(sum == k){
                cnt++;
            }
        }
    }

    return cnt;
}

int countSubarraysKO(vector<int> &arr, int n, int k){
    
    int sum = 0;
    int cnt = 0;
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    for(int i=0;i<n;i++){
        sum += arr[i];

        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            cnt += mpp[rem];
        }

        mpp[sum]++;
        
    }

    return cnt;
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
    
    int cnt = countSubarraysKO(arr, n, k);
    cout<<cnt;
    
    return 0;
}
