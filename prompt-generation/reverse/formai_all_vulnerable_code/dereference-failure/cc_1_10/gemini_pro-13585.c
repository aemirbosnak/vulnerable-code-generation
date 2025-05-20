//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a single transaction
typedef struct transaction {
  char *description;
  int amount;
  int date;
} transaction_t;

// Structure to hold the user's account balance and list of transactions
typedef struct account {
  int balance;
  int num_transactions;
  transaction_t *transactions;
} account_t;

// Function to create a new account
account_t *create_account() {
  account_t *account = malloc(sizeof(account_t));
  account->balance = 0;
  account->num_transactions = 0;
  account->transactions = NULL;
  return account;
}

// Function to add a new transaction to an account
void add_transaction(account_t *account, char *description, int amount, int date) {
  account->num_transactions++;
  account->transactions = realloc(account->transactions, account->num_transactions * sizeof(transaction_t));
  transaction_t *transaction = &account->transactions[account->num_transactions - 1];
  transaction->description = strdup(description);
  transaction->amount = amount;
  transaction->date = date;
}

// Function to print the account balance and list of transactions
void print_account(account_t *account) {
  printf("Account Balance: %d\n", account->balance);
  for (int i = 0; i < account->num_transactions; i++) {
    transaction_t *transaction = &account->transactions[i];
    printf("  %s %d %d\n", transaction->description, transaction->amount, transaction->date);
  }
}

// Function to free the memory allocated for an account
void free_account(account_t *account) {
  for (int i = 0; i < account->num_transactions; i++) {
    free(account->transactions[i].description);
  }
  free(account->transactions);
  free(account);
}

int main() {
  // Create a new account
  account_t *account = create_account();

  // Add some transactions to the account
  add_transaction(account, "Groceries", -50, 20230101);
  add_transaction(account, "Salary", 1000, 20230115);
  add_transaction(account, "Rent", -600, 20230131);

  // Print the account balance and list of transactions
  print_account(account);

  // Free the memory allocated for the account
  free_account(account);

  return 0;
}