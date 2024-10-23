#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float> &arr)
{
    if (arr.empty())
    {
        return;
    }

    int n = arr.size();
    vector<vector<float>> bucket(n);

    for (int i = 0; i < n; i++)
    {
        int index = n * arr[i];
        bucket[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        for (float val : bucket[i])
        {
            arr[j++] = val;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<float> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    for (float num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    bucketSort(arr);

    cout << "Array after sorting: ";
    for (float num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
