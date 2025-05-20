//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item
{
    char name[50];
    int quantity;
    float price;
    struct Item* next;
};

struct Item* InsertItem(struct Item* head, char* name, int quantity, float price)
{
    struct Item* newNode = (struct Item*)malloc(sizeof(struct Item));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
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

void PrintItems(struct Item* head)
{
    struct Item* current = head;
    while (current)
    {
        printf("%s - %d - %.2f\n", current->name, current->quantity, current->price);
        current = current->next;
    }
}

int main()
{
    struct Item* head = NULL;

    InsertItem(head, "Apple", 10, 1.20);
    InsertItem(head, "Banana", 5, 0.80);
    InsertItem(head, "Orange", 7, 0.90);
    InsertItem(head, "Grapes", 2, 1.00);

    PrintItems(head);

    return 0;
}