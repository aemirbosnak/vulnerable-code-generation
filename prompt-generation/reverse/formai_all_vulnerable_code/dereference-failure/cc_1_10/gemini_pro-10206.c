//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char *description;
    double amount;
    char *date;
} Expense;

// Function to create a new expense
Expense *createExpense(char *description, double amount, char *date) {
    Expense *expense = malloc(sizeof(Expense));
    expense->description = strdup(description);
    expense->amount = amount;
    expense->date = strdup(date);
    return expense;
}

// Function to print an expense
void printExpense(Expense *expense) {
    printf("%s\t%.2f\t%s\n", expense->description, expense->amount, expense->date);
}

// Function to add an expense to the array of expenses
void addExpense(Expense **expenses, int *numExpenses, Expense *expense) {
    expenses[*numExpenses] = expense;
    (*numExpenses)++;
}

// Function to sort the array of expenses by date
void sortExpensesByDate(Expense **expenses, int numExpenses) {
    for (int i = 0; i < numExpenses - 1; i++) {
        for (int j = i + 1; j < numExpenses; j++) {
            if (strcmp(expenses[i]->date, expenses[j]->date) > 0) {
                Expense *temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

// Function to print the total amount of expenses
void printTotalAmount(Expense **expenses, int numExpenses) {
    double totalAmount = 0.0;
    for (int i = 0; i < numExpenses; i++) {
        totalAmount += expenses[i]->amount;
    }
    printf("Total amount: %.2f\n", totalAmount);
}

// Function to free the memory allocated for the array of expenses
void freeExpenses(Expense **expenses, int numExpenses) {
    for (int i = 0; i < numExpenses; i++) {
        free(expenses[i]->description);
        free(expenses[i]->date);
        free(expenses[i]);
    }
    free(expenses);
}

int main() {
    // Create an array of expenses
    Expense *expenses[MAX_EXPENSES];

    // Initialize the number of expenses to 0
    int numExpenses = 0;

    // Add some expenses to the array
    addExpense(expenses, &numExpenses, createExpense("Groceries", 50.00, "2023-03-08"));
    addExpense(expenses, &numExpenses, createExpense("Rent", 1000.00, "2023-03-01"));
    addExpense(expenses, &numExpenses, createExpense("Utilities", 200.00, "2023-03-15"));
    addExpense(expenses, &numExpenses, createExpense("Gas", 50.00, "2023-03-22"));
    addExpense(expenses, &numExpenses, createExpense("Entertainment", 100.00, "2023-03-29"));

    // Sort the array of expenses by date
    sortExpensesByDate(expenses, numExpenses);

    // Print the expenses
    printf("Description\tAmount\tDate\n");
    for (int i = 0; i < numExpenses; i++) {
        printExpense(expenses[i]);
    }

    // Print the total amount of expenses
    printTotalAmount(expenses, numExpenses);

    // Free the memory allocated for the array of expenses
    freeExpenses(expenses, numExpenses);

    return 0;
}