//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char *name;
    int quantity;
    double price;
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

void destroy_warehouse(struct warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_products; i++) {
        free(warehouse->products[i].name);
    }
    free(warehouse->products);
    free(warehouse);
}

void add_product(struct warehouse *warehouse, struct product product) {
    warehouse->products = realloc(warehouse->products, sizeof(struct product) * (warehouse->num_products + 1));
    warehouse->products[warehouse->num_products] = product;
    warehouse->num_products++;
}

void remove_product(struct warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            for (int j = i; j < warehouse->num_products - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            warehouse->num_products--;
            break;
        }
    }
}

struct product *find_product(struct warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            return &warehouse->products[i];
        }
    }
    return NULL;
}

void print_warehouse(struct warehouse *warehouse) {
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("ID: %d\n", warehouse->products[i].id);
        printf("Name: %s\n", warehouse->products[i].name);
        printf("Quantity: %d\n", warehouse->products[i].quantity);
        printf("Price: %f\n", warehouse->products[i].price);
        printf("\n");
    }
}

int main() {
    struct warehouse *warehouse = create_warehouse();

    struct product product1 = {1, "Product 1", 10, 10.0};
    add_product(warehouse, product1);

    struct product product2 = {2, "Product 2", 20, 20.0};
    add_product(warehouse, product2);

    struct product product3 = {3, "Product 3", 30, 30.0};
    add_product(warehouse, product3);

    print_warehouse(warehouse);

    struct product *product = find_product(warehouse, 2);
    if (product != NULL) {
        printf("Product found:\n");
        printf("ID: %d\n", product->id);
        printf("Name: %s\n", product->name);
        printf("Quantity: %d\n", product->quantity);
        printf("Price: %f\n", product->price);
        printf("\n");
    } else {
        printf("Product not found.\n");
    }

    remove_product(warehouse, 3);

    print_warehouse(warehouse);

    destroy_warehouse(warehouse);

    return 0;
}