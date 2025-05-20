//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct account {
  int account_number;
  char name[50];
  double balance;
} account_t;

// Define the transaction structure
typedef struct transaction {
  int account_number;
  char type[20];
  double amount;
} transaction_t;

// Define the bank record system structure
typedef struct bank_record_system {
  account_t accounts[MAX_ACCOUNTS];
  int num_accounts;
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_transactions;
} bank_record_system_t;

// Create a new bank record system
bank_record_system_t *create_bank_record_system() {
  bank_record_system_t *brs = malloc(sizeof(bank_record_system_t));
  brs->num_accounts = 0;
  brs->num_transactions = 0;
  return brs;
}

// Destroy a bank record system
void destroy_bank_record_system(bank_record_system_t *brs) {
  free(brs);
}

// Add an account to the bank record system
void add_account(bank_record_system_t *brs, int account_number, char *name, double balance) {
  brs->accounts[brs->num_accounts].account_number = account_number;
  strcpy(brs->accounts[brs->num_accounts].name, name);
  brs->accounts[brs->num_accounts].balance = balance;
  brs->num_accounts++;
}

// Add a transaction to the bank record system
void add_transaction(bank_record_system_t *brs, int account_number, char *type, double amount) {
  brs->transactions[brs->num_transactions].account_number = account_number;
  strcpy(brs->transactions[brs->num_transactions].type, type);
  brs->transactions[brs->num_transactions].amount = amount;
  brs->num_transactions++;
}

// Print the bank record system
void print_bank_record_system(bank_record_system_t *brs) {
  printf("Accounts:\n");
  for (int i = 0; i < brs->num_accounts; i++) {
    printf("  %d %s %.2f\n", brs->accounts[i].account_number, brs->accounts[i].name, brs->accounts[i].balance);
  }

  printf("Transactions:\n");
  for (int i = 0; i < brs->num_transactions; i++) {
    printf("  %d %s %.2f\n", brs->transactions[i].account_number, brs->transactions[i].type, brs->transactions[i].amount);
  }
}

// Main function
int main() {
  // Create a new bank record system
  bank_record_system_t *brs = create_bank_record_system();

  // Add some accounts to the bank record system
  add_account(brs, 12345, "John Doe", 1000.00);
  add_account(brs, 67890, "Jane Doe", 2000.00);

  // Add some transactions to the bank record system
  add_transaction(brs, 12345, "deposit", 500.00);
  add_transaction(brs, 67890, "withdrawal", 300.00);

  // Print the bank record system
  print_bank_record_system(brs);

  // Destroy the bank record system
  destroy_bank_record_system(brs);

  return 0;
}