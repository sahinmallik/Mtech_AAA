#include <bits/stdc++.h>
using namespace std;
struct Interval
{
    char name;
    int start;
    int end;
};

bool sortEndTime(Interval a, Interval b)
{
    return (a.end < b.end);
}

void intervalScheduling(Interval arr[], int n)
{
    sort(arr, arr + n, sortEndTime);
    vector<Interval> result;

    for (int i = 0; i < n; i++)
    {
        int n = result.size();
        if (n == 0)
        {
            result.push_back(arr[i]);
        }
        else
        {
            if (result[n - 1].end < arr[i].start)
            {
                result.push_back(arr[i]);
            }
        }
    }

    for (auto it : result)
    {
        cout << it.name << " ";
    }
    cout << endl;
}

int main()
{

    Interval arr[] = {{'a', 3, 4},
                      {'b', 1, 4},
                      {'c', 2, 5},
                      {'d', 1, 2},
                      {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    intervalScheduling(arr, n);
    return 0;
}