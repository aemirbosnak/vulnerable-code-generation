//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char *name;
    int quantity;
    float price;
} product;

typedef struct inventory {
    product *products;
    int num_products;
} inventory;

inventory *create_inventory() {
    inventory *inv = malloc(sizeof(inventory));
    inv->products = NULL;
    inv->num_products = 0;
    return inv;
}

void add_product(inventory *inv, char *name, int quantity, float price) {
    inv->products = realloc(inv->products, sizeof(product) * (inv->num_products + 1));
    inv->products[inv->num_products].name = strdup(name);
    inv->products[inv->num_products].quantity = quantity;
    inv->products[inv->num_products].price = price;
    inv->num_products++;
}

void print_inventory(inventory *inv) {
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s: %d %f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

void free_inventory(inventory *inv) {
    for (int i = 0; i < inv->num_products; i++) {
        free(inv->products[i].name);
    }
    free(inv->products);
    free(inv);
}

int main() {
    inventory *inv = create_inventory();
    add_product(inv, "Clockwork Orange", 1, 9.99);
    add_product(inv, "The Hitchhiker's Guide to the Galaxy", 2, 12.99);
    add_product(inv, "1984", 3, 14.99);
    print_inventory(inv);
    free_inventory(inv);
    return 0;
}