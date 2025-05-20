//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct account {
  int account_number;
  char *account_holder_name;
  double balance;
} account_t;

// Define the transaction structure
typedef struct transaction {
  int transaction_id;
  int account_number;
  char *transaction_type;
  double amount;
} transaction_t;

// Define the banking record system structure
typedef struct banking_record_system {
  account_t accounts[MAX_ACCOUNTS];
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_accounts;
  int num_transactions;
} banking_record_system_t;

// Create a new banking record system
banking_record_system_t *create_banking_record_system() {
  banking_record_system_t *brs = malloc(sizeof(banking_record_system_t));
  brs->num_accounts = 0;
  brs->num_transactions = 0;
  return brs;
}

// Add a new account to the banking record system
void add_account(banking_record_system_t *brs, int account_number, char *account_holder_name, double balance) {
  brs->accounts[brs->num_accounts].account_number = account_number;
  brs->accounts[brs->num_accounts].account_holder_name = strdup(account_holder_name);
  brs->accounts[brs->num_accounts].balance = balance;
  brs->num_accounts++;
}

// Add a new transaction to the banking record system
void add_transaction(banking_record_system_t *brs, int transaction_id, int account_number, char *transaction_type, double amount) {
  brs->transactions[brs->num_transactions].transaction_id = transaction_id;
  brs->transactions[brs->num_transactions].account_number = account_number;
  brs->transactions[brs->num_transactions].transaction_type = strdup(transaction_type);
  brs->transactions[brs->num_transactions].amount = amount;
  brs->num_transactions++;
}

// Print the banking record system
void print_banking_record_system(banking_record_system_t *brs) {
  printf("Accounts:\n");
  for (int i = 0; i < brs->num_accounts; i++) {
    printf("  Account Number: %d\n", brs->accounts[i].account_number);
    printf("  Account Holder Name: %s\n", brs->accounts[i].account_holder_name);
    printf("  Balance: %.2f\n", brs->accounts[i].balance);
  }

  printf("\nTransactions:\n");
  for (int i = 0; i < brs->num_transactions; i++) {
    printf("  Transaction ID: %d\n", brs->transactions[i].transaction_id);
    printf("  Account Number: %d\n", brs->transactions[i].account_number);
    printf("  Transaction Type: %s\n", brs->transactions[i].transaction_type);
    printf("  Amount: %.2f\n", brs->transactions[i].amount);
  }
}

// Destroy the banking record system
void destroy_banking_record_system(banking_record_system_t *brs) {
  for (int i = 0; i < brs->num_accounts; i++) {
    free(brs->accounts[i].account_holder_name);
  }

  for (int i = 0; i < brs->num_transactions; i++) {
    free(brs->transactions[i].transaction_type);
  }

  free(brs);
}

// Main function
int main() {
  // Create a new banking record system
  banking_record_system_t *brs = create_banking_record_system();

  // Add some accounts to the banking record system
  add_account(brs, 123456, "John Smith", 1000.00);
  add_account(brs, 654321, "Jane Doe", 2000.00);

  // Add some transactions to the banking record system
  add_transaction(brs, 1, 123456, "deposit", 500.00);
  add_transaction(brs, 2, 654321, "withdrawal", 300.00);

  // Print the banking record system
  print_banking_record_system(brs);

  // Destroy the banking record system
  destroy_banking_record_system(brs);

  return 0;
}