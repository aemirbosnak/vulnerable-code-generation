//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
    int id;
    char *name;
    int quantity;
    float price;
} Product;

// Structure to represent a warehouse
typedef struct Warehouse {
    int num_products;
    Product **products;
} Warehouse;

// Function to create a new product
Product *create_product(int id, char *name, int quantity, float price) {
    Product *product = malloc(sizeof(Product));
    product->id = id;
    product->name = strdup(name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to create a new warehouse
Warehouse *create_warehouse(int num_products) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->num_products = num_products;
    warehouse->products = malloc(sizeof(Product *) * num_products);
    return warehouse;
}

// Function to add a product to a warehouse
void add_product(Warehouse *warehouse, Product *product) {
    warehouse->products[warehouse->num_products++] = product;
}

// Function to remove a product from a warehouse
void remove_product(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i]->id == id) {
            free(warehouse->products[i]->name);
            free(warehouse->products[i]);
            warehouse->products[i] = warehouse->products[warehouse->num_products - 1];
            warehouse->num_products--;
            break;
        }
    }
}

// Function to get the total value of the products in a warehouse
float get_total_value(Warehouse *warehouse) {
    float total_value = 0;
    for (int i = 0; i < warehouse->num_products; i++) {
        total_value += warehouse->products[i]->quantity * warehouse->products[i]->price;
    }
    return total_value;
}

// Function to print the products in a warehouse
void print_products(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("Product %d: %s, %d, %.2f\n", warehouse->products[i]->id, warehouse->products[i]->name, warehouse->products[i]->quantity, warehouse->products[i]->price);
    }
}

// Main function
int main() {
    // Create a warehouse
    Warehouse *warehouse = create_warehouse(10);

    // Add some products to the warehouse
    Product *product1 = create_product(1, "Product 1", 10, 10.0);
    Product *product2 = create_product(2, "Product 2", 20, 20.0);
    Product *product3 = create_product(3, "Product 3", 30, 30.0);
    add_product(warehouse, product1);
    add_product(warehouse, product2);
    add_product(warehouse, product3);

    // Print the products in the warehouse
    printf("Products in the warehouse:\n");
    print_products(warehouse);

    // Get the total value of the products in the warehouse
    float total_value = get_total_value(warehouse);
    printf("Total value of the products: %.2f\n", total_value);

    // Remove a product from the warehouse
    remove_product(warehouse, 2);

    // Print the products in the warehouse
    printf("\nProducts in the warehouse after removing product 2:\n");
    print_products(warehouse);

    // Get the total value of the products in the warehouse
    total_value = get_total_value(warehouse);
    printf("Total value of the products: %.2f\n", total_value);

    // Free the allocated memory
    for (int i = 0; i < warehouse->num_products; i++) {
        free(warehouse->products[i]->name);
        free(warehouse->products[i]);
    }
    free(warehouse->products);
    free(warehouse);

    return 0;
}