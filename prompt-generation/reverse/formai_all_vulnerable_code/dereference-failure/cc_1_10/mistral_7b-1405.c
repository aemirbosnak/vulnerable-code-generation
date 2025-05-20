//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Medicine {
    char name[50];
    float price;
    int stock;
} Medicine;

typedef struct Node {
    Medicine med;
    struct Node *next;
} Node;

Node *head = NULL;

void displayMenu() {
    printf("\n*************************************************\n");
    printf("*             Welcome to C-Meds                *\n");
    printf("*************************************************\n");
    printf("*     1. Add new Medicine                     *\n");
    printf("*     2. View Stock                           *\n");
    printf("*     3. Sell Medicine                        *\n");
    printf("*     4. Update Medicine Stock                *\n");
    printf("*     5. Exit                                 *\n");
    printf("*************************************************\n");
}

void addMedicine(char *name, float price, int stock) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    strcpy(newNode->med.name, name);
    newNode->med.price = price;
    newNode->med.stock = stock;

    newNode->next = head;
    head = newNode;
}

void viewStock() {
    Node *current = head;

    printf("\nCurrent Stock:\n");

    while (current != NULL) {
        printf("\nName: %s", current->med.name);
        printf("\nPrice: %.2f", current->med.price);
        printf("\nStock: %d", current->med.stock);
        current = current->next;
    }
}

void sellMedicine(char *name, int quantity) {
    Node *current = head;
    Node *previous = NULL;
    int stock = 0;

    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            stock = current->med.stock;
            break;
        }
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Medicine not found in stock.\n");
        return;
    }

    if (stock < quantity) {
        printf("Insufficient stock for the given medicine.\n");
        return;
    }

    previous->med.stock += quantity;
    current->med.stock -= quantity;

    printf("Sold %d units of %s successfully.\n", quantity, name);
}

void updateStock(char *name, int newStock) {
    Node *current = head;

    while (current != NULL) {
        if (strcmp(current->med.name, name) == 0) {
            current->med.stock = newStock;
            printf("Stock updated successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Medicine not found in stock.\n");
}

int main() {
    int choice;
    char name[50];
    float price;
    int stock, quantity;

    while (true) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Medicine Name: ");
                scanf("%s", name);
                printf("Enter Medicine Price: ");
                scanf("%f", &price);
                printf("Enter Medicine Stock: ");
                scanf("%d", &stock);
                addMedicine(name, price, stock);
                break;
            case 2:
                viewStock();
                break;
            case 3:
                printf("Enter Medicine Name to be sold: ");
                scanf("%s", name);
                printf("Enter the quantity to be sold: ");
                scanf("%d", &quantity);
                sellMedicine(name, quantity);
                break;
            case 4:
                printf("Enter Medicine Name to be updated: ");
                scanf("%s", name);
                printf("Enter the new stock: ");
                scanf("%d", &stock);
                updateStock(name, stock);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice! Please try again.\n");
        }
    }

    return 0;
}