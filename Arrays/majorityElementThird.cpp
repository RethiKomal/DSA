#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementB(vector<int> &arr, int n){

    vector<int> ans;
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j] && !visited[j]){
                cnt++;
                visited[j] = true;
            }
        }

        if(cnt == (n/3)+1){
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

vector<int> majorityElementM(vector<int> &arr, int n){

    map<int,int> mpp;
    vector<int> ans;

    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        if(it.second > (n/3)){
            ans.push_back(it.first);
        }
    }

    return ans;
}

vector<int> majorityElementO(vector<int> &arr, int n){
    
    int cnt1=0,cnt2=0,el1=0,el2=0;
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(cnt1==0 && el2 != arr[i]){
            cnt1 = 1;
            el1 = arr[i];
        }

        else if(cnt2 == 0 && el1 != arr[i]){
            cnt2 = 1;
            el2 = arr[i];
        }

        else if(el1 == arr[i]) cnt1++;
        else if(el2 == arr[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1=0, cnt2=0;
    for(int i=0;i<n;i++){
        if(el1 == arr[i]) cnt1++;
        if(el2==arr[i]) cnt2++;
    }

    if(cnt1>(n/3)) ans.push_back(el1);
    if(cnt2>(n/3)) ans.push_back(el2);

    return ans;
}

int main(){

    vector<int> vec;
    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vec.push_back(a);
    }

    vector<int> res = majorityElementO(vec, n);
    for(auto it: res){
        cout<<it<<" ";
    }
    
    
    return 0;
}
