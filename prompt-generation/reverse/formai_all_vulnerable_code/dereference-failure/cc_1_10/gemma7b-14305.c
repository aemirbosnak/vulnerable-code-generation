//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the warehouse management system structure
typedef struct WarehouseManagementSystem {
    char item_name[20];
    int item_quantity;
    struct WarehouseManagementSystem* next;
} WarehouseManagementSystem;

// Function to insert an item into the warehouse management system
void insert_item(WarehouseManagementSystem* head, char* item_name, int item_quantity) {
    // Allocate memory for the new item
    WarehouseManagementSystem* new_item = (WarehouseManagementSystem*)malloc(sizeof(WarehouseManagementSystem));

    // Copy the item name and quantity
    strcpy(new_item->item_name, item_name);
    new_item->item_quantity = item_quantity;

    // If the head is NULL, then this is the first item in the system
    if (head == NULL) {
        head = new_item;
    } else {
        // Traverse the system until the last item is reached
        WarehouseManagementSystem* current_item = head;
        while (current_item->next != NULL) {
            current_item = current_item->next;
        }

        // Insert the new item at the end of the system
        current_item->next = new_item;
    }
}

// Function to find an item in the warehouse management system
WarehouseManagementSystem* find_item(WarehouseManagementSystem* head, char* item_name) {
    // Traverse the system to find the item
    WarehouseManagementSystem* current_item = head;
    while (current_item != NULL) {
        if (strcmp(current_item->item_name, item_name) == 0) {
            return current_item;
        }
        current_item = current_item->next;
    }

    // Item not found
    return NULL;
}

// Function to update the quantity of an item in the warehouse management system
void update_item_quantity(WarehouseManagementSystem* item, int new_quantity) {
    // Update the item quantity
    item->item_quantity = new_quantity;
}

// Main function
int main() {
    // Create a warehouse management system
    WarehouseManagementSystem* head = NULL;

    // Insert items into the system
    insert_item(head, "Item A", 10);
    insert_item(head, "Item B", 20);
    insert_item(head, "Item C", 30);

    // Find an item in the system
    WarehouseManagementSystem* item = find_item(head, "Item B");
    if (item != NULL) {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->item_quantity);
    }

    // Update the quantity of an item
    update_item_quantity(item, 25);

    // Find the updated item in the system
    item = find_item(head, "Item B");
    if (item != NULL) {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->item_quantity);
    }

    return 0;
}