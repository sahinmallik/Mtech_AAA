#include <bits/stdc++.h>
using namespace std;

int matchingNumber(vector<vector<int>> &adj, int V);
int maxDeficiency(vector<vector<int>> &adj, int V);
void generateSubset(vector<vector<int>> &adj, vector<int> &vertices, set<int> &current_subset, int index, int &maxDef);
int deficiency(vector<vector<int>> &adj, set<int> &current_subset);
set<int> findNeighbour(vector<vector<int>> &adj, set<int> &current_subset);

int main()
{
    int V;
    cout << "Enter the number of the vertices: ";
    cin >> V;
    int E;
    cout << "Enter the number of the edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter the Edges (Indexing starts from 0):" << endl;
    for (int i = 0; i < E; i++)
    {
        cout << "Edge " << i + 1 << ": ";
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Display the adjacency list
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }

    int matching_number = matchingNumber(adj, V);
    if (matching_number >= 0)
    {
        cout << "The matching number is: " << matching_number << endl;
    }
    else
    {
        cout << "Error: Matching number could not be calculated." << endl;
    }

    return 0;
}

int matchingNumber(vector<vector<int>> &adj, int V)
{
    int deficiency_value = maxDeficiency(adj, V);
    return (V - deficiency_value) / 2;
}

int maxDeficiency(vector<vector<int>> &adj, int V)
{
    vector<int> vertices(V);
    iota(vertices.begin(), vertices.end(), 0); // Initialize vertices with 0, 1, ..., V-1

    set<int> current_subset;
    int maxDef = 0;

    generateSubset(adj, vertices, current_subset, 0, maxDef);
    return maxDef;
}

void generateSubset(vector<vector<int>> &adj, vector<int> &vertices, set<int> &current_subset, int index, int &maxDef)
{
    if (index == vertices.size())
    {
        maxDef = max(maxDef, deficiency(adj, current_subset));
        return;
    }

    // Exclude the current vertex
    generateSubset(adj, vertices, current_subset, index + 1, maxDef);

    // Include the current vertex
    current_subset.insert(vertices[index]);
    generateSubset(adj, vertices, current_subset, index + 1, maxDef);
    current_subset.erase(vertices[index]); // Backtrack
}

int deficiency(vector<vector<int>> &adj, set<int> &current_subset)
{
    int subsetSize = current_subset.size();
    int neighbourSize = findNeighbour(adj, current_subset).size();
    return max(0, subsetSize - neighbourSize);
}

set<int> findNeighbour(vector<vector<int>> &adj, set<int> &current_subset)
{
    set<int> neighbour;
    for (auto u : current_subset)
    {
        for (auto v : adj[u])
        {
            neighbour.insert(v);
        }
    }
    return neighbour;
}
