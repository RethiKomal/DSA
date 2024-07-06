#include <bits/stdc++.h>
using namespace std;

vector<int> mergingArraysB(vector<int> &arr1, vector<int> &arr2, int n, int m){
    vector<int> ans;

    int left = 0;
    int right = 0;

    while(left<n && right<m){
        if(arr1[left]<arr2[right]){
            ans.push_back(arr1[left]);
            left++;
        }

        else{
            ans.push_back(arr2[right]);
            right++;
        }
    }

    while(left < n){
        ans.push_back(arr1[left]);
        left++;
    }

    while(right < m){
        ans.push_back(arr2[right]);
        right++;
    }

    return ans;

}

vector<int> mergingArraysO(vector<int> &arr1, vector<int> &arr2, int n, int m){
    
    int left = n-1, right = 0;
    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }

        else break;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for(int i=0;i<arr2.size();i++){
        arr1.push_back(arr2[i]);
    }

    return arr1;
}

int main(){

    int n, m;
    vector<int> vec1, vec2;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vec1.push_back(a);
    }

    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        vec2.push_back(a);
    }

    vector<int> vec = mergingArraysB(vec1, vec2, n, m);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    

    return 0;
}
