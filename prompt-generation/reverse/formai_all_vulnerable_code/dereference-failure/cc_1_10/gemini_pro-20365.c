//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
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
warehouse* create_warehouse() {
    warehouse* w = (warehouse*)malloc(sizeof(warehouse));
    w->num_items = 0;
    return w;
}

// Add an item to the warehouse
void add_item(warehouse* w, item* i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items] = *i;
        w->num_items++;
    } else {
        printf("Error: Warehouse is full\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse* w, int id) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            w->items[i] = w->items[w->num_items - 1];
            w->num_items--;
            break;
        }
    }
}

// Find an item in the warehouse
item* find_item(warehouse* w, int id) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            return &w->items[i];
        }
    }
    return NULL;
}

// Print the warehouse
void print_warehouse(warehouse* w) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        printf("Item %d: %s, %d, %.2f\n", w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some items to the warehouse
    item i1 = {1, "Item 1", 10, 10.00};
    item i2 = {2, "Item 2", 20, 20.00};
    item i3 = {3, "Item 3", 30, 30.00};
    add_item(w, &i1);
    add_item(w, &i2);
    add_item(w, &i3);

    // Print the warehouse
    print_warehouse(w);

    // Remove an item from the warehouse
    remove_item(w, 2);

    // Print the warehouse again
    print_warehouse(w);

    // Find an item in the warehouse
    item* i = find_item(w, 1);
    if (i != NULL) {
        printf("Found item: %s, %d, %.2f\n", i->name, i->quantity, i->price);
    } else {
        printf("Item not found\n");
    }

    return 0;
}