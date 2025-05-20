//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the expense structure
typedef struct expense {
  char *name;
  double amount;
  struct expense *next;
} expense;

// Define the expense tracker structure
typedef struct expense_tracker {
  expense *head;
  expense *tail;
} expense_tracker;

// Create a new expense
expense *new_expense(char *name, double amount) {
  expense *e = malloc(sizeof(expense));
  e->name = strdup(name);
  e->amount = amount;
  e->next = NULL;
  return e;
}

// Add an expense to the tracker
void add_expense(expense_tracker *tracker, expense *e) {
  if (tracker->head == NULL) {
    tracker->head = e;
    tracker->tail = e;
  } else {
    tracker->tail->next = e;
    tracker->tail = e;
  }
}

// Print the expenses in the tracker
void print_expenses(expense_tracker *tracker) {
  expense *e = tracker->head;
  while (e != NULL) {
    printf("%s: $%.2f\n", e->name, e->amount);
    e = e->next;
  }
}

// Free the memory allocated for the expenses
void free_expenses(expense_tracker *tracker) {
  expense *e = tracker->head;
  while (e != NULL) {
    expense *next = e->next;
    free(e->name);
    free(e);
    e = next;
  }
}

// Main function
int main() {
  // Create an expense tracker
  expense_tracker tracker;
  tracker.head = NULL;
  tracker.tail = NULL;

  // Add some expenses to the tracker
  add_expense(&tracker, new_expense("Groceries", 100.00));
  add_expense(&tracker, new_expense("Rent", 1200.00));
  add_expense(&tracker, new_expense("Utilities", 150.00));
  add_expense(&tracker, new_expense("Transportation", 200.00));
  add_expense(&tracker, new_expense("Entertainment", 100.00));

  // Print the expenses in the tracker
  print_expenses(&tracker);

  // Free the memory allocated for the expenses
  free_expenses(&tracker);

  return 0;
}