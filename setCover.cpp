#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> selected;

int setCover(const vector<int> &universal, vector<vector<int>> &subset, vector<int> &cost)
{

    set<int> universalSet(universal.begin(), universal.end());

    while (universalSet.size() > 0)
    {
        vector<double> gain;

        for (int i = 0; i < subset.size(); i++)
        {

            set<int> subsetSet(subset[i].begin(), subset[i].end());
            vector<int> intersection;

            set_intersection(subsetSet.begin(), subsetSet.end(), universalSet.begin(), universalSet.end(),
                             back_inserter(intersection));

            if (intersection.empty())
            {
                gain.push_back(numeric_limits<double>::infinity());
            }
            else
            {
                gain.push_back(cost[i] / intersection.size());
            }
        }

        auto selectedSubset = min_element(gain.begin(), gain.end()) - gain.begin();

        for (int elem : subset[selectedSubset])
        {
            universalSet.erase(elem);
        }

        selected.push_back(subset[selectedSubset]);

        subset.erase(subset.begin() + selectedSubset);
        cost.erase(cost.begin() + selectedSubset);
    }

    for (const auto &it : selected)
    {
        cout << "{ ";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "}\n";
    }
    return 0;
}

int main()
{
    vector<int> universal = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> subset = {{1, 2, 3, 4}, {1, 5}, {2, 5}, {3, 6}};
    vector<int> cost = {2, 3, 2, 2};
    setCover(universal, subset, cost);
    return 0;
}
