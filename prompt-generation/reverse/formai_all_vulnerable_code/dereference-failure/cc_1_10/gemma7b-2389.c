//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAG_NUMBER 100
#define MAX_BAG_WEIGHT 50

typedef struct Bag
{
    int number;
    char *owner;
    int weight;
    struct Bag *next;
} Bag;

Bag *createBag(int number, char *owner, int weight)
{
    Bag *newBag = (Bag *)malloc(sizeof(Bag));
    newBag->number = number;
    newBag->owner = owner;
    newBag->weight = weight;
    newBag->next = NULL;

    return newBag;
}

void addBag(Bag *head, int number, char *owner, int weight)
{
    Bag *newBag = createBag(number, owner, weight);

    if (head == NULL)
    {
        head = newBag;
    }
    else
    {
        newBag->next = head;
        head = newBag;
    }
}

void printBags(Bag *head)
{
    while (head)
    {
        printf("Bag number: %d\n", head->number);
        printf("Owner: %s\n", head->owner);
        printf("Weight: %d\n", head->weight);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Bag *head = NULL;

    addBag(head, 1, "John Doe", 20);
    addBag(head, 2, "Jane Doe", 30);
    addBag(head, 3, "Peter Pan", 40);

    printBags(head);

    return 0;
}