//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the warehouse
#define MAX_PRODUCTS 100

// Define the maximum length of a product name
#define MAX_NAME_LENGTH 50

// Define the maximum weight of a product (in kilograms)
#define MAX_WEIGHT 100

// Define the maximum volume of a product (in cubic meters)
#define MAX_VOLUME 1

// Define the structure of a product
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double weight;
    double volume;
} product;

// Define the structure of the warehouse
typedef struct {
    product products[MAX_PRODUCTS];
    int num_products;
} warehouse;

// Create a new warehouse
warehouse* create_warehouse() {
    warehouse* w = malloc(sizeof(warehouse));
    w->num_products = 0;
    return w;
}

// Add a product to the warehouse
void add_product(warehouse* w, product* p) {
    if (w->num_products < MAX_PRODUCTS) {
        w->products[w->num_products] = *p;
        w->num_products++;
    } else {
        printf("Warehouse is full!\n");
    }
}

// Remove a product from the warehouse
void remove_product(warehouse* w, int index) {
    if (index >= 0 && index < w->num_products) {
        for (int i = index; i < w->num_products - 1; i++) {
            w->products[i] = w->products[i + 1];
        }
        w->num_products--;
    } else {
        printf("Invalid index!\n");
    }
}

// Find a product in the warehouse by name
product* find_product_by_name(warehouse* w, char* name) {
    for (int i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            return &w->products[i];
        }
    }
    return NULL;
}

// Print the warehouse inventory
void print_inventory(warehouse* w) {
    printf("Warehouse Inventory:\n");
    for (int i = 0; i < w->num_products; i++) {
        printf("%s (%d, %.2f kg, %.2f m^3)\n", w->products[i].name, w->products[i].quantity,
               w->products[i].weight, w->products[i].volume);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some products to the warehouse
    product p1 = {"Product 1", 10, 10.0, 0.5};
    product p2 = {"Product 2", 20, 20.0, 1.0};
    product p3 = {"Product 3", 30, 30.0, 1.5};
    add_product(w, &p1);
    add_product(w, &p2);
    add_product(w, &p3);

    // Print the warehouse inventory
    print_inventory(w);

    // Find a product in the warehouse by name
    product* p = find_product_by_name(w, "Product 2");
    if (p != NULL) {
        printf("Found product: %s (%d, %.2f kg, %.2f m^3)\n", p->name, p->quantity, p->weight, p->volume);
    } else {
        printf("Product not found!\n");
    }

    // Remove a product from the warehouse
    remove_product(w, 1);

    // Print the warehouse inventory again
    print_inventory(w);

    return 0;
}