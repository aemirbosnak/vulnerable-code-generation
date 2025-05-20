//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: detailed
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
        printf("Error: The inventory is full.\n");
    }
}

// Remove an item from the inventory
void remove_item(Inventory* inventory, char* name) {
    int index = find_item_index(inventory, name);
    if (index != -1) {
        for (int i = index; i < inventory->num_items - 1; i++) {
            inventory->items[i] = inventory->items[i + 1];
        }
        inventory->num_items--;
    } else {
        printf("Error: The item was not found in the inventory.\n");
    }
}

// Find the index of an item in the inventory
int find_item_index(Inventory* inventory, char* name) {
    for (int i = 0; i < inventory->num_items; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Print the inventory
void print_inventory(Inventory* inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->num_items; i++) {
        printf("%s: %d units, $%.2f each\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

// Get the total value of the inventory
float get_total_value(Inventory* inventory) {
    float total_value = 0;
    for (int i = 0; i < inventory->num_items; i++) {
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
    Item item2 = {"Ibuprofen", 50, 0.75};
    add_item(inventory, item2);
    Item item3 = {"Acetaminophen", 25, 1.00};
    add_item(inventory, item3);

    // Print the inventory
    print_inventory(inventory);

    // Get the total value of the inventory
    float total_value = get_total_value(inventory);
    printf("Total value: $%.2f\n", total_value);

    // Remove an item from the inventory
    remove_item(inventory, "Ibuprofen");

    // Print the inventory
    print_inventory(inventory);

    // Free the memory allocated for the inventory
    free(inventory);

    return 0;
}