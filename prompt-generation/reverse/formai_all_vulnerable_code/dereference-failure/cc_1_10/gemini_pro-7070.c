//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
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
void add_item(warehouse* w, item i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items] = i;
        w->num_items++;
    } else {
        printf("Error: warehouse is full\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse* w, int id) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (w->items[i].id == id) {
            break;
        }
    }
    if (i < w->num_items) {
        for (int j = i; j < w->num_items - 1; j++) {
            w->items[j] = w->items[j + 1];
        }
        w->num_items--;
    } else {
        printf("Error: item not found\n");
    }
}

// Get the total value of the items in the warehouse
float get_total_value(warehouse* w) {
    float total_value = 0;
    for (int i = 0; i < w->num_items; i++) {
        total_value += w->items[i].quantity * w->items[i].price;
    }
    return total_value;
}

// Print the items in the warehouse
void print_warehouse(warehouse* w) {
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("%d\t%s\t\t%d\t%f\n", w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some items to the warehouse
    item i1 = {1, "Item 1", 10, 10.0f};
    add_item(w, i1);
    item i2 = {2, "Item 2", 20, 20.0f};
    add_item(w, i2);
    item i3 = {3, "Item 3", 30, 30.0f};
    add_item(w, i3);

    // Print the items in the warehouse
    printf("Initial warehouse:\n");
    print_warehouse(w);

    // Remove an item from the warehouse
    remove_item(w, 2);

    // Print the items in the warehouse
    printf("Warehouse after removing item 2:\n");
    print_warehouse(w);

    // Get the total value of the items in the warehouse
    float total_value = get_total_value(w);
    printf("Total value of items in the warehouse: %f\n", total_value);

    return 0;
}