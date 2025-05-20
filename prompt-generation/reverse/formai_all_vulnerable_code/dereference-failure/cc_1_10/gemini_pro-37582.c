//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that can be stored in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
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
void add_product(inventory *inv, product *p) {
    if (inv->num_products < MAX_PRODUCTS) {
        inv->products[inv->num_products++] = *p;
    } else {
        printf("Error: Inventory is full.\n");
    }
}

// Remove a product from the inventory
void remove_product(inventory *inv, int id) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            inv->products[i] = inv->products[inv->num_products - 1];
            inv->num_products--;
            break;
        }
    }
}

// Find a product in the inventory by its ID
product *find_product(inventory *inv, int id) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
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
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", inv->products[i].id, inv->products[i].name, inv->products[i].price, inv->products[i].quantity);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory *inv = create_inventory();

    // Add some products to the inventory
    product p1 = {1, "Apple", 1.00, 10};
    product p2 = {2, "Orange", 1.50, 15};
    product p3 = {3, "Banana", 2.00, 20};
    add_product(inv, &p1);
    add_product(inv, &p2);
    add_product(inv, &p3);

    // Print the inventory
    print_inventory(inv);

    // Find a product in the inventory by its ID
    product *p = find_product(inv, 2);
    if (p != NULL) {
        printf("Found product: %s\n", p->name);
    } else {
        printf("Product not found.\n");
    }

    // Remove a product from the inventory
    remove_product(inv, 3);

    // Print the inventory again
    print_inventory(inv);

    // Free the memory allocated for the inventory
    free(inv);

    return 0;
}