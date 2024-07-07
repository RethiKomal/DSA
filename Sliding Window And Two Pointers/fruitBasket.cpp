#include<bits/stdc++.h>
using namespace std;

int friutBasket(vector<int> &arr){
    int n = arr.size();
    int maxLen = 0;

    for(int i=0;i<n;i++){
        set<int> st;
        for(int j=i;j<n;j++){
            st.insert(arr[j]);
            if(st.size() <= 2){
                maxLen = max(maxLen, j-i+1);
            }

            else break;
        }
    }

    return maxLen;

}

int fruitBasket1(vector<int> &arr){
    int n = arr.size();
    int maxLen = 0;

    int l = 0, r = 0;
    map<int, int> mpp;

    while(r < n){

        mpp[arr[r]]++;
        if(mpp.size()>2){ // while(mpp.size()>2){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
        }

        if(mpp.size()<=2) maxLen = max(maxLen, r-l+1);      
        r++;
    }

    return maxLen;
}

int main(){

    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4}; // output: 5
    cout<<fruitBasket1(arr)<<endl;

    return 0;
}