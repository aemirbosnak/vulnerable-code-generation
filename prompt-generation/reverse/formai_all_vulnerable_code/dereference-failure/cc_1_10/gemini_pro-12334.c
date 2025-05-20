//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
  char description[50];
  double amount;
  char type[10];
} transaction;

// Define the structure of the personal finance planner
typedef struct {
  char name[50];
  double balance;
  transaction transactions[MAX_TRANSACTIONS];
  int num_transactions;
} personal_finance_planner;

// Create a new personal finance planner
personal_finance_planner* create_personal_finance_planner(char* name) {
  personal_finance_planner* planner = malloc(sizeof(personal_finance_planner));
  strcpy(planner->name, name);
  planner->balance = 0.0;
  planner->num_transactions = 0;
  return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner* planner, char* description, double amount, char* type) {
  if (planner->num_transactions < MAX_TRANSACTIONS) {
    strcpy(planner->transactions[planner->num_transactions].description, description);
    planner->transactions[planner->num_transactions].amount = amount;
    strcpy(planner->transactions[planner->num_transactions].type, type);
    planner->num_transactions++;
    if (strcmp(type, "income") == 0) {
      planner->balance += amount;
    } else if (strcmp(type, "expense") == 0) {
      planner->balance -= amount;
    }
  }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner* planner) {
  printf("Name: %s\n", planner->name);
  printf("Balance: %.2f\n", planner->balance);
  printf("Transactions:\n");
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("  %s: %.2f (%s)\n", planner->transactions[i].description, planner->transactions[i].amount, planner->transactions[i].type);
  }
}

// Free the memory allocated for the personal finance planner
void free_personal_finance_planner(personal_finance_planner* planner) {
  free(planner);
}

// Main function
int main() {
  // Create a new personal finance planner
  personal_finance_planner* planner = create_personal_finance_planner("John Doe");

  // Add some transactions to the personal finance planner
  add_transaction(planner, "Salary", 2000.00, "income");
  add_transaction(planner, "Rent", -1000.00, "expense");
  add_transaction(planner, "Groceries", -200.00, "expense");
  add_transaction(planner, "Entertainment", -100.00, "expense");

  // Print the personal finance planner
  print_personal_finance_planner(planner);

  // Free the memory allocated for the personal finance planner
  free_personal_finance_planner(planner);

  return 0;
}