//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[50];
    int stock;
    struct Product *next;
} Product;

Product *head = NULL;

void displayInventory() {
    Product *current = head;

    if (head == NULL) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("%-20s %s\n", "Product Name", "Stock");

    while (current != NULL) {
        printf("%-20s %d\n", current->name, current->stock);
        current = current->next;
    }
}

void addProduct(char *name, int stock) {
    Product *newProduct = (Product *)malloc(sizeof(Product));

    if (newProduct == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(newProduct->name, name);
    newProduct->stock = stock;
    newProduct->next = head;

    head = newProduct;
}

void removeProduct(char *name) {
    Product *current = head;
    Product *previous = NULL;

    if (head == NULL) {
        printf("Inventory is empty.\n");
        return;
    }

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Product not found in inventory.\n");
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

int main() {
    addProduct("Laptop", 5);
    addProduct("Monitor", 3);
    addProduct("Keyboard", 10);

    displayInventory();

    removeProduct("Monitor");

    displayInventory();

    return 0;
}