//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a single expense
typedef struct Expense {
  char *category;
  char *description;
  double amount;
  struct Expense *next;
} Expense;

// A struct to represent the entire expense tracker
typedef struct ExpenseTracker {
  Expense *head;
  Expense *tail;
  int num_expenses;
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker *new_expense_tracker() {
  ExpenseTracker *tracker = malloc(sizeof(ExpenseTracker));
  tracker->head = NULL;
  tracker->tail = NULL;
  tracker->num_expenses = 0;
  return tracker;
}

// Add a new expense to the tracker
void add_expense(ExpenseTracker *tracker, char *category, char *description, double amount) {
  Expense *new_expense = malloc(sizeof(Expense));
  new_expense->category = strdup(category);
  new_expense->description = strdup(description);
  new_expense->amount = amount;
  new_expense->next = NULL;

  if (tracker->head == NULL) {
    tracker->head = new_expense;
    tracker->tail = new_expense;
  } else {
    tracker->tail->next = new_expense;
    tracker->tail = new_expense;
  }
  tracker->num_expenses++;
}

// Print a report of all expenses in the tracker
void print_report(ExpenseTracker *tracker) {
  Expense *current = tracker->head;
  while (current != NULL) {
    printf("%s: %.2f (%s)\n", current->category, current->amount, current->description);
    current = current->next;
  }
}

// Free the memory used by the tracker and all of its expenses
void free_expense_tracker(ExpenseTracker *tracker) {
  Expense *current = tracker->head;
  while (current != NULL) {
    Expense *next = current->next;
    free(current->category);
    free(current->description);
    free(current);
    current = next;
  }
  free(tracker);
}

// Example usage
int main() {
  ExpenseTracker *tracker = new_expense_tracker();
  add_expense(tracker, "Groceries", "Milk, eggs, bread", 20.00);
  add_expense(tracker, "Entertainment", "Movie tickets", 15.00);
  add_expense(tracker, "Transportation", "Gas for car", 30.00);
  add_expense(tracker, "Utilities", "Electric bill", 50.00);
  print_report(tracker);
  free_expense_tracker(tracker);
  return 0;
}