//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a product
typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

// Define a struct to represent a warehouse
typedef struct Warehouse {
    char name[50];
    int capacity;
    Product* products;
} Warehouse;

// Define a function to add a product to a warehouse
void add_product(Warehouse* warehouse, char* name, int quantity, float price) {
    // Allocate memory for a new product
    Product* product = (Product*) malloc(sizeof(Product));
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;

    // Resize the products array to fit the new product
    warehouse->capacity += 1;
    warehouse->products = (Product*) realloc(warehouse->products, warehouse->capacity * sizeof(Product));

    // Add the product to the warehouse
    warehouse->products[warehouse->capacity - 1] = *product;
    free(product);
}

// Define a function to find a product in a warehouse
Product* find_product(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->capacity; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            return &(warehouse->products[i]);
        }
    }
    return NULL;
}

// Define a function to remove a product from a warehouse
void remove_product(Warehouse* warehouse, char* name) {
    Product* product = find_product(warehouse, name);
    if (product != NULL) {
        int index = product - warehouse->products;
        for (int i = index; i < warehouse->capacity - 1; i++) {
            warehouse->products[i] = warehouse->products[i + 1];
        }
        warehouse->capacity -= 1;
        warehouse->products = (Product*) realloc(warehouse->products, warehouse->capacity * sizeof(Product));
    }
}

// Define a function to print the products in a warehouse
void print_products(Warehouse* warehouse) {
    printf("%s:\n", warehouse->name);
    for (int i = 0; i < warehouse->capacity; i++) {
        printf("%s (Quantity: %d, Price: $%.2f)\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

int main() {
    // Create a new warehouse with a capacity of 10 products
    Warehouse* warehouse = (Warehouse*) malloc(sizeof(Warehouse));
    strcpy(warehouse->name, "Main Warehouse");
    warehouse->capacity = 0;
    warehouse->products = (Product*) malloc(10 * sizeof(Product));

    // Add some products to the warehouse
    add_product(warehouse, "Bananas", 100, 0.99);
    add_product(warehouse, "Apples", 50, 1.50);
    add_product(warehouse, "Oranges", 75, 0.75);

    // Print the products in the warehouse
    print_products(warehouse);

    // Remove a product from the warehouse
    remove_product(warehouse, "Apples");

    // Print the products in the warehouse again
    print_products(warehouse);

    // Cleanup memory
    free(warehouse->products);
    free(warehouse);

    return 0;
}