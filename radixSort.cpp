#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr, int n, int exp)
{
    vector<vector<int>> count(10);
    vector<int> output(n);

    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int digit = (a / exp) % 10;
        count[digit].push_back(arr[i]);
    }

    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        for (auto it : count[i])
        {
            output[index] = it;
            index++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr, int n)
{
    int maxElement = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxElement / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Original: ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    radixSort(arr, n);

    cout << "Sorted: ";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
