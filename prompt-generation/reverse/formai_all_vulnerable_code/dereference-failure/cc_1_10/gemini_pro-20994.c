//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 100

struct product {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
};

struct warehouse {
    struct product products[MAX_PRODUCTS];
    int num_products;
};

struct warehouse* create_warehouse() {
    struct warehouse* warehouse = malloc(sizeof(struct warehouse));
    warehouse->num_products = 0;
    return warehouse;
}

void destroy_warehouse(struct warehouse* warehouse) {
    free(warehouse);
}

bool add_product(struct warehouse* warehouse, struct product product) {
    if (warehouse->num_products >= MAX_PRODUCTS) {
        return false;
    }
    warehouse->products[warehouse->num_products++] = product;
    return true;
}

struct product* find_product_by_id(struct warehouse* warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            return &warehouse->products[i];
        }
    }
    return NULL;
}

bool remove_product_by_id(struct warehouse* warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            for (int j = i; j < warehouse->num_products - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->num_products--;
            return true;
        }
    }
    return false;
}

void print_warehouse(struct warehouse* warehouse) {
    printf("Warehouse contains: %d products\n", warehouse->num_products);
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("Product %d: %s (%d units, $%.2f each)\n",
            warehouse->products[i].id,
            warehouse->products[i].name,
            warehouse->products[i].quantity,
            warehouse->products[i].price);
    }
}

int main() {
    struct warehouse* warehouse = create_warehouse();

    struct product product1 = {
        .id = 1,
        .name = "Apple",
        .quantity = 100,
        .price = 1.00
    };
    add_product(warehouse, product1);

    struct product product2 = {
        .id = 2,
        .name = "Orange",
        .quantity = 50,
        .price = 1.50
    };
    add_product(warehouse, product2);

    struct product product3 = {
        .id = 3,
        .name = "Banana",
        .quantity = 25,
        .price = 2.00
    };
    add_product(warehouse, product3);

    print_warehouse(warehouse);

    struct product* product = find_product_by_id(warehouse, 2);
    if (product != NULL) {
        printf("Found product: %s\n", product->name);
    } else {
        printf("Product not found\n");
    }

    remove_product_by_id(warehouse, 3);
    print_warehouse(warehouse);

    destroy_warehouse(warehouse);

    return 0;
}