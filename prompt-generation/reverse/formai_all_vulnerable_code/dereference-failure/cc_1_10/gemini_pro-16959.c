//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_NAME_LENGTH 50

// Define the structure of an item in the warehouse
typedef struct item {
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
warehouse* create_warehouse() {
    warehouse* w = (warehouse*)malloc(sizeof(warehouse));
    w->num_items = 0;
    return w;
}

// Add an item to the warehouse
void add_item(warehouse* w, item* i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items++] = *i;
    } else {
        printf("Error: Warehouse is full.\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse* w, char* name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            w->items[i] = w->items[w->num_items - 1];
            w->num_items--;
            return;
        }
    }
    printf("Error: Item not found.\n");
}

// Find an item in the warehouse
item* find_item(warehouse* w, char* name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
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
        printf("%s: %d, $%.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Get the total value of the warehouse
float get_total_value(warehouse* w) {
    int i;
    float total = 0;
    for (i = 0; i < w->num_items; i++) {
        total += w->items[i].quantity * w->items[i].price;
    }
    return total;
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some items to the warehouse
    item i1 = {"Apple", 10, 0.50};
    add_item(w, &i1);
    item i2 = {"Orange", 5, 0.75};
    add_item(w, &i2);
    item i3 = {"Banana", 15, 1.00};
    add_item(w, &i3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Find an item in the warehouse
    item* found_item = find_item(w, "Orange");
    if (found_item != NULL) {
        printf("Found item: %s, %d, $%.2f\n", found_item->name, found_item->quantity, found_item->price);
    } else {
        printf("Item not found.\n");
    }

    // Remove an item from the warehouse
    remove_item(w, "Banana");

    // Print the contents of the warehouse
    print_warehouse(w);

    // Get the total value of the warehouse
    float total_value = get_total_value(w);
    printf("Total value of the warehouse: $%.2f\n", total_value);

    // Free the memory allocated for the warehouse
    free(w);

    return 0;
}