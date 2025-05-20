//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
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
void add_item(warehouse *w, char *name, int quantity, float price) {
    strcpy(w->items[w->num_items].name, name);
    w->items[w->num_items].quantity = quantity;
    w->items[w->num_items].price = price;
    w->num_items++;
}

// Remove an item from the warehouse
void remove_item(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            break;
        }
    }

    if (i < w->num_items) {
        for (int j = i; j < w->num_items - 1; j++) {
            w->items[j] = w->items[j + 1];
        }
        w->num_items--;
    }
}

// Get the quantity of an item in the warehouse
int get_quantity(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            return w->items[i].quantity;
        }
    }

    return 0;
}

// Get the price of an item in the warehouse
float get_price(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            return w->items[i].price;
        }
    }

    return 0.0;
}

// Print the contents of the warehouse
void print_warehouse(warehouse *w) {
    printf("Warehouse contents:\n");
    for (int i = 0; i < w->num_items; i++) {
        printf("%s %d %.2f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some items to the warehouse
    add_item(w, "Apple", 10, 1.0);
    add_item(w, "Orange", 5, 1.5);
    add_item(w, "Banana", 15, 2.0);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Get the quantity of an item in the warehouse
    int quantity = get_quantity(w, "Apple");
    printf("The quantity of apples in the warehouse is: %d\n", quantity);

    // Get the price of an item in the warehouse
    float price = get_price(w, "Orange");
    printf("The price of oranges in the warehouse is: %.2f\n", price);

    // Remove an item from the warehouse
    remove_item(w, "Banana");

    // Print the contents of the warehouse
    print_warehouse(w);

    return 0;
}