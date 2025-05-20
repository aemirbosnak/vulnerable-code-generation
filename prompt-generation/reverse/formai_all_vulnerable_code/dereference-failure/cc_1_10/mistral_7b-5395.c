//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Product {
    char name[50];
    int quantity;
    struct Product *next;
} Product;

Product *root = NULL;

void addProduct(char *name, int quantity) {
    Product *newProduct = (Product *) malloc(sizeof(Product));
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->next = root;
    root = newProduct;
}

void displayInventory() {
    Product *current = root;
    if (root == NULL) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("Current inventory:\n");
    while (current != NULL) {
        printf("%s: %d\n", current->name, current->quantity);
        current = current->next;
    }
}

void recursiveDisplayInventory(Product *product) {
    if (product != NULL) {
        printf("%s: %d\n", product->name, product->quantity);
        recursiveDisplayInventory(product->next);
    }
}

int main() {
    addProduct("Laptop", 5);
    addProduct("Monitor", 3);
    addProduct("Keyboard", 10);

    displayInventory();

    printf("\nRecursive display:\n");
    recursiveDisplayInventory(root);

    return 0;
}