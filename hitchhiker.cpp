#include <bits/stdc++.h>
using namespace std;

void pickHitchhiker(vector<int> &index, int n)
{
    int sampleSize = n / 2;
    int first = -1;
    int second = -1;
    int BestPretiest = -1;
    int secondPrettiest = -1;
    for (int i = 0; i < sampleSize; i++)
    {
        if (index[i] > secondPrettiest)
        {
            secondPrettiest = index[i];
            second = i;
        }
    }
    for (int j = sampleSize; j < n; j++)
    {
        if (index[j] > secondPrettiest)
        {
            BestPretiest = index[j];
            first = j;
            break;
        }
    }

    if (first <= second)
    {
        cout << "No hitchhiker is choosed!!" << endl;
    }
    else
    {
        cout << "Hitchhikker is picked at: " << first << " and the prettiness index is: " << index[first] << endl;
    }
}

int main()
{

    random_device rd;
    mt19937 generator(rd());
    vector<int> index;
    int n;
    cout << "Enter the number of the hitchhiker present: ";
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        index.push_back(i);
    }

    shuffle(index.begin(), index.end(), generator);
    cout << endl;
    pickHitchhiker(index, n);
    return 0;
}