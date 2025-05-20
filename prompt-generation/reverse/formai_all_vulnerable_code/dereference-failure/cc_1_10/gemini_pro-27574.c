//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double amount;
} expense_t;

expense_t *create_expense(char *name, double amount) {
    expense_t *expense = malloc(sizeof(expense_t));
    expense->name = malloc(strlen(name) + 1);
    strcpy(expense->name, name);
    expense->amount = amount;
    return expense;
}

void free_expense(expense_t *expense) {
    free(expense->name);
    free(expense);
}

typedef struct {
    expense_t **expenses;
    int n_expenses;
} expense_list_t;

expense_list_t *create_expense_list(expense_t **expenses, int n_expenses) {
    expense_list_t *expense_list = malloc(sizeof(expense_list_t));
    expense_list->expenses = expenses;
    expense_list->n_expenses = n_expenses;
    return expense_list;
}

void free_expense_list(expense_list_t *expense_list) {
    for (int i = 0; i < expense_list->n_expenses; i++) {
        free_expense(expense_list->expenses[i]);
    }
    free(expense_list->expenses);
    free(expense_list);
}

double calculate_total_expenses(expense_list_t *expense_list) {
    double total = 0;
    for (int i = 0; i < expense_list->n_expenses; i++) {
        total += expense_list->expenses[i]->amount;
    }
    return total;
}

void print_expense_list(expense_list_t *expense_list) {
    for (int i = 0; i < expense_list->n_expenses; i++) {
        printf("%s: $%.2f\n", expense_list->expenses[i]->name, expense_list->expenses[i]->amount);
    }
}

int main() {
    // Create a list of expenses
    expense_t *expenses[] = {
        create_expense("Groceries", 100.00),
        create_expense("Rent", 1200.00),
        create_expense("Utilities", 200.00),
        create_expense("Entertainment", 100.00),
        create_expense("Transportation", 200.00),
    };
    expense_list_t *expense_list = create_expense_list(expenses, 5);

    // Print the list of expenses
    print_expense_list(expense_list);

    // Calculate the total expenses
    double total_expenses = calculate_total_expenses(expense_list);
    printf("Total expenses: $%.2f\n", total_expenses);

    // Free the memory allocated for the expenses and expense list
    free_expense_list(expense_list);

    return 0;
}