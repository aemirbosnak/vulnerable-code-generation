//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the warehouse
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
    char name[50];
    int quantity;
    float price;
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
void add_product(warehouse* w, product p) {
    if (w->num_products >= MAX_PRODUCTS) {
        printf("Error: warehouse is full\n");
        return;
    }

    w->products[w->num_products] = p;
    w->num_products++;
}

// Remove a product from the warehouse
void remove_product(warehouse* w, char* name) {
    int i;

    for (i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            break;
        }
    }

    if (i == w->num_products) {
        printf("Error: product not found\n");
        return;
    }

    for (; i < w->num_products - 1; i++) {
        w->products[i] = w->products[i + 1];
    }

    w->num_products--;
}

// Get the quantity of a product in the warehouse
int get_quantity(warehouse* w, char* name) {
    int i;

    for (i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            return w->products[i].quantity;
        }
    }

    return 0;
}

// Set the quantity of a product in the warehouse
void set_quantity(warehouse* w, char* name, int quantity) {
    int i;

    for (i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            break;
        }
    }

    if (i == w->num_products) {
        printf("Error: product not found\n");
        return;
    }

    w->products[i].quantity = quantity;
}

// Get the total value of the products in the warehouse
float get_total_value(warehouse* w) {
    int i;
    float total = 0;

    for (i = 0; i < w->num_products; i++) {
        total += w->products[i].quantity * w->products[i].price;
    }

    return total;
}

// Print the contents of the warehouse
void print_warehouse(warehouse* w) {
    int i;

    printf("Warehouse contents:\n");
    for (i = 0; i < w->num_products; i++) {
        printf("%s: %d, %.2f\n", w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

// Main function
int main() {
    // Create a new warehouse
    warehouse* w = create_warehouse();

    // Add some products to the warehouse
    product p1 = {"apple", 10, 1.0};
    add_product(w, p1);
    product p2 = {"banana", 20, 1.5};
    add_product(w, p2);
    product p3 = {"orange", 30, 2.0};
    add_product(w, p3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Get the quantity of a product in the warehouse
    int quantity = get_quantity(w, "apple");
    printf("Quantity of apples: %d\n", quantity);

    // Set the quantity of a product in the warehouse
    set_quantity(w, "banana", 25);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Get the total value of the products in the warehouse
    float total_value = get_total_value(w);
    printf("Total value of products: %.2f\n", total_value);

    // Remove a product from the warehouse
    remove_product(w, "orange");

    // Print the contents of the warehouse
    print_warehouse(w);

    // Free the memory allocated for the warehouse
    free(w);

    return 0;
}