//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
// Linus Torvalds style Expense Tracker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the expense structure
typedef struct {
  char *description;
  float amount;
  struct tm *date;
} expense;

// Define the expense tracker structure
typedef struct {
  expense *expenses;
  int num_expenses;
} expense_tracker;

// Create a new expense tracker
expense_tracker *create_expense_tracker() {
  expense_tracker *tracker = malloc(sizeof(expense_tracker));
  tracker->expenses = NULL;
  tracker->num_expenses = 0;
  return tracker;
}

// Add an expense to the tracker
void add_expense(expense_tracker *tracker, char *description, float amount, struct tm *date) {
  tracker->expenses = realloc(tracker->expenses, (tracker->num_expenses + 1) * sizeof(expense));
  tracker->expenses[tracker->num_expenses].description = strdup(description);
  tracker->expenses[tracker->num_expenses].amount = amount;
  tracker->expenses[tracker->num_expenses].date = date;
  tracker->num_expenses++;
}

// Print the expenses in the tracker
void print_expenses(expense_tracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    printf("%s: %.2f (%s)\n", tracker->expenses[i].description, tracker->expenses[i].amount, asctime(tracker->expenses[i].date));
  }
}

// Free the memory allocated for the tracker
void free_expense_tracker(expense_tracker *tracker) {
  for (int i = 0; i < tracker->num_expenses; i++) {
    free(tracker->expenses[i].description);
  }
  free(tracker->expenses);
  free(tracker);
}

// Main function
int main() {
  // Create a new expense tracker
  expense_tracker *tracker = create_expense_tracker();

  // Add some expenses to the tracker
  add_expense(tracker, "Coffee", 2.50, localtime(NULL));
  add_expense(tracker, "Lunch", 10.00, localtime(NULL));
  add_expense(tracker, "Dinner", 15.00, localtime(NULL));

  // Print the expenses in the tracker
  print_expenses(tracker);

  // Free the memory allocated for the tracker
  free_expense_tracker(tracker);

  return 0;
}