//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

typedef struct {
    product *products;
    int size;
    int capacity;
} warehouse;

warehouse *create_warehouse(int capacity) {
    warehouse *w = (warehouse *)malloc(sizeof(warehouse));
    w->size = 0;
    w->capacity = capacity;
    w->products = (product *)malloc(capacity * sizeof(product));
    return w;
}

int is_full(warehouse *w) {
    return w->size == w->capacity;
}

int is_empty(warehouse *w) {
    return w->size == 0;
}

void add_product(warehouse *w, product p) {
    if (is_full(w)) {
        printf("Warehouse is full.\n");
        return;
    }
    w->products[w->size] = p;
    w->size++;
}

void remove_product(warehouse *w, int id) {
    int i;
    for (i = 0; i < w->size; i++) {
        if (w->products[i].id == id) {
            w->size--;
            break;
        }
    }
}

void display_products(warehouse *w) {
    int i;
    for (i = 0; i < w->size; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               w->products[i].id, w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

int main() {
    warehouse *w = create_warehouse(MAX_SIZE);
    product p1 = {1, "Product 1", 100, 10.00};
    product p2 = {2, "Product 2", 200, 20.00};
    product p3 = {3, "Product 3", 300, 30.00};

    add_product(w, p1);
    add_product(w, p2);
    add_product(w, p3);

    display_products(w);

    remove_product(w, 1);

    display_products(w);

    return 0;
}