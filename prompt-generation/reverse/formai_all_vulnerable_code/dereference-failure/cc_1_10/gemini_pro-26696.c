//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the inventory
#define MAX_INVENTORY_SIZE 100

// Define the structure of a medicine item
typedef struct medicine_item {
    char name[50];
    int quantity;
    float price;
} medicine_item;

// Define the structure of the inventory
typedef struct inventory {
    medicine_item items[MAX_INVENTORY_SIZE];
    int size;
} inventory;

// Create a new inventory
inventory* create_inventory() {
    inventory* inv = (inventory*)malloc(sizeof(inventory));
    inv->size = 0;
    return inv;
}

// Add a new medicine item to the inventory
void add_item(inventory* inv, medicine_item item) {
    if (inv->size < MAX_INVENTORY_SIZE) {
        inv->items[inv->size++] = item;
    } else {
        printf("Inventory is full!\n");
    }
}

// Search for a medicine item in the inventory
medicine_item* find_item(inventory* inv, char* name) {
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            return &inv->items[i];
        }
    }
    return NULL;
}

// Remove a medicine item from the inventory
void remove_item(inventory* inv, char* name) {
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            for (int j = i + 1; j < inv->size; j++) {
                inv->items[j - 1] = inv->items[j];
            }
            inv->size--;
            break;
        }
    }
}

// Update the quantity of a medicine item in the inventory
void update_quantity(inventory* inv, char* name, int quantity) {
    medicine_item* item = find_item(inv, name);
    if (item != NULL) {
        item->quantity = quantity;
    } else {
        printf("Medicine item not found!\n");
    }
}

// Print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->size; i++) {
        printf("%s %d %.2f\n", inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory* inv = create_inventory();

    // Add some medicine items to the inventory
    medicine_item item1 = {"Paracetamol", 100, 10.0};
    add_item(inv, item1);
    medicine_item item2 = {"Ibuprofen", 50, 15.0};
    add_item(inv, item2);

    // Search for a medicine item in the inventory
    medicine_item* item = find_item(inv, "Paracetamol");
    if (item != NULL) {
        printf("Found medicine item: %s %d %.2f\n", item->name, item->quantity, item->price);
    } else {
        printf("Medicine item not found!\n");
    }

    // Remove a medicine item from the inventory
    remove_item(inv, "Ibuprofen");

    // Update the quantity of a medicine item in the inventory
    update_quantity(inv, "Paracetamol", 200);

    // Print the inventory
    print_inventory(inv);

    // Free the memory allocated for the inventory
    free(inv);

    return 0;
}