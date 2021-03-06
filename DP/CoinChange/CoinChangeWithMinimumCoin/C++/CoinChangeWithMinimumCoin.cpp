#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int m, int V)
{
    int table[V + 1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i = 1; i <= V; i++)
        table[i] = 100;

    // Compute minimum coins required for all
    // values from 1 to V

    for (int i = 1; i <= V; i++)
    {
        // Go through all coins smaller than i
        for (int j = 0; j < m; j++)

            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
    }
    return table[V];
}

int main()
{
    int coins[] = {9, 6, 5};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}
