//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a coin
typedef struct Coin
{
    int value;
    struct Coin* next;
} Coin;

// Function to insert a coin into a linked list
void insertCoin(Coin* head, int value)
{
    Coin* newCoin = malloc(sizeof(Coin));
    newCoin->value = value;
    newCoin->next = NULL;

    if (head == NULL)
    {
        head = newCoin;
    }
    else
    {
        head->next = newCoin;
    }
}

// Function to find the minimum coins required to get a given change
int findMinCoins(Coin* head, int change)
{
    int coins = 0;
    Coin* currentCoin = head;

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
    Coin* head = NULL;
    insertCoin(head, 1);
    insertCoin(head, 2);
    insertCoin(head, 3);
    insertCoin(head, 4);
    insertCoin(head, 5);

    int change = 9;
    int minCoins = findMinCoins(head, change);

    printf("The minimum coins required to get a change of %d is: %d\n", change, minCoins);

    return 0;
}