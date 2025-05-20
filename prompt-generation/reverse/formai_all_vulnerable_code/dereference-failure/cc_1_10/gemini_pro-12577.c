//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char *name;
    int quantity;
    float price;
} product;

void add_product(product **products, int *num_products, char *name, int quantity, float price) {
    *products = realloc(*products, sizeof(product) * (*num_products + 1));
    (*products)[*num_products].name = strdup(name);
    (*products)[*num_products].quantity = quantity;
    (*products)[*num_products].price = price;
    (*num_products)++;
}

void remove_product(product **products, int *num_products, char *name) {
    int i;
    for (i = 0; i < *num_products; i++) {
        if (strcmp((*products)[i].name, name) == 0) {
            free((*products)[i].name);
            (*products)[i] = (*products)[*num_products - 1];
            (*num_products)--;
            break;
        }
    }
}

void update_product(product **products, int *num_products, char *name, int quantity, float price) {
    int i;
    for (i = 0; i < *num_products; i++) {
        if (strcmp((*products)[i].name, name) == 0) {
            (*products)[i].quantity = quantity;
            (*products)[i].price = price;
            break;
        }
    }
}

void print_products(product **products, int *num_products) {
    int i;
    for (i = 0; i < *num_products; i++) {
        printf("%s %d %f\n", (*products)[i].name, (*products)[i].quantity, (*products)[i].price);
    }
}

int main() {
    product *products = NULL;
    int num_products = 0;
    add_product(&products, &num_products, "Apple", 10, 1.0);
    add_product(&products, &num_products, "Orange", 5, 2.0);
    add_product(&products, &num_products, "Banana", 15, 3.0);
    print_products(&products, &num_products);
    remove_product(&products, &num_products, "Orange");
    update_product(&products, &num_products, "Apple", 20, 1.5);
    print_products(&products, &num_products);
    return 0;
}