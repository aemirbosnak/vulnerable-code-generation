//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// Function to find the minimum number of coins needed to make change
int makeChange(int amount, int coins[], int n) {
    // Sort the coins in descending order
    qsort(coins, n, sizeof(int), compare);

    // Initialize the number of coins to 0
    int numCoins = 0;

    // Iterate over the coins
    for (int i = 0; i < n; i++) {
        // While the amount is greater than or equal to the current coin
        while (amount >= coins[i]) {
            // Subtract the current coin from the amount
            amount -= coins[i];

            // Increment the number of coins
            numCoins++;
        }
    }

    // Return the number of coins
    return numCoins;
}

// Main function
int main() {
    // Get the amount of change
    int amount;
    printf("Enter the amount of change: ");
    scanf("%d", &amount);

    // Get the number of coins
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    // Get the coins
    int coins[n];
    printf("Enter the coins: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Find the minimum number of coins needed to make change
    int numCoins = makeChange(amount, coins, n);

    // Print the minimum number of coins
    printf("The minimum number of coins needed to make change is: %d\n", numCoins);

    return 0;
}