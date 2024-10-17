#include <bits/stdc++.h>
using namespace std;

bool checkBipartite(const vector<vector<int>> &adj, int v, int E)
{
    vector<int> color(v, -1);

    for (int i = 0; i < v; ++i)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node])
                {
                    if (color[neighbor] == -1)
                    {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int V;
    cout << "Enter the number of the vertices of the graph: ";
    cin >> V;
    int E;
    cout << "Enter the number of the edges: ";
    cin >> E;
    vector<vector<int>> adj(V);
    cout << "Enter the edges of the graph(Indexing start from 0)" << endl;

    for (int i = 0; i < E; i++)
    {
        cout << "Edge " << i + 1 << ": ";
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < adj.size(); i++)
    {
        cout << i << ": ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
    if (checkBipartite(adj, V, E))
    {
        cout << "The Given Grpah is Bipartite" << endl;
    }
    else
    {
        cout << "The Given Graph is not Bipartite" << endl;
    }
    return 0;
}