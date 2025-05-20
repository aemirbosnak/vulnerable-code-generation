//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
  char description[100]; // Description of the expense
  float amount;         // Amount of the expense
  int year;             // Year in which the expense was incurred
  int month;            // Month in which the expense was incurred
  int day;              // Day in which the expense was incurred
} Expense;

// Define the structure of the expense tracker
typedef struct {
  Expense expenses[MAX_EXPENSES]; // Array of expenses
  int num_expenses;              // Number of expenses currently tracked
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker* create_expense_tracker() {
  ExpenseTracker* tracker = (ExpenseTracker*)malloc(sizeof(ExpenseTracker));
  tracker->num_expenses = 0;
  return tracker;
}

// Add an expense to the tracker
void add_expense(ExpenseTracker* tracker, Expense expense) {
  if (tracker->num_expenses < MAX_EXPENSES) {
    tracker->expenses[tracker->num_expenses] = expense;
    tracker->num_expenses++;
  } else {
    printf("Error: Maximum number of expenses reached.\n");
  }
}

// Print the expenses in the tracker
void print_expenses(ExpenseTracker* tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    Expense expense = tracker->expenses[i];
    printf("%s: $%.2f (%d-%d-%d)\n", expense.description, expense.amount, expense.year, expense.month, expense.day);
  }
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(ExpenseTracker* tracker) {
  free(tracker);
}

// Main function
int main() {
  // Create a new expense tracker
  ExpenseTracker* tracker = create_expense_tracker();

  // Add some expenses to the tracker
  Expense expense1 = {"Groceries", 50.00, 2023, 1, 1};
  add_expense(tracker, expense1);

  Expense expense2 = {"Gas", 25.00, 2023, 1, 2};
  add_expense(tracker, expense2);

  Expense expense3 = {"Electricity", 100.00, 2023, 1, 3};
  add_expense(tracker, expense3);

  // Print the expenses in the tracker
  print_expenses(tracker);

  // Free the memory allocated for the expense tracker
  free_expense_tracker(tracker);

  return 0;
}