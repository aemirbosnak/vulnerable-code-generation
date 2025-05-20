//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Define the product structure
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Define the inventory structure
typedef struct inventory {
    product products[MAX_PRODUCTS];
    int num_products;
} inventory;

// Create a new inventory
inventory* create_inventory() {
    inventory* inv = malloc(sizeof(inventory));
    inv->num_products = 0;
    return inv;
}

// Add a product to the inventory
void add_product(inventory* inv, char* name, int quantity, float price) {
    // Check if the inventory is full
    if (inv->num_products >= MAX_PRODUCTS) {
        printf("Error: inventory is full\n");
        return;
    }

    // Add the product to the inventory
    strcpy(inv->products[inv->num_products].name, name);
    inv->products[inv->num_products].quantity = quantity;
    inv->products[inv->num_products].price = price;
    inv->num_products++;
}

// Remove a product from the inventory
void remove_product(inventory* inv, char* name) {
    // Find the product in the inventory
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            break;
        }
    }

    // Check if the product was found
    if (i == inv->num_products) {
        printf("Error: product not found\n");
        return;
    }

    // Remove the product from the inventory
    for (i++; i < inv->num_products; i++) {
        inv->products[i - 1] = inv->products[i];
    }
    inv->num_products--;
}

// Update the quantity of a product in the inventory
void update_product(inventory* inv, char* name, int quantity) {
    // Find the product in the inventory
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            break;
        }
    }

    // Check if the product was found
    if (i == inv->num_products) {
        printf("Error: product not found\n");
        return;
    }

    // Update the product's quantity
    inv->products[i].quantity = quantity;
}

// Print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("  %s: %d units, $%.2f each\n",
            inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Free the memory allocated for the inventory
void free_inventory(inventory* inv) {
    free(inv);
}

// Main function
int main() {
    // Create a new inventory
    inventory* inv = create_inventory();

    // Add some products to the inventory
    add_product(inv, "Apple", 10, 0.50);
    add_product(inv, "Orange", 15, 0.75);
    add_product(inv, "Banana", 20, 1.00);

    // Print the inventory
    print_inventory(inv);

    // Remove a product from the inventory
    remove_product(inv, "Banana");

    // Update the quantity of a product in the inventory
    update_product(inv, "Apple", 15);

    // Print the inventory again
    print_inventory(inv);

    // Free the memory allocated for the inventory
    free_inventory(inv);

    return 0;
}