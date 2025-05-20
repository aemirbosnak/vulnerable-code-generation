//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a product
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Struct to represent a warehouse
typedef struct warehouse {
    char name[50];
    int num_products;
    product *products;
} warehouse;

// Function to create a new product
product *create_product(char *name, int quantity, float price) {
    product *new_product = (product *)malloc(sizeof(product));

    strcpy(new_product->name, name);
    new_product->quantity = quantity;
    new_product->price = price;

    return new_product;
}

// Function to create a new warehouse
warehouse *create_warehouse(char *name) {
    warehouse *new_warehouse = (warehouse *)malloc(sizeof(warehouse));

    strcpy(new_warehouse->name, name);
    new_warehouse->num_products = 0;
    new_warehouse->products = NULL;

    return new_warehouse;
}

// Function to add a product to a warehouse
void add_product(warehouse *warehouse, product *product) {
    warehouse->products = realloc(warehouse->products, (warehouse->num_products + 1) * sizeof(product));
    warehouse->products[warehouse->num_products] = *product;
    warehouse->num_products++;
}

// Function to print the contents of a warehouse
void print_warehouse(warehouse *warehouse) {
    printf("Warehouse: %s\n", warehouse->name);
    printf("Number of products: %d\n", warehouse->num_products);
    printf("Products:\n");
    for (int i = 0; i < warehouse->num_products; i++) {
        printf(" - %s: %d units, $%.2f each\n",
               warehouse->products[i].name,
               warehouse->products[i].quantity,
               warehouse->products[i].price);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *warehouse = create_warehouse("My Warehouse");

    // Add some products to the warehouse
    add_product(warehouse, create_product("Apples", 100, 0.50));
    add_product(warehouse, create_product("Oranges", 50, 0.75));
    add_product(warehouse, create_product("Bananas", 75, 0.60));

    // Print the contents of the warehouse
    print_warehouse(warehouse);

    return 0;
}