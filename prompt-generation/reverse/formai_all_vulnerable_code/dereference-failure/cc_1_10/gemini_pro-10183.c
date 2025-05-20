//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products and warehouses
#define MAX_PRODUCTS 100
#define MAX_WAREHOUSES 10

// Define the structure of a product
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Define the structure of a warehouse
typedef struct {
    int id;
    char name[50];
    Product products[MAX_PRODUCTS];
    int num_products;
} Warehouse;

// Function to create a new product
Product* create_product(int id, char* name, int quantity, float price) {
    Product* product = (Product*)malloc(sizeof(Product));
    product->id = id;
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to create a new warehouse
Warehouse* create_warehouse(int id, char* name) {
    Warehouse* warehouse = (Warehouse*)malloc(sizeof(Warehouse));
    warehouse->id = id;
    strcpy(warehouse->name, name);
    warehouse->num_products = 0;
    return warehouse;
}

// Function to add a product to a warehouse
void add_product_to_warehouse(Warehouse* warehouse, Product* product) {
    warehouse->products[warehouse->num_products] = *product;
    warehouse->num_products++;
}

// Function to print the details of a product
void print_product(Product* product) {
    printf("Product ID: %d\n", product->id);
    printf("Product Name: %s\n", product->name);
    printf("Product Quantity: %d\n", product->quantity);
    printf("Product Price: %.2f\n", product->price);
}

// Function to print the details of a warehouse
void print_warehouse(Warehouse* warehouse) {
    printf("Warehouse ID: %d\n", warehouse->id);
    printf("Warehouse Name: %s\n", warehouse->name);
    printf("Number of Products: %d\n", warehouse->num_products);
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("Product %d:\n", i + 1);
        print_product(&warehouse->products[i]);
    }
}

// Main function
int main() {
    // Create a warehouse management system
    Warehouse* warehouses[MAX_WAREHOUSES];
    int num_warehouses = 0;

    // Create some products
    Product* product1 = create_product(1, "Product 1", 10, 10.0);
    Product* product2 = create_product(2, "Product 2", 20, 20.0);
    Product* product3 = create_product(3, "Product 3", 30, 30.0);

    // Create some warehouses
    Warehouse* warehouse1 = create_warehouse(1, "Warehouse 1");
    Warehouse* warehouse2 = create_warehouse(2, "Warehouse 2");

    // Add products to warehouses
    add_product_to_warehouse(warehouse1, product1);
    add_product_to_warehouse(warehouse1, product2);
    add_product_to_warehouse(warehouse2, product3);

    // Print the details of the warehouses
    printf("Warehouse 1:\n");
    print_warehouse(warehouse1);
    printf("\n");

    printf("Warehouse 2:\n");
    print_warehouse(warehouse2);

    // Free the allocated memory
    free(product1);
    free(product2);
    free(product3);
    free(warehouse1);
    free(warehouse2);

    return 0;
}