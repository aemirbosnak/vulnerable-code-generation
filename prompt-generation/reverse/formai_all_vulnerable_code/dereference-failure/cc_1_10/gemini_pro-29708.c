//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

typedef struct node {
    product data;
    struct node *next;
} node;

node *head = NULL;

void addProduct(char *name, int quantity, float price) {
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->data.name, name);
    new->data.quantity = quantity;
    new->data.price = price;
    new->next = head;
    head = new;
}

void deleteProduct(char *name) {
    node *curr = head;
    node *prev = NULL;

    while (curr != NULL && strcmp(curr->data.name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Product not found.\n");
    } else {
        if (prev == NULL) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}

void updateProduct(char *name, int quantity, float price) {
    node *curr = head;

    while (curr != NULL && strcmp(curr->data.name, name) != 0) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Product not found.\n");
    } else {
        curr->data.quantity = quantity;
        curr->data.price = price;
    }
}

void searchProduct(char *name) {
    node *curr = head;

    while (curr != NULL && strcmp(curr->data.name, name) != 0) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Product not found.\n");
    } else {
        printf("Name: %s\n", curr->data.name);
        printf("Quantity: %d\n", curr->data.quantity);
        printf("Price: %.2f\n", curr->data.price);
    }
}

void printInventory() {
    node *curr = head;

    printf("Inventory:\n");
    while (curr != NULL) {
        printf("%s %d %.2f\n", curr->data.name, curr->data.quantity, curr->data.price);
        curr = curr->next;
    }
}

int main() {
    addProduct("Apple", 10, 1.00);
    addProduct("Banana", 20, 1.50);
    addProduct("Orange", 30, 2.00);

    updateProduct("Apple", 20, 1.20);
    deleteProduct("Banana");

    searchProduct("Apple");
    searchProduct("Banana");

    printInventory();

    return 0;
}