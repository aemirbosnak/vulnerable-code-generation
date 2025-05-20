//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char *name;
    int quantity;
    float price;
};

struct warehouse {
    struct product *products;
    int num_products;
};

struct warehouse *create_warehouse() {
    struct warehouse *warehouse = malloc(sizeof(struct warehouse));
    warehouse->products = NULL;
    warehouse->num_products = 0;
    return warehouse;
}

void add_product(struct warehouse *warehouse, char *name, int quantity, float price) {
    warehouse->products = realloc(warehouse->products, (warehouse->num_products + 1) * sizeof(struct product));
    warehouse->products[warehouse->num_products].name = strdup(name);
    warehouse->products[warehouse->num_products].quantity = quantity;
    warehouse->products[warehouse->num_products].price = price;
    warehouse->num_products++;
}

void remove_product(struct warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            free(warehouse->products[i].name);
            warehouse->products[i] = warehouse->products[warehouse->num_products - 1];
            warehouse->num_products--;
        }
    }
}

void print_warehouse(struct warehouse *warehouse) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        printf("%s: %d @ $%.2f\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

int main() {
    struct warehouse *warehouse = create_warehouse();
    add_product(warehouse, "Apple", 100, 1.00);
    add_product(warehouse, "Orange", 50, 1.50);
    add_product(warehouse, "Banana", 25, 2.00);
    print_warehouse(warehouse);
    remove_product(warehouse, "Orange");
    print_warehouse(warehouse);
    return 0;
}