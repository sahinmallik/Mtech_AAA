#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr)
{
    if (arr.empty())
        return;

    int maxElement = *max_element(arr.begin(), arr.end());
    vector<int> count(maxElement + 1, 0);
    for (int num : arr)
    {
        count[num]++;
    }

    int j = 0;
    for (int i = 0; i <= maxElement; i++)
    {
        while (count[i] > 0)
        {
            arr[j] = i;
            j++;
            count[i]--;
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
