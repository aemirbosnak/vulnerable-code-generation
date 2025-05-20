//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char *name;
    int quantity;
    float price;
} product;

product *products = NULL;
int num_products = 0;

void add_product(product *p) {
    products = realloc(products, (num_products + 1) * sizeof(product));
    products[num_products++] = *p;
}

void remove_product(int id) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            break;
        }
    }
    if (i < num_products) {
        memmove(&products[i], &products[i + 1], (num_products - i - 1) * sizeof(product));
        num_products--;
    }
}

product *find_product(int id) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }
    return NULL;
}

void print_products() {
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%d %s %d %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    product p1 = {1, "Apple", 10, 1.0};
    product p2 = {2, "Banana", 20, 2.0};
    product p3 = {3, "Orange", 30, 3.0};
    add_product(&p1);
    add_product(&p2);
    add_product(&p3);
    print_products();
    remove_product(2);
    print_products();
    product *p = find_product(1);
    printf("%d %s %d %.2f\n", p->id, p->name, p->quantity, p->price);
    return 0;
}