//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

// Node structure for linked list
typedef struct Node {
    Product product;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(Product product) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->product = product;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node **head, Product product) {
    Node *newNode = createNode(product);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node **head, Product product) {
    Node *newNode = createNode(product);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the linked list
void deleteNode(Node **head, char *name) {
    if (*head == NULL) {
        return;
    }

    if (strcmp((*head)->product.name, name) == 0) {
        *head = (*head)->next;
    } else {
        Node *temp = *head;
        while (temp->next != NULL && strcmp(temp->next->product.name, name) != 0) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
        }
    }
}

// Function to search for a product in the linked list
Node *searchProduct(Node *head, char *name) {
    while (head != NULL && strcmp(head->product.name, name) != 0) {
        head = head->next;
    }

    return head;
}

// Function to display the products in the linked list
void displayProducts(Node *head) {
    while (head != NULL) {
        printf("%s %d %.2f\n", head->product.name, head->product.quantity, head->product.price);
        head = head->next;
    }
}

// Function to get the total value of the inventory
float getTotalValue(Node *head) {
    float totalValue = 0;
    while (head != NULL) {
        totalValue += head->product.quantity * head->product.price;
        head = head->next;
    }

    return totalValue;
}

// Main function
int main() {
    // Create a linked list of products
    Node *head = NULL;

    // Insert some products into the linked list
    Product product1 = {"iPhone", 10, 999.99};
    insertAtBeginning(&head, product1);

    Product product2 = {"iPad", 5, 499.99};
    insertAtEnd(&head, product2);

    Product product3 = {"MacBook", 3, 1299.99};
    insertAtEnd(&head, product3);

    // Display the products in the linked list
    printf("Products in the inventory:\n");
    displayProducts(head);

    // Search for a product in the linked list
    char *name = "iPad";
    Node *foundProduct = searchProduct(head, name);
    if (foundProduct != NULL) {
        printf("Product found:\n");
        printf("%s %d %.2f\n", foundProduct->product.name, foundProduct->product.quantity, foundProduct->product.price);
    } else {
        printf("Product not found.\n");
    }

    // Delete a product from the linked list
    name = "MacBook";
    deleteNode(&head, name);

    // Display the products in the linked list
    printf("Products in the inventory after deletion:\n");
    displayProducts(head);

    // Get the total value of the inventory
    float totalValue = getTotalValue(head);
    printf("Total value of the inventory: %.2f\n", totalValue);

    return 0;
}