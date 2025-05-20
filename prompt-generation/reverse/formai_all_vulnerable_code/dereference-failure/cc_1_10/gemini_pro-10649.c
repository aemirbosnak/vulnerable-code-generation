//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the warehouse
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
    int id;
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
warehouse* create_warehouse() {
    warehouse* w = (warehouse*)malloc(sizeof(warehouse));
    w->num_products = 0;
    return w;
}

// Add a new product to the warehouse
void add_product(warehouse* w, product p) {
    if (w->num_products < MAX_PRODUCTS) {
        w->products[w->num_products++] = p;
    } else {
        printf("Error: Warehouse is full!\n");
    }
}

// Remove a product from the warehouse
void remove_product(warehouse* w, int id) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            w->products[i] = w->products[w->num_products - 1];
            w->num_products--;
            break;
        }
    }
}

// Find a product in the warehouse
product* find_product(warehouse* w, int id) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            return &w->products[i];
        }
    }
    return NULL;
}

// Print the contents of the warehouse
void print_warehouse(warehouse* w) {
    int i;
    printf("Warehouse contains %d products:\n", w->num_products);
    for (i = 0; i < w->num_products; i++) {
        printf("%d %s %d %.2f\n", w->products[i].id, w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some products to the warehouse
    product p1 = {1, "Apple", 10, 1.00};
    add_product(w, p1);
    product p2 = {2, "Banana", 20, 2.00};
    add_product(w, p2);
    product p3 = {3, "Orange", 15, 3.00};
    add_product(w, p3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Find a product in the warehouse
    product* p = find_product(w, 2);
    if (p != NULL) {
        printf("Found product: %d %s %d %.2f\n", p->id, p->name, p->quantity, p->price);
    } else {
        printf("Product not found!\n");
    }

    // Remove a product from the warehouse
    remove_product(w, 1);

    // Print the contents of the warehouse again
    printf("\n");
    print_warehouse(w);

    // Free the memory allocated for the warehouse
    free(w);

    return 0;
}