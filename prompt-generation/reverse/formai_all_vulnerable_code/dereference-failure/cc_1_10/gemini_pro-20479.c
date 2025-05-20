//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ITEMS 1000
#define MAX_ITEM_NAME 20
#define MAX_ITEM_TYPE 20
#define MAX_ITEM_LOCATION 20

// Item struct
typedef struct {
    char name[MAX_ITEM_NAME];
    char type[MAX_ITEM_TYPE];
    char location[MAX_ITEM_LOCATION];
    int quantity;
} item;

// Warehouse struct
typedef struct {
    item items[MAX_ITEMS];
    int num_items;
} warehouse;

// Function to create a new warehouse
warehouse *create_warehouse() {
    warehouse *w = (warehouse *)malloc(sizeof(warehouse));
    w->num_items = 0;
    return w;
}

// Function to destroy a warehouse
void destroy_warehouse(warehouse *w) {
    free(w);
}

// Function to add an item to a warehouse
void add_item(warehouse *w, item *i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items++] = *i;
    }
}

// Function to remove an item from a warehouse
void remove_item(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            w->items[i] = w->items[w->num_items - 1];
            w->num_items--;
            break;
        }
    }
}

// Function to get an item from a warehouse
item *get_item(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            return &w->items[i];
        }
    }
    return NULL;
}

// Function to print a warehouse
void print_warehouse(warehouse *w) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        printf("%s %s %s %d\n", w->items[i].name, w->items[i].type, w->items[i].location, w->items[i].quantity);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some items to the warehouse
    item i1 = {"Item 1", "Type 1", "Location 1", 10};
    item i2 = {"Item 2", "Type 2", "Location 2", 20};
    item i3 = {"Item 3", "Type 3", "Location 3", 30};
    add_item(w, &i1);
    add_item(w, &i2);
    add_item(w, &i3);

    // Print the warehouse
    print_warehouse(w);

    // Get an item from the warehouse
    item *i4 = get_item(w, "Item 2");
    if (i4 != NULL) {
        printf("Item found: %s %s %s %d\n", i4->name, i4->type, i4->location, i4->quantity);
    } else {
        printf("Item not found.\n");
    }

    // Remove an item from the warehouse
    remove_item(w, "Item 1");

    // Print the warehouse again
    print_warehouse(w);

    // Destroy the warehouse
    destroy_warehouse(w);

    return 0;
}