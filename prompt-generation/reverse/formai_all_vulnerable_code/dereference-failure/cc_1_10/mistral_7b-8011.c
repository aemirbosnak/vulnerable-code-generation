//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int id;
    char name[50];
    int stock;
    struct Product *next;
} Product;

typedef struct Node {
    Product *data;
    struct Node *next;
} Node;

void createProduct(Product **head, int id, char name[50], int stock) {
    Product *newProduct = (Product *)malloc(sizeof(Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->stock = stock;
    newProduct->next = *head;
    *head = newProduct;
}

void addProduct(Product **head, int id, char name[50], int stock) {
    Product *current = *head;
    Product *newProduct = (Product *)malloc(sizeof(Product));

    while (current != NULL && current->id < id) {
        current = current->next;
    }

    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->stock = stock;

    if (current == NULL) {
        newProduct->next = *head;
        *head = newProduct;
    } else {
        newProduct->next = current->next;
        current->next = newProduct;
    }
}

void displayInventory(Product *head) {
    Product *current = head;
    printf("\nProduct Inventory:\n");
    printf("--------------------\n");

    while (current != NULL) {
        printf("ID: %d, Name: %s, Stock: %d\n", current->id, current->name, current->stock);
        current = current->next;
    }
}

int main() {
    Product *head = NULL;

    createProduct(&head, 1, "Laptop", 5);
    createProduct(&head, 2, "Monitor", 3);
    createProduct(&head, 3, "Keyboard", 10);

    addProduct(&head, 4, "Mouse", 15);
    addProduct(&head, 5, "Printer", 7);

    displayInventory(head);

    return 0;
}