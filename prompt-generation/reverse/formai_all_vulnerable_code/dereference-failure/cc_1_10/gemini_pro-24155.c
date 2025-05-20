//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item in the warehouse
typedef struct item {
    char *name;
    int quantity;
    float price;
} item;

// Define the structure of the warehouse
typedef struct warehouse {
    item items[MAX_ITEMS];
    int num_items;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse() {
    warehouse *w = malloc(sizeof(warehouse));
    if (w == NULL) {
        return NULL;
    }

    w->num_items = 0;
    return w;
}

// Add an item to the warehouse
void add_item(warehouse *w, char *name, int quantity, float price) {
    if (w->num_items == MAX_ITEMS) {
        return;
    }

    w->items[w->num_items].name = malloc(strlen(name) + 1);
    strcpy(w->items[w->num_items].name, name);
    w->items[w->num_items].quantity = quantity;
    w->items[w->num_items].price = price;
    w->num_items++;
}

// Remove an item from the warehouse
void remove_item(warehouse *w, char *name) {
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            free(w->items[i].name);
            for (int j = i + 1; j < w->num_items; j++) {
                w->items[j - 1] = w->items[j];
            }
            w->num_items--;
            return;
        }
    }
}

// Get the total value of the warehouse
float get_total_value(warehouse *w) {
    float total = 0;
    for (int i = 0; i < w->num_items; i++) {
        total += w->items[i].quantity * w->items[i].price;
    }
    return total;
}

// Print the contents of the warehouse
void print_warehouse(warehouse *w) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("%s: %d units, $%.2f each\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
    printf("Total value: $%.2f\n", get_total_value(w));
}

// Free the memory allocated for the warehouse
void free_warehouse(warehouse *w) {
    for (int i = 0; i < w->num_items; i++) {
        free(w->items[i].name);
    }
    free(w);
}

int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some items to the warehouse
    add_item(w, "Apples", 10, 1.0);
    add_item(w, "Bananas", 15, 0.5);
    add_item(w, "Oranges", 20, 0.75);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Remove an item from the warehouse
    remove_item(w, "Apples");

    // Print the contents of the warehouse again
    print_warehouse(w);

    // Free the memory allocated for the warehouse
    free_warehouse(w);

    return 0;
}