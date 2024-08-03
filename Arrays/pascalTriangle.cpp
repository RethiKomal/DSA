#include <bits/stdc++.h>
using namespace std;

// Varient - 1:
int NCR(int row, int col){

    int ans = 1;
    for(int i=1;i<col;i++){
        ans *= (row-i);
        ans /= (i);
    }

    return ans;
}

// Varient - 2:
vector<int> generateRow(int row){

    vector<int> ans;

    int res = 1;
    ans.push_back(1);
    for(int col=1;col<row;col++){
        res *= (row-col);
        res /= (col);
        ans.push_back(res);
    }

    return ans;
}

// Varient - 3:
vector<vector<int>> pascalTriangle(int row, int col){
    vector<vector<int>> ans;

    for(int i=1;i<=row;i++){
        vector<int> temp = generateRow(i);
        ans.push_back(temp);
    }

    return ans;
}

int main(){

    int row, col;
    cin>>row>>col;

    int res = NCR(row, col);
    // cout<<res;

    vector<int> ans = generateRow(row);

    /*
    for(auto i: ans){
        cout<<i<<" ";
    }
    */

    vector<vector<int>> vec =  pascalTriangle(row, col);
    for(auto it : vec){
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}
