//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a coin
struct Coin {
    int value;
    struct Coin* next;
};

// Function to compare two coins
int compareCoins(struct Coin* a, struct Coin* b) {
    return a->value - b->value;
}

// Function to insert a coin into a linked list
void insertCoin(struct Coin** head, int value) {
    struct Coin* newCoin = (struct Coin*)malloc(sizeof(struct Coin));
    newCoin->value = value;
    newCoin->next = NULL;

    if (*head == NULL) {
        *head = newCoin;
    } else {
        struct Coin* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newCoin;
    }
}

// Function to find the maximum sum of coins
int findMaxSum(struct Coin* head) {
    int sum = 0;
    struct Coin* currentCoin = head;

    while (currentCoin) {
        sum += currentCoin->value;
        currentCoin = currentCoin->next;
    }

    return sum;
}

int main() {
    struct Coin* head = NULL;

    // Insert coins into the linked list
    insertCoin(&head, 1);
    insertCoin(&head, 2);
    insertCoin(&head, 3);
    insertCoin(&head, 4);
    insertCoin(&head, 5);

    // Find the maximum sum of coins
    int maxSum = findMaxSum(head);

    // Print the maximum sum
    printf("The maximum sum of coins is: %d", maxSum);

    return 0;
}