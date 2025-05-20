//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse structure
typedef struct warehouse {
    char *name;
    int capacity;
    int num_items;
    char **items;
} warehouse;

// Define the item structure
typedef struct item {
    char *name;
    int quantity;
} item;

// Create a new warehouse
warehouse *create_warehouse(char *name, int capacity) {
    warehouse *w = malloc(sizeof(warehouse));
    w->name = strdup(name);
    w->capacity = capacity;
    w->num_items = 0;
    w->items = malloc(sizeof(char *) * capacity);
    return w;
}

// Destroy a warehouse
void destroy_warehouse(warehouse *w) {
    free(w->name);
    for (int i = 0; i < w->num_items; i++) {
        free(w->items[i]);
    }
    free(w->items);
    free(w);
}

// Add an item to a warehouse
void add_item(warehouse *w, item *i) {
    if (w->num_items >= w->capacity) {
        printf("Warehouse is full!\n");
        return;
    }
    w->items[w->num_items++] = strdup(i->name);
}

// Remove an item from a warehouse
void remove_item(warehouse *w, item *i) {
    for (int j = 0; j < w->num_items; j++) {
        if (strcmp(w->items[j], i->name) == 0) {
            free(w->items[j]);
            for (int k = j; k < w->num_items - 1; k++) {
                w->items[k] = w->items[k+1];
            }
            w->num_items--;
            return;
        }
    }
    printf("Item not found!\n");
}

// Print the contents of a warehouse
void print_warehouse(warehouse *w) {
    printf("Warehouse: %s\n", w->name);
    printf("Capacity: %d\n", w->capacity);
    printf("Number of items: %d\n", w->num_items);
    for (int i = 0; i < w->num_items; i++) {
        printf("Item %d: %s\n", i+1, w->items[i]);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w1 = create_warehouse("Warehouse 1", 10);

    // Add some items to the warehouse
    item *i1 = malloc(sizeof(item));
    i1->name = strdup("Item 1");
    i1->quantity = 10;
    add_item(w1, i1);

    item *i2 = malloc(sizeof(item));
    i2->name = strdup("Item 2");
    i2->quantity = 20;
    add_item(w1, i2);

    item *i3 = malloc(sizeof(item));
    i3->name = strdup("Item 3");
    i3->quantity = 30;
    add_item(w1, i3);

    // Print the contents of the warehouse
    print_warehouse(w1);

    // Remove an item from the warehouse
    remove_item(w1, i2);

    // Print the contents of the warehouse
    print_warehouse(w1);

    // Destroy the warehouse
    destroy_warehouse(w1);

    return 0;
}