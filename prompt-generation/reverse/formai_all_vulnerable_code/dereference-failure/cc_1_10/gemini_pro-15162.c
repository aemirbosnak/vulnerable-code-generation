//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Expense data structure
typedef struct {
  char *description;
  float amount;
} Expense;

// List of expenses
Expense *expenses;
int num_expenses = 0;

// Function to add a new expense
void add_expense(char *description, float amount) {
  // Reallocate the expenses array if necessary
  if (num_expenses % 10 == 0) {
    expenses = realloc(expenses, (num_expenses + 10) * sizeof(Expense));
  }

  // Add the new expense to the array
  expenses[num_expenses].description = strdup(description);
  expenses[num_expenses].amount = amount;
  num_expenses++;
}

// Function to print the list of expenses
void print_expenses() {
  for (int i = 0; i < num_expenses; i++) {
    printf("%s: %.2f\n", expenses[i].description, expenses[i].amount);
  }
}

// Function to free the memory allocated for the expenses
void free_expenses() {
  for (int i = 0; i < num_expenses; i++) {
    free(expenses[i].description);
  }
  free(expenses);
}

// Main function
int main() {
  // Add some sample expenses
  add_expense("Groceries", 100.00);
  add_expense("Rent", 1200.00);
  add_expense("Utilities", 200.00);

  // Print the list of expenses
  print_expenses();

  // Free the memory allocated for the expenses
  free_expenses();

  return 0;
}