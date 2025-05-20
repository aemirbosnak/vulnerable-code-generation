//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Define the expense structure
typedef struct {
  char *description;
  double amount;
  char *date;
} expense_t;

// Function to create a new expense
expense_t *new_expense(char *description, double amount, char *date) {
  // Allocate memory for the new expense
  expense_t *expense = malloc(sizeof(expense_t));

  // Set the properties of the new expense
  expense->description = strdup(description);
  expense->amount = amount;
  expense->date = strdup(date);

  // Return the new expense
  return expense;
}

// Function to add an expense to the list of expenses
void add_expense(expense_t **expenses, int *num_expenses, expense_t *expense) {
  // Reallocate memory for the list of expenses if necessary
  if (*num_expenses == MAX_EXPENSES) {
    *expenses = realloc(*expenses, (*num_expenses + 1) * sizeof(expense_t));
  }

  // Add the expense to the list of expenses
  (*expenses)[*num_expenses] = *expense;

  // Increment the number of expenses
  (*num_expenses)++;
}

// Function to print the list of expenses
void print_expenses(expense_t *expenses, int num_expenses) {
  // Print the header
  printf("Expenses:\n");

  // Print each expense
  for (int i = 0; i < num_expenses; i++) {
    printf("  %s - $%.2f - %s\n", expenses[i].description, expenses[i].amount, expenses[i].date);
  }
}

// Function to free the memory allocated for the list of expenses
void free_expenses(expense_t *expenses, int num_expenses) {
  // Free the memory allocated for each expense
  for (int i = 0; i < num_expenses; i++) {
    free(expenses[i].description);
    free(expenses[i].date);
  }

  // Free the memory allocated for the list of expenses
  free(expenses);
}

int main() {
  // Create the list of expenses
  expense_t *expenses = NULL;
  int num_expenses = 0;

  // Add some expenses to the list of expenses
  add_expense(&expenses, &num_expenses, new_expense("Dinner at the Bluebird", 50.00, "2023-03-08"));
  add_expense(&expenses, &num_expenses, new_expense("Groceries", 100.00, "2023-03-10"));
  add_expense(&expenses, &num_expenses, new_expense("Rent", 1500.00, "2023-03-15"));
  add_expense(&expenses, &num_expenses, new_expense("Utilities", 200.00, "2023-03-20"));

  // Print the list of expenses
  print_expenses(expenses, num_expenses);

  // Free the memory allocated for the list of expenses
  free_expenses(expenses, num_expenses);

  return 0;
}