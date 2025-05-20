//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the product struct
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product_t;

// Define the inventory struct
typedef struct inventory {
    product_t products[MAX_PRODUCTS];
    int num_products;
} inventory_t;

// Create a new inventory
inventory_t* create_inventory() {
    inventory_t* inventory = (inventory_t*)malloc(sizeof(inventory_t));
    inventory->num_products = 0;
    return inventory;
}

// Add a product to the inventory
void add_product(inventory_t* inventory, product_t product) {
    // Check if the inventory is full
    if (inventory->num_products >= MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    // Add the product to the inventory
    inventory->products[inventory->num_products] = product;
    inventory->num_products++;
}

// Remove a product from the inventory
void remove_product(inventory_t* inventory, char* name) {
    // Find the product in the inventory
    int index = -1;
    for (int i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // Check if the product was found
    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    // Remove the product from the inventory
    for (int i = index; i < inventory->num_products - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }
    inventory->num_products--;
}

// Print the inventory
void print_inventory(inventory_t* inventory) {
    // Print the header
    printf("%-50s%-10s%-10s\n", "Name", "Quantity", "Price");

    // Print the products
    for (int i = 0; i < inventory->num_products; i++) {
        printf("%-50s%-10d%-10.2f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

// Get the total value of the inventory
float get_total_value(inventory_t* inventory) {
    float total_value = 0;

    // Calculate the total value of the inventory
    for (int i = 0; i < inventory->num_products; i++) {
        total_value += inventory->products[i].price * inventory->products[i].quantity;
    }

    return total_value;
}

// Main function
int main() {
    // Create a new inventory
    inventory_t* inventory = create_inventory();

    // Add some products to the inventory
    product_t product1 = {"Apple", 10, 0.50};
    add_product(inventory, product1);
    product_t product2 = {"Orange", 5, 0.75};
    add_product(inventory, product2);
    product_t product3 = {"Banana", 15, 1.00};
    add_product(inventory, product3);

    // Print the inventory
    printf("Inventory:\n");
    print_inventory(inventory);

    // Get the total value of the inventory
    float total_value = get_total_value(inventory);
    printf("Total value of inventory: %.2f\n", total_value);

    // Remove a product from the inventory
    remove_product(inventory, "Orange");

    // Print the inventory
    printf("Inventory after removing Orange:\n");
    print_inventory(inventory);

    // Free the inventory
    free(inventory);

    return 0;
}