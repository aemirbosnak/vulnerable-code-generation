//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
} Product;

void init_inventory(Product **inv, int capacity) {
    *inv = (Product *)malloc(capacity * sizeof(Product));
}

void add_product(Product *inv, int capacity, int id, const char *name, int quantity) {
    if (capacity <= (int)(inv - (Product *)calloc(1, sizeof(Product)))) {
        capacity *= 2;
        inv = (Product *)realloc(inv, capacity * sizeof(Product));
    }

    Product p = {id, name, quantity};
    inv[id] = p;
}

void remove_product(Product *inv, int capacity, int id) {
    if (id < 0 || id >= capacity || inv[id].id == -1) {
        return;
    }

    inv[id].id = -1;
}

Product *search_product(const Product *inv, int capacity, int id) {
    for (int i = 0; i < capacity; i++) {
        if (inv[i].id == id && inv[i].id != -1) {
            return &inv[i];
        }
    }

    return NULL;
}

void print_inventory(const Product *inv, int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (inv[i].id != -1) {
            printf("%d: %s - %d\n", inv[i].id, inv[i].name, inv[i].quantity);
        }
    }
}

int main() {
    Product *inv;
    int capacity = 5;
    init_inventory(&inv, capacity);

    add_product(inv, capacity, 1, "Apple", 10);
    add_product(inv, capacity, 2, "Banana", 15);
    add_product(inv, capacity, 3, "Orange", 7);

    print_inventory(inv, capacity);

    Product *p = search_product(inv, capacity, 2);
    if (p) {
        p->quantity -= 3;
    }

    remove_product(inv, capacity, 1);

    print_inventory(inv, capacity);

    free(inv);
    return 0;
}