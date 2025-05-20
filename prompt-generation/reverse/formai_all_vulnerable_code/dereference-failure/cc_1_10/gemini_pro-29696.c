//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account structure
typedef struct account {
  char name[256];
  int account_number;
  double balance;
} account_t;

// Create a new account
account_t* create_account(char* name, int account_number, double balance) {
  account_t* account = malloc(sizeof(account_t));
  strcpy(account->name, name);
  account->account_number = account_number;
  account->balance = balance;
  return account;
}

// Print account information
void print_account(account_t* account) {
  printf("Name: %s\n", account->name);
  printf("Account Number: %d\n", account->account_number);
  printf("Balance: %.2f\n", account->balance);
  printf("\n");
}

// Deposit money into an account
void deposit(account_t* account, double amount) {
  account->balance += amount;
}

// Withdraw money from an account
void withdraw(account_t* account, double amount) {
  if (amount > account->balance) {
    printf("Insufficient funds\n");
  } else {
    account->balance -= amount;
  }
}

// Transfer money between accounts
void transfer(account_t* from_account, account_t* to_account, double amount) {
  if (amount > from_account->balance) {
    printf("Insufficient funds\n");
  } else {
    from_account->balance -= amount;
    to_account->balance += amount;
  }
}

// Main function
int main() {
  // Create a few accounts
  account_t* account1 = create_account("John Doe", 123456789, 1000.00);
  account_t* account2 = create_account("Jane Doe", 987654321, 500.00);

  // Print account information
  print_account(account1);
  print_account(account2);

  // Deposit money into account1
  deposit(account1, 200.00);

  // Withdraw money from account2
  withdraw(account2, 150.00);

  // Transfer money from account1 to account2
  transfer(account1, account2, 100.00);

  // Print account information again
  print_account(account1);
  print_account(account2);

  // Free the memory allocated for the accounts
  free(account1);
  free(account2);

  return 0;
}