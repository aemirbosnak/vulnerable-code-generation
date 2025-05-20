//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse structure
typedef struct warehouse {
    char name[50];
    int capacity;
    int current_stock;
    struct item *items;
} warehouse;

// Define the item structure
typedef struct item {
    char name[50];
    int quantity;
    float price;
    struct item *next;
} item;

// Function to create a new warehouse
warehouse *create_warehouse(char *name, int capacity) {
    warehouse *new_warehouse = (warehouse *)malloc(sizeof(warehouse));
    strcpy(new_warehouse->name, name);
    new_warehouse->capacity = capacity;
    new_warehouse->current_stock = 0;
    new_warehouse->items = NULL;
    return new_warehouse;
}

// Function to add an item to the warehouse
void add_item(warehouse *warehouse, item *item) {
    if (warehouse->current_stock + item->quantity <= warehouse->capacity) {
        // Add the item to the linked list of items
        item->next = warehouse->items;
        warehouse->items = item;
        warehouse->current_stock += item->quantity;
    } else {
        printf("Error: Warehouse is full!\n");
    }
}

// Function to remove an item from the warehouse
void remove_item(warehouse *warehouse, char *name) {
    // Find the item in the linked list
    item *current_item = warehouse->items;
    item *previous_item = NULL;
    while (current_item != NULL && strcmp(current_item->name, name) != 0) {
        previous_item = current_item;
        current_item = current_item->next;
    }

    // If the item was found, remove it from the linked list and decrement the current stock
    if (current_item != NULL) {
        if (previous_item == NULL) {
            warehouse->items = current_item->next;
        } else {
            previous_item->next = current_item->next;
        }
        warehouse->current_stock -= current_item->quantity;
        free(current_item);
    } else {
        printf("Error: Item not found!\n");
    }
}

// Function to print the inventory of the warehouse
void print_inventory(warehouse *warehouse) {
    // Iterate over the linked list of items and print their details
    item *current_item = warehouse->items;
    while (current_item != NULL) {
        printf("Item: %s, Quantity: %d, Price: %.2f\n", current_item->name, current_item->quantity, current_item->price);
        current_item = current_item->next;
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *warehouse = create_warehouse("My Warehouse", 100);

    // Add some items to the warehouse
    item *item1 = (item *)malloc(sizeof(item));
    strcpy(item1->name, "Item 1");
    item1->quantity = 10;
    item1->price = 10.0;
    add_item(warehouse, item1);

    item *item2 = (item *)malloc(sizeof(item));
    strcpy(item2->name, "Item 2");
    item2->quantity = 20;
    item2->price = 20.0;
    add_item(warehouse, item2);

    item *item3 = (item *)malloc(sizeof(item));
    strcpy(item3->name, "Item 3");
    item3->quantity = 30;
    item3->price = 30.0;
    add_item(warehouse, item3);

    // Print the inventory of the warehouse
    printf("Inventory:\n");
    print_inventory(warehouse);

    // Remove an item from the warehouse
    remove_item(warehouse, "Item 2");

    // Print the inventory of the warehouse again
    printf("\nInventory after removing Item 2:\n");
    print_inventory(warehouse);

    return 0;
}