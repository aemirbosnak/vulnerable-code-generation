//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the product structure
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
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
void add_product(inventory* inv, product* p) {
    if (inv->num_products < MAX_PRODUCTS) {
        inv->products[inv->num_products++] = *p;
    } else {
        printf("Inventory is full.\n");
    }
}

// Remove a product from the inventory
void remove_product(inventory* inv, int id) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            inv->products[i] = inv->products[inv->num_products - 1];
            inv->num_products--;
            return;
        }
    }
    printf("Product not found.\n");
}

// Update a product in the inventory
void update_product(inventory* inv, product* p) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == p->id) {
            inv->products[i] = *p;
            return;
        }
    }
    printf("Product not found.\n");
}

// Print the inventory
void print_inventory(inventory* inv) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inv->num_products; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
            inv->products[i].id, inv->products[i].name,
            inv->products[i].price, inv->products[i].quantity);
    }
}

// Main function
int main() {
    // Create an inventory
    inventory* inv = create_inventory();

    // Add some products to the inventory
    product p1 = {1, "Product 1", 10.00, 10};
    product p2 = {2, "Product 2", 15.00, 15};
    product p3 = {3, "Product 3", 20.00, 20};
    add_product(inv, &p1);
    add_product(inv, &p2);
    add_product(inv, &p3);

    // Print the inventory
    print_inventory(inv);

    // Remove a product from the inventory
    remove_product(inv, 2);

    // Update a product in the inventory
    product p4 = {1, "Product 1", 12.00, 12};
    update_product(inv, &p4);

    // Print the inventory
    print_inventory(inv);

    // Free the inventory
    free(inv);

    return 0;
}