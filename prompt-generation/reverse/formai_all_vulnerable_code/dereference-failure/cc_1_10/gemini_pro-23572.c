//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: artistic
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

// Create a new warehouse
warehouse *create_warehouse(char *name, int capacity) {
    warehouse *w = malloc(sizeof(warehouse));
    w->name = strdup(name);
    w->capacity = capacity;
    w->num_items = 0;
    w->items = malloc(sizeof(char *) * capacity);
    return w;
}

// Add an item to the warehouse
void add_item(warehouse *w, char *item) {
    if (w->num_items < w->capacity) {
        w->items[w->num_items++] = strdup(item);
    } else {
        printf("Warehouse is full!\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse *w, char *item) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i], item) == 0) {
            free(w->items[i]);
            w->items[i] = w->items[w->num_items - 1];
            w->num_items--;
            return;
        }
    }
    printf("Item not found!\n");
}

// Print the warehouse inventory
void print_inventory(warehouse *w) {
    int i;
    printf("Warehouse %s inventory:\n", w->name);
    for (i = 0; i < w->num_items; i++) {
        printf(" - %s\n", w->items[i]);
    }
}

// Free the warehouse memory
void free_warehouse(warehouse *w) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        free(w->items[i]);
    }
    free(w->items);
    free(w->name);
    free(w);
}

int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse("My Warehouse", 10);

    // Add some items to the warehouse
    add_item(w, "Item 1");
    add_item(w, "Item 2");
    add_item(w, "Item 3");

    // Print the warehouse inventory
    print_inventory(w);

    // Remove an item from the warehouse
    remove_item(w, "Item 2");

    // Print the warehouse inventory again
    print_inventory(w);

    // Free the warehouse memory
    free_warehouse(w);

    return 0;
}