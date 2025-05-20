//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct item {
    char name[50];
    int quantity;
    double price;
} item;

// Define the structure of the warehouse
typedef struct warehouse {
    item items[MAX_ITEMS];
    int num_items;
} warehouse;

// Create a new warehouse
warehouse* create_warehouse() {
    warehouse* wh = malloc(sizeof(warehouse));
    wh->num_items = 0;
    return wh;
}

// Add an item to the warehouse
void add_item(warehouse* wh, char* name, int quantity, double price) {
    if (wh->num_items == MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }

    strcpy(wh->items[wh->num_items].name, name);
    wh->items[wh->num_items].quantity = quantity;
    wh->items[wh->num_items].price = price;
    wh->num_items++;
}

// Remove an item from the warehouse
void remove_item(warehouse* wh, char* name) {
    for (int i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->items[i].name, name) == 0) {
            for (int j = i; j < wh->num_items - 1; j++) {
                wh->items[j] = wh->items[j + 1];
            }
            wh->num_items--;
            return;
        }
    }

    printf("Item not found!\n");
}

// Get the total value of the warehouse
double get_total_value(warehouse* wh) {
    double total_value = 0;
    for (int i = 0; i < wh->num_items; i++) {
        total_value += wh->items[i].quantity * wh->items[i].price;
    }
    return total_value;
}

// Print the contents of the warehouse
void print_warehouse(warehouse* wh) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < wh->num_items; i++) {
        printf("%s: %d, $%.2f\n", wh->items[i].name, wh->items[i].quantity, wh->items[i].price);
    }
}

// Free the memory allocated for the warehouse
void destroy_warehouse(warehouse* wh) {
    free(wh);
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* wh = create_warehouse();

    // Add some items to the warehouse
    add_item(wh, "Apple", 10, 1.00);
    add_item(wh, "Orange", 20, 1.50);
    add_item(wh, "Banana", 30, 2.00);

    // Print the contents of the warehouse
    print_warehouse(wh);

    // Get the total value of the warehouse
    double total_value = get_total_value(wh);
    printf("Total value of the warehouse: $%.2f\n", total_value);

    // Remove an item from the warehouse
    remove_item(wh, "Apple");

    // Print the contents of the warehouse
    print_warehouse(wh);

    // Free the memory allocated for the warehouse
    destroy_warehouse(wh);

    return 0;
}