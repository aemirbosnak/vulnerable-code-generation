//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the warehouse
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Define the structure of the warehouse
typedef struct {
    Product products[MAX_PRODUCTS];
    int num_products;
} Warehouse;

// Create a new warehouse
Warehouse* create_warehouse() {
    Warehouse* warehouse = (Warehouse*) malloc(sizeof(Warehouse));
    warehouse->num_products = 0;
    return warehouse;
}

// Add a new product to the warehouse
void add_product(Warehouse* warehouse, Product product) {
    if (warehouse->num_products >= MAX_PRODUCTS) {
        printf("Error: Warehouse is full\n");
        return;
    }

    warehouse->products[warehouse->num_products] = product;
    warehouse->num_products++;
}

// Remove a product from the warehouse
void remove_product(Warehouse* warehouse, int id) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            break;
        }
    }

    if (i == warehouse->num_products) {
        printf("Error: Product not found\n");
        return;
    }

    for (i++; i < warehouse->num_products; i++) {
        warehouse->products[i - 1] = warehouse->products[i];
    }

    warehouse->num_products--;
}

// Find a product in the warehouse by its id
Product* find_product(Warehouse* warehouse, int id) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            return &warehouse->products[i];
        }
    }

    return NULL;
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
    int i;
    printf("Warehouse:\n");
    for (i = 0; i < warehouse->num_products; i++) {
        printf("  %d: %s (%d, %.2f)\n", warehouse->products[i].id, warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse* warehouse = create_warehouse();

    // Add some products to the warehouse
    Product product1 = {1, "Apple", 100, 0.50};
    add_product(warehouse, product1);

    Product product2 = {2, "Orange", 50, 0.75};
    add_product(warehouse, product2);

    Product product3 = {3, "Banana", 25, 1.00};
    add_product(warehouse, product3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Find a product in the warehouse by its id
    Product* product = find_product(warehouse, 2);
    if (product != NULL) {
        printf("Found product: %s (%d, %.2f)\n", product->name, product->quantity, product->price);
    } else {
        printf("Product not found\n");
    }

    // Remove a product from the warehouse
    remove_product(warehouse, 3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse);

    return 0;
}