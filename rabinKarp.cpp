#include <bits/stdc++.h>
using namespace std;

void rabinKarp(string s, string pattern, int q)
{
    vector<int> matchedIndex;
    vector<int> potentialMatchedIndex;
    int mod = stoi(pattern) % q;
    for (int i = 0; i < s.size(); i++)
    {
        string str = s.substr(i, pattern.size());
        int pat = stoi(str);
        if (pat % q == mod)
        {
            if (str == pattern)
            {
                matchedIndex.push_back(i);
            }
            else
            {
                potentialMatchedIndex.push_back(i);
            }
        }
    }
    if (matchedIndex.empty())
    {
        cout << "There is no matching found!!!";
    }
    else
    {
        cout << "The matches are found at these corrosponding indexes: ";
        for (auto it : matchedIndex)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << "The number of spurious hit: " << potentialMatchedIndex.size() << endl;
}

int main()
{
    string s;
    cout << "Enter the string(only integer value): ";
    cin >> s;

    string pattern;
    cout << "Enter the pattern(only integer value): ";
    cin >> pattern;

    int q;
    cout << "Enter a prime no: ";
    cin >> q;

    rabinKarp(s, pattern, q);
    return 0;
}