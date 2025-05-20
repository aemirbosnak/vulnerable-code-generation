//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Product {
    char name[50];
    int stock;
    struct Product *next;
} Product;

Product *head = NULL;

void addProduct(char *name, int stock) {
    Product *newProduct = (Product *)malloc(sizeof(Product));
    strcpy(newProduct->name, name);
    newProduct->stock = stock;
    newProduct->next = head;
    head = newProduct;
}

Product *searchProduct(char *name) {
    Product *current = head;
    while (current != NULL) {
        if (strcasecmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void removeProduct(char *name) {
    Product *current = head, *previous = NULL;
    while (current != NULL) {
        if (strcasecmp(current->name, name) == 0) {
            if (previous == NULL)
                head = current->next;
            else
                previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void displayInventory() {
    Product *current = head;
    printf("Product Name\tStock\n");
    while (current != NULL) {
        printf("%s\t%d\n", current->name, current->stock);
        current = current->next;
    }
}

int main() {
    addProduct("Laptop", 10);
    addProduct("Monitor", 5);
    addProduct("Keyboard", 3);

    displayInventory();

    Product *productToRemove = searchProduct("Monitor");
    if (productToRemove != NULL) {
        removeProduct("Monitor");
        printf("Removed Monitor from inventory.\n");
    }

    displayInventory();

    return 0;
}