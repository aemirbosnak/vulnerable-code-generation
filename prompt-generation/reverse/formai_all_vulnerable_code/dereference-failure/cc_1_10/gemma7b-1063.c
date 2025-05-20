//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

void insertProduct(Product **products, int *numProducts) {
    *products = realloc(*products, (*numProducts + 1) * sizeof(Product));
    (*numProducts)++;
    products[*numProducts - 1] = malloc(sizeof(Product));
    products[*numProducts - 1]->quantity = 0;
    products[*numProducts - 1]->price = 0.0f;
    strcpy(products[*numProducts - 1]->name, "");
}

void updateProductQuantity(Product **products, int numProducts, char *name, int quantity) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i]->name, name) == 0) {
            products[i]->quantity = quantity;
            return;
        }
    }
    insertProduct(products, &numProducts);
    products[numProducts - 1]->quantity = quantity;
}

int main() {
    Product **products = NULL;
    int numProducts = 0;

    insertProduct(products, &numProducts);
    strcpy(products[0]->name, "Product A");
    products[0]->quantity = 10;
    products[0]->price = 10.0f;

    insertProduct(products, &numProducts);
    strcpy(products[1]->name, "Product B");
    products[1]->quantity = 20;
    products[1]->price = 20.0f;

    updateProductQuantity(products, numProducts, "Product A", 15);

    for (int i = 0; i < numProducts; i++) {
        printf("%s: %d, %.2f\n", products[i]->name, products[i]->quantity, products[i]->price);
    }

    return 0;
}