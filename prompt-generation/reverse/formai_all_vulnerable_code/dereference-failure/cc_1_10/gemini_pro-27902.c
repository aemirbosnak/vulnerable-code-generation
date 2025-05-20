//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    char *name;
    int quantity;
    float price;
} product;

// Structure to represent a warehouse
typedef struct warehouse {
    char *name;
    int num_products;
    product *products;
} warehouse;

// Function to create a new product
product *create_product(char *name, int quantity, float price) {
    product *p = malloc(sizeof(product));
    p->name = strdup(name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Function to create a new warehouse
warehouse *create_warehouse(char *name) {
    warehouse *w = malloc(sizeof(warehouse));
    w->name = strdup(name);
    w->num_products = 0;
    w->products = NULL;
    return w;
}

// Function to add a product to a warehouse
void add_product(warehouse *w, product *p) {
    w->products = realloc(w->products, (w->num_products + 1) * sizeof(product));
    w->products[w->num_products++] = *p;
}

// Function to print the contents of a warehouse
void print_warehouse(warehouse *w) {
    printf("Warehouse: %s\n", w->name);
    for (int i = 0; i < w->num_products; i++) {
        printf("  - %s: %d units at $%.2f each\n", w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse("My Warehouse");

    // Add some products to the warehouse
    add_product(w, create_product("Product 1", 10, 10.0));
    add_product(w, create_product("Product 2", 20, 20.0));
    add_product(w, create_product("Product 3", 30, 30.0));

    // Print the contents of the warehouse
    print_warehouse(w);

    // Free the memory allocated for the warehouse and its products
    for (int i = 0; i < w->num_products; i++) {
        free(w->products[i].name);
    }
    free(w->products);
    free(w->name);
    free(w);

    return 0;
}