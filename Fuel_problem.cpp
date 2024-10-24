#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minGasTankVolume(int n, int d, vector<int> &gasStations)
{
    int maxDistance = max(gasStations[0], d - gasStations[n - 1]); // distance from 0 to the first station or from the last station to d

    for (int i = 1; i < n; ++i)
    {
        maxDistance = max(maxDistance, gasStations[i] - gasStations[i - 1]);
    }

    return maxDistance * 2; // round trip distance
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, d;
        cin >> n >> d;

        vector<int> gasStations(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> gasStations[i];
        }

        cout << minGasTankVolume(n, d, gasStations) << endl;
    }

    return 0;
}
