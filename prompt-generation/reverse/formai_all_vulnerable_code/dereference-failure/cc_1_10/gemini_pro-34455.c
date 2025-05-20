//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
  char description[50];
  float amount;
  int type; // 1 for income, 2 for expense
} transaction_t;

// Define the structure of the personal finance planner
typedef struct {
  float balance;
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_transactions;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t *create_personal_finance_planner() {
  personal_finance_planner_t *planner = malloc(sizeof(personal_finance_planner_t));
  planner->balance = 0.0;
  planner->num_transactions = 0;
  return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner_t *planner, transaction_t transaction) {
  planner->transactions[planner->num_transactions++] = transaction;
  if (transaction.type == 1) {
    planner->balance += transaction.amount;
  } else {
    planner->balance -= transaction.amount;
  }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner_t *planner) {
  printf("Balance: $%.2f\n", planner->balance);
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("%s: $%.2f\n", planner->transactions[i].description, planner->transactions[i].amount);
  }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner_t *planner) {
  free(planner);
}

// Main function
int main() {
  // Create a new personal finance planner
  personal_finance_planner_t *planner = create_personal_finance_planner();

  // Add some transactions to the personal finance planner
  transaction_t transaction1 = {"Salary", 2000.0, 1};
  add_transaction(planner, transaction1);
  transaction_t transaction2 = {"Rent", -1000.0, 2};
  add_transaction(planner, transaction2);
  transaction_t transaction3 = {"Groceries", -200.0, 2};
  add_transaction(planner, transaction3);
  transaction_t transaction4 = {"Entertainment", -100.0, 2};
  add_transaction(planner, transaction4);

  // Print the personal finance planner
  print_personal_finance_planner(planner);

  // Free the memory allocated for the personal finance planner
  free_personal_finance_planner(planner);

  return 0;
}