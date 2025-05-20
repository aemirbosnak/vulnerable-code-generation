//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
  char *description;
  double amount;
  char *category;
} transaction;

// Define the structure of a personal finance planner
typedef struct {
  char *name;
  double balance;
  transaction transactions[MAX_TRANSACTIONS];
  int num_transactions;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner *create_personal_finance_planner(char *name) {
  personal_finance_planner *planner = malloc(sizeof(personal_finance_planner));
  planner->name = malloc(strlen(name) + 1);
  strcpy(planner->name, name);
  planner->balance = 0.0;
  planner->num_transactions = 0;
  return planner;
}

// Add a transaction to a personal finance planner
void add_transaction(personal_finance_planner *planner, transaction *transaction) {
  planner->transactions[planner->num_transactions] = *transaction;
  planner->num_transactions++;
}

// Print the transactions of a personal finance planner
void print_transactions(personal_finance_planner *planner) {
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("%s %f %s\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].category);
  }
}

// Free the memory allocated for a personal finance planner
void free_personal_finance_planner(personal_finance_planner *planner) {
  free(planner->name);
  for (int i = 0; i < planner->num_transactions; i++) {
    free(planner->transactions[i].description);
    free(planner->transactions[i].category);
  }
  free(planner);
}

// Main function
int main() {
  // Create a new personal finance planner
  personal_finance_planner *planner = create_personal_finance_planner("John Doe");

  // Add some transactions to the planner
  transaction transaction1 = {"Bought groceries", -50.0, "Groceries"};
  add_transaction(planner, &transaction1);
  transaction transaction2 = {"Received salary", 1000.0, "Salary"};
  add_transaction(planner, &transaction2);
  transaction transaction3 = {"Paid rent", -500.0, "Rent"};
  add_transaction(planner, &transaction3);

  // Print the transactions
  print_transactions(planner);

  // Free the memory allocated for the planner
  free_personal_finance_planner(planner);

  return 0;
}