//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int id;
    char *name;
    int quantity;
    double price;
} Product;

typedef struct Warehouse {
    int capacity;
    Product *products;
    int num_products;
} Warehouse;

Warehouse *create_warehouse(int capacity) {
    Warehouse *warehouse = malloc(sizeof(Warehouse));
    warehouse->capacity = capacity;
    warehouse->products = malloc(sizeof(Product) * capacity);
    warehouse->num_products = 0;
    return warehouse;
}

void destroy_warehouse(Warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_products; i++) {
        free(warehouse->products[i].name);
    }
    free(warehouse->products);
    free(warehouse);
}

Product *find_product_by_id(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            return &warehouse->products[i];
        }
    }
    return NULL;
}

Product *find_product_by_name(Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            return &warehouse->products[i];
        }
    }
    return NULL;
}

int add_product(Warehouse *warehouse, Product product) {
    if (warehouse->num_products >= warehouse->capacity) {
        return -1;
    }

    warehouse->products[warehouse->num_products++] = product;
    return 0;
}

int remove_product(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            warehouse->num_products--;
            for (int j = i; j < warehouse->num_products; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            return 0;
        }
    }
    return -1;
}

void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse:\n");
    printf("Capacity: %d\n", warehouse->capacity);
    printf("Products:\n");
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("  - %d: %s, %d, %.2f\n", warehouse->products[i].id, warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

int main() {
    Warehouse *warehouse = create_warehouse(10);

    Product product1 = {1, "iPhone", 10, 999.99};
    Product product2 = {2, "iPad", 5, 499.99};
    Product product3 = {3, "Macbook", 2, 1299.99};

    add_product(warehouse, product1);
    add_product(warehouse, product2);
    add_product(warehouse, product3);

    print_warehouse(warehouse);

    Product *product = find_product_by_id(warehouse, 2);
    if (product != NULL) {
        printf("Product found: %s\n", product->name);
    } else {
        printf("Product not found.\n");
    }

    remove_product(warehouse, 3);

    print_warehouse(warehouse);

    destroy_warehouse(warehouse);

    return 0;
}