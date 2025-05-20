//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void add_transaction(char *name, float amount) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->amount = amount;
    new_node->next = head;
    head = new_node;
}

void display_transactions() {
    current = head;
    float total = 0.0;
    if (head == NULL) {
        printf("No transactions found.\n");
        return;
    }
    printf("\nCurrent Transactions:\n");
    printf("-----------------------\n");
    while (current != NULL) {
        printf("%s: %f\n", current->name, current->amount);
        total += current->amount;
        current = current->next;
    }
    printf("\nTotal: %f\n", total);
}

int main() {
    int choice, i;
    char name[50];
    float amount;
    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Transaction\n");
        printf("2. Display Transactions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_transaction(name, amount);
                break;
            case 2:
                display_transactions();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}