//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void printShockMessage(int numCoins, int *coins, int amount) {
    printf("\n--- Shock Alert! ---\n");
    printf("To make the amount of %d, \n", amount);
    printf("You would only need %d coins!\n", numCoins);
    printf("Which gems are we using?\n");
    for (int i = 0; i < numCoins; i++) {
        printf("Coin of denomination: %d\n", coins[i]);
    }
    printf("--- End of Shock! ---\n");
}

void findMinCoins(int *coins, int numCoins, int amount) {
    int *result = (int *)malloc(numCoins * sizeof(int));
    int currentAmount = amount;
    int totalCoins = 0;

    for (int i = numCoins - 1; i >= 0; i--) {
        while (currentAmount >= coins[i]) {
            currentAmount -= coins[i];
            result[totalCoins++] = coins[i];
        }
    }

    if (currentAmount != 0) {
        printf("Unfortunately, it's impossible to form the amount %d with the given coins.\n", amount);
    } else {
        printShockMessage(totalCoins, result, amount);
    }

    free(result);
}

int main() {
    int coins[] = {1, 3, 4};
    int amount = 6;
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    printf("Welcome to the Coin Shockulator!\n");
    printf("We're about to calculate the minimum coins needed for the amount: %d\n", amount);
    
    findMinCoins(coins, numCoins, amount);

    // Adding random unexpected elements
    printf("\n---- SURPRISE! ----\n");
    printf("What if we had to do this for more amounts? Let's extend the shock:\n");

    int amounts[] = {2, 8, 9, 10};
    int numAmounts = sizeof(amounts) / sizeof(amounts[0]);
    
    for (int i = 0; i < numAmounts; i++) {
        printf("Calculating for amount: %d\n", amounts[i]);
        findMinCoins(coins, numCoins, amounts[i]);
    }

    printf("\n---- Shocking Summary Complete! ----\n");
    return 0;
}