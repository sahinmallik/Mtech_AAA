/*A large ship is to be loaded with cargo. The cargo is containerized, and all containers are the same size. Different containers may have different weights. Let wi be the weight of the I th container, 1 ≤ i ≤ n. The cargo capacity of the ship is c. Propose a solution to load the ship with maximum number of containers.*/

#include <bits/stdc++.h>
using namespace std;

void maxContainer(vector<int> &weights, int capacity)
{
    vector<int> result;
    sort(weights.begin(), weights.end());
    int currentWeight = 0;
    int count = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (currentWeight + weights[i] <= capacity)
        {
            currentWeight = currentWeight + weights[i];
            result.push_back(weights[i]);
            count++;
        }
        else
        {
            break;
        }
    }
    cout << "The no of container: " << count << endl;
    cout << "The containers are: ";
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> weights = {40, 80, 50, 30, 100};
    int capacity;
    cout << "Enter the capacity of the cargo: ";
    cin >> capacity;
    maxContainer(weights, capacity);
    return 0;
}
