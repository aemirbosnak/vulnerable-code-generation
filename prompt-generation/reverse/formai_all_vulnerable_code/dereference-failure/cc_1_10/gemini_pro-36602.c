//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

product* createProduct(int id, char* name, int quantity, float price) {
    product* p = (product*)malloc(sizeof(product));
    p->id = id;
    strcpy(p->name, name);
    p->quantity = quantity;
    p->price = price;
    return p;
}

void addProduct(product** products, int* numProducts, product* p) {
    products[*numProducts] = p;
    (*numProducts)++;
}

void removeProduct(product** products, int* numProducts, int id) {
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (products[i]->id == id) {
            products[i] = products[*numProducts - 1];
            (*numProducts)--;
            break;
        }
    }
}

void updateProduct(product** products, int* numProducts, int id, char* name, int quantity, float price) {
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (products[i]->id == id) {
            strcpy(products[i]->name, name);
            products[i]->quantity = quantity;
            products[i]->price = price;
            break;
        }
    }
}

void printProducts(product** products, int numProducts) {
    int i;
    for (i = 0; i < numProducts; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", products[i]->id, products[i]->name, products[i]->quantity, products[i]->price);
    }
}

int main() {
    product* products[100];
    int numProducts = 0;

    addProduct(products, &numProducts, createProduct(1, "Apple", 10, 1.0));
    addProduct(products, &numProducts, createProduct(2, "Orange", 15, 1.5));
    addProduct(products, &numProducts, createProduct(3, "Banana", 20, 2.0));

    printProducts(products, numProducts);

    removeProduct(products, &numProducts, 2);

    printProducts(products, numProducts);

    updateProduct(products, &numProducts, 1, "Apple", 15, 1.2);

    printProducts(products, numProducts);

    return 0;
}