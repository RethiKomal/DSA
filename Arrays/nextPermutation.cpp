#include <bits/stdc++.h>
using namespace std;

void nextPermutationB(vector<int> &arr, int n){
    /*

    Brute Force: Finding all possible permutations. 

    Approach :

    Step 1: Find all possible permutations of elements present and store them.
    Step 2: Search input from all possible permutations.
    Step 3: Print the next permutation present right after it.
    TC -> O(n!*n)
    sc -> O(1)

    */
}

void nextPermuationM(vector<int> &arr, int n){
    next_permutation(arr.begin(), arr.end());
}

void nextPermuationO(vector<int> &arr, int n){

    int ind = -1;
    for(int i=n-1;i>0;i--){
        if(arr[i-1]<arr[i]){
            ind = i-1;
            break;
        }
    }

    if(ind == -1) reverse(arr.begin(), arr.end());
    for(int i=n-1;i>ind;i--){
        if(arr[ind] < arr[i]){
            swap(arr[ind], arr[i]);
            break;
        }
    }
    
    reverse(arr.begin()+ind+1, arr.end());
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

    nextPermuationM(arr, n);
    for(auto i: arr){
        cout<<i<<" ";
    }
    
    return 0;
}
