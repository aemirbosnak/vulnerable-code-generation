//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct product {
    int id;
    char *name;
    int quantity;
    float price;
};

struct warehouse {
    int num_products;
    struct product *products;
};

struct warehouse *create_warehouse() {
    struct warehouse *warehouse = malloc(sizeof(struct warehouse));
    warehouse->num_products = 0;
    warehouse->products = NULL;
    return warehouse;
}

void add_product(struct warehouse *warehouse, struct product *product) {
    warehouse->num_products++;
    warehouse->products = realloc(warehouse->products, sizeof(struct product) * warehouse->num_products);
    warehouse->products[warehouse->num_products - 1] = *product;
}

struct product *find_product_by_id(struct warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            return &warehouse->products[i];
        }
    }
    return NULL;
}

void remove_product_by_id(struct warehouse *warehouse, int id) {
    int index = -1;
    for (int i = 0; i < warehouse->num_products; i++) {
        if (warehouse->products[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < warehouse->num_products - 1; i++) {
            warehouse->products[i] = warehouse->products[i + 1];
        }
        warehouse->num_products--;
        warehouse->products = realloc(warehouse->products, sizeof(struct product) * warehouse->num_products);
    }
}

void print_warehouse(struct warehouse *warehouse) {
    printf("Warehouse:\n");
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("  - ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
            warehouse->products[i].id,
            warehouse->products[i].name,
            warehouse->products[i].quantity,
            warehouse->products[i].price);
    }
}

int main() {
    struct warehouse *warehouse = create_warehouse();

    // Add some products to the warehouse
    struct product product1 = {1, "Product 1", 10, 10.0};
    add_product(warehouse, &product1);
    struct product product2 = {2, "Product 2", 20, 20.0};
    add_product(warehouse, &product2);
    struct product product3 = {3, "Product 3", 30, 30.0};
    add_product(warehouse, &product3);

    // Print the warehouse
    print_warehouse(warehouse);

    // Find a product by ID
    struct product *product = find_product_by_id(warehouse, 2);
    if (product != NULL) {
        printf("Found product: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
            product->id,
            product->name,
            product->quantity,
            product->price);
    } else {
        printf("Product not found.\n");
    }

    // Remove a product by ID
    remove_product_by_id(warehouse, 2);

    // Print the warehouse again
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse->products);
    free(warehouse);

    return 0;
}