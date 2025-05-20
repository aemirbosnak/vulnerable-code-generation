//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the expense structure
typedef struct expense {
  char *description;
  int amount;
  struct expense *next;
} expense_t;

// Declare the expense tracker structure
typedef struct expense_tracker {
  expense_t *head;
  int num_expenses;
} expense_tracker_t;

// Create a new expense
expense_t *create_expense(char *description, int amount) {
  // Allocate memory for the new expense
  expense_t *new_expense = malloc(sizeof(expense_t));

  // Set the description and amount of the new expense
  new_expense->description = strdup(description);
  new_expense->amount = amount;

  // Set the next pointer of the new expense to NULL
  new_expense->next = NULL;

  // Return the new expense
  return new_expense;
}

// Add an expense to the expense tracker
void add_expense(expense_tracker_t *tracker, expense_t *expense) {
  // If the expense tracker is empty, set the head to the new expense
  if (tracker->head == NULL) {
    tracker->head = expense;
  } else {
    // Otherwise, iterate through the expense tracker until we reach the last expense
    expense_t *current_expense = tracker->head;
    while (current_expense->next != NULL) {
      current_expense = current_expense->next;
    }

    // Set the next pointer of the last expense to the new expense
    current_expense->next = expense;
  }

  // Increment the number of expenses in the expense tracker
  tracker->num_expenses++;
}

// Delete an expense from the expense tracker
void delete_expense(expense_tracker_t *tracker, expense_t *expense) {
  // If the expense is the first expense in the expense tracker, set the head to the next expense
  if (expense == tracker->head) {
    tracker->head = expense->next;
  } else {
    // Otherwise, iterate through the expense tracker until we find the expense
    expense_t *current_expense = tracker->head;
    while (current_expense->next != expense) {
      current_expense = current_expense->next;
    }

    // Set the next pointer of the previous expense to the next expense of the expense to be deleted
    current_expense->next = expense->next;
  }

  // Decrement the number of expenses in the expense tracker
  tracker->num_expenses--;

  // Free the memory allocated for the expense
  free(expense->description);
  free(expense);
}

// Print the expense tracker
void print_expense_tracker(expense_tracker_t *tracker) {
  // Iterate through the expense tracker and print each expense
  expense_t *current_expense = tracker->head;
  while (current_expense != NULL) {
    printf("%s: %d\n", current_expense->description, current_expense->amount);
    current_expense = current_expense->next;
  }
}

// Free the memory allocated for the expense tracker
void free_expense_tracker(expense_tracker_t *tracker) {
  // Iterate through the expense tracker and free the memory allocated for each expense
  expense_t *current_expense = tracker->head;
  while (current_expense != NULL) {
    expense_t *next_expense = current_expense->next;
    free(current_expense->description);
    free(current_expense);
    current_expense = next_expense;
  }

  // Free the memory allocated for the expense tracker
  free(tracker);
}

int main() {
  // Create an expense tracker
  expense_tracker_t *tracker = malloc(sizeof(expense_tracker_t));
  tracker->head = NULL;
  tracker->num_expenses = 0;

  // Add some expenses to the expense tracker
  add_expense(tracker, create_expense("Rent", 1000));
  add_expense(tracker, create_expense("Groceries", 200));
  add_expense(tracker, create_expense("Utilities", 150));

  // Print the expense tracker
  printf("Expense Tracker:\n");
  print_expense_tracker(tracker);

  // Delete an expense from the expense tracker
  delete_expense(tracker, tracker->head->next);

  // Print the expense tracker again
  printf("\nExpense Tracker after deleting an expense:\n");
  print_expense_tracker(tracker);

  // Free the memory allocated for the expense tracker
  free_expense_tracker(tracker);

  return 0;
}