//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Structure to represent a warehouse
typedef struct warehouse {
    product products[100];
    int num_products;
} warehouse;

// Function to create a new warehouse
warehouse *create_warehouse() {
    warehouse *w = (warehouse *)malloc(sizeof(warehouse));
    w->num_products = 0;
    return w;
}

// Function to add a product to a warehouse
void add_product(warehouse *w, product p) {
    w->products[w->num_products++] = p;
}

// Function to remove a product from a warehouse
void remove_product(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            break;
        }
    }

    if (i < w->num_products) {
        for (i; i < w->num_products - 1; i++) {
            w->products[i] = w->products[i + 1];
        }
        w->num_products--;
    }
}

// Function to get the total value of a warehouse
float get_total_value(warehouse *w) {
    float total = 0;
    int i;
    for (i = 0; i < w->num_products; i++) {
        total += w->products[i].quantity * w->products[i].price;
    }
    return total;
}

// Function to print the contents of a warehouse
void print_warehouse(warehouse *w) {
    int i;
    printf("Warehouse:\n");
    for (i = 0; i < w->num_products; i++) {
        printf("  %s: %d units, $%.2f each\n", w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
    printf("Total value: $%.2f\n", get_total_value(w));
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some products to the warehouse
    add_product(w, (product){"Apples", 10, 1.0});
    add_product(w, (product){"Oranges", 5, 1.5});
    add_product(w, (product){"Bananas", 15, 2.0});

    // Print the contents of the warehouse
    print_warehouse(w);

    // Remove a product from the warehouse
    remove_product(w, "Oranges");

    // Print the contents of the warehouse again
    print_warehouse(w);

    return 0;
}