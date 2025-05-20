//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

// Structure to represent a warehouse
typedef struct Warehouse {
    char name[50];
    int num_products;
    Product *products;
} Warehouse;

// Function to create a new product
Product *create_product(char *name, int quantity, float price) {
    Product *product = malloc(sizeof(Product));
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to create a new warehouse
Warehouse *create_warehouse(char *name) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    strcpy(warehouse->name, name);
    warehouse->num_products = 0;
    warehouse->products = NULL;
    return warehouse;
}

// Function to add a product to a warehouse
void add_product(Warehouse *warehouse, Product *product) {
    warehouse->products = realloc(warehouse->products, (warehouse->num_products + 1) * sizeof(Product));
    warehouse->products[warehouse->num_products++] = *product;
}

// Function to remove a product from a warehouse
void remove_product(Warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            break;
        }
    }
    if (i < warehouse->num_products) {
        for (int j = i + 1; j < warehouse->num_products; j++) {
            warehouse->products[j - 1] = warehouse->products[j];
        }
        warehouse->num_products--;
        warehouse->products = realloc(warehouse->products, warehouse->num_products * sizeof(Product));
    }
}

// Function to print the details of a warehouse
void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse: %s\n", warehouse->name);
    printf("Number of products: %d\n", warehouse->num_products);
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", warehouse->products[i].name);
        printf("Quantity: %d\n", warehouse->products[i].quantity);
        printf("Price: %.2f\n", warehouse->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse("My Warehouse");

    // Add some products to the warehouse
    add_product(warehouse, create_product("Product 1", 10, 10.0));
    add_product(warehouse, create_product("Product 2", 20, 20.0));
    add_product(warehouse, create_product("Product 3", 30, 30.0));

    // Print the details of the warehouse
    print_warehouse(warehouse);

    // Remove a product from the warehouse
    remove_product(warehouse, "Product 2");

    // Print the details of the warehouse again
    print_warehouse(warehouse);

    return 0;
}