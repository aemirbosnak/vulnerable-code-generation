//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product {
    int id;
    char *name;
    int quantity;
    float price;
} product;

// Define the inventory structure
typedef struct inventory {
    int num_products;
    product *products;
} inventory;

// Create a new product
product *create_product(int id, char *name, int quantity, float price) {
    product *new_product = malloc(sizeof(product));
    new_product->id = id;
    new_product->name = strdup(name);
    new_product->quantity = quantity;
    new_product->price = price;
    return new_product;
}

// Create a new inventory
inventory *create_inventory() {
    inventory *new_inventory = malloc(sizeof(inventory));
    new_inventory->num_products = 0;
    new_inventory->products = NULL;
    return new_inventory;
}

// Add a product to the inventory
void add_product(inventory *inv, product *product) {
    inv->num_products++;
    inv->products = realloc(inv->products, sizeof(product) * inv->num_products);
    inv->products[inv->num_products - 1] = *product;
}

// Remove a product from the inventory
void remove_product(inventory *inv, int product_id) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == product_id) {
            free(inv->products[i].name);
            memmove(&inv->products[i], &inv->products[i + 1], sizeof(product) * (inv->num_products - i - 1));
            inv->num_products--;
            inv->products = realloc(inv->products, sizeof(product) * inv->num_products);
            break;
        }
    }
}

// Print the inventory
void print_inventory(inventory *inv) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inv->num_products; i++) {
        printf("  %d %s %d %.2f\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Free the inventory
void free_inventory(inventory *inv) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        free(inv->products[i].name);
    }
    free(inv->products);
    free(inv);
}

// Main function
int main() {
    // Create a new inventory
    inventory *inv = create_inventory();

    // Add some products to the inventory
    add_product(inv, create_product(1, "Apple", 10, 0.50));
    add_product(inv, create_product(2, "Orange", 15, 0.75));
    add_product(inv, create_product(3, "Banana", 20, 1.00));

    // Print the inventory
    print_inventory(inv);

    // Remove a product from the inventory
    remove_product(inv, 2);

    // Print the inventory again
    print_inventory(inv);

    // Free the inventory
    free_inventory(inv);

    return 0;
}