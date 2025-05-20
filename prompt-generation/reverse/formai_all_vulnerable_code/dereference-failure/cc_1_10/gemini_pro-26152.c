//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
  int account_number;
  char *name;
  double balance;
} account_t;

// Create an array of accounts
account_t accounts[MAX_ACCOUNTS];

// Initialize the number of accounts to 0
int num_accounts = 0;

// Function to create a new account
void create_account(int account_number, char *name, double balance) {
  // Check if the array of accounts is full
  if (num_accounts == MAX_ACCOUNTS) {
    printf("Error: The array of accounts is full.\n");
    return;
  }

  // Create a new account
  accounts[num_accounts].account_number = account_number;
  accounts[num_accounts].name = strdup(name);
  accounts[num_accounts].balance = balance;

  // Increment the number of accounts
  num_accounts++;
}

// Function to deposit money into an account
void deposit_money(int account_number, double amount) {
  // Find the account with the given account number
  int i;
  for (i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      break;
    }
  }

  // Check if the account was found
  if (i == num_accounts) {
    printf("Error: Account not found.\n");
    return;
  }

  // Deposit the money into the account
  accounts[i].balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(int account_number, double amount) {
  // Find the account with the given account number
  int i;
  for (i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      break;
    }
  }

  // Check if the account was found
  if (i == num_accounts) {
    printf("Error: Account not found.\n");
    return;
  }

  // Check if the account has enough money
  if (accounts[i].balance < amount) {
    printf("Error: Insufficient funds.\n");
    return;
  }

  // Withdraw the money from the account
  accounts[i].balance -= amount;
}

// Function to print the details of an account
void print_account_details(int account_number) {
  // Find the account with the given account number
  int i;
  for (i = 0; i < num_accounts; i++) {
    if (accounts[i].account_number == account_number) {
      break;
    }
  }

  // Check if the account was found
  if (i == num_accounts) {
    printf("Error: Account not found.\n");
    return;
  }

  // Print the account details
  printf("Account Number: %d\n", accounts[i].account_number);
  printf("Name: %s\n", accounts[i].name);
  printf("Balance: %f\n", accounts[i].balance);
}

// Main function
int main() {
  // Create some accounts
  create_account(1, "John Doe", 1000.00);
  create_account(2, "Jane Doe", 2000.00);
  create_account(3, "Peter Jones", 3000.00);

  // Deposit money into an account
  deposit_money(1, 500.00);

  // Withdraw money from an account
  withdraw_money(2, 1000.00);

  // Print the details of an account
  print_account_details(3);

  return 0;
}