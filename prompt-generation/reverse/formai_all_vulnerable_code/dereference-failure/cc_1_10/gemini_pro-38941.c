//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
  char *description;
  double amount;
  char *category;
} Expense;

// Define the structure of the expense tracker
typedef struct {
  Expense *expenses;
  int num_expenses;
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker *create_expense_tracker() {
  ExpenseTracker *tracker = malloc(sizeof(ExpenseTracker));
  tracker->expenses = malloc(MAX_EXPENSES * sizeof(Expense));
  tracker->num_expenses = 0;
  return tracker;
}

// Add an expense to the tracker
void add_expense(ExpenseTracker *tracker, Expense expense) {
  if (tracker->num_expenses >= MAX_EXPENSES) {
    printf("Error: cannot add more expenses.\n");
    return;
  }
  tracker->expenses[tracker->num_expenses] = expense;
  tracker->num_expenses++;
}

// Print the expenses in the tracker
void print_expenses(ExpenseTracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    printf("%s: $%.2f (%s)\n", tracker->expenses[i].description, tracker->expenses[i].amount, tracker->expenses[i].category);
  }
}

// Free the memory used by the expense tracker
void free_expense_tracker(ExpenseTracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    free(tracker->expenses[i].description);
    free(tracker->expenses[i].category);
  }
  free(tracker->expenses);
  free(tracker);
}

// Main function
int main() {
  // Create a new expense tracker
  ExpenseTracker *tracker = create_expense_tracker();

  // Add some expenses to the tracker
  Expense expense1 = {"Groceries", 50.00, "Food"};
  Expense expense2 = {"Gas", 20.00, "Transportation"};
  Expense expense3 = {"Movie", 15.00, "Entertainment"};
  add_expense(tracker, expense1);
  add_expense(tracker, expense2);
  add_expense(tracker, expense3);

  // Print the expenses in the tracker
  print_expenses(tracker);

  // Free the memory used by the expense tracker
  free_expense_tracker(tracker);

  return 0;
}