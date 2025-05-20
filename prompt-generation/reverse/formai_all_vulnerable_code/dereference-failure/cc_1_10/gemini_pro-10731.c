//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account struct
typedef struct account {
  int account_number;
  char *name;
  double balance;
} account;

// Define the transaction struct
typedef struct transaction {
  int transaction_id;
  int account_number;
  char *type;
  double amount;
} transaction;

// Define the bank struct
typedef struct bank {
  account accounts[MAX_ACCOUNTS];
  transaction transactions[MAX_TRANSACTIONS];
  int num_accounts;
  int num_transactions;
} bank;

// Create a new bank
bank *create_bank() {
  bank *b = malloc(sizeof(bank));
  b->num_accounts = 0;
  b->num_transactions = 0;
  return b;
}

// Add an account to the bank
void add_account(bank *b, account *a) {
  b->accounts[b->num_accounts++] = *a;
}

// Add a transaction to the bank
void add_transaction(bank *b, transaction *t) {
  b->transactions[b->num_transactions++] = *t;
}

// Get an account by account number
account *get_account(bank *b, int account_number) {
  for (int i = 0; i < b->num_accounts; i++) {
    if (b->accounts[i].account_number == account_number) {
      return &b->accounts[i];
    }
  }
  return NULL;
}

// Get a transaction by transaction ID
transaction *get_transaction(bank *b, int transaction_id) {
  for (int i = 0; i < b->num_transactions; i++) {
    if (b->transactions[i].transaction_id == transaction_id) {
      return &b->transactions[i];
    }
  }
  return NULL;
}

// Print the bank's accounts
void print_accounts(bank *b) {
  for (int i = 0; i < b->num_accounts; i++) {
    printf("Account %d: %s, %.2f\n", b->accounts[i].account_number, b->accounts[i].name, b->accounts[i].balance);
  }
}

// Print the bank's transactions
void print_transactions(bank *b) {
  for (int i = 0; i < b->num_transactions; i++) {
    printf("Transaction %d: %d, %s, %.2f\n", b->transactions[i].transaction_id, b->transactions[i].account_number, b->transactions[i].type, b->transactions[i].amount);
  }
}

// Free the bank's memory
void free_bank(bank *b) {
  for (int i = 0; i < b->num_accounts; i++) {
    free(b->accounts[i].name);
  }
  free(b);
}

// Main function
int main() {
  // Create a new bank
  bank *b = create_bank();

  // Add some accounts to the bank
  account a1 = {1, "John Doe", 1000.0};
  account a2 = {2, "Jane Doe", 2000.0};
  add_account(b, &a1);
  add_account(b, &a2);

  // Add some transactions to the bank
  transaction t1 = {1, 1, "deposit", 500.0};
  transaction t2 = {2, 2, "withdrawal", 100.0};
  add_transaction(b, &t1);
  add_transaction(b, &t2);

  // Print the bank's accounts
  printf("Accounts:\n");
  print_accounts(b);

  // Print the bank's transactions
  printf("\nTransactions:\n");
  print_transactions(b);

  // Free the bank's memory
  free_bank(b);

  return 0;
}