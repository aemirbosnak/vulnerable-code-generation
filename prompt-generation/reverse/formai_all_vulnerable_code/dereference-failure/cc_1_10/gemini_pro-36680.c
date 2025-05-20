//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct {
    int id;             // The unique ID of the item
    char *name;         // The name of the item
    int quantity;       // The quantity of the item in stock
    float price;        // The price of the item
} item;

// Define the structure of the warehouse
typedef struct {
    item items[MAX_ITEMS];  // The array of items in the warehouse
    int num_items;          // The number of items in the warehouse
} warehouse;

// Create a new warehouse
warehouse *create_warehouse() {
    warehouse *w = malloc(sizeof(warehouse));
    w->num_items = 0;
    return w;
}

// Add an item to the warehouse
void add_item(warehouse *w, item *i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items++] = *i;
    }
}

// Remove an item from the warehouse
void remove_item(warehouse *w, int id) {
    for (int i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            w->items[i] = w->items[w->num_items - 1];
            w->num_items--;
            break;
        }
    }
}

// Get an item from the warehouse
item *get_item(warehouse *w, int id) {
    for (int i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            return &w->items[i];
        }
    }
    return NULL;
}

// Print the warehouse
void print_warehouse(warehouse *w) {
    printf("Warehouse:\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("Item %d: %s, %d, %f\n", w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Free the warehouse
void free_warehouse(warehouse *w) {
    for (int i = 0; i < w->num_items; i++) {
        free(w->items[i].name);
    }
    free(w);
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some items to the warehouse
    item i1 = { 1, "Item 1", 10, 10.0 };
    item i2 = { 2, "Item 2", 20, 20.0 };
    item i3 = { 3, "Item 3", 30, 30.0 };
    add_item(w, &i1);
    add_item(w, &i2);
    add_item(w, &i3);

    // Print the warehouse
    print_warehouse(w);

    // Get an item from the warehouse
    item *i = get_item(w, 2);
    if (i != NULL) {
        printf("Item found: %s, %d, %f\n", i->name, i->quantity, i->price);
    } else {
        printf("Item not found.\n");
    }

    // Remove an item from the warehouse
    remove_item(w, 1);

    // Print the warehouse
    print_warehouse(w);

    // Free the warehouse
    free_warehouse(w);

    return 0;
}