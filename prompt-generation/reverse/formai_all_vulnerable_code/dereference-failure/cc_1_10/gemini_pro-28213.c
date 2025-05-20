//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Item model
struct Item {
    int id;
    char name[100];
    int quantity;
    float price;
};

// Inventory model
struct Inventory {
    struct Item *items;  // Array of items
    int count;            // Number of items in the inventory
};

// Create a new inventory
struct Inventory *createInventory() {
    struct Inventory *inventory = (struct Inventory *)malloc(sizeof(struct Inventory));
    inventory->items = NULL;
    inventory->count = 0;
    return inventory;
}

// Add an item to the inventory
void addItem(struct Inventory *inventory, struct Item item) {
    // Increase the size of the items array
    inventory->items = (struct Item *)realloc(inventory->items, (inventory->count + 1) * sizeof(struct Item));
    
    // Add the item to the array
    inventory->items[inventory->count] = item;
    
    // Increase the count of items
    inventory->count++;
}

// Get an item from the inventory by its ID
struct Item *getItemById(struct Inventory *inventory, int id) {
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->items[i].id == id) {
            return &inventory->items[i];
        }
    }
    return NULL;
}

// Remove an item from the inventory by its ID
void removeItemById(struct Inventory *inventory, int id) {
    int index = -1;
    
    // Find the index of the item in the array
    for (int i = 0; i < inventory->count; i++) {
        if (inventory->items[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        return;  // Item not found
    }
    
    // Shift the items after the removed item to the left
    for (int i = index; i < inventory->count - 1; i++) {
        inventory->items[i] = inventory->items[i + 1];
    }
    
    // Decrease the count of items
    inventory->count--;
    
    // Reallocate the items array to a smaller size
    inventory->items = (struct Item *)realloc(inventory->items, inventory->count * sizeof(struct Item));
}

// Print the inventory
void printInventory(struct Inventory *inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->count; i++) {
        printf("%d %s %d %.2f\n", 
            inventory->items[i].id, 
            inventory->items[i].name, 
            inventory->items[i].quantity, 
            inventory->items[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    struct Inventory *inventory = createInventory();
    
    // Add some items to the inventory
    struct Item item1 = {1, "Apple", 10, 1.5};
    addItem(inventory, item1);
    
    struct Item item2 = {2, "Orange", 15, 2.0};
    addItem(inventory, item2);
    
    struct Item item3 = {3, "Banana", 20, 2.5};
    addItem(inventory, item3);
    
    // Print the inventory
    printInventory(inventory);
    
    // Get an item from the inventory by its ID
    struct Item *item = getItemById(inventory, 2);
    printf("Item with ID 2: %d %s %d %.2f\n", 
        item->id, 
        item->name, 
        item->quantity, 
        item->price);
    
    // Remove the item from the inventory
    removeItemById(inventory, 2);
    
    // Print the inventory again
    printInventory(inventory);
    
    // Free the memory allocated for the inventory
    free(inventory->items);
    free(inventory);
    
    return 0;
}