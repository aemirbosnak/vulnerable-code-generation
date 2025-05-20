//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Expense structure
typedef struct {
    char* category;
    double amount;
    char* date;
} Expense;

// Function to create a new expense
Expense* new_expense(char* category, double amount, char* date) {
    Expense* expense = malloc(sizeof(Expense));
    expense->category = strdup(category);
    expense->amount = amount;
    expense->date = strdup(date);
    return expense;
}

// Function to free an expense
void free_expense(Expense* expense) {
    free(expense->category);
    free(expense->date);
    free(expense);
}

// Function to add an expense to an array of expenses
void add_expense(Expense** expenses, int* num_expenses, Expense* expense) {
    if (*num_expenses == MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached\n");
        return;
    }
    expenses[*num_expenses] = expense;
    (*num_expenses)++;
}

// Function to print an expense
void print_expense(Expense* expense) {
    printf("Category: %s\n", expense->category);
    printf("Amount: %.2f\n", expense->amount);
    printf("Date: %s\n", expense->date);
}

// Function to print an array of expenses
void print_expenses(Expense** expenses, int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        print_expense(expenses[i]);
        printf("\n");
    }
}

// Function to free an array of expenses
void free_expenses(Expense** expenses, int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        free_expense(expenses[i]);
    }
    free(expenses);
}

int main() {
    // Create an array of expenses
    Expense** expenses = malloc(MAX_EXPENSES * sizeof(Expense*));
    int num_expenses = 0;

    // Add some expenses to the array
    add_expense(expenses, &num_expenses, new_expense("Food", 10.00, "2023-03-08"));
    add_expense(expenses, &num_expenses, new_expense("Gas", 20.00, "2023-03-10"));
    add_expense(expenses, &num_expenses, new_expense("Entertainment", 30.00, "2023-03-12"));

    // Print the expenses
    print_expenses(expenses, num_expenses);

    // Free the expenses
    free_expenses(expenses, num_expenses);

    return 0;
}