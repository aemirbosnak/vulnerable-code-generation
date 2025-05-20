//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int quantity;
} product;

typedef struct {
    int id;
    char *name;
    product *products;
    int num_products;
} warehouse;

warehouse *create_warehouse(char *name) {
    warehouse *w = malloc(sizeof(warehouse));
    w->id = rand();
    w->name = strdup(name);
    w->products = NULL;
    w->num_products = 0;
    return w;
}

void destroy_warehouse(warehouse *w) {
    free(w->name);
    for (int i = 0; i < w->num_products; i++) {
        free(w->products[i].name);
    }
    free(w->products);
    free(w);
}

product *create_product(char *name, int quantity) {
    product *p = malloc(sizeof(product));
    p->id = rand();
    p->name = strdup(name);
    p->quantity = quantity;
    return p;
}

void destroy_product(product *p) {
    free(p->name);
    free(p);
}

void add_product_to_warehouse(warehouse *w, product *p) {
    w->products = realloc(w->products, (w->num_products + 1) * sizeof(product));
    w->products[w->num_products++] = *p;
}

void remove_product_from_warehouse(warehouse *w, int id) {
    for (int i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            for (int j = i; j < w->num_products - 1; j++) {
                w->products[j] = w->products[j + 1];
            }
            w->num_products--;
            return;
        }
    }
}

void print_warehouse(warehouse *w) {
    printf("Warehouse: %s (%d)\n", w->name, w->id);
    for (int i = 0; i < w->num_products; i++) {
        printf("\tProduct: %s (%d) - Quantity: %d\n", w->products[i].name, w->products[i].id, w->products[i].quantity);
    }
}

int main() {
    warehouse *w1 = create_warehouse("Warehouse 1");
    warehouse *w2 = create_warehouse("Warehouse 2");

    product *p1 = create_product("Product 1", 10);
    product *p2 = create_product("Product 2", 20);
    product *p3 = create_product("Product 3", 30);

    add_product_to_warehouse(w1, p1);
    add_product_to_warehouse(w1, p2);
    add_product_to_warehouse(w2, p3);

    print_warehouse(w1);
    print_warehouse(w2);

    remove_product_from_warehouse(w1, p1->id);

    print_warehouse(w1);

    destroy_product(p1);
    destroy_product(p2);
    destroy_product(p3);
    destroy_warehouse(w1);
    destroy_warehouse(w2);

    return 0;
}