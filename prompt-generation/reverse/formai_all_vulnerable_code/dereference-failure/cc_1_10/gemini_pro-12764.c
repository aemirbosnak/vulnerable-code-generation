//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of line items
#define MAX_ITEMS 100

// Define the structure of a line item
typedef struct {
  char *description;
  double amount;
} line_item;

// Define the structure of the expense tracker
typedef struct {
  line_item *items;
  int num_items;
} expense_tracker;

// Create a new expense tracker
expense_tracker *new_expense_tracker() {
  expense_tracker *tracker = malloc(sizeof(expense_tracker));
  tracker->items = malloc(MAX_ITEMS * sizeof(line_item));
  tracker->num_items = 0;
  return tracker;
}

// Add a new line item to the expense tracker
void add_line_item(expense_tracker *tracker, char *description, double amount) {
  tracker->items[tracker->num_items].description = strdup(description);
  tracker->items[tracker->num_items].amount = amount;
  tracker->num_items++;
}

// Print the expense tracker
void print_expense_tracker(expense_tracker *tracker) {
  for (int i = 0; i < tracker->num_items; i++) {
    printf("%s: $%.2f\n", tracker->items[i].description, tracker->items[i].amount);
  }
}

// Free the memory allocated by the expense tracker
void free_expense_tracker(expense_tracker *tracker) {
  for (int i = 0; i < tracker->num_items; i++) {
    free(tracker->items[i].description);
  }
  free(tracker->items);
  free(tracker);
}

// Main function
int main() {
  // Create a new expense tracker
  expense_tracker *tracker = new_expense_tracker();

  // Add some line items to the expense tracker
  add_line_item(tracker, "Groceries", 100.00);
  add_line_item(tracker, "Rent", 1200.00);
  add_line_item(tracker, "Utilities", 200.00);
  add_line_item(tracker, "Transportation", 300.00);
  add_line_item(tracker, "Entertainment", 100.00);

  // Print the expense tracker
  print_expense_tracker(tracker);

  // Free the memory allocated by the expense tracker
  free_expense_tracker(tracker);

  return 0;
}