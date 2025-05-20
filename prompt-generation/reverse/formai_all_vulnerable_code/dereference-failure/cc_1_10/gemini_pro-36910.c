//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: secure
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
    warehouse* wh = (warehouse*)malloc(sizeof(warehouse));
    wh->num_items = 0;
    return wh;
}

// Add an item to the warehouse
void add_item(warehouse* wh, item* item) {
    // Check if the warehouse is full
    if (wh->num_items == MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }

    // Add the item to the warehouse
    wh->items[wh->num_items++] = *item;
}

// Remove an item from the warehouse
void remove_item(warehouse* wh, char* name) {
    // Find the item in the warehouse
    int index = -1;
    for (int i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the item was found
    if (index == -1) {
        printf("Item not found!\n");
        return;
    }

    // Remove the item from the warehouse
    for (int i = index; i < wh->num_items - 1; i++) {
        wh->items[i] = wh->items[i + 1];
    }

    wh->num_items--;
}

// Print the contents of the warehouse
void print_warehouse(warehouse* wh) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < wh->num_items; i++) {
        printf("%s %d %.2f\n", wh->items[i].name, wh->items[i].quantity, wh->items[i].price);
    }
}

// Get the total value of the warehouse
float get_total_value(warehouse* wh) {
    float total_value = 0;
    for (int i = 0; i < wh->num_items; i++) {
        total_value += wh->items[i].quantity * wh->items[i].price;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* wh = create_warehouse();

    // Add some items to the warehouse
    item item1 = {"Apple", 10, 1.0};
    add_item(wh, &item1);
    item item2 = {"Orange", 5, 2.0};
    add_item(wh, &item2);
    item item3 = {"Banana", 15, 3.0};
    add_item(wh, &item3);

    // Print the contents of the warehouse
    print_warehouse(wh);

    // Get the total value of the warehouse
    float total_value = get_total_value(wh);
    printf("Total value of the warehouse: %.2f\n", total_value);

    // Remove an item from the warehouse
    remove_item(wh, "Orange");

    // Print the contents of the warehouse
    print_warehouse(wh);

    // Get the total value of the warehouse
    total_value = get_total_value(wh);
    printf("Total value of the warehouse: %.2f\n", total_value);

    return 0;
}