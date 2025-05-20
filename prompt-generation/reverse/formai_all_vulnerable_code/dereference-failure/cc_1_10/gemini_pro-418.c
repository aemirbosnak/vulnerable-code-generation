//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Serenity Expense Tracker

typedef struct {
  char name[50];
  double amount;
} Expense;

// Create a new expense
Expense* createExpense(char* name, double amount) {
  Expense* expense = malloc(sizeof(Expense));
  strcpy(expense->name, name);
  expense->amount = amount;
  return expense;
}

// Print an expense
void printExpense(Expense* expense) {
  printf("%s: $%.2f\n", expense->name, expense->amount);
}

// Add an expense to a list
void addExpense(Expense** expenses, int* numExpenses, Expense* expense) {
  expenses[*numExpenses] = expense;
  (*numExpenses)++;
}

// Print a list of expenses
void printExpenses(Expense** expenses, int numExpenses) {
  for (int i = 0; i < numExpenses; i++) {
    printExpense(expenses[i]);
  }
}

// Free the memory allocated for a list of expenses
void freeExpenses(Expense** expenses, int numExpenses) {
  for (int i = 0; i < numExpenses; i++) {
    free(expenses[i]);
  }
}

// Main function
int main() {
  // Create a list of expenses
  Expense** expenses = malloc(100 * sizeof(Expense*));
  int numExpenses = 0;

  // Add some expenses to the list
  addExpense(expenses, &numExpenses, createExpense("Groceries", 100.00));
  addExpense(expenses, &numExpenses, createExpense("Gas", 50.00));
  addExpense(expenses, &numExpenses, createExpense("Rent", 1200.00));

  // Print the list of expenses
  printExpenses(expenses, numExpenses);

  // Free the memory allocated for the list of expenses
  freeExpenses(expenses, numExpenses);

  return 0;
}