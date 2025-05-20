//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product_t;

product_t *products = NULL;
int num_products = 0;

void add_product(product_t product) {
    products = realloc(products, sizeof(product_t) * (num_products + 1));
    products[num_products++] = product;
}

void remove_product(int id) {
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            products[i] = products[num_products - 1];
            num_products--;
            break;
        }
    }
}

void update_product(int id, product_t product) {
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            products[i] = product;
            break;
        }
    }
}

void print_products() {
    printf("Products:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d %s %d %.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    product_t product1 = {1, "Apple", 10, 1.0};
    product_t product2 = {2, "Orange", 5, 1.5};
    product_t product3 = {3, "Banana", 15, 2.0};

    add_product(product1);
    add_product(product2);
    add_product(product3);

    print_products();

    remove_product(2);

    print_products();

    product_t product4 = {3, "Banana", 10, 2.5};

    update_product(3, product4);

    print_products();

    return 0;
}