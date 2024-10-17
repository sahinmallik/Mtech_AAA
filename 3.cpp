#include <bits/stdc++.h>
using namespace std;

// Function to find the neighbors of a given subset S
set<int> find_neighbors(const vector<vector<int>> &adj, const set<int> &S)
{
    set<int> neighbors;
    for (int u : S)
    {
        for (int v : adj[u])
        {
            if (S.find(v) == S.end())
            { // Only add if v is not in S
                neighbors.insert(v);
            }
        }
    }
    return neighbors;
}

// Function to calculate the deficiency for a given subset S
int deficiency(const vector<vector<int>> &adj, const set<int> &S)
{
    int s_size = S.size();
    int ns_size = find_neighbors(adj, S).size();
    return max(0, s_size - ns_size); // Deficiency is max(0, |S| - |N(S)|)
}

// Helper function to generate all non-empty subsets of vertices
void generate_subsets(const vector<vector<int>> &adj, const vector<int> &vertices,
                      set<int> &current_set, int index, int &max_def)
{
    // If the subset is non-empty, calculate its deficiency
    if (!current_set.empty())
    {
        max_def = max(max_def, deficiency(adj, current_set));
    }

    // Base case: If we've considered all vertices, return
    if (index == vertices.size())
    {
        return;
    }

    // Exclude the current vertex from the subset and recurse
    generate_subsets(adj, vertices, current_set, index + 1, max_def);

    // Include the current vertex in the subset and recurse
    current_set.insert(vertices[index]);
    generate_subsets(adj, vertices, current_set, index + 1, max_def);

    // Backtrack: Remove the vertex after recursion
    current_set.erase(vertices[index]);
}

// Function to find the maximum deficiency over all subsets
int max_deficiency(const vector<vector<int>> &adj, int n)
{
    vector<int> vertices(n);
    iota(vertices.begin(), vertices.end(), 0); // Fill with {0, 1, ..., n-1}
    set<int> current_set;
    int max_def = 0;

    // Generate all subsets and calculate max deficiency
    generate_subsets(adj, vertices, current_set, 0, max_def);

    return max_def;
}

// Function to calculate the matching number using the deficiency test
int matching_number(const vector<vector<int>> &adj, int n)
{
    int delta_G = max_deficiency(adj, n);
    return (n - delta_G) / 2;
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);
    cout << "Enter the edges (u v) where vertices are 0-indexed:\n";
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_matching = matching_number(adj, n);
    cout << "The matching number of the graph is: " << max_matching << endl;

    return 0;
}
