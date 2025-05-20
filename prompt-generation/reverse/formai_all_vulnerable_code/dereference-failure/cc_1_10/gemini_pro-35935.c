//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct Product {
    int id;
    char *name;
    float price;
    int quantity;
} Product;

// Warehouse structure
typedef struct Warehouse {
    Product *products;
    int num_products;
} Warehouse;

// Create a new product
Product *create_product(int id, char *name, float price, int quantity) {
    Product *product = malloc(sizeof(Product));
    product->id = id;
    product->name = strdup(name);
    product->price = price;
    product->quantity = quantity;
    return product;
}

// Create a new warehouse
Warehouse *create_warehouse() {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->products = NULL;
    warehouse->num_products = 0;
    return warehouse;
}

// Add a product to the warehouse
void add_product(Warehouse *warehouse, Product *product) {
    warehouse->products = realloc(warehouse->products, (warehouse->num_products + 1) * sizeof(Product));
    warehouse->products[warehouse->num_products++] = *product;
}

// Get a product from the warehouse by its ID
Product *get_product(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            return &warehouse->products[i];
        }
    }
    return NULL;
}

// Remove a product from the warehouse by its ID
void remove_product(Warehouse *warehouse, int id) {
    int index = -1;
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < warehouse->num_products - 1; i++) {
            warehouse->products[i] = warehouse->products[i + 1];
        }
        warehouse->num_products--;
        warehouse->products = realloc(warehouse->products, warehouse->num_products * sizeof(Product));
    }
}

// Print the warehouse's inventory
void print_inventory(Warehouse *warehouse) {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("Product ID: %d\n", warehouse->products[i].id);
        printf("Product Name: %s\n", warehouse->products[i].name);
        printf("Product Price: %f\n", warehouse->products[i].price);
        printf("Product Quantity: %d\n", warehouse->products[i].quantity);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new warehouse
    Warehouse *warehouse = create_warehouse();

    // Add some products to the warehouse
    add_product(warehouse, create_product(1, "Apple", 1.00, 10));
    add_product(warehouse, create_product(2, "Orange", 2.00, 5));
    add_product(warehouse, create_product(3, "Banana", 1.50, 15));

    // Print the warehouse's inventory
    print_inventory(warehouse);

    // Get a product from the warehouse by its ID
    Product *product = get_product(warehouse, 2);

    // Print the product's details
    if (product != NULL) {
        printf("\nProduct Details:\n");
        printf("Product ID: %d\n", product->id);
        printf("Product Name: %s\n", product->name);
        printf("Product Price: %f\n", product->price);
        printf("Product Quantity: %d\n", product->quantity);
    } else {
        printf("Product not found.\n");
    }

    // Remove a product from the warehouse by its ID
    remove_product(warehouse, 3);

    // Print the warehouse's inventory again
    print_inventory(warehouse);

    // Free the memory allocated for the warehouse and its products
    for (int i = 0; i < warehouse->num_products; i++) {
        free(warehouse->products[i].name);
    }
    free(warehouse->products);
    free(warehouse);

    return 0;
}