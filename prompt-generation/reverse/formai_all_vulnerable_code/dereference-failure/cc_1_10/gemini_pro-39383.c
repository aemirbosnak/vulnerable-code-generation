//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Linked list node
typedef struct Node {
    Product product;
    struct Node *next;
} Node;

// Head of the linked list
Node *head = NULL;

// Function to create a new product
Product createProduct(int id, char *name, int quantity, float price) {
    Product product;
    product.id = id;
    strcpy(product.name, name);
    product.quantity = quantity;
    product.price = price;
    return product;
}

// Function to add a new product to the inventory
void addProduct(Product product) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->product = product;
    new_node->next = head;
    head = new_node;
}

// Function to search for a product by ID
Product *searchProduct(int id) {
    Node *current = head;
    while (current != NULL) {
        if (current->product.id == id) {
            return &current->product;
        }
        current = current->next;
    }
    return NULL;
}

// Function to update a product
void updateProduct(Product product) {
    Node *current = head;
    while (current != NULL) {
        if (current->product.id == product.id) {
            current->product = product;
            break;
        }
        current = current->next;
    }
}

// Function to delete a product
void deleteProduct(int id) {
    Node *current = head, *previous = NULL;
    while (current != NULL) {
        if (current->product.id == id) {
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

// Function to print the inventory
void printInventory() {
    Node *current = head;
    printf("\nProduct Inventory:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               current->product.id, current->product.name,
               current->product.quantity, current->product.price);
        current = current->next;
    }
}

int main() {
    // Add some products to the inventory
    addProduct(createProduct(1, "Apple", 10, 1.50));
    addProduct(createProduct(2, "Banana", 15, 2.00));
    addProduct(createProduct(3, "Orange", 20, 2.50));

    // Print the inventory
    printInventory();

    // Search for a product by ID
    Product *product = searchProduct(2);
    if (product != NULL) {
        printf("\nProduct found: %s, Quantity: %d, Price: %.2f\n",
               product->name, product->quantity, product->price);
    } else {
        printf("Product not found.\n");
    }

    // Update a product
    product->quantity = 25;
    updateProduct(*product);

    // Print the updated inventory
    printInventory();

    // Delete a product
    deleteProduct(1);

    // Print the updated inventory
    printInventory();

    return 0;
}