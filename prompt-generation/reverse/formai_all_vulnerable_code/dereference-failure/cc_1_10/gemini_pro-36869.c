//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Define the structure of the inventory system
typedef struct inventory_system {
    product products[MAX_PRODUCTS];
    int num_products;
} inventory_system;

// Create a new inventory system
inventory_system* create_inventory_system() {
    inventory_system* system = malloc(sizeof(inventory_system));
    system->num_products = 0;
    return system;
}

// Add a product to the inventory system
void add_product(inventory_system* system, product product) {
    if (system->num_products < MAX_PRODUCTS) {
        system->products[system->num_products] = product;
        system->num_products++;
    }
}

// Remove a product from the inventory system
void remove_product(inventory_system* system, char* name) {
    for (int i = 0; i < system->num_products; i++) {
        if (strcmp(system->products[i].name, name) == 0) {
            system->products[i] = system->products[system->num_products - 1];
            system->num_products--;
        }
    }
}

// Find a product in the inventory system
product* find_product(inventory_system* system, char* name) {
    for (int i = 0; i < system->num_products; i++) {
        if (strcmp(system->products[i].name, name) == 0) {
            return &system->products[i];
        }
    }
    return NULL;
}

// Print the inventory system
void print_inventory_system(inventory_system* system) {
    for (int i = 0; i < system->num_products; i++) {
        printf("Product: %s\n", system->products[i].name);
        printf("Quantity: %d\n", system->products[i].quantity);
        printf("Price: %.2f\n\n", system->products[i].price);
    }
}

// Free the memory allocated for the inventory system
void free_inventory_system(inventory_system* system) {
    free(system);
}

// Main function
int main() {
    // Create a new inventory system
    inventory_system* system = create_inventory_system();

    // Add some products to the inventory system
    product product1 = {"Apple", 10, 1.00};
    add_product(system, product1);
    product product2 = {"Orange", 5, 0.50};
    add_product(system, product2);
    product product3 = {"Banana", 15, 0.75};
    add_product(system, product3);

    // Print the inventory system
    print_inventory_system(system);

    // Find a product in the inventory system
    product* product = find_product(system, "Apple");
    if (product != NULL) {
        printf("Product found: %s\n", product->name);
    } else {
        printf("Product not found.\n");
    }

    // Remove a product from the inventory system
    remove_product(system, "Orange");

    // Print the inventory system
    print_inventory_system(system);

    // Free the memory allocated for the inventory system
    free_inventory_system(system);

    return 0;
}