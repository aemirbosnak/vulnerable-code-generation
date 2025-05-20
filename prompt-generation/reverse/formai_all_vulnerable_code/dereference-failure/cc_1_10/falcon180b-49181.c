//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM_COINS 5

// Function to find the minimum number of coins required to make a given amount
int findMinCoins(int amount, int coins[], int numCoins) {
    int i, minCoins = MAX_NUM_COINS;

    // Start with the largest coin and check if it can be used to make the amount
    for (i = numCoins - 1; i >= 0; i--) {
        if (amount >= coins[i]) {
            minCoins = amount / coins[i];
            break;
        }
    }

    return minCoins;
}

// Function to print the minimum number of coins required to make a given amount
void printMinCoins(int amount, int coins[], int numCoins) {
    int minCoins = findMinCoins(amount, coins, numCoins);

    if (minCoins == MAX_NUM_COINS) {
        printf("No solution exists for amount %d\n", amount);
    } else {
        printf("Minimum number of coins required to make amount %d: %d\n", amount, minCoins);
    }
}

int main() {
    int amount, coins[MAX_NUM_COINS], numCoins = 0;

    // Prompt user to enter the number of coins and their values
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);

    printf("Enter the values of the coins: ");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    // Prompt user to enter the amount to be made
    printf("Enter the amount to be made: ");
    scanf("%d", &amount);

    // Print the minimum number of coins required to make the given amount
    printMinCoins(amount, coins, numCoins);

    return 0;
}