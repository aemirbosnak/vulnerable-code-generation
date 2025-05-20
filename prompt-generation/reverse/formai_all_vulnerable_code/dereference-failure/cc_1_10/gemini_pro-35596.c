//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction types
#define INCOME 1
#define EXPENSE -1

// Define the transaction categories
#define CATEGORY_UNSPECIFIED 0
#define CATEGORY_HOUSING 1
#define CATEGORY_FOOD 2
#define CATEGORY_TRANSPORTATION 3
#define CATEGORY_EDUCATION 4
#define CATEGORY_ENTERTAINMENT 5
#define CATEGORY_OTHER 6

// Define the transaction struct
typedef struct {
  int type;
  int category;
  float amount;
  char *description;
} transaction_t;

// Define the personal finance planner struct
typedef struct {
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_transactions;
  float balance;
} personal_finance_planner_t;

// Create a new personal finance planner
personal_finance_planner_t *create_personal_finance_planner() {
  personal_finance_planner_t *planner = malloc(sizeof(personal_finance_planner_t));
  planner->num_transactions = 0;
  planner->balance = 0.0;
  return planner;
}

// Destroy a personal finance planner
void destroy_personal_finance_planner(personal_finance_planner_t *planner) {
  for (int i = 0; i < planner->num_transactions; i++) {
    free(planner->transactions[i].description);
  }
  free(planner);
}

// Add a transaction to a personal finance planner
void add_transaction(personal_finance_planner_t *planner, transaction_t transaction) {
  if (planner->num_transactions >= MAX_TRANSACTIONS) {
    printf("Error: Maximum number of transactions reached.\n");
    return;
  }
  planner->transactions[planner->num_transactions++] = transaction;
  planner->balance += (transaction.type * transaction.amount);
}

// Print the transactions in a personal finance planner
void print_transactions(personal_finance_planner_t *planner) {
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("%s %s %f\n",
           (planner->transactions[i].type == INCOME) ? "Income" : "Expense",
           (planner->transactions[i].category == CATEGORY_UNSPECIFIED) ? "Unspecified" :
           (planner->transactions[i].category == CATEGORY_HOUSING) ? "Housing" :
           (planner->transactions[i].category == CATEGORY_FOOD) ? "Food" :
           (planner->transactions[i].category == CATEGORY_TRANSPORTATION) ? "Transportation" :
           (planner->transactions[i].category == CATEGORY_EDUCATION) ? "Education" :
           (planner->transactions[i].category == CATEGORY_ENTERTAINMENT) ? "Entertainment" : "Other",
           planner->transactions[i].amount);
  }
}

// Get the balance of a personal finance planner
float get_balance(personal_finance_planner_t *planner) {
  return planner->balance;
}

// Main function
int main() {
  // Create a new personal finance planner
  personal_finance_planner_t *planner = create_personal_finance_planner();

  // Add some transactions to the planner
  transaction_t transaction1 = {INCOME, CATEGORY_UNSPECIFIED, 1000.0, "Salary"};
  transaction_t transaction2 = {EXPENSE, CATEGORY_HOUSING, 500.0, "Rent"};
  transaction_t transaction3 = {EXPENSE, CATEGORY_FOOD, 200.0, "Groceries"};
  transaction_t transaction4 = {EXPENSE, CATEGORY_TRANSPORTATION, 100.0, "Gas"};
  add_transaction(planner, transaction1);
  add_transaction(planner, transaction2);
  add_transaction(planner, transaction3);
  add_transaction(planner, transaction4);

  // Print the transactions
  print_transactions(planner);

  // Get the balance
  float balance = get_balance(planner);
  printf("Balance: %f\n", balance);

  // Destroy the planner
  destroy_personal_finance_planner(planner);

  return 0;
}