//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct product {
    char name[50];
    int quantity;
} Product;

typedef struct order {
    char product[50];
    int quantity;
} Order;

typedef struct warehouse {
    Product *products;
    int num_products;
    Order *orders;
    int num_orders;
} Warehouse;

Warehouse *create_warehouse() {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->products = NULL;
    warehouse->num_products = 0;
    warehouse->orders = NULL;
    warehouse->num_orders = 0;
    return warehouse;
}

void add_product(Warehouse *warehouse, const char *name, int quantity) {
    Product *product = malloc(sizeof(Product));
    strcpy(product->name, name);
    product->quantity = quantity;
    warehouse->products = realloc(warehouse->products, (warehouse->num_products + 1) * sizeof(Product));
    warehouse->products[warehouse->num_products++] = *product;
}

void add_order(Warehouse *warehouse, const char *product, int quantity) {
    Order *order = malloc(sizeof(Order));
    strcpy(order->product, product);
    order->quantity = quantity;
    warehouse->orders = realloc(warehouse->orders, (warehouse->num_orders + 1) * sizeof(Order));
    warehouse->orders[warehouse->num_orders++] = *order;
}

void print_inventory(Warehouse *warehouse) {
    printf("Inventory:\n");
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("Product: %s, Quantity: %d\n", warehouse->products[i].name, warehouse->products[i].quantity);
    }
}

void print_orders(Warehouse *warehouse) {
    printf("Orders:\n");
    for (int i = 0; i < warehouse->num_orders; i++) {
        printf("Order: %s, Quantity: %d\n", warehouse->orders[i].product, warehouse->orders[i].quantity);
    }
}

int main() {
    Warehouse *warehouse = create_warehouse();
    add_product(warehouse, "A", 100);
    add_product(warehouse, "B", 200);
    add_order(warehouse, "A", 50);
    add_order(warehouse, "B", 75);

    print_inventory(warehouse);
    print_orders(warehouse);

    return 0;
}