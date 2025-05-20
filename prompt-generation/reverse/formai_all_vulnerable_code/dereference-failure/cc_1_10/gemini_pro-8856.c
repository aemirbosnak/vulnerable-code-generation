//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item in the store
typedef struct item {
    int id;
    char name[50];
    float price;
    int quantity;
} item;

// Define the structure of the store
typedef struct store {
    item items[MAX_ITEMS];
    int num_items;
} store;

// Create a new store
store* create_store() {
    store* s = (store*)malloc(sizeof(store));
    s->num_items = 0;
    return s;
}

// Add an item to the store
void add_item(store* s, item i) {
    s->items[s->num_items] = i;
    s->num_items++;
}

// Find an item in the store by its ID
item* find_item_by_id(store* s, int id) {
    for (int i = 0; i < s->num_items; i++) {
        if (s->items[i].id == id) {
            return &s->items[i];
        }
    }
    return NULL;
}

// Find an item in the store by its name
item* find_item_by_name(store* s, char* name) {
    for (int i = 0; i < s->num_items; i++) {
        if (strcmp(s->items[i].name, name) == 0) {
            return &s->items[i];
        }
    }
    return NULL;
}

// Print the items in the store
void print_items(store* s) {
    for (int i = 0; i < s->num_items; i++) {
        printf("Item %d: %s, $%.2f, %d units\n", s->items[i].id, s->items[i].name, s->items[i].price, s->items[i].quantity);
    }
}

// Main function
int main() {
    // Create a new store
    store* s = create_store();

    // Add some items to the store
    item i1 = {1, "Item 1", 10.00, 5};
    add_item(s, i1);

    item i2 = {2, "Item 2", 15.00, 10};
    add_item(s, i2);

    item i3 = {3, "Item 3", 20.00, 15};
    add_item(s, i3);

    // Print the items in the store
    print_items(s);

    // Find an item in the store by its ID
    item* item_by_id = find_item_by_id(s, 2);
    if (item_by_id != NULL) {
        printf("Item found by ID: %s, $%.2f, %d units\n", item_by_id->name, item_by_id->price, item_by_id->quantity);
    }

    // Find an item in the store by its name
    item* item_by_name = find_item_by_name(s, "Item 3");
    if (item_by_name != NULL) {
        printf("Item found by name: %s, $%.2f, %d units\n", item_by_name->name, item_by_name->price, item_by_name->quantity);
    }

    return 0;
}