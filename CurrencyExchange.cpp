#include <bits/stdc++.h>
using namespace std;

vector<int> denomination = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
vector<int> result;

void minExchange(int n)
{
    int length = denomination.size();
    for (int i = length - 1; i >= 0; i--)
    {
        while (n >= denomination[i])
        {
            result.push_back(denomination[i]);
            n = n - denomination[i];
        }
    }
    cout << "The Minimum denominaion that will be needed: ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the amount: ";
    cin >> n;
    minExchange(n);
    return 0;
}