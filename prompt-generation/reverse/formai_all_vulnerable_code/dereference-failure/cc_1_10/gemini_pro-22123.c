//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the transaction types
#define INCOME 1
#define EXPENSE 2

// Define the data structure for a transaction
typedef struct transaction {
  int type;
  double amount;
  char *description;
} transaction_t;

// Define the data structure for a budget
typedef struct budget {
  double income;
  double expenses;
  double balance;
  transaction_t *transactions;
  int num_transactions;
} budget_t;

// Create a new budget
budget_t *create_budget() {
  budget_t *budget = malloc(sizeof(budget_t));
  budget->income = 0;
  budget->expenses = 0;
  budget->balance = 0;
  budget->transactions = NULL;
  budget->num_transactions = 0;
  return budget;
}

// Free the memory allocated for a budget
void free_budget(budget_t *budget) {
  for (int i = 0; i < budget->num_transactions; i++) {
    free(budget->transactions[i].description);
  }
  free(budget->transactions);
  free(budget);
}

// Add a transaction to a budget
void add_transaction(budget_t *budget, transaction_t transaction) {
  // Reallocate the memory for the transactions array if necessary
  if (budget->num_transactions == 0) {
    budget->transactions = malloc(sizeof(transaction_t));
  } else {
    budget->transactions = realloc(budget->transactions, (budget->num_transactions + 1) * sizeof(transaction_t));
  }

  // Add the transaction to the array
  budget->transactions[budget->num_transactions] = transaction;
  budget->num_transactions++;

  // Update the budget balance
  if (transaction.type == INCOME) {
    budget->income += transaction.amount;
  } else if (transaction.type == EXPENSE) {
    budget->expenses += transaction.amount;
  }
  budget->balance = budget->income - budget->expenses;
}

// Print the budget
void print_budget(budget_t *budget) {
  printf("Income: $%.2f\n", budget->income);
  printf("Expenses: $%.2f\n", budget->expenses);
  printf("Balance: $%.2f\n", budget->balance);

  for (int i = 0; i < budget->num_transactions; i++) {
    printf("%s - $%.2f\n", budget->transactions[i].description, budget->transactions[i].amount);
  }
}

// Get a transaction from the user
transaction_t get_transaction() {
  transaction_t transaction;

  // Get the transaction type
  printf("Enter the transaction type (income or expense): ");
  char *type = malloc(100);
  scanf("%s", type);
  if (strcmp(type, "income") == 0) {
    transaction.type = INCOME;
  } else if (strcmp(type, "expense") == 0) {
    transaction.type = EXPENSE;
  } else {
    printf("Invalid transaction type\n");
    return transaction;
  }

  // Get the transaction amount
  printf("Enter the transaction amount: ");
  double amount;
  scanf("%lf", &amount);
  transaction.amount = amount;

  // Get the transaction description
  printf("Enter the transaction description: ");
  char *description = malloc(100);
  scanf("%s", description);
  transaction.description = description;

  return transaction;
}

// Main function
int main() {
  // Create a new budget
  budget_t *budget = create_budget();

  // Get transactions from the user
  while (1) {
    transaction_t transaction = get_transaction();
    if (transaction.type == 0) {
      break;
    }
    add_transaction(budget, transaction);
  }

  // Print the budget
  print_budget(budget);

  // Free the memory allocated for the budget
  free_budget(budget);

  return 0;
}