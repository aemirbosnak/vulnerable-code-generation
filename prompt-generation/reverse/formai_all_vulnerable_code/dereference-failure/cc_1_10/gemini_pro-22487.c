//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    float price;
} Product;

typedef struct {
    char *name;
    Product *products;
    int num_products;
} Warehouse;

Warehouse *warehouses[100];
int num_warehouses = 0;

void add_warehouse(char *name) {
    warehouses[num_warehouses] = malloc(sizeof(Warehouse));
    warehouses[num_warehouses]->name = strdup(name);
    warehouses[num_warehouses]->products = malloc(sizeof(Product) * 100);
    warehouses[num_warehouses]->num_products = 0;
    num_warehouses++;
}

void add_product(char *warehouse_name, char *product_name, int quantity, float price) {
    int i;
    for (i = 0; i < num_warehouses; i++) {
        if (strcmp(warehouses[i]->name, warehouse_name) == 0) {
            warehouses[i]->products[warehouses[i]->num_products].name = strdup(product_name);
            warehouses[i]->products[warehouses[i]->num_products].quantity = quantity;
            warehouses[i]->products[warehouses[i]->num_products].price = price;
            warehouses[i]->num_products++;
            break;
        }
    }
}

void print_inventory() {
    int i, j;
    for (i = 0; i < num_warehouses; i++) {
        printf("Warehouse: %s\n", warehouses[i]->name);
        for (j = 0; j < warehouses[i]->num_products; j++) {
            printf("  Product: %s, Quantity: %d, Price: %f\n", 
                   warehouses[i]->products[j].name, 
                   warehouses[i]->products[j].quantity, 
                   warehouses[i]->products[j].price);
        }
    }
}

int main() {
    add_warehouse("Warehouse A");
    add_warehouse("Warehouse B");
    add_product("Warehouse A", "Product 1", 10, 10.0);
    add_product("Warehouse A", "Product 2", 20, 20.0);
    add_product("Warehouse B", "Product 3", 30, 30.0);
    add_product("Warehouse B", "Product 4", 40, 40.0);
    print_inventory();
    return 0;
}