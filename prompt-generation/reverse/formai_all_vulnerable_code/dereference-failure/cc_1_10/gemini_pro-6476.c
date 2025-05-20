//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char* name;
    int quantity;
    float price;
} Product;

Product* createProduct(char* name, int quantity, float price) {
    Product* product = (Product*)malloc(sizeof(Product));
    product->name = strdup(name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

void destroyProduct(Product* product) {
    free(product->name);
    free(product);
}

typedef struct {
    Product** products;
    int size;
    int capacity;
} ProductInventory;

ProductInventory* createProductInventory() {
    ProductInventory* inventory = (ProductInventory*)malloc(sizeof(ProductInventory));
    inventory->products = (Product**)malloc(sizeof(Product*) * 10);
    inventory->size = 0;
    inventory->capacity = 10;
    return inventory;
}

void destroyProductInventory(ProductInventory* inventory) {
    for (int i = 0; i < inventory->size; i++) {
        destroyProduct(inventory->products[i]);
    }
    free(inventory->products);
    free(inventory);
}

void addProduct(ProductInventory* inventory, Product* product) {
    if (inventory->size == inventory->capacity) {
        inventory->capacity *= 2;
        inventory->products = (Product**)realloc(inventory->products, sizeof(Product*) * inventory->capacity);
    }
    inventory->products[inventory->size++] = product;
}

Product* getProductByName(ProductInventory* inventory, char* name) {
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i]->name, name) == 0) {
            return inventory->products[i];
        }
    }
    return NULL;
}

void printProductInventory(ProductInventory* inventory) {
    for (int i = 0; i < inventory->size; i++) {
        printf("%s, %d, %.2f\n", inventory->products[i]->name, inventory->products[i]->quantity, inventory->products[i]->price);
    }
}

int main() {
    ProductInventory* inventory = createProductInventory();

    Product* product1 = createProduct("Apple", 10, 1.0);
    addProduct(inventory, product1);

    Product* product2 = createProduct("Orange", 5, 1.5);
    addProduct(inventory, product2);

    Product* product3 = createProduct("Banana", 15, 2.0);
    addProduct(inventory, product3);

    printProductInventory(inventory);

    Product* product4 = getProductByName(inventory, "Apple");
    printf("Apple: %d, %.2f\n", product4->quantity, product4->price);

    destroyProductInventory(inventory);

    return 0;
}