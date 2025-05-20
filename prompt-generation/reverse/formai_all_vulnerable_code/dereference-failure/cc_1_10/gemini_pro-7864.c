//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct account {
  int account_number;
  char *name;
  double balance;
} account_t;

// Define the transaction structure
typedef struct transaction {
  int account_number;
  char *type;
  double amount;
} transaction_t;

// Create an array of accounts
account_t accounts[MAX_ACCOUNTS];

// Create an array of transactions
transaction_t transactions[MAX_TRANSACTIONS];

// Initialize the number of accounts and transactions
int num_accounts = 0;
int num_transactions = 0;

// Create a new account
account_t *create_account(int account_number, char *name, double balance) {
  // Check if the number of accounts has reached the maximum
  if (num_accounts >= MAX_ACCOUNTS) {
    return NULL;
  }

  // Create a new account
  account_t *account = &accounts[num_accounts++];

  // Set the account number, name, and balance
  account->account_number = account_number;
  account->name = strdup(name);
  account->balance = balance;

  // Return the new account
  return account;
}

// Create a new transaction
transaction_t *create_transaction(int account_number, char *type, double amount) {
  // Check if the number of transactions has reached the maximum
  if (num_transactions >= MAX_TRANSACTIONS) {
    return NULL;
  }

  // Create a new transaction
  transaction_t *transaction = &transactions[num_transactions++];

  // Set the account number, type, and amount
  transaction->account_number = account_number;
  transaction->type = strdup(type);
  transaction->amount = amount;

  // Return the new transaction
  return transaction;
}

// Print the account information
void print_account(account_t *account) {
  printf("Account number: %d\n", account->account_number);
  printf("Name: %s\n", account->name);
  printf("Balance: %f\n", account->balance);
}

// Print the transaction information
void print_transaction(transaction_t *transaction) {
  printf("Account number: %d\n", transaction->account_number);
  printf("Type: %s\n", transaction->type);
  printf("Amount: %f\n", transaction->amount);
}

// Main function
int main() {
  // Create a new account
  account_t *account = create_account(123456, "John Doe", 1000.00);

  // Print the account information
  print_account(account);

  // Create a new deposit transaction
  transaction_t *deposit = create_transaction(123456, "deposit", 500.00);

  // Print the transaction information
  print_transaction(deposit);

  // Update the account balance
  account->balance += deposit->amount;

  // Print the updated account information
  print_account(account);

  // Create a new withdrawal transaction
  transaction_t *withdrawal = create_transaction(123456, "withdrawal", 300.00);

  // Print the transaction information
  print_transaction(withdrawal);

  // Update the account balance
  account->balance -= withdrawal->amount;

  // Print the updated account information
  print_account(account);

  return 0;
}