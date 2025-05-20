//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 50

// Define the structure of an item in the warehouse
typedef struct item {
    int id;
    char name[MAX_NAME_LENGTH];
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

// Add an item to the warehouse
void add_item(warehouse *w, item *i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items++] = *i;
    }
}

// Remove an item from the warehouse
void remove_item(warehouse *w, int id) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            // Move the items after the removed item one position to the left
            for (int j = i; j < w->num_items - 1; j++) {
                w->items[j] = w->items[j + 1];
            }
            w->num_items--;
            break;
        }
    }
}

// Find an item in the warehouse by its ID
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
    printf("Warehouse contents:\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("%d %s %d %f\n", w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Get the total value of the items in the warehouse
float get_total_value(warehouse *w) {
    float total_value = 0;
    for (int i = 0; i < w->num_items; i++) {
        total_value += w->items[i].quantity * w->items[i].price;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some items to the warehouse
    item item1 = {1, "Item 1", 10, 10.0};
    add_item(w, &item1);

    item item2 = {2, "Item 2", 20, 20.0};
    add_item(w, &item2);

    item item3 = {3, "Item 3", 30, 30.0};
    add_item(w, &item3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Get the total value of the items in the warehouse
    float total_value = get_total_value(w);
    printf("Total value of the items in the warehouse: %f\n", total_value);

    // Remove an item from the warehouse
    remove_item(w, 2);

    // Print the contents of the warehouse again
    print_warehouse(w);

    // Free the memory allocated for the warehouse
    free(w);

    return 0;
}