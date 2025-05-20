//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
  char description[50];
  float amount;
  int type; // 0 for expense, 1 for income
} transaction;

// Define the structure of a personal finance planner
typedef struct {
  float balance;
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

// Add a transaction to a personal finance planner
void add_transaction(personal_finance_planner* planner, transaction* transaction) {
  if (planner->num_transactions == MAX_TRANSACTIONS) {
    printf("Error: Maximum number of transactions reached\n");
    return;
  }

  planner->transactions[planner->num_transactions] = *transaction;
  planner->num_transactions++;

  if (transaction->type == 0) {
    planner->balance -= transaction->amount;
  } else {
    planner->balance += transaction->amount;
  }
}

// Print the balance of a personal finance planner
void print_balance(personal_finance_planner* planner) {
  printf("Balance: %f\n", planner->balance);
}

// Print the transactions of a personal finance planner
void print_transactions(personal_finance_planner* planner) {
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("%s: %f\n", planner->transactions[i].description, planner->transactions[i].amount);
  }
}

// Free the memory allocated for a personal finance planner
void free_personal_finance_planner(personal_finance_planner* planner) {
  free(planner);
}

// Main function
int main() {
  // Create a new personal finance planner
  personal_finance_planner* planner = create_personal_finance_planner();

  // Add some transactions to the planner
  transaction transaction1 = {"Rent", -1000.0, 0};
  add_transaction(planner, &transaction1);

  transaction transaction2 = {"Salary", 2000.0, 1};
  add_transaction(planner, &transaction2);

  transaction transaction3 = {"Groceries", -50.0, 0};
  add_transaction(planner, &transaction3);

  transaction transaction4 = {"Savings", 100.0, 1};
  add_transaction(planner, &transaction4);

  // Print the balance of the planner
  print_balance(planner);

  // Print the transactions of the planner
  print_transactions(planner);

  // Free the memory allocated for the planner
  free_personal_finance_planner(planner);

  return 0;
}