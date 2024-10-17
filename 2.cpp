#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check if a graph is bipartite using BFS
bool isBipartite(int V, const vector<vector<int>> &adj)
{
    vector<int> color(V, -1); // Color array to store colors of vertices (initialized to -1)

    for (int i = 0; i < V; ++i)
    {
        if (color[i] == -1)
        { // If not colored, start a BFS
            queue<int> q;
            q.push(i);
            color[i] = 0; // Start with color 0

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node])
                {
                    if (color[neighbor] == -1)
                    { // If not colored, color with opposite color
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node])
                    {
                        return false; // If neighbor has the same color, not bipartite
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int V = 4; // Number of vertices
    vector<vector<int>> adj = {
        {0, 1}, // Edges from vertex 0
        {0, 2}, // Edges from vertex 1
        {0, 3}, // Edges from vertex 2
        {1, 2}  // Edges from vertex 3
    };

    if (isBipartite(V, adj))
        cout << "The graph is bipartite.\n";
    else
        cout << "The graph is not bipartite.\n";

    return 0;
}
