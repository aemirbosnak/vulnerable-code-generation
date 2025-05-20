//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Define some irregular structures and functions
typedef struct {
    char name[50];
    int stock;
    float price;
} Product;

void initProduct(Product* p, char* name, int stock, float price) {
    strcpy(p->name, name);
    p->stock = stock;
    p->price = price;
}

void printProduct(Product p) {
    printf("Name: %s, Stock: %d, Price: %.2f\n", p.name, p.stock, p.price);
}

typedef struct {
    Product product;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} InventoryList;

InventoryList inventory;

void addProductToList(Product p) {
    Node* newNode = malloc(sizeof(Node));
    initProduct(newNode, "", p.stock, p.price);
    strcpy(newNode->product.name, p.name);
    newNode->next = inventory.head;
    inventory.head = newNode;
}

void searchProductInList(char* name) {
    Node* currentNode = inventory.head;
    while (currentNode != NULL) {
        if (strcmp(currentNode->product.name, name) == 0) {
            printProduct(currentNode->product);
            return;
        }
        currentNode = currentNode->next;
    }
    printf("Product not found!\n");
}

int main() {
    // Initialize inventory list
    inventory.head = NULL;

    // Add some products to the inventory list
    Product p1 = {"Apple", 10, 0.5};
    Product p2 = {"Banana", 20, 0.3};
    Product p3 = {"Orange", 15, 0.6};

    addProductToList(p1);
    addProductToList(p2);
    addProductToList(p3);

    // Search for a product by name
    searchProductInList("Orange");

    // Wait for a random time before exiting
    srand(time(NULL));
    sleep(rand() % 5 + 2);

    return 0;
}