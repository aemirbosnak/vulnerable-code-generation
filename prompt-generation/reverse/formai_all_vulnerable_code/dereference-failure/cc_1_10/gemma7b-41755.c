//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse management system structure
typedef struct WarehouseManagementSystem
{
    char item_name[20];
    int item_quantity;
    struct WarehouseManagementSystem* next;
} WarehouseManagementSystem;

// Create a linked list of warehouse management systems
WarehouseManagementSystem* head = NULL;

// Function to add an item to the warehouse management system
void add_item(char* item_name, int item_quantity)
{
    // Allocate memory for a new warehouse management system node
    WarehouseManagementSystem* new_node = (WarehouseManagementSystem*)malloc(sizeof(WarehouseManagementSystem));

    // Copy the item name and quantity into the new node
    strcpy(new_node->item_name, item_name);
    new_node->item_quantity = item_quantity;

    // If the head of the list is NULL, make the new node the head
    if (head == NULL)
    {
        head = new_node;
    }
    // Otherwise, traverse the list and insert the new node at the end
    else
    {
        WarehouseManagementSystem* current_node = head;
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to find an item in the warehouse management system
WarehouseManagementSystem* find_item(char* item_name)
{
    // Traverse the list of warehouse management systems
    WarehouseManagementSystem* current_node = head;
    while (current_node)
    {
        // If the item name is equal to the current node's item name, return the current node
        if (strcmp(current_node->item_name, item_name) == 0)
        {
            return current_node;
        }
        // Otherwise, move to the next node
        current_node = current_node->next;
    }

    // If the item name is not found, return NULL
    return NULL;
}

// Function to update the quantity of an item in the warehouse management system
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

// Function to list all items in the warehouse management system
void list_items()
{
    // Traverse the list of warehouse management systems
    WarehouseManagementSystem* current_node = head;
    while (current_node)
    {
        // Print the item name and quantity
        printf("%s: %d\n", current_node->item_name, current_node->item_quantity);
        // Move to the next node
        current_node = current_node->next;
    }
}

int main()
{
    // Add items to the warehouse management system
    add_item("Apple", 10);
    add_item("Orange", 15);
    add_item("Banana", 20);

    // List all items in the warehouse management system
    list_items();

    // Update the quantity of an item
    update_item_quantity("Orange", 20);

    // List all items in the warehouse management system after updating the quantity
    list_items();

    return 0;
}