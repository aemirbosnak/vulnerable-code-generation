//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: expert-level
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
  int transaction_id;
  int account_number;
  char type[50];
  double amount;
} transaction_t;

// Define the bank structure
typedef struct bank {
  account_t accounts[MAX_ACCOUNTS];
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_accounts;
  int num_transactions;
} bank_t;

// Create a new bank
bank_t* create_bank() {
  bank_t* bank = (bank_t*)malloc(sizeof(bank_t));
  bank->num_accounts = 0;
  bank->num_transactions = 0;
  return bank;
}

// Add an account to the bank
void add_account(bank_t* bank, account_t account) {
  bank->accounts[bank->num_accounts++] = account;
}

// Add a transaction to the bank
void add_transaction(bank_t* bank, transaction_t transaction) {
  bank->transactions[bank->num_transactions++] = transaction;
}

// Process a transaction
void process_transaction(bank_t* bank, transaction_t transaction) {
  // Find the account associated with the transaction
  account_t* account = NULL;
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == transaction.account_number) {
      account = &bank->accounts[i];
      break;
    }
  }

  // If the account was not found, return an error
  if (account == NULL) {
    printf("Error: Account not found.\n");
    return;
  }

  // Process the transaction
  if (strcmp(transaction.type, "deposit") == 0) {
    account->balance += transaction.amount;
  } else if (strcmp(transaction.type, "withdrawal") == 0) {
    if (transaction.amount > account->balance) {
      printf("Error: Insufficient funds.\n");
      return;
    }
    account->balance -= transaction.amount;
  } else {
    printf("Error: Invalid transaction type.\n");
    return;
  }
}

// Print the bank statement
void print_statement(bank_t* bank) {
  printf("Bank Statement\n");
  printf("========================================================================\n");
  printf("Account Number\tName\tBalance\n");
  printf("------------------------------------------------------------------------\n");
  for (int i = 0; i < bank->num_accounts; i++) {
    printf("%d\t\t%s\t%.2f\n", bank->accounts[i].account_number, bank->accounts[i].name, bank->accounts[i].balance);
  }
  printf("========================================================================\n");
}

// Free the memory allocated for the bank
void free_bank(bank_t* bank) {
  free(bank);
}

// Main function
int main() {
  // Create a new bank
  bank_t* bank = create_bank();

  // Add some accounts to the bank
  account_t account1 = {12345, "John Doe", 1000.00};
  account_t account2 = {54321, "Jane Doe", 2000.00};
  add_account(bank, account1);
  add_account(bank, account2);

  // Add some transactions to the bank
  transaction_t transaction1 = {1, 12345, "deposit", 500.00};
  transaction_t transaction2 = {2, 54321, "withdrawal", 300.00};
  transaction_t transaction3 = {3, 12345, "withdrawal", 200.00};
  add_transaction(bank, transaction1);
  add_transaction(bank, transaction2);
  add_transaction(bank, transaction3);

  // Process the transactions
  for (int i = 0; i < bank->num_transactions; i++) {
    process_transaction(bank, bank->transactions[i]);
  }

  // Print the bank statement
  print_statement(bank);

  // Free the memory allocated for the bank
  free_bank(bank);

  return 0;
}