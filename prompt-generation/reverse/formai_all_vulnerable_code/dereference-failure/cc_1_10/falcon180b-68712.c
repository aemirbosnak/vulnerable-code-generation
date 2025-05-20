//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 100
#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_PRODUCT_QUANTITY 1000

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

typedef struct {
    Product products[MAX_WAREHOUSE_SIZE];
    int num_products;
} Warehouse;

Warehouse* create_warehouse() {
    Warehouse* w = (Warehouse*)malloc(sizeof(Warehouse));
    w->num_products = 0;
    return w;
}

void add_product(Warehouse* w, char* name, int quantity) {
    if (w->num_products >= MAX_WAREHOUSE_SIZE) {
        printf("Warehouse is full!\n");
        return;
    }

    Product product;
    strcpy(product.name, name);
    product.quantity = quantity;

    w->products[w->num_products++] = product;
}

void remove_product(Warehouse* w, char* name) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            w->num_products--;
            memmove(&w->products[i], &w->products[i+1], (w->num_products - i) * sizeof(Product));
            break;
        }
    }
}

void print_warehouse(Warehouse* w) {
    printf("Warehouse:\n");
    printf("--------------------\n");
    for (int i = 0; i < w->num_products; i++) {
        printf("%s - %d units\n", w->products[i].name, w->products[i].quantity);
    }
    printf("--------------------\n");
}

int main() {
    Warehouse* w = create_warehouse();

    add_product(w, "Apples", 100);
    add_product(w, "Oranges", 50);
    add_product(w, "Bananas", 200);

    print_warehouse(w);

    remove_product(w, "Apples");

    print_warehouse(w);

    return 0;
}