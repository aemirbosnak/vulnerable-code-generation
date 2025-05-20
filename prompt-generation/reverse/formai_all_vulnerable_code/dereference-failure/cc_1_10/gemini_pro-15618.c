//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction types
typedef enum {
  INCOME,
  EXPENSE
} transaction_type;

// Define the transaction structure
typedef struct {
  transaction_type type;
  char description[50];
  float amount;
} transaction;

// Define the personal finance planner structure
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

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, transaction_type type, char* description, float amount) {
  if (planner->num_transactions < MAX_TRANSACTIONS) {
    transaction* new_transaction = &planner->transactions[planner->num_transactions++];
    new_transaction->type = type;
    strcpy(new_transaction->description, description);
    new_transaction->amount = amount;
    
    if (type == INCOME) {
      planner->balance += amount;
    } else {
      planner->balance -= amount;
    }
  }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner* planner) {
  printf("Balance: %.2f\n", planner->balance);
  for (int i = 0; i < planner->num_transactions; i++) {
    transaction* transaction = &planner->transactions[i];
    printf("%s %.2f\n", transaction->description, transaction->amount);
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
  add_transaction(planner, INCOME, "Salary", 1000.0);
  add_transaction(planner, EXPENSE, "Rent", 500.0);
  add_transaction(planner, EXPENSE, "Groceries", 100.0);

  // Print the personal finance planner
  print_personal_finance_planner(planner);

  // Free the memory allocated for the personal finance planner
  free_personal_finance_planner(planner);

  return 0;
}