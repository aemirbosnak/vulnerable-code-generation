//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char id[10];
    char name[50];
    int quantity;
    float price;
} Product;

typedef struct node {
    Product product;
    struct node* next;
} Node;

Node* head = NULL;

void addProduct(Product product) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->product = product;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void removeProduct(char* id) {
    if (head == NULL) {
        printf("Inventory is empty!\n");
        return;
    }
    if (strcmp(head->product.id, id) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->product.id, id) == 0) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    printf("Product not found!\n");
}

void displayInventory() {
    if (head == NULL) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("ID\tName\tQuantity\tPrice\n");
    Node* current = head;
    while (current != NULL) {
        printf("%s\t%s\t%d\t\t%.2f\n", current->product.id, current->product.name, current->product.quantity, current->product.price);
        current = current->next;
    }
}

int main() {
    int choice;
    printf("Welcome to the Warehouse Management System!\n");
    do {
        printf("\nMain Menu\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Product product;
                printf("\nEnter product ID: ");
                scanf("%s", product.id);
                printf("Enter product name: ");
                scanf("%s", product.name);
                printf("Enter product quantity: ");
                scanf("%d", &product.quantity);
                printf("Enter product price: ");
                scanf("%f", &product.price);
                addProduct(product);
                printf("Product added successfully!\n");
                break;
            }
            case 2: {
                char id[10];
                printf("\nEnter product ID: ");
                scanf("%s", id);
                removeProduct(id);
                break;
            }
            case 3: {
                displayInventory();
                break;
            }
            case 4: {
                printf("\nExiting the program...Goodbye!\n");
                break;
            }
            default: {
                printf("\nInvalid choice! Try again.\n");
                break;
            }
        }
    } while (choice != 4);
    return 0;
}