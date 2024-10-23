#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr)
{
    if (arr.empty())
        return;

    int maxElement = *max_element(arr.begin(), arr.end());
    vector<vector<int>> count(maxElement + 1);

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]].push_back(arr[i]);
    }

    int index = 0;
    for (int i = 0; i <= maxElement; i++)
    {
        for (auto it : count[i])
        {
            arr[index] = it;
            index++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of the element: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    countingSort(arr);

    cout << "Sorted array:   ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
