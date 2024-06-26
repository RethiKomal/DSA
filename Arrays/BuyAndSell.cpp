#include <bits/stdc++.h>
using namespace std;

int BuyAndSellB(vector<int> &arr, int n){

    int maxProfit = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i])
                maxProfit = max(maxProfit, arr[j]-arr[i]);
        }
    }

    return maxProfit;
}

int BuyAndSellO(vector<int> &arr, int n){

    int mini = INT_MAX;
    int maxProfit = INT_MIN;

    for(int i=0;i<n;i++){
        mini = min(mini, arr[i]);
        maxProfit = max(maxProfit, arr[i]-mini);
    }

    return maxProfit;
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

    int profit = BuyAndSellO(arr, n);
    cout<<profit;
    
    return 0;
}
