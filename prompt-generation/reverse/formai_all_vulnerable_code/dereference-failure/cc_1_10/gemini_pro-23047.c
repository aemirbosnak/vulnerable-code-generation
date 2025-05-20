//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: active
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
warehouse *create_warehouse() {
    warehouse *w = malloc(sizeof(warehouse));
    w->num_items = 0;
    return w;
}

// Add an item to the warehouse
void add_item(warehouse *w, item i) {
    w->items[w->num_items] = i;
    w->num_items++;
}

// Remove an item from the warehouse
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

// Find an item in the warehouse
item *find_item(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            return &w->items[i];
        }
    }
    return NULL;
}

// Print the contents of the warehouse
void print_warehouse(warehouse *w) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        printf("%s %d %.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

// Get the total value of the warehouse
float get_total_value(warehouse *w) {
    float total = 0;
    int i;
    for (i = 0; i < w->num_items; i++) {
        total += w->items[i].quantity * w->items[i].price;
    }
    return total;
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some items to the warehouse
    item i1 = {"Apple", 10, 0.50};
    add_item(w, i1);
    item i2 = {"Banana", 20, 0.75};
    add_item(w, i2);
    item i3 = {"Orange", 30, 1.00};
    add_item(w, i3);

    // Print the contents of the warehouse
    printf("Warehouse contents:\n");
    print_warehouse(w);

    // Get the total value of the warehouse
    float total_value = get_total_value(w);
    printf("Total value of the warehouse: %.2f\n", total_value);

    // Remove an item from the warehouse
    remove_item(w, "Banana");

    // Print the contents of the warehouse
    printf("Warehouse contents after removing Banana:\n");
    print_warehouse(w);

    // Find an item in the warehouse
    item *i4 = find_item(w, "Apple");
    if (i4 != NULL) {
        printf("Found Apple: %d %f\n", i4->quantity, i4->price);
    } else {
        printf("Apple not found.\n");
    }

    // Free the memory allocated for the warehouse
    free(w);

    return 0;
}