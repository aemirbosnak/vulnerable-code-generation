//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: protected
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
} account;

// Define the transaction structure
typedef struct transaction {
  int account_number;
  char *type;
  double amount;
} transaction;

// Create an array of accounts
account accounts[MAX_ACCOUNTS];

// Create an array of transactions
transaction transactions[MAX_TRANSACTIONS];

// Initialize the number of accounts and transactions to 0
int num_accounts = 0;
int num_transactions = 0;

// Function to create a new account
void create_account(int account_number, char *name, double balance) {
  // Check if the account number is already in use
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Error: Account number already in use.\n");
      return;
    }
  }

  // Create the new account
  accounts[num_accounts].account_number = account_number;
  accounts[num_accounts].name = strdup(name);
  accounts[num_accounts].balance = balance;

  // Increment the number of accounts
  num_accounts++;
}

// Function to deposit money into an account
void deposit(int account_number, double amount) {
  // Find the account by account number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      // Deposit the money
      accounts[i].balance += amount;

      // Create a transaction record
      transactions[num_transactions].account_number = account_number;
      transactions[num_transactions].type = "deposit";
      transactions[num_transactions].amount = amount;

      // Increment the number of transactions
      num_transactions++;

      return;
    }
  }

  // If the account number was not found, print an error message
  printf("Error: Account number not found.\n");
}

// Function to withdraw money from an account
void withdraw(int account_number, double amount) {
  // Find the account by account number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      // Check if the account has enough money
      if (accounts[i].balance < amount) {
        printf("Error: Insufficient funds.\n");
        return;
      }

      // Withdraw the money
      accounts[i].balance -= amount;

      // Create a transaction record
      transactions[num_transactions].account_number = account_number;
      transactions[num_transactions].type = "withdrawal";
      transactions[num_transactions].amount = amount;

      // Increment the number of transactions
      num_transactions++;

      return;
    }
  }

  // If the account number was not found, print an error message
  printf("Error: Account number not found.\n");
}

// Function to print the account statement
void print_statement(int account_number) {
  // Find the account by account number
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      // Print the account information
      printf("Account Number: %d\n", accounts[i].account_number);
      printf("Name: %s\n", accounts[i].name);
      printf("Balance: %.2f\n", accounts[i].balance);

      // Print the transaction history
      for (int j = 0; j < num_transactions; j++) {
        if (transactions[j].account_number == account_number) {
          printf("%s %.2f\n", transactions[j].type, transactions[j].amount);
        }
      }

      return;
    }
  }

  // If the account number was not found, print an error message
  printf("Error: Account number not found.\n");
}

// Main function
int main() {
  // Create some accounts
  create_account(12345, "John Doe", 1000.00);
  create_account(54321, "Jane Doe", 2000.00);

  // Deposit some money into the accounts
  deposit(12345, 500.00);
  deposit(54321, 1000.00);

  // Withdraw some money from the accounts
  withdraw(12345, 200.00);
  withdraw(54321, 500.00);

  // Print the account statements
  print_statement(12345);
  print_statement(54321);

  return 0;
}