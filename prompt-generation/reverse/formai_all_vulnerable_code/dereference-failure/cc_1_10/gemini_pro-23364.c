//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Define the structure of the inventory
typedef struct {
    Product products[MAX_PRODUCTS];
    int num_products;
} Inventory;

// Create a new inventory
Inventory* create_inventory() {
    Inventory* inventory = malloc(sizeof(Inventory));
    inventory->num_products = 0;
    return inventory;
}

// Add a product to the inventory
void add_product(Inventory* inventory, Product product) {
    if (inventory->num_products < MAX_PRODUCTS) {
        inventory->products[inventory->num_products] = product;
        inventory->num_products++;
    } else {
        printf("Error: Inventory is full.\n");
    }
}

// Remove a product from the inventory
void remove_product(Inventory* inventory, int id) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (inventory->products[i].id == id) {
            inventory->products[i] = inventory->products[inventory->num_products - 1];
            inventory->num_products--;
            break;
        }
    }
}

// Update the quantity of a product in the inventory
void update_product(Inventory* inventory, int id, int quantity) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (inventory->products[i].id == id) {
            inventory->products[i].quantity = quantity;
            break;
        }
    }
}

// Get the product with the specified ID
Product* get_product(Inventory* inventory, int id) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (inventory->products[i].id == id) {
            return &inventory->products[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(Inventory* inventory) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        printf("Product %d: %s, %d, %f\n", inventory->products[i].id, inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

// Destroy the inventory
void destroy_inventory(Inventory* inventory) {
    free(inventory);
}

// Main function
int main() {
    // Create a new inventory
    Inventory* inventory = create_inventory();

    // Add some products to the inventory
    Product product1 = {1, "Apple", 10, 1.0};
    add_product(inventory, product1);
    Product product2 = {2, "Banana", 20, 2.0};
    add_product(inventory, product2);
    Product product3 = {3, "Orange", 30, 3.0};
    add_product(inventory, product3);

    // Print the inventory
    print_inventory(inventory);

    // Remove a product from the inventory
    remove_product(inventory, 2);

    // Update the quantity of a product in the inventory
    update_product(inventory, 1, 15);

    // Get the product with the specified ID
    Product* product = get_product(inventory, 1);
    printf("Product %d: %s, %d, %f\n", product->id, product->name, product->quantity, product->price);

    // Destroy the inventory
    destroy_inventory(inventory);

    return 0;
}