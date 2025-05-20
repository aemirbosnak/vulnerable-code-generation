//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define PRODUCT_NAME_SIZE 50

typedef struct Product {
    char name[PRODUCT_NAME_SIZE];
    int stock;
    struct Product* next;
} Product;

Product* inventory = NULL;

void addProduct(char* name, int stock) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    strcpy(newProduct->name, name);
    newProduct->stock = stock;
    newProduct->next = inventory;
    inventory = newProduct;
}

int getStock(char* name) {
    Product* current = inventory;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->stock;
        }
        current = current->next;
    }
    return -1;
}

void displayInventory() {
    Product* current = inventory;
    while (current != NULL) {
        printf("%s: %d\n", current->name, current->stock);
        current = current->next;
    }
}

int main() {
    addProduct("Laptop", 5);
    addProduct("Monitor", 3);
    addProduct("Keyboard", 10);
    addProduct("Mouse", 7);

    displayInventory();

    int laptopStock = getStock("Laptop");
    int monitorStock = getStock("Monitor");

    printf("Laptop stock: %d\n", laptopStock);
    printf("Monitor stock: %d\n", monitorStock);

    return 0;
}