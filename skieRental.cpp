// first take the rent for the K days and then by at the K+1 day.

// renting cost is 1$
//  buying cost is 30$
//  pick a random amount of days till the season will exist.

#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void skiRental(int duration, int buying, int renting)
{
    // objective is to minimise the cost of using the ski.
    // days*renting <= buying;
    // days <= buying/renting;
    // days*renting>buying then buy the ski and exit the loop;
    int cost = 0;
    for (int i = 1; i <= duration; i++)
    {
        if (i * renting <= buying)
        {
            cost += renting;
        }
        else
        {
            cost += buying;
            break;
        }
    }

    cout << "The Cost of the using of the ski for the entire season will be: " << cost;
    cout << endl;
}

int main()
{
    time_t now = time(0);
    tm *localTime = localtime(&now);
    int currentSecond = localTime->tm_sec;

    srand(currentSecond);

    int buying;
    int renting;
    cout << "Enter the cost of the buying of the skies: ";
    cin >> buying;
    cout << "Enter the cost of the per day renting: ";
    cin >> renting;
    int duration = rand() % 130;
    skiRental(duration, buying, renting);
    return 0;
}