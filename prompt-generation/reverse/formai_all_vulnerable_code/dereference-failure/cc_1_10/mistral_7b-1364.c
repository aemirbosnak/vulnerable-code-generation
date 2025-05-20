//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
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
    struct Node* next;
} Node;

Node* createNode(Product p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = NULL;
    return newNode;
}

void addProduct(Node** head, Product p) {
    Node* newNode = createNode(p);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayInventory(Node* head) {
    printf("\nProduct Inventory System\n");
    Node* current = head;
    while (current != NULL) {
        printf("%s - Stock: %d - Price: %.2f\n", current->data.name, current->data.stock, current->data.price);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    addProduct(&head, (Product){"Laptop", 10, 500.0});
    addProduct(&head, (Product){"Monitor", 5, 250.0});
    addProduct(&head, (Product){"Mouse", 20, 10.0});
    addProduct(&head, (Product){"Keyboard", 15, 20.0});

    displayInventory(head);

    return 0;
}