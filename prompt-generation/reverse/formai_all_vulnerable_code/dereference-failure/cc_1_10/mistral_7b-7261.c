//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    int year;
    int month;
    int day;
    char description[50];
    float amount;
} Expense;

Expense *expenses;
int num_expenses = 0;

void add_expense(Expense *expenses, int *num_expenses) {
    Expense new_expense;
    if (*num_expenses >= MAX_EXPENSES) {
        printf("Error: Max number of expenses reached.\n");
        return;
    }

    printf("Enter expense date (yyyy mm dd): ");
    scanf("%d %d %d", &new_expense.year, &new_expense.month, &new_expense.day);

    printf("Enter expense description: ");
    scanf("%s", new_expense.description);

    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);

    expenses[*num_expenses] = new_expense;
    (*num_expenses)++;
}

void delete_expense(Expense *expenses, int *num_expenses) {
    int index;
    printf("Enter index of expense to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < *num_expenses) {
        memmove(&expenses[index], &expenses[index + 1], sizeof(Expense) * (*num_expenses - index - 1));
        (*num_expenses)--;
        free((&expenses[*num_expenses]) + sizeof(Expense));
        expenses = realloc(expenses, sizeof(Expense) * (*num_expenses));
    } else {
        printf("Error: Invalid expense index.\n");
    }
}

void view_expenses(Expense *expenses, int num_expenses) {
    int i;
    printf("\nExpenses:\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%d/%d/%d - %s - %.2f\n", expenses[i].year, expenses[i].month, expenses[i].day, expenses[i].description, expenses[i].amount);
    }
}

int main() {
    expenses = malloc(sizeof(Expense));

    int choice;
    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Delete expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                view_expenses(expenses, num_expenses);
                break;
            case 3:
                delete_expense(expenses, &num_expenses);
                break;
            case 4:
                free(expenses);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}