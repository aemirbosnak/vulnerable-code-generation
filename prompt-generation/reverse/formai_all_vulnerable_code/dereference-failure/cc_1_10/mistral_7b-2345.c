//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char description[50];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void addExpense(char *description, float amount) {
    Expense *newExpense = (Expense *) malloc(sizeof(Expense));

    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = head;

    head = newExpense;
}

void printExpenses() {
    Expense *current = head;

    printf("Expenses:\n");
    printf("-----------------------\n");

    while (current != NULL) {
        printf("%s: $%.2f\n", current->description, current->amount);
        current = current->next;
    }

    printf("-----------------------\n");
}

void searchExpenses(char *description) {
    Expense *current = head;

    while (current != NULL) {
        if (strcmp(current->description, description) == 0) {
            printf("Expense found: %s, $%.2f\n", current->description, current->amount);
            return;
        }
        current = current->next;
    }

    printf("Expense not found.\n");
}

int main() {
    char description[50];
    float amount;
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Search Expense\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense description: ");
                scanf("%s", description);
                printf("Enter expense amount: $");
                scanf("%f", &amount);
                addExpense(description, amount);
                break;
            case 2:
                printExpenses();
                break;
            case 3:
                printf("Enter expense description to search: ");
                scanf("%s", description);
                searchExpenses(description);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}