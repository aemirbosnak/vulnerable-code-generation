//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Structure to represent a warehouse
typedef struct warehouse {
    int id;
    char name[50];
    int capacity;
    product *products; // Array of products in the warehouse
    int num_products; // Number of products in the warehouse
} warehouse;

// Function to create a new product
product *create_product(int id, char *name, int quantity, float price) {
    product *new_product = (product *)malloc(sizeof(product));
    new_product->id = id;
    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->price = price;
    return new_product;
}

// Function to create a new warehouse
warehouse *create_warehouse(int id, char *name, int capacity) {
    warehouse *new_warehouse = (warehouse *)malloc(sizeof(warehouse));
    new_warehouse->id = id;
    strcpy(new_warehouse->name, name);
    new_warehouse->capacity = capacity;
    new_warehouse->products = (product *)malloc(capacity * sizeof(product));
    new_warehouse->num_products = 0;
    return new_warehouse;
}

// Function to add a product to a warehouse
void add_product(warehouse *warehouse, product *product) {
    if (warehouse->num_products < warehouse->capacity) {
        warehouse->products[warehouse->num_products] = *product;
        warehouse->num_products++;
    } else {
        printf("Warehouse is full. Cannot add more products.\n");
    }
}

// Function to remove a product from a warehouse
void remove_product(warehouse *warehouse, int product_id) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == product_id) {
            warehouse->products[i] = warehouse->products[warehouse->num_products - 1];
            warehouse->num_products--;
            break;
        }
    }
}

// Function to print the products in a warehouse
void print_products(warehouse *warehouse) {
    int i;
    printf("Products in warehouse %s:\n", warehouse->name);
    for (i = 0; i < warehouse->num_products; i++) {
        printf("%d %s %d %.2f\n", warehouse->products[i].id, warehouse->products[i].name, warehouse->products[i].quantity,
               warehouse->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *warehouse1 = create_warehouse(1, "Warehouse 1", 10);

    // Create some products
    product *product1 = create_product(1, "Product 1", 10, 10.0);
    product *product2 = create_product(2, "Product 2", 20, 20.0);
    product *product3 = create_product(3, "Product 3", 30, 30.0);

    // Add the products to the warehouse
    add_product(warehouse1, product1);
    add_product(warehouse1, product2);
    add_product(warehouse1, product3);

    // Print the products in the warehouse
    print_products(warehouse1);

    // Remove a product from the warehouse
    remove_product(warehouse1, 2);

    // Print the products in the warehouse again
    print_products(warehouse1);

    return 0;
}