//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void printResult(int *denominations, int *numCoins, int size) {
    printf("\n🌟 Here's the magical breakdown of your change! 🌟\n");
    for (int i = 0; i < size; i++) {
        if (numCoins[i] > 0) {
            printf("🔷 %d coin(s) of denomination %d\n", numCoins[i], denominations[i]);
        }
    }
    printf("💰 Total coins used: %d\n", numCoins[size]);
}

void coinChange(int amount, int *denominations, int size) {
    int *numCoins = (int *)malloc((size + 1) * sizeof(int));
    int totalCoins = 0;

    for (int i = 0; i < size; i++) {
        numCoins[i] = 0;
    }
    
    for (int i = 0; i < size; i++) {
        while (amount >= denominations[i]) {
            amount -= denominations[i];
            numCoins[i]++;
            totalCoins++;
        }
    }
    
    numCoins[size] = totalCoins; // store the total coins used
    printResult(denominations, numCoins, size);
    free(numCoins);
}

int main() {
    int denominations[] = {100, 50, 20, 10, 5, 1}; // denominations in cents
    int size = sizeof(denominations) / sizeof(denominations[0]);
    int amount;

    printf("🌈 Welcome to the Coin Change Calculator! 🌈\n");
    printf("✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦\n");
    printf("Please enter the amount in cents (whole number): ");
    scanf("%d", &amount);

    // Check if the entered amount is negative
    if (amount < 0) {
        printf("🚫 Oops! The amount cannot be negative. Please try again! 🚫\n");
        return 1;
    }

    // Call the coin change function
    coinChange(amount, denominations, size);
    printf("👋 Thank you for using the Coin Change Calculator! 👋\n");
    printf("✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦✦\n");

    return 0;
}