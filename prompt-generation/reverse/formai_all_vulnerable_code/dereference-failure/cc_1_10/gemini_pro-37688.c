//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Define the structure of the inventory
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
void add_product(inventory* inv, product* p) {
    if (inv->num_products >= MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    inv->products[inv->num_products] = *p;
    inv->num_products++;
}

// Remove a product from the inventory
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

// Get the total value of the inventory
float get_total_value(inventory* inv) {
    int i;
    float total_value = 0;

    for (i = 0; i < inv->num_products; i++) {
        total_value += inv->products[i].quantity * inv->products[i].price;
    }

    return total_value;
}

// Print the inventory
void print_inventory(inventory* inv) {
    int i;

    printf("Inventory:\n");
    for (i = 0; i < inv->num_products; i++) {
        printf("%s\t%d\t%.2f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
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
    product p1 = {"Apple", 10, 1.99};
    add_product(inv, &p1);
    product p2 = {"Orange", 5, 2.99};
    add_product(inv, &p2);
    product p3 = {"Banana", 7, 1.49};
    add_product(inv, &p3);

    // Print the inventory
    print_inventory(inv);

    // Get the total value of the inventory
    float total_value = get_total_value(inv);
    printf("Total value of the inventory: %.2f\n", total_value);

    // Remove a product from the inventory
    remove_product(inv, "Orange");

    // Print the inventory
    print_inventory(inv);

    // Free the memory allocated for the inventory
    free_inventory(inv);

    return 0;
}