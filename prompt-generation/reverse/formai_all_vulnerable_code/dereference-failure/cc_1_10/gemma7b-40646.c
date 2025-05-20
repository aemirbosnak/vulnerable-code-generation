//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <string.h>

// Define a structure to store product information
typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

// Define a function to add a product to the inventory
void addProduct(Product *products, int *numProducts) {
    products = (Product *)realloc(products, (*numProducts + 1) * sizeof(Product));
    products[*numProducts].name[0] = '\0';
    products[*numProducts].quantity = 0;
    products[*numProducts].price = 0.0f;
    *numProducts++;
}

// Define a function to remove a product from the inventory
void removeProduct(Product *products, int *numProducts) {
    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].name, "") == 0) {
            products[i].name[0] = '\0';
            products[i].quantity = 0;
            products[i].price = 0.0f;
            *numProducts--;
            return;
        }
    }
    printf("Error: Product not found.\n");
}

// Define a function to update the quantity of a product
void updateQuantity(Product *products, int *numProducts, char *name, int quantity) {
    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity = quantity;
            return;
        }
    }
    printf("Error: Product not found.\n");
}

int main() {
    // Create an array of products
    Product *products = NULL;
    int numProducts = 0;

    // Add some products to the inventory
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);

    // Update the quantity of a product
    updateQuantity(products, &numProducts, "Product 2", 10);

    // Remove a product from the inventory
    removeProduct(products, &numProducts);

    // Print the inventory
    for (int i = 0; i < numProducts; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    return 0;
}