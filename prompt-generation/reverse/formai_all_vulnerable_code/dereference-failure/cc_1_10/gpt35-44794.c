//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    char category[20];
    float price;
    int quantity;
};

struct Warehouse {
    int size;
    struct Product *products;
};

void add_product(struct Warehouse *warehouse, struct Product product) {
    // Increase the size of the products array
    warehouse->size++;
    warehouse->products = (struct Product*) realloc(warehouse->products, warehouse->size * sizeof(struct Product));

    // Add the new product to the end of the array
    warehouse->products[warehouse->size-1] = product;
}

void remove_product(struct Warehouse *warehouse, int id) {
    int i, j;
    for (i = 0; i < warehouse->size; i++) {
        if (warehouse->products[i].id == id) {
            // Shift products left to fill the gap
            for (j = i+1; j < warehouse->size; j++) {
                warehouse->products[j-1] = warehouse->products[j];
            }
            // Decrease the size of the products array
            warehouse->size--;
            warehouse->products = (struct Product*) realloc(warehouse->products, warehouse->size * sizeof(struct Product));
            break;
        }
    }
}

void print_product(struct Product product) {
    printf("Product #%d: %s (%s) - %.2f - %d\n", product.id, product.name, product.category, product.price, product.quantity);
}

void print_warehouse(struct Warehouse warehouse) {
    int i;
    for (i = 0; i < warehouse.size; i++) {
        print_product(warehouse.products[i]);
    }
}

int main() {
    struct Warehouse warehouse = {0, NULL};

    // Test adding products
    struct Product p1 = {1, "Shampoo", "Personal care", 4.99, 50};
    add_product(&warehouse, p1);
    struct Product p2 = {2, "Toothbrush", "Personal care", 2.49, 100};
    add_product(&warehouse, p2);
    struct Product p3 = {3, "T-shirt", "Clothing", 9.99, 20};
    add_product(&warehouse, p3);

    // Test removing a product
    remove_product(&warehouse, 2);

    // Test printing all products
    print_warehouse(warehouse);

    // Free memory allocated for the products array
    free(warehouse.products);

    return 0;
}