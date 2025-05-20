//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction types
#define INCOME 1
#define EXPENSE 2

// Define the transaction categories
#define FOOD 1
#define HOUSING 2
#define TRANSPORTATION 3
#define ENTERTAINMENT 4
#define OTHER 5

// Define the transaction structure
typedef struct {
  int type;
  int category;
  double amount;
  char description[50];
} transaction_t;

// Define the personal finance planner structure
typedef struct {
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_transactions;
  double income;
  double expenses;
  double balance;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t* create_personal_finance_planner() {
  personal_finance_planner_t* planner = malloc(sizeof(personal_finance_planner_t));
  planner->num_transactions = 0;
  planner->income = 0;
  planner->expenses = 0;
  planner->balance = 0;
  return planner;
}

// Add a transaction to the personal finance planner
void add_transaction(personal_finance_planner_t* planner, transaction_t transaction) {
  if (planner->num_transactions < MAX_TRANSACTIONS) {
    planner->transactions[planner->num_transactions] = transaction;
    planner->num_transactions++;
    if (transaction.type == INCOME) {
      planner->income += transaction.amount;
    } else if (transaction.type == EXPENSE) {
      planner->expenses += transaction.amount;
    }
    planner->balance = planner->income - planner->expenses;
  }
}

// Print the personal finance planner
void print_personal_finance_planner(personal_finance_planner_t* planner) {
  printf("Personal Finance Planner\n");
  printf("=======================\n");
  printf("Income: $%.2f\n", planner->income);
  printf("Expenses: $%.2f\n", planner->expenses);
  printf("Balance: $%.2f\n", planner->balance);
  printf("\nTransactions:\n");
  for (int i = 0; i < planner->num_transactions; i++) {
    transaction_t transaction = planner->transactions[i];
    printf("  - %s: $%.2f (%s)\n", transaction.description, transaction.amount, transaction.category == INCOME ? "Income" : "Expense");
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
  transaction_t transaction1 = {INCOME, FOOD, 100, "Grocery shopping"};
  add_transaction(planner, transaction1);
  transaction_t transaction2 = {EXPENSE, HOUSING, 500, "Rent"};
  add_transaction(planner, transaction2);
  transaction_t transaction3 = {EXPENSE, TRANSPORTATION, 200, "Gas"};
  add_transaction(planner, transaction3);
  transaction_t transaction4 = {INCOME, OTHER, 50, "Allowance"};
  add_transaction(planner, transaction4);
  transaction_t transaction5 = {EXPENSE, ENTERTAINMENT, 100, "Movie tickets"};
  add_transaction(planner, transaction5);

  // Print the personal finance planner
  print_personal_finance_planner(planner);

  // Free the memory allocated for the personal finance planner
  free_personal_finance_planner(planner);

  return 0;
}