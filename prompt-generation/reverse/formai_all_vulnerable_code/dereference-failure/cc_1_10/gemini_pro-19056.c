//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: modular
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
    Product *products;
    int num_products;
    int capacity;
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
Warehouse *create_warehouse(int capacity) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->products = malloc(sizeof(Product) * capacity);
    warehouse->num_products = 0;
    warehouse->capacity = capacity;
    return warehouse;
}

// Function to add a product to a warehouse
void add_product(Warehouse *warehouse, Product *product) {
    if (warehouse->num_products == warehouse->capacity) {
        printf("Warehouse is full!\n");
        return;
    }
    warehouse->products[warehouse->num_products++] = *product;
}

// Function to remove a product from a warehouse
void remove_product(Warehouse *warehouse, int id) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            warehouse->products[i] = warehouse->products[warehouse->num_products - 1];
            warehouse->num_products--;
            return;
        }
    }
    printf("Product not found!\n");
}

// Function to print the products in a warehouse
void print_products(Warehouse *warehouse) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %.2f\n",
            warehouse->products[i].id,
            warehouse->products[i].name,
            warehouse->products[i].quantity,
            warehouse->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse with a capacity of 10 products
    Warehouse *warehouse = create_warehouse(10);

    // Create some products
    Product *product1 = create_product(1, "Apple", 10, 0.5);
    Product *product2 = create_product(2, "Orange", 20, 0.75);
    Product *product3 = create_product(3, "Banana", 30, 1.0);

    // Add the products to the warehouse
    add_product(warehouse, product1);
    add_product(warehouse, product2);
    add_product(warehouse, product3);

    // Print the products in the warehouse
    printf("Products in the warehouse:\n");
    print_products(warehouse);

    // Remove a product from the warehouse
    remove_product(warehouse, 2);

    // Print the products in the warehouse again
    printf("\nProducts in the warehouse after removing product 2:\n");
    print_products(warehouse);

    // Free the memory allocated for the products and the warehouse
    free(product1);
    free(product2);
    free(product3);
    free(warehouse->products);
    free(warehouse);

    return 0;
}