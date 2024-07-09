// longest repeating character

#include<bits/stdc++.h>
using namespace std;

int longestRepeating(string str, int k){
    int maxLen = 0;

    for(int i=0;i<str.size();i++){
        int maxf = 0;
        int hash[26] = {0};
        for(int j=i;j<str.size();j++){
            hash[str[j]-'A']++;
            maxf = max(maxf, hash[str[j]-'A']);
            if((j-i+1)-maxf <= k){
                maxLen = max(maxLen, j-i+1);
            }
            else break;
        }
    }
    return maxLen;
}

int longestRepeating1(string str, int k){

    int maxLen = 0;
    int l = 0, r = 0;
    int n = str.size();
    int hash[26] = {0};
    int maxf = 0;

    while(r < n){
        hash[str[r]-'A']++;
        maxf = max(maxf, hash[str[r]-'A']);

        if((r-l+1)-maxf > k){ // while((r-l+1)-maxf > k){
            hash[str[l]-'A']--;
            // for(int i=0;i<26;i++){ maxf = max(maxf, hash[i]); }
            l++;
        }

        if((r-l+1)-maxf <= k){
            maxLen = max(maxLen, r-l+1);
        }

        r++;
    }

    return maxLen;
}

int main(){

    string str = "AABABBC"; // Output: 5

    int k; // k = 2
    cin>>k;
    cout<<longestRepeating1(str, k);

    return 0;
}