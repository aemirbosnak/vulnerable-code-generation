//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: systematic
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
} item;

// Define the structure of the inventory
typedef struct {
    item items[MAX_ITEMS];
    int num_items;
} inventory;

// Create a new inventory
inventory* create_inventory() {
    inventory* inv = malloc(sizeof(inventory));
    inv->num_items = 0;
    return inv;
}

// Add an item to the inventory
void add_item(inventory* inv, item* item) {
    if (inv->num_items < MAX_ITEMS) {
        inv->items[inv->num_items++] = *item;
    }
}

// Remove an item from the inventory
void remove_item(inventory* inv, int index) {
    if (index >= 0 && index < inv->num_items) {
        for (int i = index; i < inv->num_items - 1; i++) {
            inv->items[i] = inv->items[i + 1];
        }
        inv->num_items--;
    }
}

// Get the total value of the inventory
float get_total_value(inventory* inv) {
    float total = 0;
    for (int i = 0; i < inv->num_items; i++) {
        total += inv->items[i].price * inv->items[i].quantity;
    }
    return total;
}

// Print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", inv->items[i].name);
        printf("Description: %s\n", inv->items[i].description);
        printf("Quantity: %d\n", inv->items[i].quantity);
        printf("Price: %.2f\n", inv->items[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory* inv = create_inventory();

    // Add some items to the inventory
    item item1 = {"Aspirin", "Pain reliever", 100, 0.50};
    add_item(inv, &item1);
    item item2 = {"Ibuprofen", "Pain reliever", 50, 0.75};
    add_item(inv, &item2);
    item item3 = {"Acetaminophen", "Pain reliever", 25, 1.00};
    add_item(inv, &item3);

    // Print the inventory
    print_inventory(inv);

    // Get the total value of the inventory
    float total_value = get_total_value(inv);
    printf("Total value of the inventory: %.2f\n", total_value);

    // Remove an item from the inventory
    remove_item(inv, 1);

    // Print the inventory again
    print_inventory(inv);

    // Free the memory allocated for the inventory
    free(inv);

    return 0;
}