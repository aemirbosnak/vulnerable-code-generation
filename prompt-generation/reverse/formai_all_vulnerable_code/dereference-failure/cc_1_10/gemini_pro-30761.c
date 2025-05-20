//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the data structure for a transaction
typedef struct transaction {
  char description[50];
  double amount;
  char date[20];
} transaction_t;

// Define the data structure for a budget
typedef struct budget {
  char name[50];
  double amount;
  double spent;
} budget_t;

// Define the data structure for a financial plan
typedef struct financial_plan {
  char name[50];
  double income;
  double expenses;
  double savings;
  transaction_t *transactions;
  int num_transactions;
  budget_t *budgets;
  int num_budgets;
} financial_plan_t;

// Create a new financial plan
financial_plan_t *create_financial_plan(char *name, double income, double expenses, double savings) {
  financial_plan_t *plan = malloc(sizeof(financial_plan_t));
  strcpy(plan->name, name);
  plan->income = income;
  plan->expenses = expenses;
  plan->savings = savings;
  plan->transactions = NULL;
  plan->num_transactions = 0;
  plan->budgets = NULL;
  plan->num_budgets = 0;
  return plan;
}

// Add a transaction to a financial plan
void add_transaction(financial_plan_t *plan, char *description, double amount, char *date) {
  transaction_t *transaction = malloc(sizeof(transaction_t));
  strcpy(transaction->description, description);
  transaction->amount = amount;
  strcpy(transaction->date, date);
  plan->transactions = realloc(plan->transactions, (plan->num_transactions + 1) * sizeof(transaction_t));
  plan->transactions[plan->num_transactions] = *transaction;
  plan->num_transactions++;
}

// Add a budget to a financial plan
void add_budget(financial_plan_t *plan, char *name, double amount) {
  budget_t *budget = malloc(sizeof(budget_t));
  strcpy(budget->name, name);
  budget->amount = amount;
  budget->spent = 0;
  plan->budgets = realloc(plan->budgets, (plan->num_budgets + 1) * sizeof(budget_t));
  plan->budgets[plan->num_budgets] = *budget;
  plan->num_budgets++;
}

// Print a financial plan
void print_financial_plan(financial_plan_t *plan) {
  printf("Financial Plan: %s\n", plan->name);
  printf("Income: $%.2f\n", plan->income);
  printf("Expenses: $%.2f\n", plan->expenses);
  printf("Savings: $%.2f\n", plan->savings);
  printf("Transactions:\n");
  for (int i = 0; i < plan->num_transactions; i++) {
    printf("  - %s: $%.2f (%s)\n", plan->transactions[i].description, plan->transactions[i].amount, plan->transactions[i].date);
  }
  printf("Budgets:\n");
  for (int i = 0; i < plan->num_budgets; i++) {
    printf("  - %s: $%.2f (spent: $%.2f)\n", plan->budgets[i].name, plan->budgets[i].amount, plan->budgets[i].spent);
  }
}

// Free the memory allocated for a financial plan
void free_financial_plan(financial_plan_t *plan) {
  free(plan->transactions);
  free(plan->budgets);
  free(plan);
}

int main() {
  // Create a new financial plan
  financial_plan_t *plan = create_financial_plan("My Financial Plan", 5000, 3000, 2000);

  // Add some transactions to the plan
  add_transaction(plan, "Rent", -1000, "2023-01-01");
  add_transaction(plan, "Groceries", -200, "2023-01-05");
  add_transaction(plan, "Entertainment", -100, "2023-01-10");
  add_transaction(plan, "Savings", 500, "2023-01-15");

  // Add some budgets to the plan
  add_budget(plan, "Food", 500);
  add_budget(plan, "Entertainment", 200);

  // Print the financial plan
  print_financial_plan(plan);

  // Free the memory allocated for the financial plan
  free_financial_plan(plan);

  return 0;
}