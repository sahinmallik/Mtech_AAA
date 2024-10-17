#include <bits/stdc++.h>
using namespace std;

int min_refills(int distance, int tank_capacity, std::vector<int> stations)
{
    int num_refills = 0;
    int current_position = 0;

    stations.push_back(distance);
    vector<int> breakpoint;
    sort(stations.begin(), stations.end());

    size_t i = 0;

    while (current_position != distance)
    {
        int last_position = current_position;

        while (i < stations.size() && stations[i] <= current_position + tank_capacity)
        {
            last_position = stations[i];
            i++;
        }

        if (last_position == current_position)
        {
            return -1;
        }

        if (last_position < distance)
        {
            breakpoint.push_back(last_position);
            num_refills++;
        }

        current_position = last_position;
    }
    cout << "Break points selected:";
    for (int i = 0; i < breakpoint.size(); i++)
    {
        cout << breakpoint[i] << " ";
    }
    cout << "\n number of break points: " << num_refills;
}

int main()
{
    int distance = 600;
    int tank_capacity = 200;
    std::vector<int> stations;
    stations.push_back(100);
    stations.push_back(200);
    stations.push_back(300);
    stations.push_back(400);
    stations.push_back(500);
    min_refills(distance, tank_capacity, stations);

    return 0;
}
