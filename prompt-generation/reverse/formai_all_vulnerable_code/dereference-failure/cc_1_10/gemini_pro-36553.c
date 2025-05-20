//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to represent a bank account
typedef struct bank_account {
  char *name;
  int account_number;
  double balance;
} bank_account;

// Create a function to create a new bank account
bank_account *create_account(char *name, int account_number, double balance) {
  // Allocate memory for the new account
  bank_account *account = malloc(sizeof(bank_account));

  // Set the account's properties
  account->name = strdup(name);
  account->account_number = account_number;
  account->balance = balance;

  // Return the new account
  return account;
}

// Create a function to deposit money into an account
void deposit_money(bank_account *account, double amount) {
  // Add the amount to the account's balance
  account->balance += amount;
}

// Create a function to withdraw money from an account
void withdraw_money(bank_account *account, double amount) {
  // Subtract the amount from the account's balance
  account->balance -= amount;
}

// Create a function to print the details of an account
void print_account_details(bank_account *account) {
  // Print the account's properties
  printf("Name: %s\n", account->name);
  printf("Account number: %d\n", account->account_number);
  printf("Balance: %.2f\n", account->balance);
}

// Create an array of bank accounts
bank_account *accounts[100];

// Create a function to initialize the array of bank accounts
void initialize_accounts() {
  // Create a few sample accounts
  accounts[0] = create_account("John Doe", 123456, 1000.00);
  accounts[1] = create_account("Jane Doe", 654321, 500.00);
  accounts[2] = create_account("Peter Parker", 789101, 2000.00);
}

// Create a function to find an account by account number
bank_account *find_account(int account_number) {
  // Loop through the array of accounts
  for (int i = 0; i < 100; i++) {
    // Check if the account number matches the given account number
    if (accounts[i]->account_number == account_number) {
      // Return the account
      return accounts[i];
    }
  }

  // If the account number was not found, return NULL
  return NULL;
}

// Create a function to process a transaction
void process_transaction(int account_number, char *transaction_type, double amount) {
  // Find the account by account number
  bank_account *account = find_account(account_number);

  // Check if the account was found
  if (account == NULL) {
    // Print an error message
    printf("Account not found.\n");

    // Return
    return;
  }

  // Process the transaction
  if (strcmp(transaction_type, "deposit") == 0) {
    // Deposit the money into the account
    deposit_money(account, amount);
  } else if (strcmp(transaction_type, "withdraw") == 0) {
    // Withdraw the money from the account
    withdraw_money(account, amount);
  } else {
    // Print an error message
    printf("Invalid transaction type.\n");

    // Return
    return;
  }

  // Print the account's new balance
  printf("New balance: %.2f\n", account->balance);
}

// Create a function to print the balances of all accounts
void print_balances() {
  // Loop through the array of accounts
  for (int i = 0; i < 100; i++) {
    // Print the account's balance
    printf("Account %d: %.2f\n", accounts[i]->account_number, accounts[i]->balance);
  }
}

// Create a function to main
int main() {
  // Initialize the array of bank accounts
  initialize_accounts();

  // Process a few sample transactions
  process_transaction(123456, "deposit", 100.00);
  process_transaction(654321, "withdraw", 50.00);
  process_transaction(789101, "deposit", 200.00);

  // Print the balances of all accounts
  print_balances();

  // Return 0
  return 0;
}