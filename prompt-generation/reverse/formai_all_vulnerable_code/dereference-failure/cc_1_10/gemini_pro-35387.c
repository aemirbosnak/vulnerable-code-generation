//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the product structure
typedef struct product {
    char name[50];
    int quantity;
    double price;
} product;

// Define the inventory structure
typedef struct inventory {
    int num_products;
    product *products;
} inventory;

// Create a new product
product *create_product(char *name, int quantity, double price) {
    product *p = malloc(sizeof(product));
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Add a product to the inventory
void add_product(inventory *inv, product *p) {
    inv->products = realloc(inv->products, (inv->num_products + 1) * sizeof(product));
    inv->products[inv->num_products++] = *p;
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

// Remove a product from the inventory
void remove_product(inventory *inv, char *name) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            break;
        }
    }
    if (i < inv->num_products) {
        for (int j = i; j < inv->num_products - 1; j++) {
            inv->products[j] = inv->products[j + 1];
        }
        inv->num_products--;
        inv->products = realloc(inv->products, inv->num_products * sizeof(product));
    }
}

// Print the inventory
void print_inventory(inventory *inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("  %s: %d units at $%.2f each\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory *inv = malloc(sizeof(inventory));
    inv->num_products = 0;
    inv->products = NULL;

    // Add some products to the inventory
    add_product(inv, create_product("Apple", 10, 0.50));
    add_product(inv, create_product("Orange", 5, 0.75));
    add_product(inv, create_product("Banana", 15, 1.00));

    // Print the inventory
    print_inventory(inv);

    // Find a product in the inventory
    product *p = find_product(inv, "Apple");
    if (p != NULL) {
        printf("Found product: %s\n", p->name);
    } else {
        printf("Product not found\n");
    }

    // Remove a product from the inventory
    remove_product(inv, "Orange");

    // Print the inventory again
    print_inventory(inv);

    // Free the memory allocated for the inventory
    free(inv->products);
    free(inv);

    return 0;
}