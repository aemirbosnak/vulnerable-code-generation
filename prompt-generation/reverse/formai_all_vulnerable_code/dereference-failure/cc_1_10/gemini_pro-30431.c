//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct inventory {
    struct product *products;
    int num_products;
};


void add_product(struct inventory *inv, struct product *product) {
    inv->products = realloc(inv->products, (inv->num_products + 1) * sizeof(struct product));
    inv->products[inv->num_products++] = *product;
}


void remove_product(struct inventory *inv, int id) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            inv->num_products--;
            memmove(&inv->products[i], &inv->products[i + 1], (inv->num_products - i) * sizeof(struct product));
            break;
        }
    }
}

void update_product(struct inventory *inv, int id, struct product *product) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            inv->products[i] = *product;
            break;
        }
    }
}


void print_inventory(struct inventory *inv) {
    int i;
    for (i = 0; i < inv->num_products; i++) {
        printf("%d %s %d %.2f\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}


int main() {
    struct inventory *inv = malloc(sizeof(struct inventory));
    inv->products = NULL;
    inv->num_products = 0;

    struct product product1 = {1, "Product 1", 10, 10.0};
    struct product product2 = {2, "Product 2", 20, 20.0};
    struct product product3 = {3, "Product 3", 30, 30.0};

    add_product(inv, &product1);
    add_product(inv, &product2);
    add_product(inv, &product3);

    print_inventory(inv);

    remove_product(inv, 2);
    print_inventory(inv);

    product1.quantity = 20;
    update_product(inv, 1, &product1);
    print_inventory(inv);

    free(inv->products);
    free(inv);

    return 0;
}