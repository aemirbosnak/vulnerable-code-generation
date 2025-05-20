//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
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
    inventory_system* inv_system = malloc(sizeof(inventory_system));
    inv_system->num_products = 0;
    return inv_system;
}

// Add a product to the inventory system
void add_product(inventory_system* inv_system, product* product) {
    if (inv_system->num_products < MAX_PRODUCTS) {
        inv_system->products[inv_system->num_products] = *product;
        inv_system->num_products++;
    } else {
        printf("Error: Inventory system is full.\n");
    }
}

// Remove a product from the inventory system
void remove_product(inventory_system* inv_system, int id) {
    int i;
    for (i = 0; i < inv_system->num_products; i++) {
        if (inv_system->products[i].id == id) {
            inv_system->products[i] = inv_system->products[inv_system->num_products - 1];
            inv_system->num_products--;
            break;
        }
    }
}

// Update a product in the inventory system
void update_product(inventory_system* inv_system, product* product) {
    int i;
    for (i = 0; i < inv_system->num_products; i++) {
        if (inv_system->products[i].id == product->id) {
            inv_system->products[i] = *product;
            break;
        }
    }
}

// Get a product from the inventory system
product* get_product(inventory_system* inv_system, int id) {
    int i;
    for (i = 0; i < inv_system->num_products; i++) {
        if (inv_system->products[i].id == id) {
            return &inv_system->products[i];
        }
    }
    return NULL;
}

// Print the inventory system
void print_inventory_system(inventory_system* inv_system) {
    int i;
    for (i = 0; i < inv_system->num_products; i++) {
        printf("Product %d:\n", inv_system->products[i].id);
        printf("Name: %s\n", inv_system->products[i].name);
        printf("Quantity: %d\n", inv_system->products[i].quantity);
        printf("Price: %f\n\n", inv_system->products[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory system
    inventory_system* inv_system = create_inventory_system();

    // Add some products to the inventory system
    product product1 = {1, "Product 1", 10, 10.0};
    add_product(inv_system, &product1);
    product product2 = {2, "Product 2", 20, 20.0};
    add_product(inv_system, &product2);
    product product3 = {3, "Product 3", 30, 30.0};
    add_product(inv_system, &product3);

    // Print the inventory system
    print_inventory_system(inv_system);

    // Remove a product from the inventory system
    remove_product(inv_system, 2);

    // Update a product in the inventory system
    product product4 = {1, "Product 1", 40, 15.0};
    update_product(inv_system, &product4);

    // Print the inventory system
    print_inventory_system(inv_system);

    // Get a product from the inventory system
    product* product5 = get_product(inv_system, 3);
    if (product5 != NULL) {
        printf("Product %d:\n", product5->id);
        printf("Name: %s\n", product5->name);
        printf("Quantity: %d\n", product5->quantity);
        printf("Price: %f\n\n", product5->price);
    } else {
        printf("Product not found.\n");
    }

    // Free the memory allocated for the inventory system
    free(inv_system);

    return 0;
}