//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the warehouse management system structure
typedef struct WarehouseManagementSystem
{
    char item_name[50];
    int item_quantity;
    double item_price;
    time_t item_arrival_time;
} WarehouseManagementSystem;

// Create a linked list of warehouse management systems
typedef struct Node
{
    WarehouseManagementSystem data;
    struct Node* next;
} Node;

// Function to insert a new item into the warehouse management system
void insert_item(Node* head, WarehouseManagementSystem item)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        head->next = new_node;
    }
}

// Function to search for an item in the warehouse management system
WarehouseManagementSystem* search_item(Node* head, char* item_name)
{
    Node* current = head;

    while (current)
    {
        if (strcmp(current->data.item_name, item_name) == 0)
        {
            return &current->data;
        }
        current = current->next;
    }

    return NULL;
}

// Function to update the quantity of an item in the warehouse management system
void update_item_quantity(Node* head, char* item_name, int new_quantity)
{
    WarehouseManagementSystem* item = search_item(head, item_name);

    if (item)
    {
        item->item_quantity = new_quantity;
    }
}

// Function to delete an item from the warehouse management system
void delete_item(Node* head, char* item_name)
{
    Node* current = head;
    Node* previous = NULL;

    while (current)
    {
        if (strcmp(current->data.item_name, item_name) == 0)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    return;
}

// Main function
int main()
{
    Node* head = NULL;

    // Insert some items into the warehouse management system
    insert_item(head, (WarehouseManagementSystem){.item_name = "Laptop", .item_quantity = 10, .item_price = 1000, .item_arrival_time = time(NULL)});
    insert_item(head, (WarehouseManagementSystem){.item_name = "Smartphone", .item_quantity = 20, .item_price = 800, .item_arrival_time = time(NULL)});
    insert_item(head, (WarehouseManagementSystem){.item_name = "Desktop", .item_quantity = 15, .item_price = 1200, .item_arrival_time = time(NULL)});

    // Search for an item in the warehouse management system
    WarehouseManagementSystem* item = search_item(head, "Laptop");

    if (item)
    {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->item_quantity);
        printf("Item price: %.2lf\n", item->item_price);
        printf("Item arrival time: %ld\n", item->item_arrival_time);
    }

    // Update the quantity of an item in the warehouse management system
    update_item_quantity(head, "Smartphone", 25);

    // Search for the updated item in the warehouse management system
    item = search_item(head, "Smartphone");

    if (item)
    {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->item_quantity);
    }

    // Delete an item from the warehouse management system
    delete_item(head, "Desktop");

    // Search for the deleted item in the warehouse management system
    item = search_item(head, "Desktop");

    if (item)
    {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->item_quantity);
    }

    return 0;
}