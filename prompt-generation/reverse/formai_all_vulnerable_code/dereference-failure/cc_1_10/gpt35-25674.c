//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ITEMS 100 // maximum number of items that the warehouse can hold
#define MAX_NAME_LENGTH 20 // maximum length of the name of an item
#define MAX_TYPE_LENGTH 15 // maximum length of the type of an item

// Define structs
typedef struct item {
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int quantity;
} Item;

typedef struct warehouse {
    Item inventory[MAX_ITEMS];
    int count;
} Warehouse;

// Function prototypes
Warehouse* createWarehouse();
void addItem(Warehouse* warehouse, char* name, char* type, int quantity);
void removeItem(Warehouse* warehouse, char* name);
void printInventory(Warehouse* warehouse);

// Main function
int main() {
    Warehouse* warehouse = createWarehouse();

    addItem(warehouse, "hammer", "tool", 10);
    addItem(warehouse, "nails", "hardware", 1000);
    addItem(warehouse, "screwdriver", "tool", 5);

    removeItem(warehouse, "screwdriver");

    printInventory(warehouse);

    return 0;
}

// Function to create a new warehouse
Warehouse* createWarehouse() {
    Warehouse* warehouse = (Warehouse*) malloc(sizeof(Warehouse));
    warehouse->count = 0;

    return warehouse;
}

// Function to add a new item to the warehouse
void addItem(Warehouse* warehouse, char* name, char* type, int quantity) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }

    // Create a new item and add it to the inventory
    Item item;
    strcpy(item.name, name);
    strcpy(item.type, type);
    item.quantity = quantity;

    warehouse->inventory[warehouse->count++] = item;

    printf("Added %d %s to the warehouse.\n", quantity, name);
}

// Function to remove an item from the warehouse
void removeItem(Warehouse* warehouse, char* name) {
    int i;
    for (i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->inventory[i].name, name) == 0) {
            printf("Removed %s from the warehouse.\n", name);

            // Shift all items after the removed item to the left
            int j;
            for (j = i; j < warehouse->count - 1; j++) {
                warehouse->inventory[j] = warehouse->inventory[j+1];
            }

            warehouse->count--;
            return;
        }
    }

    printf("%s not found in the warehouse.\n", name);
}

// Function to print the inventory of the warehouse
void printInventory(Warehouse* warehouse) {
    printf("Inventory:\n");

    int i;
    for (i = 0; i < warehouse->count; i++) {
        Item item = warehouse->inventory[i];
        printf("%s (%s) - Quantity: %d\n", item.name, item.type, item.quantity);
    }
}