//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Warehouse item structure
typedef struct item {
    char *name;
    int quantity;
    float price;
} item;

// Warehouse structure
typedef struct warehouse {
    item *items;
    int num_items;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse() {
    warehouse *w = malloc(sizeof(warehouse));
    w->items = NULL;
    w->num_items = 0;
    return w;
}

// Destroy a warehouse
void destroy_warehouse(warehouse *w) {
    for (int i = 0; i < w->num_items; i++) {
        free(w->items[i].name);
    }
    free(w->items);
    free(w);
}

// Add an item to a warehouse
void add_item_to_warehouse(warehouse *w, char *name, int quantity, float price) {
    w->items = realloc(w->items, (w->num_items + 1) * sizeof(item));
    w->items[w->num_items].name = strdup(name);
    w->items[w->num_items].quantity = quantity;
    w->items[w->num_items].price = price;
    w->num_items++;
}

// Remove an item from a warehouse
void remove_item_from_warehouse(warehouse *w, char *name) {
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            free(w->items[i].name);
            for (int j = i + 1; j < w->num_items; j++) {
                w->items[j - 1] = w->items[j];
            }
            w->num_items--;
            break;
        }
    }
}

// Get the quantity of an item in a warehouse
int get_item_quantity(warehouse *w, char *name) {
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            return w->items[i].quantity;
        }
    }
    return 0;
}

// Get the price of an item in a warehouse
float get_item_price(warehouse *w, char *name) {
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            return w->items[i].price;
        }
    }
    return 0.0;
}

// Print the contents of a warehouse
void print_warehouse(warehouse *w) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("%s: %d @ $%.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some items to the warehouse
    add_item_to_warehouse(w, "Apples", 10, 1.0);
    add_item_to_warehouse(w, "Oranges", 5, 1.5);
    add_item_to_warehouse(w, "Bananas", 15, 2.0);

    // Print the contents of the warehouse
    printf("BEFORE\n");
    print_warehouse(w);

    // Get the quantity of an item in the warehouse
    int apples_quantity = get_item_quantity(w, "Apples");
    printf("Apples quantity: %d\n", apples_quantity);

    // Get the price of an item in the warehouse
    float oranges_price = get_item_price(w, "Oranges");
    printf("Oranges price: $%.2f\n", oranges_price);

    // Remove an item from the warehouse
    remove_item_from_warehouse(w, "Bananas");

    // Print the contents of the warehouse
    printf("\nAFTER\n");
    print_warehouse(w);

    // Destroy the warehouse
    destroy_warehouse(w);

    return 0;
}