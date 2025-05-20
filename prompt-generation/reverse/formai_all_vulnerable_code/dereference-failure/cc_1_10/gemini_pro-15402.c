//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct product {
    int id;
    char *name;
    int quantity;
    double price;
} product;

// Warehouse structure
typedef struct warehouse {
    int num_products;
    product *products;
} warehouse;

// Create a new product
product *create_product(int id, char *name, int quantity, double price) {
    product *p = malloc(sizeof(product));
    p->id = id;
    p->name = strdup(name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Create a new warehouse
warehouse *create_warehouse() {
    warehouse *w = malloc(sizeof(warehouse));
    w->num_products = 0;
    w->products = NULL;
    return w;
}

// Add a product to the warehouse
void add_product(warehouse *w, product *p) {
    w->products = realloc(w->products, (w->num_products + 1) * sizeof(product));
    w->products[w->num_products++] = *p;
}

// Get a product from the warehouse
product *get_product(warehouse *w, int id) {
    for (int i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            return &w->products[i];
        }
    }
    return NULL;
}

// Remove a product from the warehouse
void remove_product(warehouse *w, int id) {
    for (int i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            for (int j = i; j < w->num_products - 1; j++) {
                w->products[j] = w->products[j + 1];
            }
            w->num_products--;
            return;
        }
    }
}

// Print the warehouse inventory
void print_inventory(warehouse *w) {
    printf("Warehouse Inventory:\n");
    printf("---------------------\n");
    for (int i = 0; i < w->num_products; i++) {
        printf("ID: %d\n", w->products[i].id);
        printf("Name: %s\n", w->products[i].name);
        printf("Quantity: %d\n", w->products[i].quantity);
        printf("Price: %.2f\n\n", w->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse();

    // Add some products to the warehouse
    add_product(w, create_product(1, "Apple", 10, 1.00));
    add_product(w, create_product(2, "Orange", 15, 1.50));
    add_product(w, create_product(3, "Banana", 20, 2.00));

    // Print the warehouse inventory
    print_inventory(w);

    // Get a product from the warehouse
    product *p = get_product(w, 2);

    // Remove the product from the warehouse
    remove_product(w, 2);

    // Print the warehouse inventory
    print_inventory(w);

    // Free the memory allocated for the warehouse and its products
    for (int i = 0; i < w->num_products; i++) {
        free(w->products[i].name);
    }
    free(w->products);
    free(w);

    return 0;
}