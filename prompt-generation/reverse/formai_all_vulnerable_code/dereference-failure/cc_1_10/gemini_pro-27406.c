//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure of an expense
typedef struct {
  char *description;
  float amount;
  time_t date;
} Expense;

// Define the structure of an expense tracker
typedef struct {
  Expense *expenses;
  int num_expenses;
  float total_expenses;
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker *create_expense_tracker() {
  ExpenseTracker *tracker = malloc(sizeof(ExpenseTracker));
  tracker->expenses = NULL;
  tracker->num_expenses = 0;
  tracker->total_expenses = 0;
  return tracker;
}

// Add an expense to an expense tracker
void add_expense(ExpenseTracker *tracker, Expense expense) {
  tracker->expenses = realloc(tracker->expenses, (tracker->num_expenses + 1) * sizeof(Expense));
  tracker->expenses[tracker->num_expenses] = expense;
  tracker->num_expenses++;
  tracker->total_expenses += expense.amount;
}

// Print the expenses in an expense tracker
void print_expenses(ExpenseTracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    printf("%s: $%.2f (%s)\n", tracker->expenses[i].description, tracker->expenses[i].amount, ctime(&tracker->expenses[i].date));
  }
}

// Free the memory allocated for an expense tracker
void free_expense_tracker(ExpenseTracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    free(tracker->expenses[i].description);
  }
  free(tracker->expenses);
  free(tracker);
}

// Main function
int main() {
  // Create an expense tracker
  ExpenseTracker *tracker = create_expense_tracker();

  // Add some expenses to the expense tracker
  add_expense(tracker, (Expense){.description = "Groceries", .amount = 100.00, .date = time(NULL)});
  add_expense(tracker, (Expense){.description = "Rent", .amount = 1200.00, .date = time(NULL)});
  add_expense(tracker, (Expense){.description = "Utilities", .amount = 200.00, .date = time(NULL)});
  add_expense(tracker, (Expense){.description = "Entertainment", .amount = 100.00, .date = time(NULL)});

  // Print the expenses in the expense tracker
  print_expenses(tracker);

  // Free the memory allocated for the expense tracker
  free_expense_tracker(tracker);

  return 0;
}