//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
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
void add_item(warehouse* w, item i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items] = i;
        w->num_items++;
    } else {
        printf("Error: Warehouse is full!\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse* w, char* name) {
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            for (int j = i; j < w->num_items - 1; j++) {
                w->items[j] = w->items[j + 1];
            }
            w->num_items--;
            return;
        }
    }
    printf("Error: Item not found!\n");
}

// Find an item in the warehouse
item* find_item(warehouse* w, char* name) {
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            return &w->items[i];
        }
    }
    return NULL;
}

// Print the warehouse
void print_warehouse(warehouse* w) {
    printf("Warehouse:\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("  - %s (%d, $%.2f)\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some items to the warehouse
    item item1 = {"Apple", 10, 0.50};
    add_item(w, item1);
    item item2 = {"Banana", 20, 0.75};
    add_item(w, item2);
    item item3 = {"Orange", 30, 1.00};
    add_item(w, item3);

    // Print the warehouse
    print_warehouse(w);

    // Find an item in the warehouse
    item* item4 = find_item(w, "Apple");
    if (item4 != NULL) {
        printf("Found item: %s (%d, $%.2f)\n", item4->name, item4->quantity, item4->price);
    } else {
        printf("Item not found!\n");
    }

    // Remove an item from the warehouse
    remove_item(w, "Banana");

    // Print the warehouse
    print_warehouse(w);

    // Free the warehouse
    free(w);

    return 0;
}