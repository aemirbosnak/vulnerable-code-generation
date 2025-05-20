//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a coin
typedef struct Coin {
    int value;
    struct Coin* next;
} Coin;

// Function to insert a coin into the linked list
void insertCoin(Coin* head, int value) {
    Coin* newCoin = malloc(sizeof(Coin));
    newCoin->value = value;
    newCoin->next = NULL;

    if (head == NULL) {
        head = newCoin;
    } else {
        newCoin->next = head;
        head = newCoin;
    }
}

// Function to find the minimum coins required to get a given change
int findMinimumCoins(Coin* head, int target) {
    int coins = 0;
    Coin* currentCoin = head;

    while (currentCoin) {
        int coinValue = currentCoin->value;
        coins += target / coinValue;
        target %= coinValue;
        currentCoin = currentCoin->next;
    }

    return coins;
}

int main() {
    Coin* head = NULL;
    insertCoin(head, 1);
    insertCoin(head, 2);
    insertCoin(head, 3);
    insertCoin(head, 4);
    insertCoin(head, 5);

    int target = 11;
    int coins = findMinimumCoins(head, target);

    printf("The minimum coins required are: %d", coins);

    return 0;
}