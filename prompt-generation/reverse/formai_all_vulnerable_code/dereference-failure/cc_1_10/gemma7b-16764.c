//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 10
#define MAX_WEIGHT 50

typedef struct Bag
{
    char* name;
    int weight;
    struct Bag* next;
} Bag;

Bag* CreateBag(char* name, int weight)
{
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    newBag->name = name;
    newBag->weight = weight;
    newBag->next = NULL;
    return newBag;
}

void AddBag(Bag* head, char* name, int weight)
{
    Bag* newBag = CreateBag(name, weight);
    if (head == NULL)
    {
        head = newBag;
    }
    else
    {
        head->next = newBag;
    }
}

void HandleBags(Bag* head)
{
    printf("Handling bags...\n");
    while (head)
    {
        printf("Bag name: %s, Weight: %d\n", head->name, head->weight);
        head = head->next;
    }
}

int main()
{
    Bag* head = NULL;
    AddBag(head, "John Doe's bag", 20);
    AddBag(head, "Jane Doe's bag", 30);
    AddBag(head, "Peter Pan's bag", 40);
    HandleBags(head);

    return 0;
}