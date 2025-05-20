//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
  char *name;
  double amount;
} expense_t;

typedef struct {
  char *name;
  double limit;
} budget_t;

// Functions
expense_t *create_expense(char *name, double amount) {
  expense_t *expense = malloc(sizeof(expense_t));
  expense->name = strdup(name);
  expense->amount = amount;
  return expense;
}

budget_t *create_budget(char *name, double limit) {
  budget_t *budget = malloc(sizeof(budget_t));
  budget->name = strdup(name);
  budget->limit = limit;
  return budget;
}

void add_expense(expense_t *expense, budget_t *budget) {
  budget->limit -= expense->amount;
}

void print_expenses(expense_t **expenses, int num_expenses) {
  for (int i = 0; i < num_expenses; i++) {
    printf("%s: $%.2f\n", expenses[i]->name, expenses[i]->amount);
  }
}

void print_budgets(budget_t **budgets, int num_budgets) {
  for (int i = 0; i < num_budgets; i++) {
    printf("%s: $%.2f\n", budgets[i]->name, budgets[i]->limit);
  }
}

// Main function
int main() {
  // Create some expenses
  expense_t *expense1 = create_expense("Rent", 1000.00);
  expense_t *expense2 = create_expense("Food", 200.00);
  expense_t *expense3 = create_expense("Entertainment", 100.00);

  // Create some budgets
  budget_t *budget1 = create_budget("Monthly", 1500.00);
  budget_t *budget2 = create_budget("Annual", 18000.00);

  // Add expenses to budgets
  add_expense(expense1, budget1);
  add_expense(expense2, budget1);
  add_expense(expense3, budget1);

  // Print the expenses and budgets
  printf("Expenses:\n");
  print_expenses(&expense1, 3);

  printf("\nBudgets:\n");
  print_budgets(&budget1, 2);

  // Free the memory allocated for the expenses and budgets
  free(expense1->name);
  free(expense1);
  free(expense2->name);
  free(expense2);
  free(expense3->name);
  free(expense3);
  free(budget1->name);
  free(budget1);
  free(budget2->name);
  free(budget2);

  return 0;
}