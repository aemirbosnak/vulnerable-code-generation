//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product {
    char *name;
    int quantity;
    float price;
} product;

// Define the inventory structure
typedef struct inventory {
    product *products;
    int num_products;
} inventory;

// Create a new product
product *create_product(char *name, int quantity, float price) {
    product *p = malloc(sizeof(product));
    p->name = strdup(name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Add a product to the inventory
void add_product(inventory *inv, product *p) {
    inv->products = realloc(inv->products, (inv->num_products + 1) * sizeof(product));
    inv->products[inv->num_products++] = *p;
}

// Search for a product in the inventory
product *find_product(inventory *inv, char *name) {
    for (int i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return &inv->products[i];
        }
    }
    return NULL;
}

// Update the quantity of a product in the inventory
void update_product(inventory *inv, char *name, int quantity) {
    product *p = find_product(inv, name);
    if (p) {
        p->quantity = quantity;
    }
}

// Print the inventory
void print_inventory(inventory *inv) {
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s: %d, %.2f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Free the memory allocated for the inventory
void free_inventory(inventory *inv) {
    for (int i = 0; i < inv->num_products; i++) {
        free(inv->products[i].name);
    }
    free(inv->products);
}

// Main function
int main() {
    // Create an inventory
    inventory inv;
    inv.products = NULL;
    inv.num_products = 0;

    // Add some products to the inventory
    add_product(&inv, create_product("Apple", 10, 1.0));
    add_product(&inv, create_product("Orange", 5, 1.5));
    add_product(&inv, create_product("Banana", 15, 2.0));

    // Print the inventory
    print_inventory(&inv);

    // Search for a product in the inventory
    product *p = find_product(&inv, "Apple");
    if (p) {
        printf("Found product: %s, quantity: %d, price: %.2f\n", p->name, p->quantity, p->price);
    } else {
        printf("Product not found.\n");
    }

    // Update the quantity of a product in the inventory
    update_product(&inv, "Apple", 20);

    // Print the inventory
    print_inventory(&inv);

    // Free the memory allocated for the inventory
    free_inventory(&inv);

    return 0;
}