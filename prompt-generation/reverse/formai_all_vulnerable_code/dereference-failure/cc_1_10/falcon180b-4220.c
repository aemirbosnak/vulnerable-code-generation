//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for linked list of products
typedef struct node {
    char name[50];
    int quantity;
    float price;
    struct node* next;
} Node;

// Function to add a product to the linked list
void addProduct(Node** head, char* name, int quantity, float price) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list of products
void displayProducts(Node* head) {
    printf("Product List:\n");
    while (head!= NULL) {
        printf("%s - Quantity: %d - Price: %.2f\n", head->name, head->quantity, head->price);
        head = head->next;
    }
}

// Function to search for a product in the linked list
Node* searchProduct(Node* head, char* name) {
    Node* current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to update the quantity of a product in the linked list
void updateQuantity(Node** head, char* name, int quantity) {
    Node* product = searchProduct(*head, name);
    if (product!= NULL) {
        product->quantity += quantity;
    }
}

// Function to calculate the total cost of all products in the linked list
float calculateTotalCost(Node* head) {
    float totalCost = 0.0;
    while (head!= NULL) {
        totalCost += head->quantity * head->price;
        head = head->next;
    }
    return totalCost;
}

// Main function
int main() {
    Node* head = NULL;

    // Add products to the linked list
    addProduct(&head, "Paracetamol", 100, 0.50);
    addProduct(&head, "Ibuprofen", 50, 0.75);
    addProduct(&head, "Aspirin", 25, 1.00);

    // Display the initial product list
    displayProducts(head);

    // Update the quantity of Paracetamol
    updateQuantity(&head, "Paracetamol", 50);

    // Display the updated product list
    displayProducts(head);

    // Calculate the total cost of all products
    float totalCost = calculateTotalCost(head);
    printf("Total Cost: $%.2f\n", totalCost);

    return 0;
}