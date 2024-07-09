#include <iostream>
#include <string>
using namespace std;

int longestSubstring(string x) {
    int maxLen = 0;
    int n = x.size();

    for (int i = 0; i < n; i++) {
        int hash[255] = {0};
        for (int j = i; j < n; j++) {
            // cout << "i: " << i << ", j: " << j << ", maxLen: " << maxLen << endl;
            if (hash[x[j]] == 1) break;
            maxLen = max(maxLen, j - i + 1);
            hash[x[j]]++;
        }
    }

    return maxLen;
}

int longestSubstring1(string x){
    int maxLen = 1;
    int hash[255];

    for (int i = 0; i < 255; ++i) {
        hash[i] = -1;
    }
    int n = x.size();
    int l = 0, r = 0;

    while(r < n){
        if(hash[x[r]] != -1){
            if(hash[x[r]] >= l){
                l = hash[x[r]] + 1;
            }
        }

        maxLen = max(maxLen, r-l+1);
        hash[x[r]] = r;
        r++;

    }

    return maxLen;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Input string: " << str << endl;

    int len = longestSubstring1(str);
    cout << "Length of longest substring without duplicates: " << len << endl;

    return 0;
}
