//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the warehouse management system structure
typedef struct WarehouseManagementSystem {
    char item_name[20];
    int quantity;
    struct WarehouseManagementSystem* next;
} WarehouseManagementSystem;

// Function to insert a new item into the warehouse management system
void insert_item(WarehouseManagementSystem** head) {
    // Allocate memory for the new item
    WarehouseManagementSystem* new_item = (WarehouseManagementSystem*)malloc(sizeof(WarehouseManagementSystem));

    // Get the item name and quantity from the user
    printf("Enter the item name: ");
    scanf("%s", new_item->item_name);

    printf("Enter the quantity: ");
    scanf("%d", &new_item->quantity);

    // Insert the new item into the head of the linked list
    if (*head == NULL) {
        *head = new_item;
    } else {
        (*head)->next = new_item;
        *head = new_item;
    }
}

// Function to search for an item in the warehouse management system
void search_item(WarehouseManagementSystem* head) {
    // Get the item name from the user
    char item_name[20];
    printf("Enter the item name: ");
    scanf("%s", item_name);

    // Search for the item in the linked list
    WarehouseManagementSystem* current_item = head;
    while (current_item) {
        if (strcmp(current_item->item_name, item_name) == 0) {
            // Print the item name and quantity
            printf("Item name: %s\n", current_item->item_name);
            printf("Quantity: %d\n", current_item->quantity);
            break;
        }
        current_item = current_item->next;
    }

    // If the item is not found, print an error message
    if (current_item == NULL) {
        printf("Item not found.\n");
    }
}

// Function to update the quantity of an item in the warehouse management system
void update_quantity(WarehouseManagementSystem* head) {
    // Get the item name from the user
    char item_name[20];
    printf("Enter the item name: ");
    scanf("%s", item_name);

    // Search for the item in the linked list
    WarehouseManagementSystem* current_item = head;
    while (current_item) {
        if (strcmp(current_item->item_name, item_name) == 0) {
            // Get the new quantity from the user
            int new_quantity;
            printf("Enter the new quantity: ");
            scanf("%d", &new_quantity);

            // Update the item quantity
            current_item->quantity = new_quantity;

            break;
        }
        current_item = current_item->next;
    }

    // If the item is not found, print an error message
    if (current_item == NULL) {
        printf("Item not found.\n");
    }
}

// Function to delete an item from the warehouse management system
void delete_item(WarehouseManagementSystem* head) {
    // Get the item name from the user
    char item_name[20];
    printf("Enter the item name: ");
    scanf("%s", item_name);

    // Search for the item in the linked list
    WarehouseManagementSystem* current_item = head;
    WarehouseManagementSystem* previous_item = NULL;
    while (current_item) {
        if (strcmp(current_item->item_name, item_name) == 0) {
            // If the item is the first item in the list, update the head of the list
            if (previous_item == NULL) {
                head = current_item->next;
            } else {
                // Otherwise, remove the item from the list
                previous_item->next = current_item->next;
            }

            free(current_item);
            break;
        }
        previous_item = current_item;
        current_item = current_item->next;
    }

    // If the item is not found, print an error message
    if (current_item == NULL) {
        printf("Item not found.\n");
    }
}

int main() {
    // Create a new warehouse management system
    WarehouseManagementSystem* head = NULL;

    // Insert some items into the warehouse management system
    insert_item(&head);
    insert_item(&head);
    insert_item(&head);

    // Search for an item in the warehouse management system
    search_item(head);

    // Update the quantity of an item in the warehouse management system
    update_quantity(head);

    // Delete an item from the warehouse management system
    delete_item(head);

    return 0;
}