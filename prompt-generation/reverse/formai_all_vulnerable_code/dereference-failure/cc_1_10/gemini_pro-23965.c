//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: configurable
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
    product *products;
    int num_products;
} inventory;

// Create a new product
product *create_product(char *name, int quantity, float price) {
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

// Print the inventory
void print_inventory(inventory *inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s %d %.2f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Create a new inventory
    inventory inv;
    inv.products = NULL;
    inv.num_products = 0;

    // Add some products to the inventory
    add_product(&inv, create_product("Apple", 10, 1.00));
    add_product(&inv, create_product("Orange", 5, 1.50));
    add_product(&inv, create_product("Banana", 15, 0.75));

    // Print the inventory
    print_inventory(&inv);

    // Find a product in the inventory
    product *p = find_product(&inv, "Apple");
    if (p != NULL) {
        printf("Found product: %s %d %.2f\n", p->name, p->quantity, p->price);
    } else {
        printf("Product not found\n");
    }

    return 0;
}