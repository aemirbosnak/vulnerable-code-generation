//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct transaction {
  char description[50];
  double amount;
  int type; // 0 for income, 1 for expense
} transaction;

// Define the structure of the personal finance planner
typedef struct personal_finance_planner {
  double balance;
  transaction transactions[MAX_TRANSACTIONS];
  int num_transactions;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner* create_personal_finance_planner() {
  personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
  planner->balance = 0.0;
  planner->num_transactions = 0;
  return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, transaction* t) {
  if (planner->num_transactions < MAX_TRANSACTIONS) {
    planner->transactions[planner->num_transactions] = *t;
    planner->num_transactions++;
  }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner* planner) {
  printf("Balance: $%.2f\n", planner->balance);
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("%s: $%.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
  }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner* planner) {
  free(planner);
}

// Main function
int main() {
  // Create a new personal finance planner
  personal_finance_planner* planner = create_personal_finance_planner();

  // Add some transactions to the personal finance planner
  transaction t1 = {"Salary", 1000.0, 0};
  add_transaction(planner, &t1);
  transaction t2 = {"Rent", -500.0, 1};
  add_transaction(planner, &t2);
  transaction t3 = {"Groceries", -100.0, 1};
  add_transaction(planner, &t3);

  // Print the personal finance planner
  print_personal_finance_planner(planner);

  // Free the memory allocated for the personal finance planner
  free_personal_finance_planner(planner);

  return 0;
}