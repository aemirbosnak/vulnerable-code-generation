//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Node structure for linked list
typedef struct Node {
    Product product;
    struct Node *next;
} Node;

// Head of the linked list
Node *head = NULL;

// Add a new product to the inventory
void addProduct(char *name, int quantity, float price) {
    // Create a new node
    Node *new_node = (Node*)malloc(sizeof(Node));

    // Set the product data
    strcpy(new_node->product.name, name);
    new_node->product.quantity = quantity;
    new_node->product.price = price;

    // Insert the new node at the beginning of the linked list
    new_node->next = head;
    head = new_node;
}

// Search for a product in the inventory
Product* searchProduct(char *name) {
    // Traverse the linked list
    Node *current = head;
    while (current != NULL) {
        // Check if the product name matches
        if (strcmp(current->product.name, name) == 0) {
            // Return the product
            return &current->product;
        }
        // Move to the next node
        current = current->next;
    }

    // Product not found
    return NULL;
}

// Delete a product from the inventory
void deleteProduct(char *name) {
    // Traverse the linked list
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL) {
        // Check if the product name matches
        if (strcmp(current->product.name, name) == 0) {
            // Delete the node
            if (previous == NULL) {
                // Delete the head node
                head = current->next;
            } else {
                // Delete the current node
                previous->next = current->next;
            }
            free(current);
            return;
        }
        // Move to the next node
        previous = current;
        current = current->next;
    }

    // Product not found
    printf("Product not found\n");
}

// Print the inventory
void printInventory() {
    // Traverse the linked list
    Node *current = head;
    while (current != NULL) {
        // Print the product data
        printf("%s %d %.2f\n", current->product.name, current->product.quantity, current->product.price);

        // Move to the next node
        current = current->next;
    }
}

// Main function
int main() {
    // Add some products to the inventory
    addProduct("Apple", 10, 1.0);
    addProduct("Orange", 20, 1.5);
    addProduct("Banana", 30, 2.0);

    // Search for a product
    Product *product = searchProduct("Orange");
    if (product != NULL) {
        printf("Product found: %s %d %.2f\n", product->name, product->quantity, product->price);
    } else {
        printf("Product not found\n");
    }

    // Delete a product
    deleteProduct("Banana");

    // Print the inventory
    printInventory();

    return 0;
}