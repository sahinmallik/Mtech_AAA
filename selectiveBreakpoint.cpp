#include <bits/stdc++.h>
using namespace std;

int selectiveBreakpoints(int distance, int capacity, vector<int> breakpoints)
{
    vector<int> result;
    int numOfStation = 0;
    int current = 0;
    breakpoints.push_back(distance);
    int i = 0;
    while (current != distance)
    {
        int last = current;

        while (i < breakpoints.size() && breakpoints[i] <= current + capacity)
        {
            last = breakpoints[i];
            i++;
        }
        if (last == current)
        {
            return -1;
        }
        else if (last < distance)
        {
            result.push_back(last);
            numOfStation++;
        }
        current = last;
    }

    cout << "The number of breakpoint selected is: " << numOfStation << endl;
    cout << "The breakpoints are: ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

int main()
{
    int distance = 100;
    int gasCapacity = 18;
    vector<int> breakpoints = {2, 6, 9, 10, 20, 30, 40, 45, 50, 60, 70, 80, 95};
    selectiveBreakpoints(distance, gasCapacity, breakpoints);
    return 0;
}