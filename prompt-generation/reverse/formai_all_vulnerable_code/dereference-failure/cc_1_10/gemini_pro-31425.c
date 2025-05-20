//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the inventory
#define MAX_ITEMS 100

// Define the structure of an item in the inventory
typedef struct {
    char name[50];
    char description[100];
    int quantity;
    float price;
} Item;

// Define the structure of the inventory
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

// Create a new inventory
Inventory* create_inventory() {
    Inventory* inventory = (Inventory*)malloc(sizeof(Inventory));
    inventory->num_items = 0;
    return inventory;
}

// Add an item to the inventory
void add_item(Inventory* inventory, Item item) {
    inventory->items[inventory->num_items] = item;
    inventory->num_items++;
}

// Remove an item from the inventory
void remove_item(Inventory* inventory, int index) {
    for (int i = index; i < inventory->num_items - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
    }
    inventory->num_items--;
}

// Find an item in the inventory by name
Item* find_item(Inventory* inventory, char* name) {
    for (int i = 0; i < inventory->num_items; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            return &inventory->items[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(Inventory* inventory) {
    for (int i = 0; i < inventory->num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Name: %s\n", inventory->items[i].name);
        printf("  Description: %s\n", inventory->items[i].description);
        printf("  Quantity: %d\n", inventory->items[i].quantity);
        printf("  Price: %.2f\n", inventory->items[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    Inventory* inventory = create_inventory();

    // Add some items to the inventory
    Item item1 = {"Aspirin", "Pain reliever", 100, 1.99};
    add_item(inventory, item1);
    Item item2 = {"Ibuprofen", "Pain reliever", 50, 2.99};
    add_item(inventory, item2);
    Item item3 = {"Acetaminophen", "Pain reliever", 25, 1.49};
    add_item(inventory, item3);

    // Print the inventory
    print_inventory(inventory);

    // Find an item in the inventory
    Item* item = find_item(inventory, "Ibuprofen");
    if (item != NULL) {
        printf("Found item: %s\n", item->name);
    } else {
        printf("Item not found.\n");
    }

    // Remove an item from the inventory
    remove_item(inventory, 1);

    // Print the inventory again
    print_inventory(inventory);

    // Free the memory allocated for the inventory
    free(inventory);

    return 0;
}