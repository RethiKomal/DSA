#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervalsB(vector<vector<int>> &arr, int n){

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }

        for(int j=i+1;j<n;j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }

            else{
                break;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}

vector<vector<int>> mergeIntervalsO(vector<vector<int>> &arr, int n){
    
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){

        if(ans.empty() || ans.back()[1] < arr[i][0]){
            ans.push_back(arr[i]);
        }

        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

int main(){

    int n;
    vector<vector<int>> vec;
    cin>>n;

    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<2;j++){
            int a;
            cin>>a;
            temp.push_back(a);
        }

        vec.push_back(temp);
    }

    vector<vector<int>> ans;

    ans = mergeIntervalsO(vec, n);
    cout<<endl;
    cout<<"After merging the intervals:\n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<2;j++){
            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}
