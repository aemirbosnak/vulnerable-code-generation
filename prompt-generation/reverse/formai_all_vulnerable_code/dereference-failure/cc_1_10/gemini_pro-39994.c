//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct {
    int id;
    char *name;
    int quantity;
    float price;
} item;

// Define the structure of the warehouse
typedef struct {
    item items[MAX_ITEMS];
    int num_items;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse() {
    warehouse *wh = malloc(sizeof(warehouse));
    wh->num_items = 0;
    return wh;
}

// Add an item to the warehouse
void add_item(warehouse *wh, item *item) {
    if (wh->num_items < MAX_ITEMS) {
        wh->items[wh->num_items++] = *item;
    } else {
        printf("Warehouse is full!\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse *wh, int id) {
    for (int i = 0; i < wh->num_items; i++) {
        if (wh->items[i].id == id) {
            for (int j = i; j < wh->num_items - 1; j++) {
                wh->items[j] = wh->items[j + 1];
            }
            wh->num_items--;
            return;
        }
    }
    printf("Item not found!\n");
}

// Print the contents of the warehouse
void print_warehouse(warehouse *wh) {
    printf("Warehouse:\n");
    for (int i = 0; i < wh->num_items; i++) {
        printf("  %d. %s (%d, $%.2f)\n", wh->items[i].id, wh->items[i].name, wh->items[i].quantity, wh->items[i].price);
    }
}

// Get the total value of the warehouse
float get_total_value(warehouse *wh) {
    float total_value = 0;
    for (int i = 0; i < wh->num_items; i++) {
        total_value += wh->items[i].quantity * wh->items[i].price;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *wh = create_warehouse();

    // Add some items to the warehouse
    item item1 = { 1, "Item 1", 10, 10.0 };
    add_item(wh, &item1);
    item item2 = { 2, "Item 2", 20, 20.0 };
    add_item(wh, &item2);
    item item3 = { 3, "Item 3", 30, 30.0 };
    add_item(wh, &item3);

    // Print the contents of the warehouse
    print_warehouse(wh);

    // Get the total value of the warehouse
    float total_value = get_total_value(wh);
    printf("Total value: $%.2f\n", total_value);

    // Remove an item from the warehouse
    remove_item(wh, 2);

    // Print the contents of the warehouse
    print_warehouse(wh);

    // Get the total value of the warehouse
    total_value = get_total_value(wh);
    printf("Total value: $%.2f\n", total_value);

    return 0;
}