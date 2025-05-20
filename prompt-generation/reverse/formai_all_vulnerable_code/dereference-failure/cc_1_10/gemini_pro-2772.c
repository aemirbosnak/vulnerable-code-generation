//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the warehouse
#define MAX_WAREHOUSE_SIZE 100

// Define the maximum number of products in the warehouse
#define MAX_PRODUCTS 10

// Define the structure of a product
typedef struct {
    char name[50];
    int quantity;
    float price;
} product;

// Define the structure of the warehouse
typedef struct {
    product products[MAX_PRODUCTS];
    int num_products;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse() {
    warehouse *w = malloc(sizeof(warehouse));
    w->num_products = 0;
    return w;
}

// Add a product to the warehouse
void add_product(warehouse *w, product p) {
    w->products[w->num_products++] = p;
}

// Remove a product from the warehouse
void remove_product(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            w->products[i] = w->products[w->num_products - 1];
            w->num_products--;
            break;
        }
    }
}

// Get the total value of the warehouse
float get_total_value(warehouse *w) {
    int i;
    float total_value = 0;
    for (i = 0; i < w->num_products; i++) {
        total_value += w->products[i].quantity * w->products[i].price;
    }
    return total_value;
}

// Print the contents of the warehouse
void print_warehouse(warehouse *w) {
    int i;
    printf("Warehouse contents:\n");
    for (i = 0; i < w->num_products; i++) {
        printf("%s %d %f\n", w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some products to the warehouse
    product p1 = {"Product 1", 10, 10.0};
    add_product(w, p1);
    product p2 = {"Product 2", 20, 20.0};
    add_product(w, p2);
    product p3 = {"Product 3", 30, 30.0};
    add_product(w, p3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Get the total value of the warehouse
    float total_value = get_total_value(w);
    printf("Total value of the warehouse: %f\n", total_value);

    // Remove a product from the warehouse
    remove_product(w, "Product 2");

    // Print the contents of the warehouse
    print_warehouse(w);

    // Get the total value of the warehouse
    total_value = get_total_value(w);
    printf("Total value of the warehouse: %f\n", total_value);

    return 0;
}