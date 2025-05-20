//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char product_name[100];
    int quantity;
} Product;

typedef struct {
    char warehouse_name[100];
    Product* products;
    int num_products;
} Warehouse;

void add_product(Warehouse* w, char* product_name, int quantity) {
    w->num_products++;
    w->products = realloc(w->products, sizeof(Product) * w->num_products);
    strncpy(w->products[w->num_products - 1].product_name, product_name, 100);
    w->products[w->num_products - 1].quantity = quantity;
}

int main() {
    Warehouse w1 = {
       .warehouse_name = "Warehouse 1",
       .products = NULL,
       .num_products = 0
    };
    Warehouse w2 = {
       .warehouse_name = "Warehouse 2",
       .products = NULL,
       .num_products = 0
    };

    add_product(&w1, "Product A", 10);
    add_product(&w1, "Product B", 5);
    add_product(&w2, "Product C", 20);

    printf("Warehouse 1:\n");
    for (int i = 0; i < w1.num_products; i++) {
        printf("%s: %d\n", w1.products[i].product_name, w1.products[i].quantity);
    }

    printf("\nWarehouse 2:\n");
    for (int i = 0; i < w2.num_products; i++) {
        printf("%s: %d\n", w2.products[i].product_name, w2.products[i].quantity);
    }

    return 0;
}