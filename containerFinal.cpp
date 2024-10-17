#include <iostream>
#include <vector>
#include <algorithm> // for sort()

using namespace std;

// Function to calculate the maximum number of containers that can be loaded
void maxContainers(vector<int> &weights, int capacity)
{
    // Sort the container weights in ascending order
    sort(weights.begin(), weights.end());

    int currentWeight = 0; // To track the total weight of loaded containers
    int count = 0;         // To track the number of containers loaded
    vector<int> result;
    // Output the result

    // Iterate through each container
    for (int i = 0; i < weights.size(); ++i)
    {
        // If adding the current container does not exceed the capacity
        if (currentWeight + weights[i] <= capacity)
        {
            currentWeight += weights[i]; // Add the weight of the container
            result.push_back(weights[i]);
            count++; // Increment the count of containers loaded
        }
        else
        {
            break; // If capacity is exceeded, stop loading
        }
    }

    cout << "Maximum number of containers that can be loaded: " << count << endl; // Return the total number of containers loaded
    cout << "The container capacities are";
    for (auto it : result)
    {
        cout << it << " ";
    }
}

int main()
{
    // Example: Weights of the containers and the capacity of the ship
    vector<int> weights = {40, 80, 50, 30, 90}; // Container weights
    int capacity = 120;                         // Ship's capacity

    // Calculate the maximum number of containers
    maxContainers(weights, capacity);

    return 0;
}
