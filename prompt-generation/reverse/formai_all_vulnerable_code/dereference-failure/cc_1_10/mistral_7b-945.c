//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[50];
    int stock;
    float price;
} Product;

typedef struct Node {
    Product data;
    struct Node *next;
} Node;

Node *head = NULL;

void addProduct(char *name, int stock, float price) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->data.name, name);
    newNode->data.stock = stock;
    newNode->data.price = price;
    newNode->next = head;
    head = newNode;
}

void searchProduct(char *name) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            printf("Product Name : %s\n", current->data.name);
            printf("Stock : %d\n", current->data.stock);
            printf("Price : %.2f\n", current->data.price);
            return;
        }
        current = current->next;
    }
    printf("Product Not Found\n");
}

void displayInventory() {
    Node *current = head;
    printf("---------------------------------------------------------\n");
    printf("| %-50s | %-10s | %-10s |\n", "Product Name", "Stock", "Price");
    printf("---------------------------------------------------------\n");
    while (current != NULL) {
        printf("| %-50s | %-10d | %.2f |\n", current->data.name, current->data.stock, current->data.price);
        current = current->next;
    }
    printf("---------------------------------------------------------\n");
}

int main() {
    addProduct("Laptop", 10, 1000.5);
    addProduct("Monitor", 5, 500.0);
    addProduct("Mouse", 20, 15.0);

    printf("Initial Inventory:\n");
    displayInventory();

    searchProduct("Laptop");

    printf("\nAfter Selling 3 Laptops:\n");
    head->data.stock -= 3;
    displayInventory();

    return 0;
}