//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char *name;
    int quantity;
    float price;
} product;

void add_product(product *products, int *num_products, int id, char *name, int quantity, float price) {
    products[*num_products].id = id;
    products[*num_products].name = strdup(name);
    products[*num_products].quantity = quantity;
    products[*num_products].price = price;
    (*num_products)++;
}

void remove_product(product *products, int *num_products, int id) {
    int i;
    for (i = 0; i < *num_products; i++) {
        if (products[i].id == id) {
            free(products[i].name);
            products[i] = products[*num_products - 1];
            (*num_products)--;
            break;
        }
    }
}

void print_products(product *products, int num_products) {
    int i;
    printf("Here is a list of all the products in the inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("Product ID: %d\n", products[i].id);
        printf("Product Name: %s\n", products[i].name);
        printf("Product Quantity: %d\n", products[i].quantity);
        printf("Product Price: $%.2f\n\n", products[i].price);
    }
}

int main() {
    int num_products = 0;
    product *products = malloc(sizeof(product) * 100);

    // Add some products to the inventory
    add_product(products, &num_products, 1, "Bananas", 10, 0.50);
    add_product(products, &num_products, 2, "Apples", 15, 0.75);
    add_product(products, &num_products, 3, "Oranges", 20, 1.00);

    // Print the products in the inventory
    print_products(products, num_products);

    // Remove a product from the inventory
    remove_product(products, &num_products, 2);

    // Print the products in the inventory again
    print_products(products, num_products);

    // Free the memory allocated for the products
    for (int i = 0; i < num_products; i++) {
        free(products[i].name);
    }
    free(products);

    return 0;
}