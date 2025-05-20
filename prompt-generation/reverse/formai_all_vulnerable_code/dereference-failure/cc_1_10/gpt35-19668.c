//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a warehouse item
typedef struct {
    char *name;
    int quantity;
} Item;

// Define a struct for a warehouse inventory
typedef struct {
    int size;
    Item *items;
} Inventory;

// Function to add an item to the inventory
void add_item(Inventory *inv, char *name, int quantity) {
    // Check if the item already exists in the inventory
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            // If the item exists, update the quantity
            inv->items[i].quantity += quantity;
            return;
        }
    }
    // If the item does not exist, add a new item to the inventory
    inv->size++;
    inv->items = (Item *) realloc(inv->items, sizeof(Item) * inv->size);
    inv->items[inv->size - 1].name = name;
    inv->items[inv->size - 1].quantity = quantity;
}

// Function to remove an item from the inventory
void remove_item(Inventory *inv, char *name, int quantity) {
    // Check if the item exists in the inventory
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            // If the quantity to be removed is more than the quantity available, display an error message
            if (quantity > inv->items[i].quantity) {
                printf("Error: Not enough %s in inventory.\n", name);
                return;
            }
            // If the quantity to be removed is equal to the quantity available, remove the item from the inventory
            if (quantity == inv->items[i].quantity) {
                free(inv->items[i].name);
                for (int j = i; j < inv->size - 1; j++) {
                    inv->items[j] = inv->items[j + 1];
                }
                inv->size--;
                inv->items = (Item *) realloc(inv->items, sizeof(Item) * inv->size);
                return;
            }
            // If the quantity to be removed is less than the quantity available, update the quantity
            inv->items[i].quantity -= quantity;
            return;
        }
    }
    // If the item does not exist in the inventory, display an error message
    printf("Error: %s not found in inventory.\n", name);
}

// Function to display the inventory
void display_inventory(Inventory inv) {
    for (int i = 0; i < inv.size; i++) {
        printf("%s - %d\n", inv.items[i].name, inv.items[i].quantity);
    }
}

int main() {
    // Initialize inventory
    Inventory inv = {0, NULL};
    // Add items to inventory
    add_item(&inv, "Apples", 10);
    add_item(&inv, "Oranges", 5);
    add_item(&inv, "Bananas", 3);
    // Display inventory
    display_inventory(inv);
    // Remove items from inventory
    remove_item(&inv, "Apples", 3);
    remove_item(&inv, "Oranges", 7);
    remove_item(&inv, "Grapes", 5);
    // Display inventory
    display_inventory(inv);
    // Free memory allocated for item names
    for (int i = 0; i < inv.size; i++) {
        free(inv.items[i].name);
    }
    // Free memory allocated for inventory items and set pointer to NULL
    free(inv.items);
    inv.items = NULL;
    return 0;
}