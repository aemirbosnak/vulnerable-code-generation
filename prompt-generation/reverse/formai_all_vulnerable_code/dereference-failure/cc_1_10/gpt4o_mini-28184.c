//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// A whimsical function to display coins
void displayCoins(int coins[], int n){
    printf("Coins used:\n");
    for (int i = 0; i < n; i++) {
        if (coins[i] > 0) {
            printf("Coin of denomination %d used %d time(s)\n", i, coins[i]);
        }
    }
}

// The greedy algorithm to find the minimum coins needed
int greedyChange(int money, int denominations[], int size, int coins[]) {
    int count = 0; // Counting the total coins used
    
    // Dance through each denomination
    for (int i = 0; i < size; i++) {
        // While the coin can fit into the monetary pouch
        while (money >= denominations[i]) {
            money -= denominations[i]; // Deduct coin value from money
            coins[i]++;  // Count the coin used
            count++;     // Increment the overall count
        }
    }
    
    return count; // Return total coins utilized in our treasure hunt
}

int main() {
    // Ahoy! The array of our wonderful coin denominations
    int denominations[] = {100, 50, 25, 10, 5, 1}; // In cents
    int size = sizeof(denominations) / sizeof(denominations[0]);
    
    // Where to place our findings
    int *coins = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        coins[i] = 0; // Initialize our coin counts
    }

    // Time for our daring quest! How much treasure are we seeking?
    int money;
    printf("Enter an amount in cents to change: ");
    scanf("%d", &money);
    
    // The magic begins! Off we go!
    int totalCoins = greedyChange(money, denominations, size, coins);
    
    // Be amazed by the treasures gathered!
    printf("Minimum coins needed: %d\n", totalCoins);
    displayCoins(coins, size);
    
    // Return our borrowed treasure
    free(coins);
    return 0;
}