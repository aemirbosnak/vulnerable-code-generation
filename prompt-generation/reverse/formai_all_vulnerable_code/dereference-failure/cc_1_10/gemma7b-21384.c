//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse management system structure
typedef struct WarehouseManagementSystem
{
    char item_name[50];
    int item_quantity;
    float item_price;
    struct WarehouseManagementSystem* next;
} WarehouseManagementSystem;

// Create a linked list of warehouse management systems
WarehouseManagementSystem* head = NULL;

// Function to add an item to the warehouse management system
void add_item(char* item_name, int item_quantity, float item_price)
{
    // Allocate memory for the new item
    WarehouseManagementSystem* new_item = (WarehouseManagementSystem*)malloc(sizeof(WarehouseManagementSystem));

    // Copy the item name, quantity, and price into the new item
    strcpy(new_item->item_name, item_name);
    new_item->item_quantity = item_quantity;
    new_item->item_price = item_price;

    // If the head of the list is NULL, make the new item the head
    if (head == NULL)
    {
        head = new_item;
    }
    else
    {
        // Traverse the list until the last item is reached
        WarehouseManagementSystem* current_item = head;
        while (current_item->next != NULL)
        {
            current_item = current_item->next;
        }

        // Add the new item to the end of the list
        current_item->next = new_item;
    }
}

// Function to find an item in the warehouse management system
WarehouseManagementSystem* find_item(char* item_name)
{
    // Traverse the list of items
    WarehouseManagementSystem* current_item = head;
    while (current_item)
    {
        // If the item name is found, return the item
        if (strcmp(current_item->item_name, item_name) == 0)
        {
            return current_item;
        }

        // Move to the next item in the list
        current_item = current_item->next;
    }

    // Item not found
    return NULL;
}

// Function to update the quantity of an item
void update_item_quantity(char* item_name, int new_quantity)
{
    // Find the item in the warehouse management system
    WarehouseManagementSystem* item = find_item(item_name);

    // If the item is found, update its quantity
    if (item)
    {
        item->item_quantity = new_quantity;
    }
}

// Function to update the price of an item
void update_item_price(char* item_name, float new_price)
{
    // Find the item in the warehouse management system
    WarehouseManagementSystem* item = find_item(item_name);

    // If the item is found, update its price
    if (item)
    {
        item->item_price = new_price;
    }
}

// Main function
int main()
{
    // Add items to the warehouse management system
    add_item("Apple", 100, 1.20);
    add_item("Banana", 50, 1.30);
    add_item("Orange", 75, 1.40);

    // Find an item in the warehouse management system
    WarehouseManagementSystem* item = find_item("Apple");

    // If the item is found, print its name, quantity, and price
    if (item)
    {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->item_quantity);
        printf("Item price: %.2f\n", item->item_price);
    }

    // Update the quantity of an item
    update_item_quantity("Banana", 60);

    // Update the price of an item
    update_item_price("Orange", 1.50);

    // Find the item again and print its updated information
    item = find_item("Orange");

    if (item)
    {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->item_quantity);
        printf("Item price: %.2f\n", item->item_price);
    }

    return 0;
}