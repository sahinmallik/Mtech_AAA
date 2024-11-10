#include <bits/stdc++.h>

using namespace std;

void computePrefixFunction(const string &p, vector<int> &prefix) {
    int m = p.size();
    prefix[0] = 0; 

    for (int i = 1; i < m; ++i) {
        int j = prefix[i - 1];
        while (j > 0 && p[j] != p[i]) {
            j = prefix[j - 1];  
        }
        if (p[j] == p[i]) {
            j++;
        }
        prefix[i] = j;  
    }
}

void kmp(const string &s, const vector<int> &prefix, const string &p) {
    vector<int> matches;
    int i = 0, n = s.size(), m = p.size();

    while (i <= n - m) {
        int k = 0; 
        for (int j = 0; j < m; j++) {
            if (s[i + j] == p[j]) {
                k++;
            } else {
                break;
            }
        }
        if (k == m) {
            matches.push_back(i); 
        }
        int shift = (k > 0) ? k - prefix[k - 1] : 1;
        i += shift;  
    }

    if (matches.empty()) {
        cout << "No match is found!" << endl;
    } else {
        cout << "The matches are found at these corresponding indices: ";
        for (auto it : matches) {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    string p;
    cout << "Enter the pattern: ";
    cin >> p;

    vector<int> prefix(p.size());
    computePrefixFunction(p, prefix);
    kmp(s, prefix, p);
    
    cout << "Prefix function: ";
    for (auto it : prefix) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

