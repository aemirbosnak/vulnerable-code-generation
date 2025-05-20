//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct Expense {
    char description[50];
    float amount;
    struct Expense* next;
} Expense;

Expense expenses[MAX_EXPENSES];
Expense* expense_list = NULL;
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Max number of expenses reached.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    Expense* new_expense = (Expense*) malloc(sizeof(Expense));
    strcpy(new_expense->description, expenses[num_expenses].description);
    new_expense->amount = expenses[num_expenses].amount;
    new_expense->next = expense_list;
    expense_list = new_expense;
    num_expenses++;
}

void remove_expense() {
    if (num_expenses == 0) {
        printf("Error: No expenses to remove.\n");
        return;
    }

    Expense* current = expense_list;
    Expense* previous = NULL;

    printf("Enter expense number to remove: ");
    int index;
    scanf("%d", &index);

    for (int i = 0; i < index && current != NULL; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Invalid expense number.\n");
        return;
    }

    if (previous == NULL) {
        expense_list = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    num_expenses--;
}

void display_expenses() {
    if (num_expenses == 0) {
        printf("Error: No expenses to display.\n");
        return;
    }

    Expense* current = expense_list;

    printf("\nExpenses:\n");
    while (current != NULL) {
        printf("%s: %.2f\n", current->description, current->amount);
        current = current->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Remove Expense\n");
        printf("3. Display Expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                remove_expense();
                break;
            case 3:
                display_expenses();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}