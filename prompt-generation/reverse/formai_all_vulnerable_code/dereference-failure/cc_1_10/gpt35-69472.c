//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a struct to represent a product in warehouse
typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

// Defining a struct to represent a node in the linked list of products
typedef struct Node {
    Product product;
    struct Node* next;
} Node;

// Defining a struct to represent the warehouse
typedef struct Warehouse {
    Node* head;
} Warehouse;

// Function to create a new product
Product createProduct(char name[], int quantity, float price) {
    Product product;
    strcpy(product.name, name);
    product.quantity = quantity;
    product.price = price;
    return product;
}

// Function to create a new node
Node* createNode(Product product) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->product = product;
    node->next = NULL;
    return node;
}

// Function to add a product to the warehouse
void addProduct(Warehouse* warehouse, Product product) {
    Node* node = createNode(product);
    if (warehouse->head == NULL) {
        warehouse->head = node;
    } else {
        Node* current = warehouse->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Function to remove a product from the warehouse
void removeProduct(Warehouse* warehouse, char name[]) {
    Node* previous = NULL;
    Node* current = warehouse->head;
    while (current != NULL) {
        if (strcmp(current->product.name, name) == 0) {
            if (previous == NULL) {
                warehouse->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to print all products in the warehouse
void printWarehouse(Warehouse* warehouse) {
    printf("NAME\tQUANTITY\tPRICE\n");
    Node* current = warehouse->head;
    while (current != NULL) {
        printf("%s\t%d\t\t$%.2f\n", current->product.name, current->product.quantity, current->product.price);
        current = current->next;
    }
}

// Main function for the program
int main() {
    Warehouse warehouse;
    warehouse.head = NULL;
    addProduct(&warehouse, createProduct("Apple", 10, 1.5));
    addProduct(&warehouse, createProduct("Banana", 20, 0.75));
    addProduct(&warehouse, createProduct("Orange", 30, 0.5));
    printf("Initial warehouse:\n");
    printWarehouse(&warehouse);
    printf("\nRemoving Orange from the warehouse...\n");
    removeProduct(&warehouse, "Orange");
    printf("\nFinal warehouse:\n");
    printWarehouse(&warehouse);
    return 0;
}