//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEM_COUNT 100

typedef struct Item
{
    char name[50];
    int quantity;
    double price;
    struct Item* next;
} Item;

Item* newItem(char* name, int quantity, double price)
{
    Item* item = (Item*)malloc(sizeof(Item));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->price = price;
    item->next = NULL;
    return item;
}

void displayInventory(Item* item)
{
    while (item)
    {
        printf("%s - %d - %.2lf\n", item->name, item->quantity, item->price);
        item = item->next;
    }
}

void updateQuantity(Item* item, int newQuantity)
{
    item->quantity = newQuantity;
}

void setPrice(Item* item, double newPrice)
{
    item->price = newPrice;
}

int main()
{
    Item* head = NULL;

    // Create a few items
    newItem("Laser Sword", 10, 50.0);
    newItem("Energy Shield", 5, 20.0);
    newItem("Teleporter", 2, 100.0);

    // Display the inventory
    displayInventory(head);

    // Update the quantity of the Energy Shield
    updateQuantity(head->next, 10);

    // Update the price of the Teleporter
    setPrice(head->next->next, 30.0);

    // Display the updated inventory
    displayInventory(head);

    return 0;
}