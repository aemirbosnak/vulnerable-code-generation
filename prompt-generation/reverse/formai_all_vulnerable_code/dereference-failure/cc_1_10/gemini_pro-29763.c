//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    float price;
    int quantity;
} Product;

Product *products;
int numProducts = 0;

void addProduct(Product product) {
    products = realloc(products, (numProducts + 1) * sizeof(Product));
    products[numProducts] = product;
    numProducts++;
}

Product *findProductById(int id) {
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }
    return NULL;
}

Product *findProductByName(char *name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return &products[i];
        }
    }
    return NULL;
}

void removeProductById(int id) {
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numProducts--;
            return;
        }
    }
}

void removeProductByName(char *name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numProducts--;
            return;
        }
    }
}

void printProducts() {
    for (int i = 0; i < numProducts; i++) {
        printf("%d %s %f %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    addProduct((Product) {1, "Apple", 1.0, 10});
    addProduct((Product) {2, "Orange", 2.0, 20});
    addProduct((Product) {3, "Banana", 3.0, 30});

    Product *product1 = findProductById(1);
    printf("Product 1: %d %s %f %d\n", product1->id, product1->name, product1->price, product1->quantity);

    Product *product2 = findProductByName("Apple");
    printf("Product 2: %d %s %f %d\n", product2->id, product2->name, product2->price, product2->quantity);

    removeProductById(2);
    printProducts();

    removeProductByName("Banana");
    printProducts();

    return 0;
}