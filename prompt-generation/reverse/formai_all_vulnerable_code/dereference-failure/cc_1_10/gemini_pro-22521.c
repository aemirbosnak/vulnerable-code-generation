//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Structure to represent a warehouse
typedef struct warehouse {
    char name[50];
    int num_products;
    product *products;
} warehouse;

// Function to create a new warehouse
warehouse *create_warehouse(char *name) {
    warehouse *new_warehouse = malloc(sizeof(warehouse));
    strcpy(new_warehouse->name, name);
    new_warehouse->num_products = 0;
    new_warehouse->products = NULL;
    return new_warehouse;
}

// Function to add a new product to a warehouse
void add_product(warehouse *warehouse, product *product) {
    warehouse->num_products++;
    warehouse->products = realloc(warehouse->products, warehouse->num_products * sizeof(product));
    warehouse->products[warehouse->num_products - 1] = *product;
}

// Function to remove a product from a warehouse
void remove_product(warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            warehouse->num_products--;
            warehouse->products[i] = warehouse->products[warehouse->num_products];
            warehouse->products = realloc(warehouse->products, warehouse->num_products * sizeof(product));
            break;
        }
    }
}

// Function to print the inventory of a warehouse
void print_inventory(warehouse *warehouse) {
    int i;
    printf("Inventory of warehouse %s:\n", warehouse->name);
    for (i = 0; i < warehouse->num_products; i++) {
        printf("%s %d %.2f\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *warehouse = create_warehouse("Warehouse 1");

    // Add some products to the warehouse
    product product1 = {"Product 1", 10, 10.0};
    add_product(warehouse, &product1);
    product product2 = {"Product 2", 20, 20.0};
    add_product(warehouse, &product2);
    product product3 = {"Product 3", 30, 30.0};
    add_product(warehouse, &product3);

    // Print the inventory of the warehouse
    print_inventory(warehouse);

    // Remove a product from the warehouse
    remove_product(warehouse, "Product 2");

    // Print the inventory of the warehouse again
    print_inventory(warehouse);

    return 0;
}