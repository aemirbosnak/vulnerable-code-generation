//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct {
  int account_number;
  char account_holder_name[50];
  double balance;
} account_t;

// Define the transaction structure
typedef struct {
  int transaction_id;
  int account_number;
  char transaction_type; // 'D' for deposit, 'W' for withdrawal
  double amount;
} transaction_t;

// Define the bank record system structure
typedef struct {
  account_t accounts[MAX_ACCOUNTS];
  transaction_t transactions[MAX_TRANSACTIONS];
  int num_accounts;
  int num_transactions;
} bank_record_system_t;

// Create a new bank record system
bank_record_system_t* create_bank_record_system() {
  bank_record_system_t* brs = malloc(sizeof(bank_record_system_t));
  brs->num_accounts = 0;
  brs->num_transactions = 0;
  return brs;
}

// Add a new account to the bank record system
void add_account(bank_record_system_t* brs, int account_number, char* account_holder_name, double balance) {
  // Check if the account number is already in use
  for (int i = 0; i < brs->num_accounts; i++) {
    if (brs->accounts[i].account_number == account_number) {
      printf("Error: Account number %d is already in use.\n", account_number);
      return;
    }
  }

  // Add the new account to the array of accounts
  brs->accounts[brs->num_accounts].account_number = account_number;
  strcpy(brs->accounts[brs->num_accounts].account_holder_name, account_holder_name);
  brs->accounts[brs->num_accounts].balance = balance;
  brs->num_accounts++;
}

// Add a new transaction to the bank record system
void add_transaction(bank_record_system_t* brs, int transaction_id, int account_number, char transaction_type, double amount) {
  // Check if the account number is valid
  int account_index = -1;
  for (int i = 0; i < brs->num_accounts; i++) {
    if (brs->accounts[i].account_number == account_number) {
      account_index = i;
      break;
    }
  }

  if (account_index == -1) {
    printf("Error: Account number %d does not exist.\n", account_number);
    return;
  }

  // Add the new transaction to the array of transactions
  brs->transactions[brs->num_transactions].transaction_id = transaction_id;
  brs->transactions[brs->num_transactions].account_number = account_number;
  brs->transactions[brs->num_transactions].transaction_type = transaction_type;
  brs->transactions[brs->num_transactions].amount = amount;
  brs->num_transactions++;

  // Update the account balance
  if (transaction_type == 'D') {
    brs->accounts[account_index].balance += amount;
  } else if (transaction_type == 'W') {
    brs->accounts[account_index].balance -= amount;
  }
}

// Print the bank record system
void print_bank_record_system(bank_record_system_t* brs) {
  printf("Bank Record System:\n");
  printf("--------------------\n");
  printf("Accounts:\n");
  for (int i = 0; i < brs->num_accounts; i++) {
    printf("  - Account Number: %d\n", brs->accounts[i].account_number);
    printf("    - Account Holder Name: %s\n", brs->accounts[i].account_holder_name);
    printf("    - Balance: %.2f\n", brs->accounts[i].balance);
  }
  printf("Transactions:\n");
  for (int i = 0; i < brs->num_transactions; i++) {
    printf("  - Transaction ID: %d\n", brs->transactions[i].transaction_id);
    printf("    - Account Number: %d\n", brs->transactions[i].account_number);
    printf("    - Transaction Type: %c\n", brs->transactions[i].transaction_type);
    printf("    - Amount: %.2f\n", brs->transactions[i].amount);
  }
}

// Free the memory allocated for the bank record system
void free_bank_record_system(bank_record_system_t* brs) {
  free(brs);
}

// Main function
int main() {
  // Create a new bank record system
  bank_record_system_t* brs = create_bank_record_system();

  // Add some accounts to the bank record system
  add_account(brs, 123456, "John Doe", 1000.00);
  add_account(brs, 654321, "Jane Doe", 2000.00);

  // Add some transactions to the bank record system
  add_transaction(brs, 1, 123456, 'D', 500.00);
  add_transaction(brs, 2, 654321, 'W', 300.00);

  // Print the bank record system
  print_bank_record_system(brs);

  // Free the memory allocated for the bank record system
  free_bank_record_system(brs);

  return 0;
}