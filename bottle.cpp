#include <bits/stdc++.h>
using namespace std;

void medicineBottle(vector<int> &bottle, int n)
{
    int numofbottle = 0;
    vector<int> quantity(bottle.size(), 0);
    sort(bottle.begin(), bottle.end());
    for (int i = bottle.size() - 1; i >= 0; i--)
    {

        quantity[i] = n / bottle[i];
        numofbottle += quantity[i];
        n %= bottle[i];
    }

    if (n != 0)
    {

        for (int i = 0; i < bottle.size(); i++)
        {
            if (bottle[i] >= n)
            {
                quantity[i]++;
                numofbottle++;
                break;
            }
        }
    }

    cout << "The number of bottles required for the Medicine is: " << numofbottle << endl;
    for (int i = 0; i < bottle.size(); i++)
    {
        if (quantity[i] > 0)
        {
            cout << bottle[i] << " capacity bottle x " << quantity[i] << endl;
        }
    }
}

int main()
{
    vector<int> bottle = {10, 60, 130, 240, 100};
    int n;
    cout << "Enter the total number of tablets: ";
    cin >> n;

    medicineBottle(bottle, n);
    return 0;
}
