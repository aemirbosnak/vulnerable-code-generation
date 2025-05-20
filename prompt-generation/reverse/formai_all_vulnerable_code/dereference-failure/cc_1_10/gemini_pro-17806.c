//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
    int id;
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

// Add a new product to the inventory system
void add_product(inventory_system* system, product product) {
    if (system->num_products < MAX_PRODUCTS) {
        system->products[system->num_products] = product;
        system->num_products++;
    } else {
        printf("Error: Inventory system is full.\n");
    }
}

// Search for a product in the inventory system
product* search_product(inventory_system* system, int id) {
    for (int i = 0; i < system->num_products; i++) {
        if (system->products[i].id == id) {
            return &system->products[i];
        }
    }
    return NULL;
}

// Remove a product from the inventory system
void remove_product(inventory_system* system, int id) {
    for (int i = 0; i < system->num_products; i++) {
        if (system->products[i].id == id) {
            for (int j = i; j < system->num_products - 1; j++) {
                system->products[j] = system->products[j + 1];
            }
            system->num_products--;
            break;
        }
    }
}

// Print the inventory system
void print_inventory_system(inventory_system* system) {
    printf("Inventory System\n");
    printf("--------------------\n");
    for (int i = 0; i < system->num_products; i++) {
        printf("%d %s %d %.2f\n", system->products[i].id, system->products[i].name, system->products[i].quantity, system->products[i].price);
    }
}

// Get the total value of the inventory system
float get_total_value(inventory_system* system) {
    float total_value = 0;
    for (int i = 0; i < system->num_products; i++) {
        total_value += system->products[i].quantity * system->products[i].price;
    }
    return total_value;
}

// Main function
int main() {
    // Create a new inventory system
    inventory_system* system = create_inventory_system();

    // Add some products to the inventory system
    product product1 = {1, "Product 1", 10, 10.0};
    product product2 = {2, "Product 2", 20, 20.0};
    product product3 = {3, "Product 3", 30, 30.0};
    add_product(system, product1);
    add_product(system, product2);
    add_product(system, product3);

    // Search for a product in the inventory system
    product* product = search_product(system, 2);
    if (product != NULL) {
        printf("Product found: %d %s %d %.2f\n", product->id, product->name, product->quantity, product->price);
    } else {
        printf("Product not found.\n");
    }

    // Print the inventory system
    print_inventory_system(system);

    // Get the total value of the inventory system
    float total_value = get_total_value(system);
    printf("Total value of inventory system: %.2f\n", total_value);

    // Remove a product from the inventory system
    remove_product(system, 2);

    // Print the inventory system again
    print_inventory_system(system);

    // Free the memory allocated for the inventory system
    free(system);

    return 0;
}