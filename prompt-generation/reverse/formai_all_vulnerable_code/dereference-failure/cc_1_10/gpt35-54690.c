//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a storage unit
typedef struct storage_unit {
    char* item_name;
    int quantity;
    struct storage_unit* next;
    struct storage_unit* prev;
} storage_unit;

// Initialize the warehouse as an empty doubly-linked list
storage_unit* warehouse_head = NULL;

// Function to add a new storage unit to the warehouse
void add_to_warehouse(char* item_name, int quantity) {
    storage_unit* new_unit = malloc(sizeof(storage_unit));
    new_unit->item_name = strdup(item_name);
    new_unit->quantity = quantity;
    new_unit->prev = NULL;
    new_unit->next = warehouse_head;

    if (warehouse_head != NULL) {
        warehouse_head->prev = new_unit;
    }

    warehouse_head = new_unit;
}

// Function to display the contents of the warehouse
void display_warehouse() {
    printf("Warehouse contents:\n");
    for (storage_unit* current_unit = warehouse_head; current_unit != NULL; current_unit = current_unit->next) {
        printf("%d of %s\n", current_unit->quantity, current_unit->item_name);
    }
}

// Function to remove a certain quantity of an item from the warehouse
void remove_from_warehouse(char* item_name, int quantity) {
    for (storage_unit* current_unit = warehouse_head; current_unit != NULL; current_unit = current_unit->next) {
        if (strcmp(current_unit->item_name, item_name) == 0) {
            if (current_unit->quantity < quantity) {
                printf("Cannot remove %d of %s, only %d available in warehouse\n", quantity, item_name, current_unit->quantity);
            }
            else {
                current_unit->quantity -= quantity;
                printf("Removed %d of %s from warehouse\n", quantity, item_name);
                if (current_unit->quantity == 0) {
                    if (current_unit == warehouse_head) {
                        warehouse_head = current_unit->next;
                    }
                    if (current_unit->prev != NULL) {
                        current_unit->prev->next = current_unit->next;
                    }
                    if (current_unit->next != NULL) {
                        current_unit->next->prev = current_unit->prev;
                    }
                    free(current_unit->item_name);
                    free(current_unit);
                }
            }
            return;
        }
    }
    printf("%s not found in warehouse\n", item_name);
}

int main() {
    printf("Welcome to the C Warehouse Management System\n");
    int selection = 0;
    while (selection != 4) {
        printf("Enter your selection:\n");
        printf("1. Add item to warehouse\n");
        printf("2. Remove item from warehouse\n");
        printf("3. Display warehouse contents\n");
        printf("4. Exit\n");
        scanf("%d", &selection);
        switch (selection) {
            case 1:
                {
                    char item_name[20];
                    int quantity;
                    printf("Enter item name:\n");
                    scanf("%s", item_name);
                    printf("Enter quantity:\n");
                    scanf("%d", &quantity);
                    add_to_warehouse(item_name, quantity);
                    printf("%d of %s added to warehouse\n", quantity, item_name);
                    break;
                }
            case 2:
                {
                    char item_name[20];
                    int quantity;
                    printf("Enter item name:\n");
                    scanf("%s", item_name);
                    printf("Enter quantity to remove:\n");
                    scanf("%d", &quantity);
                    remove_from_warehouse(item_name, quantity);
                    break;
                }
            case 3:
                {
                    display_warehouse();
                    break;
                }
            case 4:
                {
                    printf("Exiting...\n");
                    break;
                }
            default:
                {
                    printf("Invalid selection, please try again\n");
                    break;
                }
        }
    }
    return 0;
}