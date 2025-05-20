//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: creative
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
    int num_products;
    product *products;
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

// Remove a product from the inventory
void remove_product(inventory *inv, char *name) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            break;
        }
    }
    if (i < inv->num_products) {
        for (i++; i < inv->num_products; i++) {
            inv->products[i - 1] = inv->products[i];
        }
        inv->num_products--;
        inv->products = realloc(inv->products, inv->num_products * sizeof(product));
    }
}

// Get the quantity of a product
int get_quantity(inventory *inv, char *name) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return inv->products[i].quantity;
        }
    }
    return 0;
}

// Get the price of a product
float get_price(inventory *inv, char *name) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            return inv->products[i].price;
        }
    }
    return 0.0;
}

// Print the inventory
void print_inventory(inventory *inv) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        printf("%s: %d units at $%.2f each\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Create an inventory
    inventory inv;
    inv.num_products = 0;
    inv.products = NULL;

    // Add some products to the inventory
    add_product(&inv, create_product("Apple", 100, 0.50));
    add_product(&inv, create_product("Orange", 50, 0.75));
    add_product(&inv, create_product("Banana", 25, 1.00));

    // Print the inventory
    printf("Initial inventory:\n");
    print_inventory(&inv);

    // Remove a product from the inventory
    remove_product(&inv, "Banana");

    // Print the inventory
    printf("Inventory after removing \"Banana\":\n");
    print_inventory(&inv);

    // Get the quantity of a product
    int quantity = get_quantity(&inv, "Apple");
    printf("Quantity of \"Apple\": %d\n", quantity);

    // Get the price of a product
    float price = get_price(&inv, "Orange");
    printf("Price of \"Orange\": $%.2f\n", price);

    return 0;
}