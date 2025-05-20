//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account structure
typedef struct Account {
  int account_number;
  char *name;
  double balance;
} Account;

// Create a new account
Account *create_account(int account_number, char *name, double balance) {
  Account *account = malloc(sizeof(Account));
  account->account_number = account_number;
  account->name = strdup(name);
  account->balance = balance;
  return account;
}

// Deposit money into an account
void deposit(Account *account, double amount) {
  account->balance += amount;
}

// Withdraw money from an account
void withdraw(Account *account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Transfer money from one account to another
void transfer(Account *from_account, Account *to_account, double amount) {
  if (amount <= from_account->balance) {
    from_account->balance -= amount;
    to_account->balance += amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Print the details of an account
void print_account(Account *account) {
  printf("Account Number: %d\n", account->account_number);
  printf("Name: %s\n", account->name);
  printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
  // Create three accounts
  Account *account1 = create_account(123456, "John Doe", 1000.00);
  Account *account2 = create_account(654321, "Jane Doe", 2000.00);
  Account *account3 = create_account(345678, "Bob Smith", 3000.00);

  // Deposit money into account1
  deposit(account1, 500.00);

  // Withdraw money from account2
  withdraw(account2, 300.00);

  // Transfer money from account3 to account1
  transfer(account3, account1, 200.00);

  // Print the details of each account
  print_account(account1);
  print_account(account2);
  print_account(account3);

  // Free the memory allocated for each account
  free(account1);
  free(account2);
  free(account3);

  return 0;
}