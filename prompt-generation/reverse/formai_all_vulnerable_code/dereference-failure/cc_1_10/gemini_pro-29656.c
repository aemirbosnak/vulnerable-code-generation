//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the inventory
#define MAX_ITEMS 100

// Define the structure of an item in the inventory
typedef struct {
    char name[50];
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
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->num_items = 0;
    return inventory;
}

// Add an item to the inventory
void add_item(Inventory* inventory, Item item) {
    if (inventory->num_items < MAX_ITEMS) {
        inventory->items[inventory->num_items] = item;
        inventory->num_items++;
    } else {
        printf("Inventory is full\n");
    }
}

// Remove an item from the inventory
void remove_item(Inventory* inventory, char* name) {
    int i;
    for (i = 0; i < inventory->num_items; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            inventory->items[i] = inventory->items[inventory->num_items - 1];
            inventory->num_items--;
            break;
        }
    }
    if (i == inventory->num_items) {
        printf("Item not found\n");
    }
}

// Find an item in the inventory
Item* find_item(Inventory* inventory, char* name) {
    int i;
    for (i = 0; i < inventory->num_items; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            return &inventory->items[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(Inventory* inventory) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inventory->num_items; i++) {
        printf("%s %d %.2f\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

// Get the total value of the inventory
float get_total_value(Inventory* inventory) {
    int i;
    float total_value = 0;
    for (i = 0; i < inventory->num_items; i++) {
        total_value += inventory->items[i].quantity * inventory->items[i].price;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new inventory
    Inventory* inventory = create_inventory();

    // Add some items to the inventory
    Item item1 = {"Aspirin", 100, 0.50};
    add_item(inventory, item1);
    Item item2 = {"Ibuprofen", 50, 1.00};
    add_item(inventory, item2);
    Item item3 = {"Acetaminophen", 75, 0.75};
    add_item(inventory, item3);

    // Print the inventory
    print_inventory(inventory);

    // Get the total value of the inventory
    float total_value = get_total_value(inventory);
    printf("Total value of the inventory: %.2f\n", total_value);

    // Find an item in the inventory
    Item* item = find_item(inventory, "Ibuprofen");
    if (item != NULL) {
        printf("Found item: %s %d %.2f\n", item->name, item->quantity, item->price);
    } else {
        printf("Item not found\n");
    }

    // Remove an item from the inventory
    remove_item(inventory, "Acetaminophen");

    // Print the inventory
    print_inventory(inventory);

    // Free the memory allocated for the inventory
    free(inventory);

    return 0;
}