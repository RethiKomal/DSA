#include <bits/stdc++.h>
using namespace std;

/* Varient - 1: if positive and negative elements are in same number */
vector<int> RearrangePosandNegB(vector<int> &arr, int n){

    vector<int> pos, neg;
    

    for(int i=0;i<n;i++){
        if(arr[i]>0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    for(int i=0;i<(pos.size());i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }

    return arr;

}

vector<int> RearrangePosandNegO(vector<int> &arr, int n){
    vector<int> ans(n, 0);

    int posIndex = 0, negIndex = 1;

    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            ans[posIndex] = arr[i];
            posIndex += 2;
        }

        else{
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }

    return ans;
}

/* Varient - 2: if positive and negative elements are not in same number */
vector<int> RearrangePosandNeg21(vector<int> &arr, int n){
    vector<int> ans(n, 0);

    int posIndex = 0, negIndex = 1;
    int cnt1 = 0, cnt2 = 0;

    for(int i=0;i<n;i++){
        if(arr[i]>0) cnt1++;
        else cnt2++;
    }

    for(int i=0;i<2*min(cnt1,cnt2);i++){
        if(arr[i] > 0){
            ans[posIndex] = arr[i];
            posIndex += 2;
        }

        else{
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }

    for(int i=2*min(cnt1,cnt2);i<n;i++){
        if(cnt1>cnt2){
            ans[posIndex++] = arr[i];
        }

        else if(cnt1<cnt2) ans[negIndex++] = arr[i];
    }

    return ans;
}

vector<int> RearrangePosandNeg22(vector<int> &A, int n){
    vector<int> pos;
    vector<int> neg;
    
    for(int i=0;i<n;i++){
        
        if(A[i]>0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
    }
    
    if(pos.size() < neg.size()){
        
        for(int i=0;i<pos.size();i++){
        
            A[2*i] = pos[i];
            A[2*i+1] = neg[i];
        }
        
        int index = pos.size()*2;
        for(int i = pos.size();i<neg.size();i++){
            
            A[index] = neg[i];
            index++;
        }
    }
    
    else{
        
        for(int i=0;i<neg.size();i++){
        
            A[2*i] = pos[i];
            A[2*i+1] = neg[i];
        }
        
        int index = neg.size()*2;
        for(int i = neg.size();i<pos.size();i++){
            
            A[index] = pos[i];
            index++;
        }
    }
    return A;
        
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

    vector<int> res = RearrangePosandNeg22(arr, n);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}
