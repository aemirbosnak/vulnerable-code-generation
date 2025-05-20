//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data Structures

typedef struct Expense {
    char description[100];
    float amount;
    char date[11];
    char category[50];
} Expense;

typedef struct Node {
    Expense expense;
    struct Node *next;
} Node;

// Function Prototypes

Node *createNode(Expense expense);
void addExpense(Node **head, Expense expense);
void printExpenses(Node *head);
void freeList(Node *head);
void menu();
Expense getExpenseInfo();

// Main Function

int main() {
    Node *head = NULL;
    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&head, getExpenseInfo());
                break;
            case 2:
                printExpenses(head);
                break;
            case 3:
                freeList(head);
                head = NULL;
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function Definitions

Node *createNode(Expense expense) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->expense = expense;
    new_node->next = NULL;
    return new_node;
}

void addExpense(Node **head, Expense expense) {
    Node *new_node = createNode(expense);

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void printExpenses(Node *head) {
    if (head == NULL) {
        printf("No expenses to print.\n");
    } else {
        Node *current = head;
        while (current != NULL) {
            printf("Description: %s\n", current->expense.description);
            printf("Amount: %.2f\n", current->expense.amount);
            printf("Date: %s\n", current->expense.date);
            printf("Category: %s\n\n", current->expense.category);
            current = current->next;
        }
    }
}

void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

void menu() {
    printf("\nExpense Tracker Menu\n");
    printf("1. Add Expense\n");
    printf("2. Print Expenses\n");
    printf("3. Clear Expenses\n");
    printf("4. Exit\n");
    printf("Choice: ");
}

Expense getExpenseInfo() {
    Expense expense;
    printf("Enter expense description: ");
    scanf("%s", expense.description);
    printf("Enter expense amount: ");
    scanf("%f", &expense.amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expense.date);
    printf("Enter expense category: ");
    scanf("%s", expense.category);
    return expense;
}