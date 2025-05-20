//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 5

void printCoins(int coins[], int n)
{
    printf("Coins: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", coins[i]);
    }
    printf("\n");
}

int main()
{
    int coins[MAX_COINS] = {1, 2, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    int target = 63;

    printf("Target amount: %d\n", target);

    int dp[MAX_COINS][target + 1];

    for (int i = 0; i <= target; i++)
    {
        dp[0][i] = i % coins[0] == 0? i / coins[0] : -1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (j >= coins[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (dp[i][j] == -1 && j + coins[i] <= target)
                {
                    dp[i][j] = dp[i - 1][j + coins[i]];
                }
            }
        }
    }

    int result = 0;
    int k = n - 1;

    while (k >= 0 && dp[k][target]!= -1)
    {
        result += dp[k][target];
        k--;
    }

    if (result == -1)
    {
        printf("No combination of coins found.\n");
    }
    else
    {
        printf("Minimum number of coins: %d\n", result);
        printCoins(coins, result);
    }

    return 0;
}