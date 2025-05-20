//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items and the maximum size of an item
#define MAX_ITEMS 100
#define MAX_ITEM_SIZE 100

// Define the structure of an item
typedef struct item {
    char name[MAX_ITEM_SIZE];
    int quantity;
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
void add_item(warehouse* wh, item* it) {
    wh->items[wh->num_items++] = *it;
}

// Remove an item from the warehouse
void remove_item(warehouse* wh, char* name) {
    for (int i = 0; i < wh->num_items; i++) {
        if (strcmp(wh->items[i].name, name) == 0) {
            wh->items[i] = wh->items[wh->num_items - 1];
            wh->num_items--;
            return;
        }
    }
}

// Print the contents of the warehouse
void print_warehouse(warehouse* wh) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < wh->num_items; i++) {
        printf("%s: %d\n", wh->items[i].name, wh->items[i].quantity);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* wh = create_warehouse();

    // Add some items to the warehouse
    item it1 = {"Apple", 10};
    add_item(wh, &it1);
    item it2 = {"Banana", 20};
    add_item(wh, &it2);
    item it3 = {"Orange", 30};
    add_item(wh, &it3);

    // Print the contents of the warehouse
    print_warehouse(wh);

    // Remove an item from the warehouse
    remove_item(wh, "Apple");

    //Print the contents of the warehouse again
    print_warehouse(wh);

    //Free memory allocated
    free(wh);

    return 0;
}