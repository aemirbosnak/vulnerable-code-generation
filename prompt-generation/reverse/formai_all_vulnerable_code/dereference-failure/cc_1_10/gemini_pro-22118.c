//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product {
    int id;
    char name[50];
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
    product *p = malloc(sizeof(product));
    p->id = id;
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

// Find a product by ID
product *find_product_by_id(inventory *inv, int id) {
    for (int i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            return &inv->products[i];
        }
    }
    return NULL;
}

// Print the inventory
void print_inventory(inventory *inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%d %s %d %f\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

int main() {
    // Create an inventory
    inventory *inv = malloc(sizeof(inventory));
    inv->num_products = 0;
    inv->products = NULL;

    // Add some products to the inventory
    add_product(inv, create_product(1, "Apple", 10, 0.5));
    add_product(inv, create_product(2, "Orange", 5, 0.75));
    add_product(inv, create_product(3, "Banana", 15, 1.0));

    // Print the inventory
    print_inventory(inv);

    // Find a product by ID
    product *p = find_product_by_id(inv, 2);
    if (p != NULL) {
        printf("Product found: %d %s %d %f\n", p->id, p->name, p->quantity, p->price);
    } else {
        printf("Product not found.\n");
    }

    // Free the inventory
    free(inv->products);
    free(inv);

    return 0;
}