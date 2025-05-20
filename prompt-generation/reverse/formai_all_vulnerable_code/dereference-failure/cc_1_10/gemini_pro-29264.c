//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory
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
inventory* new_inventory() {
    inventory* inv = malloc(sizeof(inventory));
    inv->num_products = 0;
    return inv;
}

// Add a product to the inventory
void add_product(inventory* inv, product* p) {
    if (inv->num_products < MAX_PRODUCTS) {
        inv->products[inv->num_products++] = *p;
    } else {
        printf("Error: Inventory is full.\n");
    }
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

// Update the quantity of a product in the inventory
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

// Print the inventory
void print_inventory(inventory* inv) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inv->num_products; i++) {
        printf("%s %d %f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory* inv = new_inventory();

    // Add some products to the inventory
    product p1 = {"Apple", 10, 1.0};
    add_product(inv, &p1);
    product p2 = {"Orange", 5, 1.5};
    add_product(inv, &p2);
    product p3 = {"Banana", 15, 2.0};
    add_product(inv, &p3);

    // Print the inventory
    print_inventory(inv);

    // Remove a product from the inventory
    remove_product(inv, "Orange");

    // Update the quantity of a product in the inventory
    update_quantity(inv, "Apple", 20);

    // Print the inventory again
    print_inventory(inv);

    // Free the memory allocated to the inventory
    free(inv);

    return 0;
}