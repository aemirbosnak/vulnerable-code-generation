//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} product;

typedef struct {
    int num_products;
    product *products;
} inventory;

inventory *create_inventory() {
    inventory *inv = malloc(sizeof(inventory));
    inv->num_products = 0;
    inv->products = NULL;
    return inv;
}

void destroy_inventory(inventory *inv) {
    if (inv->products != NULL) {
        free(inv->products);
    }
    free(inv);
}

void add_product(inventory *inv, product *p) {
    inv->num_products++;
    inv->products = realloc(inv->products, sizeof(product) * inv->num_products);
    inv->products[inv->num_products - 1] = *p;
}

void remove_product(inventory *inv, int index) {
    if (index >= 0 && index < inv->num_products) {
        for (int i = index; i < inv->num_products - 1; i++) {
            inv->products[i] = inv->products[i + 1];
        }
        inv->num_products--;
        inv->products = realloc(inv->products, sizeof(product) * inv->num_products);
    }
}

product *get_product(inventory *inv, int index) {
    if (index >= 0 && index < inv->num_products) {
        return &inv->products[index];
    }
    return NULL;
}

void print_inventory(inventory *inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("%s (%d, %.2f)\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

int main() {
    inventory *inv = create_inventory();

    product p1 = {"Apple", 10, 0.5};
    product p2 = {"Banana", 5, 0.75};
    product p3 = {"Orange", 8, 1.0};

    add_product(inv, &p1);
    add_product(inv, &p2);
    add_product(inv, &p3);

    print_inventory(inv);

    remove_product(inv, 1);

    print_inventory(inv);

    product *p = get_product(inv, 0);
    if (p != NULL) {
        printf("Product name: %s\n", p->name);
    }

    destroy_inventory(inv);

    return 0;
}