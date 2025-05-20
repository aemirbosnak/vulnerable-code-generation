//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: careful
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
product *create_product(char *name, int quantity, float price) {
    product *p = (product *)malloc(sizeof(product));
    if (p == NULL) {
        return NULL;
    }
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

// Function to create a new warehouse
warehouse *create_warehouse(char *name) {
    warehouse *w = (warehouse *)malloc(sizeof(warehouse));
    if (w == NULL) {
        return NULL;
    }
    strcpy(w->name, name);
    w->num_products = 0;
    w->products = NULL;
    return w;
}

// Function to add a product to a warehouse
void add_product(warehouse *w, product *p) {
    w->products = (product *)realloc(w->products, (w->num_products + 1) * sizeof(product));
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
        for (i++; i < w->num_products; i++) {
            w->products[i - 1] = w->products[i];
        }
        w->num_products--;
    }
}

// Function to print the contents of a warehouse
void print_warehouse(warehouse *w) {
    int i;
    printf("Warehouse: %s\n", w->name);
    printf("Number of products: %d\n", w->num_products);
    for (i = 0; i < w->num_products; i++) {
        printf("Product: %s\n", w->products[i].name);
        printf("Quantity: %d\n", w->products[i].quantity);
        printf("Price: %.2f\n", w->products[i].price);
    }
}

// Main function
int main() {
    // Create a warehouse
    warehouse *w = create_warehouse("My Warehouse");

    // Add some products to the warehouse
    product *p1 = create_product("Product 1", 10, 10.0);
    add_product(w, p1);
    product *p2 = create_product("Product 2", 20, 20.0);
    add_product(w, p2);
    product *p3 = create_product("Product 3", 30, 30.0);
    add_product(w, p3);

    // Print the contents of the warehouse
    print_warehouse(w);

    // Remove a product from the warehouse
    remove_product(w, "Product 2");

    // Print the contents of the warehouse again
    print_warehouse(w);

    // Free the memory allocated for the warehouse and its products
    free(w->products);
    free(w);

    return 0;
}