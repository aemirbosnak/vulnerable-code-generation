//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: shocked
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
    warehouse* wh = (warehouse*) malloc(sizeof(warehouse));
    wh->num_items = 0;
    return wh;
}

// Add an item to the warehouse
void add_item(warehouse* wh, item* item) {
    if (wh->num_items < MAX_ITEMS) {
        wh->items[wh->num_items++] = *item;
    } else {
        printf("Warehouse is full!\n");
    }
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

// Print the contents of the warehouse
void print_warehouse(warehouse* wh) {
    printf("Warehouse contains:\n");
    for (int i = 0; i < wh->num_items; i++) {
        printf("%s %d %.2f\n", wh->items[i].name, wh->items[i].quantity, wh->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* wh = create_warehouse();

    // Add some items to the warehouse

    item item1 = {"Apple", 10, 0.50};
    add_item(wh, &item1);
    item item2 = {"Orange", 10, 0.75};
    add_item(wh, &item2);
    item item3 = {"Banana", 10, 1.00};
    add_item(wh, &item3);
    item item4 = {"Grape", 10, 1.50};
    add_item(wh, &item4);
    item item5 = {"Strawberry", 10, 2.00};
    add_item(wh, &item5);
    

    // Print the contents of the warehouse
    print_warehouse(wh);

    // Remove an item from the warehouse
    remove_item(wh, "Orange");

    // Print the contents of the warehouse
    print_warehouse(wh);

    return 0;
}