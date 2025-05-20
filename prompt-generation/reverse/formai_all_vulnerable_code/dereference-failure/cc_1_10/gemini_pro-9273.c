//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Expense structure
typedef struct Expense {
  char *name;
  double amount;
  char *date;
} Expense;

// Expense tracker structure
typedef struct ExpenseTracker {
  Expense expenses[MAX_EXPENSES];
  int num_expenses;
} ExpenseTracker;

// Create a new expense
Expense *new_expense(char *name, double amount, char *date) {
  Expense *expense = malloc(sizeof(Expense));
  expense->name = strdup(name);
  expense->amount = amount;
  expense->date = strdup(date);
  return expense;
}

// Add an expense to the tracker
void add_expense(ExpenseTracker *tracker, Expense *expense) {
  if (tracker->num_expenses >= MAX_EXPENSES) {
    printf("Error: Maximum number of expenses reached.\n");
    return;
  }
  tracker->expenses[tracker->num_expenses++] = *expense;
}

// Print the expenses in the tracker
void print_expenses(ExpenseTracker *tracker) {
  printf("Expenses:\n");
  for (int i = 0; i < tracker->num_expenses; i++) {
    printf("  - %s: $%.2f (%s)\n", tracker->expenses[i].name, tracker->expenses[i].amount, tracker->expenses[i].date);
  }
}

// Free the memory allocated for the expenses
void free_expenses(ExpenseTracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    free(tracker->expenses[i].name);
    free(tracker->expenses[i].date);
  }
}

int main() {
  // Create a new expense tracker
  ExpenseTracker tracker;
  tracker.num_expenses = 0;

  // Add some expenses to the tracker
  add_expense(&tracker, new_expense("Groceries", 50.00, "2023-01-01"));
  add_expense(&tracker, new_expense("Rent", 1000.00, "2023-02-01"));
  add_expense(&tracker, new_expense("Gas", 50.00, "2023-03-01"));
  add_expense(&tracker, new_expense("Entertainment", 100.00, "2023-04-01"));
  add_expense(&tracker, new_expense("Utilities", 150.00, "2023-05-01"));

  // Print the expenses
  print_expenses(&tracker);

  // Free the memory allocated for the expenses
  free_expenses(&tracker);

  return 0;
}