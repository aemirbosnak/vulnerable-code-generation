//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} product;

typedef struct {
    char *name;
    product *products;
    int num_products;
} warehouse;

warehouse *create_warehouse(char *name) {
    warehouse *w = malloc(sizeof(warehouse));
    w->name = strdup(name);
    w->products = NULL;
    w->num_products = 0;
    return w;
}

void add_product(warehouse *w, product *p) {
    w->products = realloc(w->products, (w->num_products + 1) * sizeof(product));
    w->products[w->num_products++] = *p;
}

void print_warehouse(warehouse *w) {
    printf("Warehouse: %s\n", w->name);
    for (int i = 0; i < w->num_products; i++) {
        printf("  - %s: %d units at $%.2f each\n", w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

int main() {
    // Create a warehouse
    warehouse *w = create_warehouse("My Warehouse");

    // Add some products to the warehouse
    product p1 = {"iPhone", 10, 999.99};
    add_product(w, &p1);
    product p2 = {"iPad", 5, 799.99};
    add_product(w, &p2);
    product p3 = {"Apple Watch", 15, 399.99};
    add_product(w, &p3);

    // Print the warehouse
    print_warehouse(w);

    return 0;
}