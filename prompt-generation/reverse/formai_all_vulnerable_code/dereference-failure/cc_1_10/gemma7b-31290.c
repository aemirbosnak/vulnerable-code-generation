//Gemma-7B DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1024

typedef struct Item
{
    char name[MAX_DATA_SIZE];
    int quantity;
    struct Item* next;
} Item;

Item* insertItem(Item* head, char* name, int quantity)
{
    Item* newNode = malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

int main()
{
    Item* head = NULL;

    // Simulate post-apocalyptic data gathering
    insertItem(head, "Water", 20);
    insertItem(head, "Canned Food", 15);
    insertItem(head, "Weapons", 5);
    insertItem(head, "Medical Supplies", 10);

    // Data mining: Analyze the inventory
    Item* currentItem = head;
    while (currentItem)
    {
        printf("Item: %s, Quantity: %d\n", currentItem->name, currentItem->quantity);
        currentItem = currentItem->next;
    }

    return 0;
}