//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Define the inventory structure
typedef struct inventory {
    product products[100];
    int num_products;
} inventory;

// Create a new inventory
inventory *create_inventory() {
    inventory *new_inventory = malloc(sizeof(inventory));
    new_inventory->num_products = 0;
    return new_inventory;
}

// Add a product to the inventory
void add_product(inventory *inv, product new_product) {
    inv->products[inv->num_products] = new_product;
    inv->num_products++;
}

// Find a product in the inventory by name
product *find_product(inventory *inv, char *name) {
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return &inv->products[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(inventory *inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s (%d) - $%.2f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory *inv = create_inventory();

    // Add some products to the inventory
    product apple = {"apple", 10, 0.50};
    product banana = {"banana", 20, 0.75};
    product orange = {"orange", 30, 1.00};
    add_product(inv, apple);
    add_product(inv, banana);
    add_product(inv, orange);

    // Print the inventory
    print_inventory(inv);

    // Find a product in the inventory
    product *found_product = find_product(inv, "banana");
    if (found_product != NULL) {
        printf("Found product: %s (%d) - $%.2f\n", found_product->name, found_product->quantity, found_product->price);
    } else {
        printf("Product not found.\n");
    }

    // Free the inventory
    free(inv);

    return 0;
}