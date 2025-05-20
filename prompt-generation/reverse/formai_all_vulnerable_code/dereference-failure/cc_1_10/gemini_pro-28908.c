//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products and the maximum length of a product name
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Define the structure of a product
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

// Define the structure of the inventory system
typedef struct {
    Product products[MAX_PRODUCTS];
    int num_products;
} InventorySystem;

// Create a new inventory system
InventorySystem *create_inventory_system() {
    InventorySystem *inventory_system = malloc(sizeof(InventorySystem));
    inventory_system->num_products = 0;
    return inventory_system;
}

// Add a product to the inventory system
void add_product(InventorySystem *inventory_system, const char *name, int quantity, float price) {
    if (inventory_system->num_products >= MAX_PRODUCTS) {
        printf("Error: Cannot add more products to the inventory system.\n");
        return;
    }

    strcpy(inventory_system->products[inventory_system->num_products].name, name);
    inventory_system->products[inventory_system->num_products].quantity = quantity;
    inventory_system->products[inventory_system->num_products].price = price;
    inventory_system->num_products++;
}

// Print the inventory system
void print_inventory_system(InventorySystem *inventory_system) {
    for (int i = 0; i < inventory_system->num_products; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", inventory_system->products[i].name);
        printf("Quantity: %d\n", inventory_system->products[i].quantity);
        printf("Price: %.2f\n\n", inventory_system->products[i].price);
    }
}

// Free the memory allocated for the inventory system
void free_inventory_system(InventorySystem *inventory_system) {
    free(inventory_system);
}

// Main function
int main() {
    // Create a new inventory system
    InventorySystem *inventory_system = create_inventory_system();

    // Add some products to the inventory system
    add_product(inventory_system, "Apple", 10, 0.50);
    add_product(inventory_system, "Orange", 15, 0.75);
    add_product(inventory_system, "Banana", 20, 1.00);

    // Print the inventory system
    print_inventory_system(inventory_system);

    // Free the memory allocated for the inventory system
    free_inventory_system(inventory_system);

    return 0;
}