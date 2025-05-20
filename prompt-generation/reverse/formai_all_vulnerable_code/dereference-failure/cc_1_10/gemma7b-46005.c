//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// Define the structure of a product
typedef struct product {
    char name[50];
    int quantity;
    double price;
} product;

// Define the function to add a product to the inventory
void addProduct(product *products, int *numProducts) {
    products = (product *)realloc(products, (*numProducts + 1) * sizeof(product));
    products[*numProducts].name[0] = '\0';
    products[*numProducts].quantity = 0;
    products[*numProducts].price = 0.0;
    (*numProducts)++;
}

// Define the function to remove a product from the inventory
void removeProduct(product *products, int *numProducts, char *name) {
    int i = 0;
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].name[0] = '\0';
            products[i].quantity = 0;
            products[i].price = 0.0;
            (*numProducts)--;
            return;
        }
    }
    printf("Error: Product not found.\n");
}

// Define the function to list all products
void listProducts(product *products, int numProducts) {
    int i = 0;
    for (i = 0; i < numProducts; i++) {
        printf("%s: %d, $%.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    // Create an array of products
    product *products = NULL;
    int numProducts = 0;

    // Add some products to the inventory
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);

    // List all products
    listProducts(products, numProducts);

    // Remove a product from the inventory
    removeProduct(products, &numProducts, "Product 2");

    // List all products again
    listProducts(products, numProducts);

    return 0;
}