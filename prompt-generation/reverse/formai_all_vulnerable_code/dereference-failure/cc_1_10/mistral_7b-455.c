//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[50];
    float price;
    int quantity;
    struct Product *next;
} Product;

Product *head = NULL;

void addProduct(char *name, float price, int quantity) {
    Product *newProduct = (Product *) malloc(sizeof(Product));

    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->quantity = quantity;

    if (head == NULL) {
        head = newProduct;
        newProduct->next = NULL;
    } else {
        Product *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProduct;
        newProduct->next = NULL;
    }
}

void removeProductByName(char *name) {
    if (head == NULL) {
        printf("Inventory is empty!\n");
        return;
    }

    if (strcmp(head->name, name) == 0) {
        Product *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    Product *temp = head;
    while (temp->next != NULL && strcmp(temp->next->name, name) != 0) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Product not found!\n");
        return;
    }

    Product *toRemove = temp->next;
    temp->next = temp->next->next;
    free(toRemove);
}

void updateProduct(char *name, float newPrice, int newQuantity) {
    if (head == NULL) {
        printf("Inventory is empty!\n");
        return;
    }

    Product *temp = head;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product not found!\n");
        return;
    }

    temp->price = newPrice;
    temp->quantity = newQuantity;
}

void printInventory() {
    Product *temp = head;
    while (temp != NULL) {
        printf("%s, %.2f, %d\n", temp->name, temp->price, temp->quantity);
        temp = temp->next;
    }
}

int main() {
    addProduct("Laptop", 800.0, 10);
    addProduct("Monitor", 300.0, 5);
    addProduct("Keyboard", 50.0, 20);

    printInventory();

    removeProductByName("Monitor");

    updateProduct("Keyboard", 60.0, 15);

    printInventory();

    return 0;
}