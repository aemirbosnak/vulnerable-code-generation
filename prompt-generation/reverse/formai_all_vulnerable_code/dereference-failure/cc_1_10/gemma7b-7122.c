//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a coin
struct Coin
{
    int value;
    struct Coin* next;
};

// Function to insert a coin into a linked list
void insertCoin(struct Coin** head, int value)
{
    struct Coin* newCoin = malloc(sizeof(struct Coin));
    newCoin->value = value;
    newCoin->next = NULL;

    if (*head == NULL)
    {
        *head = newCoin;
    }
    else
    {
        (*head)->next = newCoin;
    }
}

// Function to find the minimum coins required to get a given change
int findCoins(struct Coin* head, int change)
{
    int coins = 0;
    struct Coin* currentCoin = head;

    while (currentCoin)
    {
        if (currentCoin->value >= change)
        {
            coins++;
            change -= currentCoin->value;
        }
        currentCoin = currentCoin->next;
    }

    return coins;
}

int main()
{
    struct Coin* head = NULL;
    insertCoin(&head, 1);
    insertCoin(&head, 2);
    insertCoin(&head, 3);
    insertCoin(&head, 4);
    insertCoin(&head, 5);

    int change = 11;
    int coins = findCoins(head, change);

    printf("The number of coins required to get a change of %d is: %d\n", change, coins);

    return 0;
}