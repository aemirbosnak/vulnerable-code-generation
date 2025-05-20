//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
  char *description;
  float amount;
  char *category;
} Expense;

// Define the structure of the expense tracker
typedef struct {
  Expense expenses[MAX_EXPENSES];
  int num_expenses;
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker *create_expense_tracker() {
  ExpenseTracker *tracker = malloc(sizeof(ExpenseTracker));
  tracker->num_expenses = 0;
  return tracker;
}

// Add an expense to the expense tracker
void add_expense(ExpenseTracker *tracker, char *description, float amount, char *category) {
  if (tracker->num_expenses < MAX_EXPENSES) {
    Expense expense;
    expense.description = strdup(description);
    expense.amount = amount;
    expense.category = strdup(category);
    tracker->expenses[tracker->num_expenses++] = expense;
  }
}

// Print the expenses in the expense tracker
void print_expenses(ExpenseTracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    Expense expense = tracker->expenses[i];
    printf("%s: $%.2f (%s)\n", expense.description, expense.amount, expense.category);
  }
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(ExpenseTracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    free(tracker->expenses[i].description);
    free(tracker->expenses[i].category);
  }
  free(tracker);
}

// Main function
int main() {
  // Create an expense tracker
  ExpenseTracker *tracker = create_expense_tracker();

  // Add some expenses to the expense tracker
  add_expense(tracker, "Groceries", 100.00, "Food");
  add_expense(tracker, "Gas", 50.00, "Transportation");
  add_expense(tracker, "Rent", 1200.00, "Housing");

  // Print the expenses in the expense tracker
  print_expenses(tracker);

  // Free the memory allocated for the expense tracker
  free_expense_tracker(tracker);

  return 0;
}