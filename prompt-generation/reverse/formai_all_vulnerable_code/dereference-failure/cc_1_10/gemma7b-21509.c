//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a coin
typedef struct Coin
{
    int value;
    struct Coin* next;
} Coin;

// Function to insert a coin into a linked list
void insertCoin(Coin** head, int value)
{
    Coin* newCoin = (Coin*)malloc(sizeof(Coin));
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

// Function to find the maximum number of coins that can be taken
int findMaxCoins(Coin* head)
{
    int coins = 0;
    Coin* currentCoin = head;

    while (currentCoin)
    {
        coins += currentCoin->value;
        currentCoin = currentCoin->next;
    }

    return coins;
}

int main()
{
    Coin* head = NULL;
    insertCoin(&head, 1);
    insertCoin(&head, 2);
    insertCoin(&head, 3);
    insertCoin(&head, 4);
    insertCoin(&head, 5);

    int maxCoins = findMaxCoins(head);

    printf("The maximum number of coins that can be taken is: %d\n", maxCoins);

    return 0;
}