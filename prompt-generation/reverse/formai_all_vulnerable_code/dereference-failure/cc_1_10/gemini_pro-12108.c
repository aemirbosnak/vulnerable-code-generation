//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct item {
    char *name;
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
    warehouse *w = malloc(sizeof(warehouse));
    w->num_items = 0;
    return w;
}

// Add an item to a warehouse
void add_item(warehouse *w, item *i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items] = *i;
        w->num_items++;
    } else {
        printf("Warehouse is full!\n");
    }
}

// Remove an item from a warehouse
void remove_item(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            w->items[i] = w->items[w->num_items - 1];
            w->num_items--;
            break;
        }
    }
}

// Get an item from a warehouse
item *get_item(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            return &w->items[i];
        }
    }
    return NULL;
}

// Print the contents of a warehouse
void print_warehouse(warehouse *w) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        printf("%s %d %.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Free the memory allocated for a warehouse
void free_warehouse(warehouse *w) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        free(w->items[i].name);
    }
    free(w);
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some items to the warehouse
    item i1 = {"Item 1", 10, 10.00};
    add_item(w, &i1);

    item i2 = {"Item 2", 20, 20.00};
    add_item(w, &i2);

    item i3 = {"Item 3", 30, 30.00};
    add_item(w, &i3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Get an item from the warehouse
    item *i = get_item(w, "Item 2");
    if (i != NULL) {
        printf("Item found: %s %d %.2f\n", i->name, i->quantity, i->price);
    } else {
        printf("Item not found!\n");
    }

    // Remove an item from the warehouse
    remove_item(w, "Item 1");

    // Print the contents of the warehouse
    print_warehouse(w);

    // Free the memory allocated for the warehouse
    free_warehouse(w);

    return 0;
}