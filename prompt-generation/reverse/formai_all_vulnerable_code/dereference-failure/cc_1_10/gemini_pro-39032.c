//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products and the maximum length of a product name
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Define the product structure
typedef struct product {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
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
        inv->products[inv->num_products] = *p;
        inv->num_products++;
    } else {
        printf("Error: Inventory is full\n");
    }
}

// Find a product in the inventory by its ID
product* find_product_by_id(inventory* inv, int id) {
    for (int i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            return &inv->products[i];
        }
    }
    return NULL;
}

// Find a product in the inventory by its name
product* find_product_by_name(inventory* inv, char* name) {
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return &inv->products[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%d %s %d %.2f\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Free the inventory
void free_inventory(inventory* inv) {
    free(inv);
}

// Test the inventory system
int main() {
    // Create a new inventory
    inventory* inv = create_inventory();

    // Add some products to the inventory
    product p1 = {1, "Apple", 10, 1.00};
    add_product(inv, &p1);
    product p2 = {2, "Orange", 5, 1.50};
    add_product(inv, &p2);
    product p3 = {3, "Banana", 15, 2.00};
    add_product(inv, &p3);

    // Print the inventory
    print_inventory(inv);

    // Find a product by its ID
    product* p = find_product_by_id(inv, 2);
    if (p != NULL) {
        printf("Found product by ID: %d %s %d %.2f\n", p->id, p->name, p->quantity, p->price);
    } else {
        printf("Product not found\n");
    }

    // Find a product by its name
    p = find_product_by_name(inv, "Banana");
    if (p != NULL) {
        printf("Found product by name: %d %s %d %.2f\n", p->id, p->name, p->quantity, p->price);
    } else {
        printf("Product not found\n");
    }

    // Free the inventory
    free_inventory(inv);

    return 0;
}