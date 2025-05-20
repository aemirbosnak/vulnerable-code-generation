//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_STOCK 100

typedef struct Item
{
    char name[50];
    int stock;
    double price;
    struct Item* next;
} Item;

Item* addItem(Item* head, char* name, int stock, double price)
{
    Item* newNode = (Item*)malloc(sizeof(Item));
    strcpy(newNode->name, name);
    newNode->stock = stock;
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

Item* findItem(Item* head, char* name)
{
    Item* current = head;

    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

int main()
{
    Item* head = NULL;

    addItem(head, "Paracetamol", 10, 2.0);
    addItem(head, "Ibuprofen", 15, 2.5);
    addItem(head, "Cough Syrup", 5, 3.0);

    Item* item = findItem(head, "Ibuprofen");

    if (item)
    {
        printf("Item name: %s\n", item->name);
        printf("Stock: %d\n", item->stock);
        printf("Price: %.2lf\n", item->price);
    }

    return 0;
}