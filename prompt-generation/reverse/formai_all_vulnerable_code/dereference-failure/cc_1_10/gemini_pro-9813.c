//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Structure to represent a warehouse
typedef struct Warehouse {
    int id;
    char name[50];
    int capacity;
    Product *products;
    int num_products;
} Warehouse;

// Function to create a new product
Product *create_product(int id, char *name, int quantity, float price) {
    Product *product = (Product *)malloc(sizeof(Product));
    product->id = id;
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to create a new warehouse
Warehouse *create_warehouse(int id, char *name, int capacity) {
    Warehouse *warehouse = (Warehouse *)malloc(sizeof(Warehouse));
    warehouse->id = id;
    strcpy(warehouse->name, name);
    warehouse->capacity = capacity;
    warehouse->products = NULL;
    warehouse->num_products = 0;
    return warehouse;
}

// Function to add a product to a warehouse
void add_product_to_warehouse(Warehouse *warehouse, Product *product) {
    if (warehouse->num_products == warehouse->capacity) {
        printf("Error: The warehouse is full!\n");
        return;
    }
    warehouse->products = (Product *)realloc(warehouse->products, (warehouse->num_products + 1) * sizeof(Product));
    warehouse->products[warehouse->num_products] = *product;
    warehouse->num_products++;
}

// Function to remove a product from a warehouse
void remove_product_from_warehouse(Warehouse *warehouse, int product_id) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == product_id) {
            break;
        }
    }
    if (i == warehouse->num_products) {
        printf("Error: The product is not in the warehouse!\n");
        return;
    }
    for (i; i < warehouse->num_products - 1; i++) {
        warehouse->products[i] = warehouse->products[i + 1];
    }
    warehouse->num_products--;
}

// Function to print the products in a warehouse
void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse: %s\n", warehouse->name);
    printf("Capacity: %d\n", warehouse->capacity);
    printf("Products: %d\n", warehouse->num_products);
    for (int i = 0; i < warehouse->num_products; i++) {
        printf(" - %s (%d, %d, %.2f)\n", warehouse->products[i].name, warehouse->products[i].id, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

int main() {
    // Create a warehouse
    Warehouse *warehouse = create_warehouse(1, "The Funny Warehouse", 100);

    // Create some products
    Product *product1 = create_product(1, "Bananas", 100, 0.50);
    Product *product2 = create_product(2, "Apples", 50, 0.75);
    Product *product3 = create_product(3, "Oranges", 25, 1.00);

    // Add the products to the warehouse
    add_product_to_warehouse(warehouse, product1);
    add_product_to_warehouse(warehouse, product2);
    add_product_to_warehouse(warehouse, product3);

    // Print the warehouse
    print_warehouse(warehouse);

    // Remove a product from the warehouse
    remove_product_from_warehouse(warehouse, 2);

    // Print the warehouse again
    printf("\n");
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse and products
    free(warehouse->products);
    free(warehouse);
    free(product1);
    free(product2);
    free(product3);

    return 0;
}