//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct Expense {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    struct Expense *next;
} Expense;

Expense *expenses = NULL;

void add_expense_recursive(Expense *current, const char *name, const char *description, float amount) {
    if (!current) {
        Expense *new_expense = (Expense *)malloc(sizeof(Expense));
        strcpy(new_expense->name, name);
        strcpy(new_expense->description, description);
        new_expense->amount = amount;
        new_expense->next = NULL;
        current = new_expense;
    } else {
        add_expense_recursive(current->next, name, description, amount);
    }
}

void print_expenses_recursive(Expense *current) {
    if (current) {
        printf("%s: %s - %.2f\n", current->name, current->description, current->amount);
        print_expenses_recursive(current->next);
    }
}

void expense_tracker() {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    int choice = 0;

    while (choice != 5) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Edit Expense\n");
        printf("4. Delete Expense\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Expense Name: ");
                scanf("%s", name);
                printf("Enter Expense Description: ");
                scanf("%s", description);
                printf("Enter Expense Amount: ");
                scanf("%f", &amount);
                add_expense_recursive(expenses, name, description, amount);
                break;
            case 2:
                printf("\nExpenses:\n");
                print_expenses_recursive(expenses);
                break;
            case 3:
                // Edit expense logic here
                break;
            case 4:
                // Delete expense logic here
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    expense_tracker();

    Expense *current_expense = expenses;
    while (current_expense != NULL) {
        Expense *next_expense = current_expense->next;
        free(current_expense);
        current_expense = next_expense;
    }

    return 0;
}