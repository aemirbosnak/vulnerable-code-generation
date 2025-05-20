//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_BAG_WEIGHT 20

typedef struct Bag
{
    char *name;
    int weight;
    struct Bag *next;
} Bag;

Bag *createBag()
{
    Bag *newBag = malloc(sizeof(Bag));
    newBag->name = malloc(20);
    newBag->weight = 0;
    newBag->next = NULL;
    return newBag;
}

void addBag(Bag *head, char *name, int weight)
{
    Bag *newBag = createBag();
    newBag->name = name;
    newBag->weight = weight;
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
        printf("%s (weight: %d) ", head->name, head->weight);
        head = head->next;
    }
}

int main()
{
    Bag *head = NULL;
    addBag(head, "John Doe's Bag", 15);
    addBag(head, "Jane Doe's Bag", 12);
    addBag(head, "Bill Smith's Bag", 18);

    printBags(head);

    return 0;
}