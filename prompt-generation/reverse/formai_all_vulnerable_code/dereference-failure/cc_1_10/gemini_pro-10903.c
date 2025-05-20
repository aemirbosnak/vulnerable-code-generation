//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the expense struct
typedef struct expense {
    char *description;
    double amount;
    int day;
    int month;
    int year;
} expense_t;

// Create a new expense
expense_t *new_expense(char *description, double amount, int day, int month, int year) {
    expense_t *expense = malloc(sizeof(expense_t));
    expense->description = strdup(description);
    expense->amount = amount;
    expense->day = day;
    expense->month = month;
    expense->year = year;
    return expense;
}

// Free an expense
void free_expense(expense_t *expense) {
    free(expense->description);
    free(expense);
}

// Print an expense
void print_expense(expense_t *expense) {
    printf("%s: $%.2f (%d/%d/%d)\n", expense->description, expense->amount, expense->day, expense->month, expense->year);
}

// Read an expense from a file
expense_t *read_expense(FILE *file) {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        return NULL;
    }
    char *description = strtok(buffer, ",");
    double amount = atof(strtok(NULL, ","));
    int day = atoi(strtok(NULL, ","));
    int month = atoi(strtok(NULL, ","));
    int year = atoi(strtok(NULL, ","));
    return new_expense(description, amount, day, month, year);
}

// Write an expense to a file
void write_expense(FILE *file, expense_t *expense) {
    fprintf(file, "%s,%.2f,%d,%d,%d\n", expense->description, expense->amount, expense->day, expense->month, expense->year);
}

// Get the total expenses for a given month
double get_total_expenses(expense_t **expenses, int num_expenses, int month) {
    double total = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i]->month == month) {
            total += expenses[i]->amount;
        }
    }
    return total;
}

// Sort expenses by date
void sort_expenses(expense_t **expenses, int num_expenses) {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (expenses[i]->year > expenses[j]->year ||
                (expenses[i]->year == expenses[j]->year && expenses[i]->month > expenses[j]->month) ||
                (expenses[i]->year == expenses[j]->year && expenses[i]->month == expenses[j]->month && expenses[i]->day > expenses[j]->day)) {
                expense_t *temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Create an array of expenses
    expense_t **expenses = malloc(sizeof(expense_t *) * 100);
    int num_expenses = 0;

    // Read expenses from a file
    FILE *file = fopen("expenses.txt", "r");
    if (file != NULL) {
        while (1) {
            expense_t *expense = read_expense(file);
            if (expense == NULL) {
                break;
            }
            expenses[num_expenses++] = expense;
        }
        fclose(file);
    }

    // Get the total expenses for a given month
    int month = 3;
    double total_expenses = get_total_expenses(expenses, num_expenses, month);
    printf("Total expenses for month %d: $%.2f\n", month, total_expenses);

    // Sort expenses by date
    sort_expenses(expenses, num_expenses);

    // Print all expenses
    for (int i = 0; i < num_expenses; i++) {
        print_expense(expenses[i]);
    }

    // Free all expenses
    for (int i = 0; i < num_expenses; i++) {
        free_expense(expenses[i]);
    }
    free(expenses);

    return 0;
}