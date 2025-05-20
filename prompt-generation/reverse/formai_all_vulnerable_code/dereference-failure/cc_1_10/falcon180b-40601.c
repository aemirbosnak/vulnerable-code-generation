//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 1000
#define MAX_VALUE 1000

// Function to find the minimum number of coins required to make a given value
int findMinCoins(int value, int coins[], int numCoins) {
    int i, minCoins = MAX_COINS;

    // Start with the highest value coin
    for (i = numCoins - 1; i >= 0; i--) {
        while (value >= coins[i]) {
            value -= coins[i];
        }
    }

    // If the value is still greater than zero, we cannot make it
    if (value > 0) {
        return MAX_COINS;
    }

    // Otherwise, return the number of coins used
    return minCoins;
}

int main() {
    int value, numCoins, i, coins[MAX_COINS];

    // Get the value and number of coins from the user
    printf("Enter the value: ");
    scanf("%d", &value);
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);

    // Get the values of the coins from the user
    printf("Enter the values of the coins: ");
    for (i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    // Find the minimum number of coins required to make the given value
    int minCoins = findMinCoins(value, coins, numCoins);

    // Print the result
    if (minCoins == MAX_COINS) {
        printf("Cannot make the value with the given coins.\n");
    } else {
        printf("Minimum number of coins required: %d\n", minCoins);
    }

    return 0;
}