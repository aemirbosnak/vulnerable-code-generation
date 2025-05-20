//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct {
  char name[50];
  int account_number;
  double balance;
} account_t;

// Define the transaction structure
typedef struct {
  int account_number;
  double amount;
  char type[10];
} transaction_t;

// Define the bank structure
typedef struct {
  account_t accounts[MAX_ACCOUNTS];
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_accounts;
  int num_transactions;
} bank_t;

// Create a new bank
bank_t *create_bank() {
  bank_t *bank = malloc(sizeof(bank_t));
  bank->num_accounts = 0;
  bank->num_transactions = 0;
  return bank;
}

// Add a new account to the bank
void add_account(bank_t *bank, char *name, int account_number, double balance) {
  account_t account;
  strcpy(account.name, name);
  account.account_number = account_number;
  account.balance = balance;
  bank->accounts[bank->num_accounts] = account;
  bank->num_accounts++;
}

// Add a new transaction to the bank
void add_transaction(bank_t *bank, int account_number, double amount, char *type) {
  transaction_t transaction;
  transaction.account_number = account_number;
  transaction.amount = amount;
  strcpy(transaction.type, type);
  bank->transactions[bank->num_transactions] = transaction;
  bank->num_transactions++;
}

// Get the balance of an account
double get_balance(bank_t *bank, int account_number) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == account_number) {
      return bank->accounts[i].balance;
    }
  }
  return -1;
}

// Process a transaction
void process_transaction(bank_t *bank, transaction_t transaction) {
  int account_number = transaction.account_number;
  double amount = transaction.amount;
  char *type = transaction.type;

  if (strcmp(type, "deposit") == 0) {
    double balance = get_balance(bank, account_number);
    bank->accounts[account_number].balance = balance + amount;
  } else if (strcmp(type, "withdrawal") == 0) {
    double balance = get_balance(bank, account_number);
    if (balance >= amount) {
      bank->accounts[account_number].balance = balance - amount;
    } else {
      printf("Insufficient funds\n");
    }
  } else {
    printf("Invalid transaction type\n");
  }
}

// Print the bank statement
void print_statement(bank_t *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    account_t account = bank->accounts[i];
    printf("Account number: %d\n", account.account_number);
    printf("Name: %s\n", account.name);
    printf("Balance: %f\n", account.balance);
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new bank
  bank_t *bank = create_bank();

  // Add some accounts to the bank
  add_account(bank, "John Doe", 12345, 1000.00);
  add_account(bank, "Jane Doe", 67890, 500.00);

  // Add some transactions to the bank
  add_transaction(bank, 12345, 200.00, "deposit");
  add_transaction(bank, 67890, 100.00, "deposit");
  add_transaction(bank, 12345, 500.00, "withdrawal");

  // Process the transactions
  for (int i = 0; i < bank->num_transactions; i++) {
    process_transaction(bank, bank->transactions[i]);
  }

  // Print the bank statement
  print_statement(bank);

  return 0;
}