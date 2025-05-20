//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

// Structure to represent a warehouse
typedef struct warehouse {
    char name[50];
    int num_products;
    product *products;
} warehouse;

// Function to create a new product
product* create_product(char *name, int quantity, float price) {
    product *p = malloc(sizeof(product));
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Function to create a new warehouse
warehouse* create_warehouse(char *name) {
    warehouse *w = malloc(sizeof(warehouse));
    strcpy(w->name, name);
    w->num_products = 0;
    w->products = NULL;
    return w;
}

// Function to add a product to a warehouse
void add_product(warehouse *w, product *p) {
    w->products = realloc(w->products, (w->num_products + 1) * sizeof(product));
    w->products[w->num_products++] = *p;
}

// Function to remove a product from a warehouse
void remove_product(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            break;
        }
    }
    
    if (i < w->num_products) {
        for (int j = i; j < w->num_products - 1; j++) {
            w->products[j] = w->products[j + 1];
        }
        w->num_products--;
        w->products = realloc(w->products, w->num_products * sizeof(product));
    }
}

// Function to print the inventory of a warehouse
void print_inventory(warehouse *w) {
    printf("Inventory of warehouse %s:\n", w->name);
    for (int i = 0; i < w->num_products; i++) {
        printf("Product: %s, Quantity: %d, Price: %f\n", w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse *w = create_warehouse("Main Warehouse");

    // Add some products to the warehouse
    add_product(w, create_product("Apple", 100, 1.0));
    add_product(w, create_product("Banana", 200, 1.5));
    add_product(w, create_product("Orange", 300, 2.0));

    // Print the inventory of the warehouse
    print_inventory(w);

    // Remove a product from the warehouse
    remove_product(w, "Apple");

    // Print the inventory of the warehouse again
    print_inventory(w);

    return 0;
}