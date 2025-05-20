//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct item {
    int id;
    char name[50];
    int quantity;
    float price;
} item;

// Define the structure of the warehouse
typedef struct warehouse {
    item items[MAX_ITEMS];
    int num_items;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse() {
    warehouse *wh = malloc(sizeof(warehouse));
    wh->num_items = 0;
    return wh;
}

// Add an item to the warehouse
void add_item(warehouse *wh, item *item) {
    wh->items[wh->num_items++] = *item;
}

// Remove an item from the warehouse
void remove_item(warehouse *wh, int id) {
    int i;
    for (i = 0; i < wh->num_items; i++) {
        if (wh->items[i].id == id) {
            wh->items[i] = wh->items[wh->num_items - 1];
            wh->num_items--;
            break;
        }
    }
}

// Find an item in the warehouse by its ID
item *find_item(warehouse *wh, int id) {
    int i;
    for (i = 0; i < wh->num_items; i++) {
        if (wh->items[i].id == id) {
            return &wh->items[i];
        }
    }
    return NULL;
}

// Print the inventory of the warehouse
void print_inventory(warehouse *wh) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < wh->num_items; i++) {
        printf("Item %d: %s, quantity: %d, price: %f\n", wh->items[i].id, wh->items[i].name, wh->items[i].quantity, wh->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *wh = create_warehouse();

    // Add some items to the warehouse
    item item1 = {1, "Item 1", 10, 10.0};
    add_item(wh, &item1);
    item item2 = {2, "Item 2", 20, 20.0};
    add_item(wh, &item2);
    item item3 = {3, "Item 3", 30, 30.0};
    add_item(wh, &item3);

    // Print the inventory of the warehouse
    print_inventory(wh);

    // Remove an item from the warehouse
    remove_item(wh, 2);

    // Print the inventory of the warehouse
    print_inventory(wh);

    // Find an item in the warehouse by its ID
    item *item4 = find_item(wh, 1);
    if (item4 != NULL) {
        printf("Item found: %s, quantity: %d, price: %f\n", item4->name, item4->quantity, item4->price);
    } else {
        printf("Item not found.\n");
    }

    // Free the memory allocated for the warehouse
    free(wh);

    return 0;
}