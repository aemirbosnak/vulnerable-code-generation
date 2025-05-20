//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int quantity;
    float price;
} Product;

typedef struct {
    Product* products;
    int capacity;
    int size;
} Warehouse;

Warehouse* create_warehouse(int capacity) {
    Warehouse* w = (Warehouse*)malloc(sizeof(Warehouse));
    w->capacity = capacity;
    w->size = 0;
    w->products = (Product*)malloc(capacity * sizeof(Product));
    return w;
}

void add_product(Warehouse* w, char* name, int quantity, float price) {
    if (w->size >= w->capacity) {
        printf("Warehouse is full.\n");
        return;
    }
    Product* p = &w->products[w->size];
    p->name = name;
    p->quantity = quantity;
    p->price = price;
    w->size++;
}

void remove_product(Warehouse* w, int index) {
    if (index >= w->size || index < 0) {
        printf("Invalid product index.\n");
        return;
    }
    w->size--;
    for (int i = index; i < w->size; i++) {
        w->products[i] = w->products[i+1];
    }
}

void print_products(Warehouse* w) {
    for (int i = 0; i < w->size; i++) {
        printf("%s - %d units - $%.2f\n", w->products[i].name, w->products[i].quantity, w->products[i].price);
    }
}

int main() {
    Warehouse* w = create_warehouse(10);
    add_product(w, "Apples", 50, 1.00);
    add_product(w, "Oranges", 25, 0.75);
    print_products(w);
    remove_product(w, 1);
    print_products(w);
    return 0;
}