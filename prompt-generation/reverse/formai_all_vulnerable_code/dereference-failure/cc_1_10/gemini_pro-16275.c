//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct item {
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
    warehouse* w = malloc(sizeof(warehouse));
    w->num_items = 0;
    return w;
}

// Add an item to the warehouse
void add_item(warehouse* w, item* i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items] = *i;
        w->num_items++;
    } else {
        printf("Warehouse is full, cannot add more items.\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse* w, char* name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            // Item found, remove it from the warehouse
            w->items[i] = w->items[w->num_items - 1];
            w->num_items--;
            break;
        }
    }
    if (i == w->num_items) {
        printf("Item not found in the warehouse.\n");
    }
}

// Search for an item in the warehouse
item* search_item(warehouse* w, char* name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            // Item found, return it
            return &w->items[i];
        }
    }
    return NULL;
}

// Print the contents of the warehouse
void print_warehouse(warehouse* w) {
    int i;
    printf("Warehouse contents:\n");
    for (i = 0; i < w->num_items; i++) {
        printf("%s %d %.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some items to the warehouse
    item i1 = {"Apple", 10, 1.00};
    item i2 = {"Orange", 5, 1.50};
    item i3 = {"Banana", 15, 2.00};
    add_item(w, &i1);
    add_item(w, &i2);
    add_item(w, &i3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Remove an item from the warehouse
    remove_item(w, "Orange");

    // Print the contents of the warehouse again
    print_warehouse(w);

    // Search for an item in the warehouse
    item* i = search_item(w, "Apple");
    if (i != NULL) {
        printf("Item found: %s %d %.2f\n", i->name, i->quantity, i->price);
    } else {
        printf("Item not found.\n");
    }

    // Free the memory allocated for the warehouse
    free(w);

    return 0;
}