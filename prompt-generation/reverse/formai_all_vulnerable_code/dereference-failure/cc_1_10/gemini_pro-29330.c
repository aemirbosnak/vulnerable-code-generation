//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the warehouse
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
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
    Warehouse* warehouse = malloc(sizeof(Warehouse));
    warehouse->num_products = 0;
    return warehouse;
}

// Add a product to the warehouse
void add_product(Warehouse* warehouse, Product product) {
    if (warehouse->num_products >= MAX_PRODUCTS) {
        printf("Error: The warehouse is full.\n");
        return;
    }

    warehouse->products[warehouse->num_products] = product;
    warehouse->num_products++;
}

// Remove a product from the warehouse
void remove_product(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            warehouse->products[i] = warehouse->products[warehouse->num_products - 1];
            warehouse->num_products--;
            return;
        }
    }

    printf("Error: The product '%s' was not found in the warehouse.\n", name);
}

// Print the contents of the warehouse
void print_warehouse(Warehouse* warehouse) {
    printf("Warehouse Contents:\n");
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("  - %s: %d units at $%.2f each\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

// Get the total value of the warehouse
float get_total_value(Warehouse* warehouse) {
    float total_value = 0;
    for (int i = 0; i < warehouse->num_products; i++) {
        total_value += warehouse->products[i].quantity * warehouse->products[i].price;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse* warehouse = create_warehouse();

    // Add some products to the warehouse
    Product product1 = {"Apple", 10, 0.50};
    add_product(warehouse, product1);
    Product product2 = {"Orange", 5, 0.75};
    add_product(warehouse, product2);
    Product product3 = {"Banana", 15, 1.00};
    add_product(warehouse, product3);

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    // Remove a product from the warehouse
    remove_product(warehouse, "Orange");

    // Print the contents of the warehouse again
    print_warehouse(warehouse);

    // Get the total value of the warehouse
    float total_value = get_total_value(warehouse);
    printf("Total value of the warehouse: $%.2f\n", total_value);

    // Free the memory allocated for the warehouse
    free(warehouse);

    return 0;
}