//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct {
    int num_products;
    Product products[100];
} Warehouse;

Warehouse* create_warehouse() {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->num_products = 0;
    return warehouse;
}

void add_product(Warehouse *warehouse, Product product) {
    warehouse->products[warehouse->num_products++] = product;
}

void remove_product(Warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            for (; i < warehouse->num_products - 1; i++) {
                warehouse->products[i] = warehouse->products[i + 1];
            }
            warehouse->num_products--;
            return;
        }
    }
}

void print_warehouse(Warehouse *warehouse) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        printf("%s %d %.2f\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

int main() {
    Warehouse *warehouse = create_warehouse();
    Product product;

    strcpy(product.name, "Apple");
    product.quantity = 10;
    product.price = 1.0;
    add_product(warehouse, product);

    strcpy(product.name, "Banana");
    product.quantity = 20;
    product.price = 1.5;
    add_product(warehouse, product);

    strcpy(product.name, "Orange");
    product.quantity = 30;
    product.price = 2.0;
    add_product(warehouse, product);

    print_warehouse(warehouse);
    printf("\n");

    remove_product(warehouse, "Apple");

    print_warehouse(warehouse);
    printf("\n");

    return 0;
}