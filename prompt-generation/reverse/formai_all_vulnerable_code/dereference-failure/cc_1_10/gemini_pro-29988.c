//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
    char name[50];        // The name of the product
    int quantity;       // The quantity of the product in stock
    double price;        // The price of the product
} product;

// Define the structure of the inventory
typedef struct inventory {
    product products[MAX_PRODUCTS];  // The array of products in the inventory
    int num_products;             // The number of products in the inventory
} inventory;

// Create a new inventory
inventory* create_inventory() {
    inventory* inv = malloc(sizeof(inventory));
    inv->num_products = 0;
    return inv;
}

// Add a product to the inventory
void add_product(inventory* inv, const char* name, int quantity, double price) {
    if (inv->num_products >= MAX_PRODUCTS) {
        printf("Error: The inventory is full.\n");
        return;
    }

    strcpy(inv->products[inv->num_products].name, name);
    inv->products[inv->num_products].quantity = quantity;
    inv->products[inv->num_products].price = price;
    inv->num_products++;
}

// Remove a product from the inventory
void remove_product(inventory* inv, const char* name) {
    int i;

    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            break;
        }
    }

    if (i == inv->num_products) {
        printf("Error: The product %s was not found in the inventory.\n", name);
        return;
    }

    for (; i < inv->num_products - 1; i++) {
        inv->products[i] = inv->products[i + 1];
    }

    inv->num_products--;
}

// Get the quantity of a product in the inventory
int get_product_quantity(inventory* inv, const char* name) {
    int i;

    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return inv->products[i].quantity;
        }
    }

    return 0;
}

// Get the price of a product in the inventory
double get_product_price(inventory* inv, const char* name) {
    int i;

    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return inv->products[i].price;
        }
    }

    return 0.0;
}

// Print the inventory
void print_inventory(inventory* inv) {
    int i;

    printf("Inventory:\n");
    for (i = 0; i < inv->num_products; i++) {
        printf("    %s: %d units at $%.2f each\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Free the memory allocated for the inventory
void free_inventory(inventory* inv) {
    free(inv);
}

// Main function
int main() {
    inventory* inv = create_inventory();

    // Add some products to the inventory
    add_product(inv, "Apple", 10, 0.50);
    add_product(inv, "Orange", 15, 0.75);
    add_product(inv, "Banana", 20, 1.00);

    // Print the inventory
    print_inventory(inv);

    // Remove a product from the inventory
    remove_product(inv, "Orange");

    // Print the inventory again
    print_inventory(inv);

    // Free the memory allocated for the inventory
    free_inventory(inv);

    return 0;
}