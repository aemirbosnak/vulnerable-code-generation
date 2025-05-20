//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Product {
    char* name;
    int quantity;
    float price;
};

struct Product* createProduct(char* name, int quantity, float price) {
    struct Product* product = (struct Product*)malloc(sizeof(struct Product));
    product->name = strdup(name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

void displayProduct(struct Product* product) {
    printf("Name: %s\n", product->name);
    printf("Quantity: %d\n", product->quantity);
    printf("Price: %f\n", product->price);
}

void addProduct(struct Product* products[], int size, struct Product* product) {
    if (size == 0) {
        products[0] = product;
        return;
    }
    for (int i = 0; i < size; i++) {
        if (strcmp(product->name, products[i]->name) == 0) {
            free(product->name);
            free(product);
            return;
        }
    }
    products[size] = product;
}

void removeProduct(struct Product* products[], int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i]->name, name) == 0) {
            free(products[i]->name);
            free(products[i]);
            for (int j = i; j < size - 1; j++) {
                products[j] = products[j + 1];
            }
            size--;
            return;
        }
    }
}

void updateQuantity(struct Product* products[], int size, char* name, int quantity) {
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i]->name, name) == 0) {
            products[i]->quantity = quantity;
            return;
        }
    }
}

int main() {
    struct Product* products[] = {NULL};
    int size = 0;

    struct Product* product1 = createProduct("Apple", 10, 0.5);
    struct Product* product2 = createProduct("Banana", 5, 0.3);

    addProduct(products, size, product1);
    addProduct(products, size, product2);

    displayProduct(products[0]);
    displayProduct(products[1]);

    removeProduct(products, size, "Banana");

    displayProduct(products[0]);

    updateQuantity(products, size, "Apple", 12);

    displayProduct(products[0]);

    return 0;
}