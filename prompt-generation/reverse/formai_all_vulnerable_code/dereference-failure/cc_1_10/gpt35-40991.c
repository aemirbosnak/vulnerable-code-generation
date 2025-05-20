//FormAI DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char description[51];
    float amount;
} Expense;

void display_menu();
void add_expense(Expense* expenses, int* num_expenses);
void view_expenses(Expense* expenses, int num_expenses);

int main() {

    int choice;
    int num_expenses = 0;
    Expense* expenses = NULL;

    do {
        display_menu();
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
                printf("Exiting program...\n");
                free(expenses);
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}

void display_menu() {
    printf("Expense Tracker\n");
    printf("====================\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
}

void add_expense(Expense* expenses, int* num_expenses) {
    Expense expense;

    printf("\nEnter the date (dd-mm-yyyy): ");
    scanf("%s", expense.date);

    printf("Enter the description: ");
    getchar();
    fgets(expense.description, 51, stdin);
    expense.description[strcspn(expense.description, "\n")] = 0;

    printf("Enter the amount: ");
    scanf("%f", &expense.amount);

    (*num_expenses)++;
    expenses = (Expense*) realloc(expenses, sizeof(Expense) * (*num_expenses));
    expenses[*num_expenses - 1] = expense;

    printf("Expense added successfully!\n\n");
}

void view_expenses(Expense* expenses, int num_expenses) {
    if (num_expenses == 0) {
        printf("No expenses found!\n\n");
        return;
    }

    float total_amount = 0;

    printf("\nDate\t\tDescription\t\tAmount\n");
    printf("=======================================================\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t\t%s\t\t%.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
        total_amount += expenses[i].amount;
    }

    printf("\nTotal Expenses: %.2f\n\n", total_amount);
}