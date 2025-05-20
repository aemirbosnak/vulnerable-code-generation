//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a coin
struct coin {
    int value;
    struct coin* next;
};

// Function to insert a coin into a linked list
void insertCoin(struct coin** head, int value) {
    struct coin* newCoin = (struct coin*)malloc(sizeof(struct coin));
    newCoin->value = value;
    newCoin->next = NULL;

    if (*head == NULL) {
        *head = newCoin;
    } else {
        (*head)->next = newCoin;
    }
}

// Function to find the total value of coins in a linked list
int findTotalValue(struct coin* head) {
    int totalValue = 0;

    while (head) {
        totalValue += head->value;
        head = head->next;
    }

    return totalValue;
}

int main() {
    // Create a linked list of coins
    struct coin* head = NULL;

    // Insert some coins into the list
    insertCoin(&head, 1);
    insertCoin(&head, 2);
    insertCoin(&head, 3);
    insertCoin(&head, 4);
    insertCoin(&head, 5);

    // Find the total value of the coins in the list
    int totalValue = findTotalValue(head);

    // Print the total value of the coins
    printf("The total value of the coins in the list is: %d", totalValue);

    return 0;
}