//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Expense structure
typedef struct Expense {
  char *description;
  float amount;
  struct Expense *next;
} Expense;

// Define the Expense Tracker structure
typedef struct ExpenseTracker {
  Expense *head;
  Expense *tail;
  int size;
} ExpenseTracker;

// Create a new expense tracker
ExpenseTracker *create_expense_tracker() {
  ExpenseTracker *tracker = (ExpenseTracker *)malloc(sizeof(ExpenseTracker));
  tracker->head = NULL;
  tracker->tail = NULL;
  tracker->size = 0;
  return tracker;
}

// Add an expense to the expense tracker
void add_expense(ExpenseTracker *tracker, char *description, float amount) {
  Expense *expense = (Expense *)malloc(sizeof(Expense));
  expense->description = strdup(description);
  expense->amount = amount;
  expense->next = NULL;

  if (tracker->head == NULL) {
    tracker->head = expense;
    tracker->tail = expense;
  } else {
    tracker->tail->next = expense;
    tracker->tail = expense;
  }

  tracker->size++;
}

// Print the expenses in the expense tracker
void print_expenses(ExpenseTracker *tracker) {
  Expense *current = tracker->head;

  while (current != NULL) {
    printf("%s: $%.2f\n", current->description, current->amount);
    current = current->next;
  }
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(ExpenseTracker *tracker) {
  Expense *current = tracker->head;

  while (current != NULL) {
    Expense *next = current->next;
    free(current->description);
    free(current);
    current = next;
  }

  free(tracker);
}

// Main function
int main() {
  // Create a new expense tracker
  ExpenseTracker *tracker = create_expense_tracker();

  // Add some expenses to the expense tracker
  add_expense(tracker, "Groceries", 100.00);
  add_expense(tracker, "Rent", 1200.00);
  add_expense(tracker, "Utilities", 200.00);
  add_expense(tracker, "Entertainment", 100.00);
  add_expense(tracker, "Savings", 500.00);

  // Print the expenses in the expense tracker
  print_expenses(tracker);

  // Free the memory allocated for the expense tracker
  free_expense_tracker(tracker);

  return 0;
}