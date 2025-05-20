//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
struct product {
    int id;
    char name[256];
    int quantity;
    double price;
};

// Define the warehouse structure
struct warehouse {
    struct product *products;
    int num_products;
};

// Create a new product
struct product *create_product(int id, char *name, int quantity, double price) {
    struct product *product = malloc(sizeof(struct product));
    product->id = id;
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Add a product to the warehouse
void add_product(struct warehouse *warehouse, struct product *product) {
    warehouse->products = realloc(warehouse->products, (warehouse->num_products + 1) * sizeof(struct product));
    warehouse->products[warehouse->num_products++] = *product;
}

// Find a product by its ID
struct product *find_product_by_id(struct warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            return &warehouse->products[i];
        }
    }
    return NULL;
}

// Print the warehouse inventory
void print_inventory(struct warehouse *warehouse) {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("Product ID: %d\n", warehouse->products[i].id);
        printf("Product Name: %s\n", warehouse->products[i].name);
        printf("Product Quantity: %d\n", warehouse->products[i].quantity);
        printf("Product Price: %.2f\n\n", warehouse->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    struct warehouse warehouse;
    warehouse.products = NULL;
    warehouse.num_products = 0;

    // Add some products to the warehouse
    add_product(&warehouse, create_product(1, "iPhone", 10, 999.99));
    add_product(&warehouse, create_product(2, "iPad", 5, 799.99));
    add_product(&warehouse, create_product(3, "Macbook", 3, 1499.99));

    // Print the warehouse inventory
    print_inventory(&warehouse);

    // Find a product by its ID
    struct product *product = find_product_by_id(&warehouse, 2);
    if (product) {
        printf("Product found: %s\n", product->name);
    } else {
        printf("Product not found.\n");
    }

    // Free the memory allocated for the warehouse
    free(warehouse.products);

    return 0;
}