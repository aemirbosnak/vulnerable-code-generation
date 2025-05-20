//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Define the product inventory system
typedef struct product_inventory_system {
    int num_products;
    product *products;
} product_inventory_system;

// Create a new product
product *create_product(int id, char *name, int quantity, float price) {
    product *p = (product *)malloc(sizeof(product));
    p->id = id;
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Add a product to the inventory system
void add_product(product_inventory_system *system, product *p) {
    system->num_products++;
    system->products = (product *)realloc(system->products, system->num_products * sizeof(product));
    system->products[system->num_products - 1] = *p;
}

// Find a product by ID
product *find_product_by_id(product_inventory_system *system, int id) {
    for (int i = 0; i < system->num_products; i++) {
        if (system->products[i].id == id) {
            return &system->products[i];
        }
    }
    return NULL;
}

// Print the inventory system
void print_inventory_system(product_inventory_system *system) {
    printf("Product Inventory System\n");
    printf("------------------------\n");
    for (int i = 0; i < system->num_products; i++) {
        printf("ID: %d\n", system->products[i].id);
        printf("Name: %s\n", system->products[i].name);
        printf("Quantity: %d\n", system->products[i].quantity);
        printf("Price: %.2f\n", system->products[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new product inventory system
    product_inventory_system *system = (product_inventory_system *)malloc(sizeof(product_inventory_system));
    system->num_products = 0;
    system->products = NULL;

    // Add some products to the inventory system
    product *p1 = create_product(1, "Apple", 10, 1.00);
    add_product(system, p1);
    product *p2 = create_product(2, "Orange", 5, 1.50);
    add_product(system, p2);
    product *p3 = create_product(3, "Banana", 15, 2.00);
    add_product(system, p3);

    // Print the inventory system
    print_inventory_system(system);

    // Find a product by ID
    product *p = find_product_by_id(system, 2);
    if (p != NULL) {
        printf("Product found:\n");
        printf("ID: %d\n", p->id);
        printf("Name: %s\n", p->name);
        printf("Quantity: %d\n", p->quantity);
        printf("Price: %.2f\n", p->price);
    } else {
        printf("Product not found.\n");
    }

    // Free the memory allocated for the inventory system
    free(system->products);
    free(system);

    return 0;
}