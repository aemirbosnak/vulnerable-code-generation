//GEMINI-pro DATASET v1.0 Category: File handling ; Style: real-life
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
    Inventory* inventory = (Inventory*)malloc(sizeof(Inventory));
    inventory->num_items = 0;
    return inventory;
}

// Add an item to the inventory
void add_item(Inventory* inventory, Item item) {
    if (inventory->num_items < MAX_ITEMS) {
        inventory->items[inventory->num_items] = item;
        inventory->num_items++;
    } else {
        printf("Error: Inventory is full.\n");
    }
}

// Remove an item from the inventory
void remove_item(Inventory* inventory, int index) {
    if (index >= 0 && index < inventory->num_items) {
        for (int i = index; i < inventory->num_items - 1; i++) {
            inventory->items[i] = inventory->items[i + 1];
        }
        inventory->num_items--;
    } else {
        printf("Error: Invalid index.\n");
    }
}

// Search for an item in the inventory
int find_item(Inventory* inventory, char* name) {
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
        printf("%s %d %.2f\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

// Save the inventory to a file
void save_inventory(Inventory* inventory, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return;
    }
    for (int i = 0; i < inventory->num_items; i++) {
        fprintf(file, "%s %d %.2f\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
    fclose(file);
}

// Load the inventory from a file
void load_inventory(Inventory* inventory, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char name[50];
        int quantity;
        float price;
        sscanf(line, "%s %d %f", name, &quantity, &price);
        Item item = { name, quantity, price };
        add_item(inventory, item);
    }
    fclose(file);
}

// Main function
int main() {
    // Create a new inventory
    Inventory* inventory = create_inventory();

    // Add some items to the inventory
    Item item1 = { "Apple", 10, 0.50 };
    add_item(inventory, item1);
    Item item2 = { "Orange", 15, 0.75 };
    add_item(inventory, item2);
    Item item3 = { "Banana", 20, 1.00 };
    add_item(inventory, item3);

    // Print the inventory
    print_inventory(inventory);

    // Save the inventory to a file
    save_inventory(inventory, "inventory.txt");

    // Load the inventory from a file
    Inventory* new_inventory = create_inventory();
    load_inventory(new_inventory, "inventory.txt");

    // Print the new inventory
    print_inventory(new_inventory);

    // Free the memory allocated for the inventories
    free(inventory);
    free(new_inventory);

    return 0;
}