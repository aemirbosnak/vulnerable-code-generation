//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 1000
#define MAX_LINE_LENGTH 100

// Define a struct to represent an expense.
typedef struct Expense {
  char date[11]; // "YYYY-MM-DD"
  char description[51];
  float amount;
} Expense;

// Define a struct to represent the expense tracker.
typedef struct ExpenseTracker {
  Expense expenses[MAX_EXPENSES];
  int num_expenses;
} ExpenseTracker;

// Create a new expense tracker.
ExpenseTracker* new_expense_tracker() {
  ExpenseTracker* tracker = malloc(sizeof(ExpenseTracker));
  tracker->num_expenses = 0;
  return tracker;
}

// Add an expense to the expense tracker.
void add_expense(ExpenseTracker* tracker, Expense expense) {
  if (tracker->num_expenses >= MAX_EXPENSES) {
    fprintf(stderr, "Error: cannot add more than %d expenses.\n", MAX_EXPENSES);
    return;
  }
  tracker->expenses[tracker->num_expenses++] = expense;
}

// Print the expense tracker to the console.
void print_expense_tracker(ExpenseTracker* tracker) {
  printf("Expenses:\n");
  for (int i = 0; i < tracker->num_expenses; i++) {
    Expense expense = tracker->expenses[i];
    printf("  %s  %-50s  %f\n", expense.date, expense.description, expense.amount);
  }
}

// Read an expense from the console.
Expense read_expense() {
  Expense expense;
  printf("Enter date (YYYY-MM-DD): ");
  scanf("%s", expense.date);
  printf("Enter description: ");
  scanf(" %[^\n]s", expense.description);
  printf("Enter amount: ");
  scanf("%f", &expense.amount);
  return expense;
}

// Main function.
int main() {
  // Create a new expense tracker.
  ExpenseTracker* tracker = new_expense_tracker();

  // Add some sample expenses to the expense tracker.
  Expense expense1 = {"2023-01-01", "Rent", 1200.00};
  Expense expense2 = {"2023-01-05", "Groceries", 150.00};
  Expense expense3 = {"2023-01-10", "Entertainment", 50.00};
  add_expense(tracker, expense1);
  add_expense(tracker, expense2);
  add_expense(tracker, expense3);

  // Print the expense tracker to the console.
  print_expense_tracker(tracker);

  // Read an expense from the console.
  Expense expense4 = read_expense();

  // Add the expense to the expense tracker.
  add_expense(tracker, expense4);

  // Print the expense tracker to the console again.
  print_expense_tracker(tracker);

  // Free the memory allocated for the expense tracker.
  free(tracker);

  return 0;
}