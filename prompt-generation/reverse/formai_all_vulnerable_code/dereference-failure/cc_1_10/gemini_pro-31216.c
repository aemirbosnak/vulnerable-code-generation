//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
  char name[50];
  double amount;
} Expense;

typedef struct {
  Expense** expenses;
  int num_expenses;
} ExpenseTracker;

// Function prototypes
ExpenseTracker* create_expense_tracker();
void add_expense(ExpenseTracker*, const char*, double);
void print_expenses(ExpenseTracker*);
void free_expense_tracker(ExpenseTracker*);

// Main function
int main() {
  // Create a new expense tracker
  ExpenseTracker* expense_tracker = create_expense_tracker();

  // Add some expenses
  add_expense(expense_tracker, "Dinner", 20.00);
  add_expense(expense_tracker, "Transportation", 10.00);
  add_expense(expense_tracker, "Entertainment", 15.00);

  // Print the expenses
  print_expenses(expense_tracker);

  // Free the expense tracker
  free_expense_tracker(expense_tracker);

  return 0;
}

// Function definitions
ExpenseTracker* create_expense_tracker() {
  ExpenseTracker* expense_tracker = malloc(sizeof(ExpenseTracker));
  expense_tracker->expenses = NULL;
  expense_tracker->num_expenses = 0;
  return expense_tracker;
}

void add_expense(ExpenseTracker* expense_tracker, const char* name, double amount) {
  // Allocate memory for the new expense
  Expense* expense = malloc(sizeof(Expense));

  // Copy the name and amount into the new expense
  strcpy(expense->name, name);
  expense->amount = amount;

  // Add the new expense to the expense tracker
  expense_tracker->expenses = realloc(expense_tracker->expenses, (expense_tracker->num_expenses + 1) * sizeof(Expense*));
  expense_tracker->expenses[expense_tracker->num_expenses] = expense;
  expense_tracker->num_expenses++;
}

void print_expenses(ExpenseTracker* expense_tracker) {
  printf("Expenses:\n");
  for (int i = 0; i < expense_tracker->num_expenses; i++) {
    printf("  - %s: %.2f\n", expense_tracker->expenses[i]->name, expense_tracker->expenses[i]->amount);
  }
}

void free_expense_tracker(ExpenseTracker* expense_tracker) {
  // Free the expenses
  for (int i = 0; i < expense_tracker->num_expenses; i++) {
    free(expense_tracker->expenses[i]);
  }

  // Free the expense tracker
  free(expense_tracker);
}