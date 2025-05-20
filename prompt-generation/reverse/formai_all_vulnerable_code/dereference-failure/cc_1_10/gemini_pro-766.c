//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct item {
    int id;
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
    if (w == NULL) {
        return NULL;
    }

    w->num_items = 0;

    return w;
}

// Add an item to the warehouse
int add_item(warehouse *w, item *i) {
    if (w->num_items == MAX_ITEMS) {
        return -1;
    }

    w->items[w->num_items++] = *i;

    return 0;
}

// Remove an item from the warehouse
int remove_item(warehouse *w, int id) {
    int i;

    for (i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            break;
        }
    }

    if (i == w->num_items) {
        return -1;
    }

    for (i++; i < w->num_items; i++) {
        w->items[i - 1] = w->items[i];
    }

    w->num_items--;

    return 0;
}

// Find an item in the warehouse
item *find_item(warehouse *w, int id) {
    int i;

    for (i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            return &w->items[i];
        }
    }

    return NULL;
}

// Print the contents of the warehouse
void print_warehouse(warehouse *w) {
    int i;

    printf("Warehouse contents:\n");
    for (i = 0; i < w->num_items; i++) {
        printf("%d %s %d %f\n", w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Free the memory allocated for the warehouse
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
    item i1 = {1, "Apple", 10, 0.50};
    item i2 = {2, "Orange", 5, 0.75};
    item i3 = {3, "Banana", 15, 1.00};
    add_item(w, &i1);
    add_item(w, &i2);
    add_item(w, &i3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Remove an item from the warehouse
    remove_item(w, 2);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Free the memory allocated for the warehouse
    free_warehouse(w);

    return 0;
}