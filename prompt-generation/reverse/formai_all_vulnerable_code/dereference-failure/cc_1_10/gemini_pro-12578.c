//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the income and expense categories
enum income_categories {
  SALARY,
  BONUSES,
  INVESTMENTS,
  OTHER_INCOME
};

enum expense_categories {
  RENT_MORTGAGE,
  UTILITIES,
  GROCERIES,
  TRANSPORTATION,
  ENTERTAINMENT,
  OTHER_EXPENSES
};

// Define the transaction structure
typedef struct {
  char *description;
  double amount;
  enum income_categories income_category;
  enum expense_categories expense_category;
} transaction;

// Define the personal finance planner structure
typedef struct {
  char *name;
  double starting_balance;
  double current_balance;
  transaction *transactions;
  int num_transactions;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner *create_personal_finance_planner(char *name, double starting_balance) {
  personal_finance_planner *planner = malloc(sizeof(personal_finance_planner));
  planner->name = strdup(name);
  planner->starting_balance = starting_balance;
  planner->current_balance = starting_balance;
  planner->transactions = NULL;
  planner->num_transactions = 0;
  return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner *planner, transaction *transaction) {
  planner->transactions = realloc(planner->transactions, (planner->num_transactions + 1) * sizeof(transaction));
  planner->transactions[planner->num_transactions] = *transaction;
  planner->num_transactions++;
}

// Calculate the total income for the personal finance planner
double calculate_total_income(personal_finance_planner *planner) {
  double total_income = 0;
  for (int i = 0; i < planner->num_transactions; i++) {
    if (planner->transactions[i].income_category != OTHER_INCOME) {
      total_income += planner->transactions[i].amount;
    }
  }
  return total_income;
}

// Calculate the total expenses for the personal finance planner
double calculate_total_expenses(personal_finance_planner *planner) {
  double total_expenses = 0;
  for (int i = 0; i < planner->num_transactions; i++) {
    if (planner->transactions[i].expense_category != OTHER_EXPENSES) {
      total_expenses += planner->transactions[i].amount;
    }
  }
  return total_expenses;
}

// Calculate the net income for the personal finance planner
double calculate_net_income(personal_finance_planner *planner) {
  return calculate_total_income(planner) - calculate_total_expenses(planner);
}

// Print the personal finance planner to the console
void print_personal_finance_planner(personal_finance_planner *planner) {
  printf("Personal Finance Planner for %s\n", planner->name);
  printf("Starting balance: %.2f\n", planner->starting_balance);
  printf("Current balance: %.2f\n", planner->current_balance);
  printf("Total income: %.2f\n", calculate_total_income(planner));
  printf("Total expenses: %.2f\n", calculate_total_expenses(planner));
  printf("Net income: %.2f\n", calculate_net_income(planner));
  printf("\nTransactions:\n");
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("  - %s: %.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
  }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner *planner) {
  free(planner->name);
  for (int i = 0; i < planner->num_transactions; i++) {
    free(planner->transactions[i].description);
  }
  free(planner->transactions);
  free(planner);
}

// Main function
int main() {
  // Create a new personal finance planner
  personal_finance_planner *planner = create_personal_finance_planner("John Doe", 1000.00);

  // Add some transactions to the personal finance planner
  transaction transaction1 = {strdup("Salary"), 2000.00, SALARY, OTHER_INCOME};
  add_transaction(planner, &transaction1);

  transaction transaction2 = {strdup("Rent"), -500.00, RENT_MORTGAGE, OTHER_EXPENSES};
  add_transaction(planner, &transaction2);

  transaction transaction3 = {strdup("Groceries"), -100.00, GROCERIES, OTHER_EXPENSES};
  add_transaction(planner, &transaction3);

  transaction transaction4 = {strdup("Entertainment"), -50.00, ENTERTAINMENT, OTHER_EXPENSES};
  add_transaction(planner, &transaction4);

  // Print the personal finance planner to the console
  print_personal_finance_planner(planner);

  // Free the memory allocated for the personal finance planner
  free_personal_finance_planner(planner);

  return 0;
}