#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> set1 = {1, 2, 4, 6};
    vector<int> set2 = {2, 3};
    vector<int> set3 = {3, 4, 6, 5};
    vector<int> result;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(result));
    set_union(result.begin(), result.end(), set3.begin(), set3.end(), back_inserter(result));
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}