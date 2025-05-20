//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the structure of an expense
typedef struct expense {
  char *description;
  float amount;
  struct expense *next;
} expense_t;

// Define the structure of a budget
typedef struct budget {
  char *name;
  float amount;
  expense_t *expenses;
  struct budget *next;
} budget_t;

// Create a new expense
expense_t *new_expense(char *description, float amount) {
  expense_t *expense = malloc(sizeof(expense_t));
  expense->description = description;
  expense->amount = amount;
  expense->next = NULL;
  return expense;
}

// Create a new budget
budget_t *new_budget(char *name, float amount) {
  budget_t *budget = malloc(sizeof(budget_t));
  budget->name = name;
  budget->amount = amount;
  budget->expenses = NULL;
  budget->next = NULL;
  return budget;
}

// Add an expense to a budget
void add_expense(budget_t *budget, expense_t *expense) {
  if (budget->expenses == NULL) {
    budget->expenses = expense;
  } else {
    expense_t *current = budget->expenses;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = expense;
  }
}

// Print a budget
void print_budget(budget_t *budget) {
  printf("Budget: %s\n", budget->name);
  printf("Amount: %.2f\n", budget->amount);
  expense_t *current = budget->expenses;
  while (current != NULL) {
    printf("  Expense: %s\n", current->description);
    printf("  Amount: %.2f\n", current->amount);
    current = current->next;
  }
}

// Free the memory allocated for a budget
void free_budget(budget_t *budget) {
  expense_t *current = budget->expenses;
  while (current != NULL) {
    expense_t *next = current->next;
    free(current->description);
    free(current);
    current = next;
  }
  free(budget->name);
  free(budget);
}

// Main function
int main() {
  // Create a new budget
  budget_t *budget = new_budget("My Budget", 1000.00);

  // Add some expenses to the budget
  add_expense(budget, new_expense("Rent", 500.00));
  add_expense(budget, new_expense("Groceries", 200.00));
  add_expense(budget, new_expense("Entertainment", 100.00));
  add_expense(budget, new_expense("Savings", 200.00));

  // Print the budget
  print_budget(budget);

  // Free the memory allocated for the budget
  free_budget(budget);

  return 0;
}