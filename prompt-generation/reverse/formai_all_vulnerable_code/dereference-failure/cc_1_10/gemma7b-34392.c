//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store product information
typedef struct Product {
    char name[20];
    int quantity;
    double price;
} Product;

// Define a linked list to store products
typedef struct Node {
    Product product;
    struct Node* next;
} Node;

// Function to insert a product into the linked list
void insertProduct(Node* head, Product product) {
    Node* newNode = malloc(sizeof(Node));
    newNode->product = product;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Function to display all products in the linked list
void displayProducts(Node* head) {
    while (head) {
        printf("%s - %d - %.2lf\n", head->product.name, head->product.quantity, head->product.price);
        head = head->next;
    }
}

int main() {
    // Create a linked list to store products
    Node* head = NULL;

    // Create a few products
    Product product1 = {"Product 1", 10, 10.0};
    Product product2 = {"Product 2", 5, 15.0};
    Product product3 = {"Product 3", 7, 20.0};

    // Insert the products into the linked list
    insertProduct(head, product1);
    insertProduct(head, product2);
    insertProduct(head, product3);

    // Display all products in the linked list
    displayProducts(head);

    return 0;
}