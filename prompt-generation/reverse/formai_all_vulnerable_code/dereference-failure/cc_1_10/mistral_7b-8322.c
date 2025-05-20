//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[50];
    int stock;
    float price;
} Product;

void addProduct(Product **products, int *numProducts, char *name, int stock, float price) {
    Product *newProduct = (Product *) malloc(sizeof(Product));

    strcpy(newProduct->name, name);
    newProduct->stock = stock;
    newProduct->price = price;

    if (*numProducts == 0) {
        *products = newProduct;
    } else {
        Product *lastProduct = (*products + *numProducts - 1);
        while (lastProduct->stock != 0) {
            lastProduct--;
        }
        lastProduct->stock = stock;
        lastProduct->price = price;
        (*numProducts)++;
    }
}

void displayInventory(Product *products, int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("%s: %d units, $%.2f\n", products[i].name, products[i].stock, products[i].price);
    }
}

int main() {
    Product *products = NULL;
    int numProducts = 0;

    addProduct(&products, &numProducts, "Apple", 10, 0.5);
    addProduct(&products, &numProducts, "Banana", 15, 0.3);
    addProduct(&products, &numProducts, "Orange", 7, 0.6);
    addProduct(&products, &numProducts, "Grapes", 5, 1.0);

    displayInventory(products, numProducts);

    free(products);

    return 0;
}