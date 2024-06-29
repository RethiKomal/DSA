#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSumB(vector<int> &arr, int n){

    set<vector<int>> st;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum = arr[i]+arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    
                    if(sum == 0){
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    ans.assign(st.begin(), st.end());
    return ans;
    
}

vector<vector<int>> fourSumM(vector<int> &arr, int n){
    
    set<vector<int>> st;
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){

            set<int> hashset;

            for(int k=j+1;k<n;k++){
                
                int rem = -(arr[i]+arr[j]+arr[k]);

                if(hashset.find(rem) != hashset.end()){
                    vector<int> temp = {arr[i], arr[j], arr[k], rem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            hashset.insert(arr[k]);
            }
        }
    }

    ans.assign(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSumO(vector<int> &arr, int n){
    
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){

        if(i!=0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(arr[j]==arr[j-1]) continue;

            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = arr[i]+arr[j]+arr[k]+arr[l];
                if(sum > 0){
                    l--;
                }

                else if(sum < 0){
                    k++;
                }

                else{
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(k<l && arr[l] == arr[l+1]) l--;
                }
            }
        }
    }

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

    vector<vector<int>> res = fourSumO(vec, n);
    
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}
