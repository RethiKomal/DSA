#include <bits/stdc++.h>
using namespace std;

int majorityElementB(vector<int> &arr, int n){

    int cnt;
    for(int i=0;i<n;i++){
        cnt = 1;
        for(int j=i+1; j<n;j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }

        if(cnt > (n/2)) return arr[i];
    }

    return -1;
}

int majorityElementM(vector<int> &arr, int n){
    unordered_map<int, int> mpp;

    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto i: mpp){
        if(i.second > (n/2)){
            return i.first;
        }
    }

    return -1;
}

// Moore's voting algorithm
int majorityElementO(vector<int> &arr, int n){

    int cnt = 0;
    int ele = -1;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            cnt = 1;
            ele = arr[i];
        }

        if(ele == arr[i]) cnt++;
        else cnt--;
    }

    cnt = 0;
    for(int i=0;i<n;i++){
        if(ele == arr[i]) cnt++;
    }

    if(cnt >(n/2)) return ele;
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

    int ele = majorityElementO(arr, n);
    cout<<ele;
    
    return 0;
}
