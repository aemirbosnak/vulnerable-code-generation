//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item
{
    char name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

Item* CreateItem(char* name, int quantity, double price)
{
    Item* item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->price = price;
    item->next = NULL;
    return item;
}

void AddItem(Item* head, char* name, int quantity, double price)
{
    Item* item = CreateItem(name, quantity, price);
    if (head == NULL)
    {
        head = item;
    }
    else
    {
        item->next = head;
        head = item;
    }
}

void PrintItems(Item* head)
{
    while (head)
    {
        printf("%s: %d, $%.2lf\n", head->name, head->quantity, head->price);
        head = head->next;
    }
}

int main()
{
    Item* head = NULL;

    AddItem(head, "Apple", 10, 1.20);
    AddItem(head, "Banana", 15, 1.50);
    AddItem(head, "Orange", 20, 1.80);
    AddItem(head, "Grape", 12, 2.00);

    PrintItems(head);

    return 0;
}