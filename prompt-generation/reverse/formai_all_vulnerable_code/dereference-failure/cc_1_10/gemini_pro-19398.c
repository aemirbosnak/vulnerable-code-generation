//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[256];
    int quantity;
    float price;
} Product;

void addProduct(Product *products, int *size, Product product) {
    products = realloc(products, (*size + 1) * sizeof(Product));
    products[*size] = product;
    (*size)++;
}

void removeProduct(Product *products, int *size, int id) {
    for (int i = 0; i < *size; i++) {
        if (products[i].id == id) {
            for (int j = i; j < *size - 1; j++) {
                products[j] = products[j + 1];
            }
            (*size)--;
            return;
        }
    }
}

void updateProduct(Product *products, int *size, Product product) {
    for (int i = 0; i < *size; i++) {
        if (products[i].id == product.id) {
            products[i] = product;
            return;
        }
    }
}

void printProducts(Product *products, int size) {
    for (int i = 0; i < size; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    Product products[100];
    int size = 0;

    addProduct(products, &size, (Product) {1, "Apple", 10, 1.0});
    addProduct(products, &size, (Product) {2, "Banana", 20, 2.0});
    addProduct(products, &size, (Product) {3, "Orange", 30, 3.0});

    printProducts(products, size);

    removeProduct(products, &size, 2);

    printProducts(products, size);

    updateProduct(products, &size, (Product) {1, "Apple", 20, 1.5});

    printProducts(products, size);

    return 0;
}