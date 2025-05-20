//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a product
typedef struct product {
    char *name;
    int quantity;
    float price;
} product;

// Define the structure of a product inventory
typedef struct product_inventory {
    product *products;
    int num_products;
} product_inventory;

// Create a new product
product *create_product(char *name, int quantity, float price) {
    product *new_product = malloc(sizeof(product));
    new_product->name = strdup(name);
    new_product->quantity = quantity;
    new_product->price = price;
    return new_product;
}

// Add a product to the inventory
void add_product(product_inventory *inventory, product *new_product) {
    inventory->products = realloc(inventory->products, (inventory->num_products + 1) * sizeof(product));
    inventory->products[inventory->num_products++] = *new_product;
}

// Remove a product from the inventory
void remove_product(product_inventory *inventory, char *name) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            break;
        }
    }
    if (i < inventory->num_products) {
        for (i; i < inventory->num_products - 1; i++) {
            inventory->products[i] = inventory->products[i + 1];
        }
        inventory->num_products--;
    }
}

// Get the total value of the inventory
float get_total_value(product_inventory *inventory) {
    float total_value = 0;
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        total_value += inventory->products[i].quantity * inventory->products[i].price;
    }
    return total_value;
}

// Print the inventory
void print_inventory(product_inventory *inventory) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inventory->num_products; i++) {
        printf("%s: %d units, $%.2f each\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
    printf("Total value: $%.2f\n", get_total_value(inventory));
}

// Main function
int main() {
    // Create a new product inventory
    product_inventory *inventory = malloc(sizeof(product_inventory));
    inventory->products = NULL;
    inventory->num_products = 0;

    // Add some products to the inventory
    add_product(inventory, create_product("Apple", 10, 0.50));
    add_product(inventory, create_product("Orange", 5, 0.75));
    add_product(inventory, create_product("Banana", 15, 1.00));

    // Print the inventory
    print_inventory(inventory);

    // Remove a product from the inventory
    remove_product(inventory, "Orange");

    // Print the inventory again
    print_inventory(inventory);

    // Free the memory allocated for the inventory
    free(inventory->products);
    free(inventory);

    return 0;
}