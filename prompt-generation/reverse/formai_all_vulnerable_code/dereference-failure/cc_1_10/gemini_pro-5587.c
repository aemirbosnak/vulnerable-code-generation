//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory.
#define MAX_PRODUCTS 100

// Define the structure of a product.
typedef struct {
    char name[50];
    int quantity;
    float price;
} product;

// Define the structure of the product inventory system.
typedef struct {
    product products[MAX_PRODUCTS];
    int num_products;
} inventory;

// Create a new product inventory system.
inventory* create_inventory() {
    inventory* inv = malloc(sizeof(inventory));
    inv->num_products = 0;
    return inv;
}

// Add a new product to the inventory.
void add_product(inventory* inv, product* product) {
    if (inv->num_products < MAX_PRODUCTS) {
        inv->products[inv->num_products] = *product;
        inv->num_products++;
    } else {
        printf("Error: Inventory is full.\n");
    }
}

// Remove a product from the inventory.
void remove_product(inventory* inv, char* name) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            inv->products[i] = inv->products[inv->num_products - 1];
            inv->num_products--;
            return;
        }
    }
    printf("Error: Product not found.\n");
}

// Update the quantity of a product in the inventory.
void update_quantity(inventory* inv, char* name, int quantity) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            inv->products[i].quantity = quantity;
            return;
        }
    }
    printf("Error: Product not found.\n");
}

// Get the total value of the inventory.
float get_total_value(inventory* inv) {
    float total_value = 0;
    int i;
    for (i = 0; i < inv->num_products; i++) {
        total_value += inv->products[i].quantity * inv->products[i].price;
    }
    return total_value;
}

// Print the inventory to the console.
void print_inventory(inventory* inv) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inv->num_products; i++) {
        printf("  %s\t%d\t%.2f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
    printf("Total value: %.2f\n", get_total_value(inv));
}

// Free the memory allocated for the inventory.
void free_inventory(inventory* inv) {
    free(inv);
}

// Main function.
int main() {
    // Create a new inventory.
    inventory* inv = create_inventory();

    // Add some products to the inventory.
    product product1 = {"Apple", 10, 1.00};
    add_product(inv, &product1);
    product product2 = {"Orange", 5, 1.50};
    add_product(inv, &product2);
    product product3 = {"Banana", 15, 0.50};
    add_product(inv, &product3);

    // Remove a product from the inventory.
    remove_product(inv, "Banana");

    // Update the quantity of a product in the inventory.
    update_quantity(inv, "Apple", 20);

    // Print the inventory to the console.
    print_inventory(inv);

    // Free the memory allocated for the inventory.
    free_inventory(inv);

    return 0;
}