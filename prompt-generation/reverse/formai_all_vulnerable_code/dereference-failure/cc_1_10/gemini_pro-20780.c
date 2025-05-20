//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
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
    s->items[s->num_items++] = i;
}

// Find an item in the store by ID
item* find_item_by_id(store* s, int id) {
    for (int i = 0; i < s->num_items; i++) {
        if (s->items[i].id == id) {
            return &s->items[i];
        }
    }
    return NULL;
}

// Find an item in the store by name
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
    printf("Items in the store:\n");
    for (int i = 0; i < s->num_items; i++) {
        printf("%d %s %.2f %d\n", s->items[i].id, s->items[i].name, s->items[i].price, s->items[i].quantity);
    }
}

// Main function
int main() {
    // Create a new store
    store* s = create_store();

    // Add some items to the store
    item i1 = { 1, "Item 1", 10.0, 5 };
    add_item(s, i1);
    item i2 = { 2, "Item 2", 15.0, 10 };
    add_item(s, i2);
    item i3 = { 3, "Item 3", 20.0, 15 };
    add_item(s, i3);

    // Print the items in the store
    print_items(s);

    // Find an item in the store by ID
    item* item = find_item_by_id(s, 2);
    if (item) {
        printf("Item found: %d %s %.2f %d\n", item->id, item->name, item->price, item->quantity);
    } else {
        printf("Item not found.\n");
    }

    // Find an item in the store by name
    item = find_item_by_name(s, "Item 3");
    if (item) {
        printf("Item found: %d %s %.2f %d\n", item->id, item->name, item->price, item->quantity);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}