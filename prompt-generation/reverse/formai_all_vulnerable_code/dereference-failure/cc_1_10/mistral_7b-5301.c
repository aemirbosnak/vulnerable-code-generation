//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum number of coins required to make change
int minCoins(int amount, int coins[]) {
    int count = 0;
    int n = sizeof(coins) / sizeof(coins[0]);

    for (int i = 0; i < n; i++) {
        int coinsRequired = amount / coins[i];
        if (coinsRequired > 0) {
            count += coinsRequired;
            amount %= coins[i];
        }
    }

    return count;
}

// Function to print coins in a funny way
void printCoins(int coins[], int numCoins) {
    printf("Here is your change, monkey!\n");
    for (int i = 0; i < numCoins; i++) {
        int coin = coins[i];
        if (coin == 1)
            printf("Monkey banana %d cent\n", coin);
        else if (coin == 5)
            printf("Monkey coconut %d cents\n", coin);
        else if (coin == 10)
            printf("Monkey durian %d cents\n", coin);
        else if (coin == 25)
            printf("Monkey pineapple %d cents\n", coin);
        else if (coin == 50)
            printf("Monkey watermelon %d cents\n", coin);
        else if (coin == 100)
            printf("Monkey elephant %d cents\n", coin);
        else {
            printf("Monkey donkey %d cents (what the monkey???)\n", coin);
        }
    }
}

int main() {
    int amount = 47;
    int coins[] = {1, 5, 10, 25, 50, 100};

    int numCoins = minCoins(amount, coins);
    int change[numCoins];

    printf("You have given me %d cents, monkey.\n", amount);
    printCoins(coins, numCoins);

    int index = 0;
    for (int i = 0; i < numCoins; i++) {
        change[index++] = minCoins(amount, coins);
        amount -= change[index - 1];
    }

    printf("Here is your change, monkey!\n");
    printCoins(change, numCoins);

    return 0;
}