//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Data Structures
typedef struct {
    char* category;
    double amount;
    char* date;
} Expense;

// Function Declarations
Expense* createExpense(char* category, double amount, char* date);
void freeExpense(Expense* expense);
void printExpense(Expense* expense);
bool compareExpenses(Expense* a, Expense* b);

// Global Variables
Expense* expenses[100];
int numExpenses = 0;

// Main Function
int main() {
    // Create some expenses
    Expense* expense1 = createExpense("Food", 10.0, "2021-03-08");
    Expense* expense2 = createExpense("Entertainment", 20.0, "2021-03-10");
    Expense* expense3 = createExpense("Transportation", 30.0, "2021-03-12");

    // Add the expenses to the array
    expenses[numExpenses++] = expense1;
    expenses[numExpenses++] = expense2;
    expenses[numExpenses++] = expense3;

    // Print the expenses
    printf("Your expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printExpense(expenses[i]);
    }

    // Free the expenses
    for (int i = 0; i < numExpenses; i++) {
        freeExpense(expenses[i]);
    }

    return 0;
}

// Function Definitions
Expense* createExpense(char* category, double amount, char* date) {
    // Allocate memory for the expense
    Expense* expense = malloc(sizeof(Expense));

    // Copy the category, amount, and date into the expense
    expense->category = malloc(strlen(category) + 1);
    strcpy(expense->category, category);
    expense->amount = amount;
    expense->date = malloc(strlen(date) + 1);
    strcpy(expense->date, date);

    // Return the expense
    return expense;
}

void freeExpense(Expense* expense) {
    // Free the category, amount, and date
    free(expense->category);
    free(expense->date);

    // Free the expense
    free(expense);
}

void printExpense(Expense* expense) {
    // Print the expense
    printf("%s: $%.2f (%s)\n", expense->category, expense->amount, expense->date);
}

bool compareExpenses(Expense* a, Expense* b) {
    // Compare the expenses by their amounts
    return a->amount < b->amount;
}