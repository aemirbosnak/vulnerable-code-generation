//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: realistic
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
typedef struct node {
    Product product;
    struct node *next;
} Node;

// Head of the linked list
Node *head = NULL;

// Function to add a product to the inventory
void addProduct(char *name, int quantity, float price) {
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    
    // Assign values to the new node
    strcpy(newNode->product.name, name);
    newNode->product.quantity = quantity;
    newNode->product.price = price;

    // Insert the new node at the beginning of the linked list
    newNode->next = head;
    head = newNode;
}

// Function to remove a product from the inventory
void removeProduct(char *name) {
    // Check if the product exists in the inventory
    Node *currNode = head;
    while (currNode != NULL) {
        if (strcmp(currNode->product.name, name) == 0) {
            break;
        }
        currNode = currNode->next;
    }

    // If the product does not exist, return
    if (currNode == NULL) {
        return;
    }

    // Remove the product from the linked list
    if (currNode == head) {
        head = head->next;
    } else {
        Node *prevNode = head;
        while (prevNode->next != currNode) {
            prevNode = prevNode->next;
        }
        prevNode->next = currNode->next;
    }

    // Free the memory allocated for the node
    free(currNode);
}

// Function to update the quantity of a product
void updateQuantity(char *name, int quantity) {
    // Check if the product exists in the inventory
    Node *currNode = head;
    while (currNode != NULL) {
        if (strcmp(currNode->product.name, name) == 0) {
            break;
        }
        currNode = currNode->next;
    }

    // If the product does not exist, return
    if (currNode == NULL) {
        return;
    }

    // Update the quantity of the product
    currNode->product.quantity = quantity;
}

// Function to update the price of a product
void updatePrice(char *name, float price) {
    // Check if the product exists in the inventory
    Node *currNode = head;
    while (currNode != NULL) {
        if (strcmp(currNode->product.name, name) == 0) {
            break;
        }
        currNode = currNode->next;
    }

    // If the product does not exist, return
    if (currNode == NULL) {
        return;
    }

    // Update the price of the product
    currNode->product.price = price;
}

// Function to display the inventory
void displayInventory() {
    // Traverse the linked list and display each product
    Node *currNode = head;
    while (currNode != NULL) {
        printf("%s %d %.2f\n", currNode->product.name, currNode->product.quantity, currNode->product.price);
        currNode = currNode->next;
    }
}

// Main function
int main() {
    // Add some products to the inventory
    addProduct("Apple", 100, 1.00);
    addProduct("Orange", 50, 1.50);
    addProduct("Banana", 20, 2.00);

    // Display the inventory
    printf("Inventory:\n");
    displayInventory();

    // Remove a product from the inventory
    removeProduct("Banana");

    // Update the quantity of a product
    updateQuantity("Apple", 150);

    // Update the price of a product
    updatePrice("Orange", 1.75);

    // Display the inventory again
    printf("\nUpdated inventory:\n");
    displayInventory();

    return 0;
}