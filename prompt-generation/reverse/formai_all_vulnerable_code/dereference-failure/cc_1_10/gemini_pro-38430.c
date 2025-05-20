//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct {
  int account_number;
  char *name;
  double balance;
} account;

// Define the transaction structure
typedef struct {
  int transaction_id;
  int account_number;
  char *type;
  double amount;
} transaction;

// Create an array of accounts
account accounts[MAX_ACCOUNTS];

// Create an array of transactions
transaction transactions[MAX_TRANSACTIONS];

// Initialize the number of accounts and transactions
int num_accounts = 0;
int num_transactions = 0;

// Function to create a new account
void create_account(int account_number, char *name, double balance) {
  // Check if the account number is already in use
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Error: Account number %d is already in use.\n", account_number);
      return;
    }
  }

  // Create the new account
  accounts[num_accounts].account_number = account_number;
  accounts[num_accounts].name = strdup(name);
  accounts[num_accounts].balance = balance;

  // Increment the number of accounts
  num_accounts++;

  printf("Account created successfully.\n");
}

// Function to deposit money into an account
void deposit_money(int account_number, double amount) {
  // Find the account by account number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      // Deposit the money
      accounts[i].balance += amount;

      // Create a transaction record
      transaction transaction;
      transaction.transaction_id = num_transactions++;
      transaction.account_number = account_number;
      transaction.type = "deposit";
      transaction.amount = amount;

      // Add the transaction to the array of transactions
      transactions[num_transactions - 1] = transaction;

      printf("Deposit successful.\n");
      return;
    }
  }

  // If the account was not found, print an error message
  printf("Error: Account number %d not found.\n", account_number);
}

// Function to withdraw money from an account
void withdraw_money(int account_number, double amount) {
  // Find the account by account number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      // Check if the account has enough balance
      if (accounts[i].balance >= amount) {
        // Withdraw the money
        accounts[i].balance -= amount;

        // Create a transaction record
        transaction transaction;
        transaction.transaction_id = num_transactions++;
        transaction.account_number = account_number;
        transaction.type = "withdrawal";
        transaction.amount = amount;

        // Add the transaction to the array of transactions
        transactions[num_transactions - 1] = transaction;

        printf("Withdrawal successful.\n");
        return;
      } else {
        printf("Error: Insufficient funds.\n");
        return;
      }
    }
  }

  // If the account was not found, print an error message
  printf("Error: Account number %d not found.\n", account_number);
}

// Function to print the balance of an account
void print_balance(int account_number) {
  // Find the account by account number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      // Print the balance
      printf("Balance: %f\n", accounts[i].balance);
      return;
    }
  }

  // If the account was not found, print an error message
  printf("Error: Account number %d not found.\n", account_number);
}

// Function to print the statement of an account
void print_statement(int account_number) {
  // Find the account by account number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      // Print the account number and name
      printf("Account number: %d\n", accounts[i].account_number);
      printf("Name: %s\n", accounts[i].name);

      // Print the transactions
      printf("Transactions:\n");
      for (int j = 0; j < num_transactions; j++) {
        if (transactions[j].account_number == account_number) {
          printf("%d %s %f\n", transactions[j].transaction_id, transactions[j].type, transactions[j].amount);
        }
      }

      return;
    }
  }

  // If the account was not found, print an error message
  printf("Error: Account number %d not found.\n", account_number);
}

// Main function
int main() {
  // Create some sample accounts
  create_account(123456, "John Doe", 1000.00);
  create_account(654321, "Jane Doe", 2000.00);
  create_account(789012, "Bob Smith", 3000.00);

  // Deposit some money into the first account
  deposit_money(123456, 500.00);

  // Withdraw some money from the second account
  withdraw_money(654321, 300.00);

  // Print the balance of the third account
  print_balance(789012);

  // Print the statement of the first account
  print_statement(123456);

  return 0;
}