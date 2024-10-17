#include <bits/stdc++.h>
using namespace std;

struct Person
{
    vector<int> preferences;
    int currentPartner = -1;
};

void galeShapely(vector<Person> &men, vector<Person> &women, int n)
{
    vector<int> propose(n, 0);

    while (true)
    {
        int freeman = -1;
        for (int i = 0; i < n; i++)
        {
            if (men[i].currentPartner == -1)
            {
                freeman = i;
                break;
            }
        }
        if (freeman == -1)
        {
            break;
        }

        int womenId = men[freeman].preferences[propose[freeman]];
        propose[freeman]++;

        if (women[womenId].currentPartner == -1)
        {
            women[womenId].currentPartner = freeman;
            men[freeman].currentPartner = womenId;
        }
        else
        {
            int currentPartner = women[womenId].currentPartner;
            int currentPartnerRank = distance(women[womenId].preferences.begin(), find(women[womenId].preferences.begin(), women[womenId].preferences.end(), currentPartner));
            int freemanRank = distance(women[womenId].preferences.begin(), find(women[womenId].preferences.begin(), women[womenId].preferences.end(), freeman));

            if (freemanRank < currentPartnerRank)
            {
                women[womenId].currentPartner = freeman;
                men[freeman].currentPartner = womenId;
                men[currentPartner].currentPartner = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "The Match for Man[" << i << "] -> Woman[" << men[i].currentPartner << "]" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of men and women is there: ";
    cin >> n;

    vector<Person> men(n);
    vector<Person> women(n);

    cout << "Enter the preferences for all the men" << endl;
    for (int i = 0; i < n; i++)
    {
        men[i].preferences.resize(n);
        cout << "Men[" << i << "] Prefenrences: ";
        for (int j = 0; j < n; j++)
        {
            cin >> men[i].preferences[j];
        }
    }
    cout << "Enter the preferences for all the women" << endl;
    for (int i = 0; i < n; i++)
    {
        women[i].preferences.resize(n);
        cout << "Women[" << i << "] Prefenrences: ";
        for (int j = 0; j < n; j++)
        {
            cin >> women[i].preferences[j];
        }
    }

    galeShapely(men, women, n);
    return 0;
}
