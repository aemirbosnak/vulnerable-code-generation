//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_ITEMS 4

int numItems;
int numCoins[MAX_COINS];
int itemPrices[MAX_ITEMS];
int coinValues[MAX_COINS];

void generateRandomItems() {
    numItems = rand() % MAX_ITEMS + 1;
    for (int i = 0; i < numItems; i++) {
        itemPrices[i] = rand() % 100;
    }
}

void generateRandomCoins() {
    int numCoinsToGenerate = rand() % MAX_COINS + 1;
    for (int i = 0; i < numCoinsToGenerate; i++) {
        coinValues[i] = rand() % 100;
    }
}

int main() {
    srand(time(NULL));
    generateRandomItems();
    generateRandomCoins();

    int numCoinsUsed = 0;
    int totalPrice = 0;
    for (int i = 0; i < numItems; i++) {
        int price = itemPrices[i];
        int numCoinsNeeded = 0;
        for (int j = 0; j < numCoins; j++) {
            if (coinValues[j] > price) {
                numCoinsNeeded = 1;
                break;
            }
        }
        if (numCoinsNeeded > numCoinsUsed) {
            printf("Not enough coins to buy item %d!\n", i+1);
            return 1;
        }
        totalPrice += price;
        numCoinsUsed += numCoinsNeeded;
    }

    printf("Total price: $%d\n", totalPrice);
    return 0;
}