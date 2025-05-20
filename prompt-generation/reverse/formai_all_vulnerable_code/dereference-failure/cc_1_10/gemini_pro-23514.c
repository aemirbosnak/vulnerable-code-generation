//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the maximum number of items that can be stored in the inventory.
#define MAX_ITEMS 100

// Define the structure of an item in the inventory.
typedef struct Item {
    char name[50];
    int quantity;
} Item;

// Define the structure of the inventory.
typedef struct Inventory {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

// Create a new inventory.
Inventory* create_inventory() {
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->num_items = 0;
    return inventory;
}

// Add an item to the inventory.
void add_item(Inventory* inventory, Item item) {
    if (inventory->num_items < MAX_ITEMS) {
        inventory->items[inventory->num_items] = item;
        inventory->num_items++;
    }
}

// Remove an item from the inventory.
void remove_item(Inventory* inventory, char* name) {
    for (int i = 0; i < inventory->num_items; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            for (int j = i; j < inventory->num_items - 1; j++) {
                inventory->items[j] = inventory->items[j + 1];
            }
            inventory->num_items--;
            break;
        }
    }
}

// Print the inventory.
void print_inventory(Inventory* inventory) {
    for (int i = 0; i < inventory->num_items; i++) {
        printf("%s: %d\n", inventory->items[i].name, inventory->items[i].quantity);
    }
}

// Main function.
int main() {
    // Create a new inventory.
    Inventory* inventory = create_inventory();

    // Add some items to the inventory.
    Item item1 = {"Water", 10};
    add_item(inventory, item1);
    Item item2 = {"Food", 5};
    add_item(inventory, item2);
    Item item3 = {"Ammunition", 20};
    add_item(inventory, item3);

    // Print the inventory.
    printf("Inventory:\n");
    print_inventory(inventory);

    // Remove an item from the inventory.
    remove_item(inventory, "Food");

    // Print the inventory again.
    printf("\nInventory after removing food:\n");
    print_inventory(inventory);

    return 0;
}