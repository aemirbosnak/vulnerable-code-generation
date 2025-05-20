//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
} Customer;

typedef struct Node {
    Customer data;
    struct Node* next;
} Node;

Node* createNode(Customer data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addCustomer(Node** head, Customer newCustomer) {
    Node* newNode = createNode(newCustomer);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayCustomers(Node* head) {
    Node* current = head;
    printf("Name\tAccount Number\tBalance\n");
    while (current != NULL) {
        printf("%s\t%d\t%.2f\n", current->data.name, current->data.account_number, current->data.balance);
        current = current->next;
    }
}

void depositMoney(Node** head, int account_number, float amount) {
    Node* current = *head;
    while (current != NULL) {
        if (current->data.account_number == account_number) {
            current->data.balance += amount;
            printf("Deposit successful! New balance: %.2f\n", current->data.balance);
            return;
        }
        current = current->next;
    }
    printf("Account not found.\n");
}

int main() {
    Node* head = NULL;
    Customer newCustomer1 = {"John Doe", 12345, 500.00};
    Customer newCustomer2 = {"Jane Doe", 67890, 1000.00};
    addCustomer(&head, newCustomer1);
    addCustomer(&head, newCustomer2);
    displayCustomers(head);
    depositMoney(&head, 12345, 300.00);
    displayCustomers(head);
    return 0;
}