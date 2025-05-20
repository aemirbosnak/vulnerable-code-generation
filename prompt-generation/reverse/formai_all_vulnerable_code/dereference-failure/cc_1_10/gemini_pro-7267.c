//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
    int id;
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
inventory *create_inventory() {
    inventory *inv = malloc(sizeof(inventory));
    inv->num_products = 0;
    return inv;
}

// Add a product to the inventory
void add_product(inventory *inv, product *prod) {
    if (inv->num_products >= MAX_PRODUCTS) {
        printf("Error: Inventory is full!\n");
        return;
    }

    inv->products[inv->num_products] = *prod;
    inv->num_products++;
}

// Remove a product from the inventory
void remove_product(inventory *inv, int id) {
    int i;

    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            inv->products[i] = inv->products[inv->num_products - 1];
            inv->num_products--;
            return;
        }
    }

    printf("Error: Product not found!\n");
}

// Find a product in the inventory by its ID
product *find_product_by_id(inventory *inv, int id) {
    int i;

    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            return &inv->products[i];
        }
    }

    return NULL;
}

// Find a product in the inventory by its name
product *find_product_by_name(inventory *inv, char *name) {
    int i;

    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return &inv->products[i];
        }
    }

    return NULL;
}

// Print the inventory
void print_inventory(inventory *inv) {
    int i;

    printf("Inventory:\n");
    for (i = 0; i < inv->num_products; i++) {
        printf("%d %s %d %.2f\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory *inv = create_inventory();

    // Add some products to the inventory
    product prod1 = {1, "Apple", 10, 1.00};
    product prod2 = {2, "Orange", 5, 1.50};
    product prod3 = {3, "Banana", 15, 2.00};
    add_product(inv, &prod1);
    add_product(inv, &prod2);
    add_product(inv, &prod3);

    // Print the inventory
    print_inventory(inv);

    // Find a product in the inventory by its ID
    product *prod = find_product_by_id(inv, 2);
    if (prod != NULL) {
        printf("Found product: %d %s %d %.2f\n", prod->id, prod->name, prod->quantity, prod->price);
    } else {
        printf("Product not found!\n");
    }

    // Remove a product from the inventory
    remove_product(inv, 3);

    // Print the inventory again
    print_inventory(inv);

    return 0;
}