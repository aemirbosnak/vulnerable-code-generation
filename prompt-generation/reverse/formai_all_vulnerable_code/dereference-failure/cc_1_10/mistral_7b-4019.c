//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void removeProduct(char *name) {
    Product *current = head;
    Product *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void displayInventory() {
    Product *current = head;

    printf("Product Name\tStock\n");

    while (current != NULL) {
        printf("%s\t\t%d\n", current->name, current->stock);
        current = current->next;
    }
}

void searchProduct(char *name) {
    Product *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s\t\t%d\n", current->name, current->stock);
            return;
        }
        current = current->next;
    }

    printf("%s not found in inventory.\n", name);
}

int main() {
    addProduct("Laptop", 10);
    addProduct("Monitor", 5);
    addProduct("Keyboard", 20);

    displayInventory();

    searchProduct("Laptop");
    searchProduct("Mouse");

    removeProduct("Keyboard");

    displayInventory();

    return 0;
}