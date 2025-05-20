//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 10
#define MAX_ITEMS 5
#define MAX_VALUE 100

int main() {
    int numCoins[MAX_COINS], numItems[MAX_ITEMS], value[MAX_ITEMS];
    int n, m, i, j;

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    printf("Enter the number of items: ");
    scanf("%d", &m);

    printf("Enter the value of each item:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter the number of each type of coin:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &numCoins[i]);
    }

    int dp[m + 1][MAX_VALUE + 1];
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= MAX_VALUE; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 0; j <= MAX_VALUE; j++) {
            for (int k = 0; k < n; k++) {
                if (j >= value[i - 1]) {
                    int newValue = j - value[i - 1];
                    if (dp[i - 1][newValue]!= -1 && dp[i - 1][newValue] + numCoins[k] > dp[i][j]) {
                        dp[i][j] = dp[i - 1][newValue] + numCoins[k];
                    }
                }
            }
        }
    }

    printf("The minimum number of coins required is: %d\n", dp[m][MAX_VALUE]);

    return 0;
}