//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
  char description[50];
  float amount;
  char type[10];
} transaction_t;

// Define the structure of the personal finance planner
typedef struct {
  float balance;
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_transactions;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner() {
  personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
  planner->balance = 0.0;
  planner->num_transactions = 0;
  return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner_t* planner, transaction_t transaction) {
  if (planner->num_transactions < MAX_TRANSACTIONS) {
    planner->transactions[planner->num_transactions] = transaction;
    planner->num_transactions++;
    if (strcmp(transaction.type, "income") == 0) {
      planner->balance += transaction.amount;
    } else if (strcmp(transaction.type, "expense") == 0) {
      planner->balance -= transaction.amount;
    }
  } else {
    printf("Error: Cannot add more than %d transactions.\n", MAX_TRANSACTIONS);
  }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner_t* planner) {
  printf("Balance: %.2f\n", planner->balance);
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("Transaction %d:\n", i + 1);
    printf("  Description: %s\n", planner->transactions[i].description);
    printf("  Amount: %.2f\n", planner->transactions[i].amount);
    printf("  Type: %s\n", planner->transactions[i].type);
  }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner_t* planner) {
  free(planner);
}

// Main function
int main() {
  // Create a new personal finance planner
  personal_finance_planner_t* planner = create_personal_finance_planner();

  // Add some transactions to the personal finance planner
  transaction_t transaction1 = {"Salary", 1000.0, "income"};
  add_transaction(planner, transaction1);
  transaction_t transaction2 = {"Rent", 500.0, "expense"};
  add_transaction(planner, transaction2);
  transaction_t transaction3 = {"Groceries", 200.0, "expense"};
  add_transaction(planner, transaction3);

  // Print the personal finance planner
  print_personal_finance_planner(planner);

  // Free the memory allocated for the personal finance planner
  free_personal_finance_planner(planner);

  return 0;
}