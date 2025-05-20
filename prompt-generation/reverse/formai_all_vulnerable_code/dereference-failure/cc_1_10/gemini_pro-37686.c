//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: single-threaded
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
} account_t;

// Define the transaction structure
typedef struct {
  int account_number;
  double amount;
  char *description;
} transaction_t;

// Create the array of accounts
account_t accounts[MAX_ACCOUNTS];

// Create the array of transactions
transaction_t transactions[MAX_TRANSACTIONS];

// Initialize the number of accounts and transactions
int num_accounts = 0;
int num_transactions = 0;

// Function to create a new account
void create_account(int account_number, char *name, double balance) {
  // Check if the maximum number of accounts has been reached
  if (num_accounts >= MAX_ACCOUNTS) {
    printf("Error: Maximum number of accounts reached.\n");
    return;
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
  // Check if the account number is valid
  int i;
  for (i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      break;
    }
  }

  // If the account number is invalid, print an error message
  if (i == num_accounts) {
    printf("Error: Invalid account number.\n");
    return;
  }

  // Deposit the money into the account
  accounts[i].balance += amount;
}

// Function to withdraw money from an account
void withdraw(int account_number, double amount) {
  // Check if the account number is valid
  int i;
  for (i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      break;
    }
  }

  // If the account number is invalid, print an error message
  if (i == num_accounts) {
    printf("Error: Invalid account number.\n");
    return;
  }

  // Withdraw the money from the account
  accounts[i].balance -= amount;
}

// Function to transfer money from one account to another
void transfer(int from_account_number, int to_account_number, double amount) {
  // Check if the from account number is valid
  int i;
  for (i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == from_account_number) {
      break;
    }
  }

  // If the from account number is invalid, print an error message
  if (i == num_accounts) {
    printf("Error: Invalid from account number.\n");
    return;
  }

  // Check if the to account number is valid
  int j;
  for (j = 0; j < num_accounts; j++) {
    if (accounts[j].account_number == to_account_number) {
      break;
    }
  }

  // If the to account number is invalid, print an error message
  if (j == num_accounts) {
    printf("Error: Invalid to account number.\n");
    return;
  }

  // Transfer the money from the from account to the to account
  accounts[i].balance -= amount;
  accounts[j].balance += amount;
}

// Function to print the account balances
void print_balances() {
  int i;
  for (i = 0; i < num_accounts; i++) {
    printf("Account %d: %s, Balance: %.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
  }
}

// Function to process transactions
void process_transactions() {
  int i;
  for (i = 0; i < num_transactions; i++) {
    switch (transactions[i].account_number) {
      case 1:
        deposit(1, transactions[i].amount);
        break;
      case 2:
        withdraw(2, transactions[i].amount);
        break;
      case 3:
        transfer(3, 4, transactions[i].amount);
        break;
      default:
        printf("Error: Invalid transaction type.\n");
        break;
    }
  }
}

// Main function
int main() {
  // Create some accounts
  create_account(1, "John Doe", 1000.00);
  create_account(2, "Jane Doe", 2000.00);
  create_account(3, "Bob Smith", 3000.00);
  create_account(4, "Alice Smith", 4000.00);

  // Create some transactions
  transactions[0].account_number = 1;
  transactions[0].amount = 100.00;
  transactions[0].description = "Deposit";
  transactions[1].account_number = 2;
  transactions[1].amount = 200.00;
  transactions[1].description = "Withdrawal";
  transactions[2].account_number = 3;
  transactions[2].amount = 300.00;
  transactions[2].description = "Transfer";
  transactions[3].account_number = 4;
  transactions[3].amount = 400.00;
  transactions[3].description = "Transfer";

  // Process the transactions
  process_transactions();

  // Print the account balances
  print_balances();

  return 0;
}