#include <bits/stdc++.h>
using namespace std;

void medicineBottle(vector<int> bottle, int n)
{
    int numofbottle = INT_MAX;
    int excess = 0;
    vector<int> quantity(bottle.size(), 0);

    for (int a = 0; a <= n % bottle[0]; a++)
    {
        for (int b = 0; b <= n % bottle[1]; b++)
        {
            for (int c = 0; c <= n % bottle[2]; c++)
            {
                for (int d = 0; d <= n % bottle[3]; d++)
                {
                    for (int e = 0; e <= n % bottle[4]; e++)
                    {
                        excess = a * bottle[0] + b * bottle[1] + c * bottle[2] + d * bottle[3] + e * bottle[4];

                        // Check if the sum is at least 'n' and uses the fewest bottles
                        if (excess >= n && (a + b + c + d + e) < numofbottle)
                        {
                            numofbottle = a + b + c + d + e;
                            quantity = {a, b, c, d, e};
                        }
                    }
                }
            }
        }
    }

    cout << "The number of bottles required for the Medicine is: " << numofbottle << endl;
    for (int i = 0; i < bottle.size(); i++)
    {
        if (quantity[i] > 0)
        {
            cout << bottle[i] << "ml x " << quantity[i] << endl;
        }
    }
}

int main()
{
    vector<int> bottle = {240, 130, 100, 60, 10};
    int n = 100;
    medicineBottle(bottle, n);
    return 0;
}
