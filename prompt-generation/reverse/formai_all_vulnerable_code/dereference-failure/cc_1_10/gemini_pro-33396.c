//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int quantity;
    float price;
};

struct Node {
    struct Product product;
    struct Node *next;
};

struct Node *head = NULL;

void addProduct(char *name, int quantity, float price) {
    struct Node *newProduct = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newProduct->product.name, name);
    newProduct->product.quantity = quantity;
    newProduct->product.price = price;
    newProduct->next = head;
    head = newProduct;
}

void deleteProduct(char *name) {
    struct Node *current = head;
    struct Node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->product.name, name) == 0) {
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

void updateProduct(char *name, int quantity, float price) {
    struct Node *current = head;
    while (current != NULL) {
        if (strcmp(current->product.name, name) == 0) {
            current->product.quantity = quantity;
            current->product.price = price;
            break;
        }
        current = current->next;
    }
}

void printInventory() {
    struct Node *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->product.name);
        printf("Quantity: %d\n", current->product.quantity);
        printf("Price: %.2f\n", current->product.price);
        printf("\n");
        current = current->next;
    }
}

int main() {
    addProduct("Apple", 10, 1.00);
    addProduct("Orange", 5, 1.50);
    addProduct("Banana", 15, 0.75);
    addProduct("Grape", 7, 1.25);
    addProduct("Strawberry", 12, 1.75);

    printInventory();

    deleteProduct("Banana");

    updateProduct("Apple", 20, 1.20);

    printInventory();

    return 0;
}