//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the account struct
typedef struct account {
  int account_number;
  char *name;
  double balance;
} account;

// Create a new account
account *create_account(int account_number, char *name, double balance) {
  account *new_account = malloc(sizeof(account));
  new_account->account_number = account_number;
  new_account->name = malloc(strlen(name) + 1);
  strcpy(new_account->name, name);
  new_account->balance = balance;
  return new_account;
}

// Deposit money into an account
void deposit(account *account, double amount) {
  account->balance += amount;
  printf("$%.2f deposited into account %d.\n", amount, account->account_number);
}

// Withdraw money from an account
void withdraw(account *account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
    printf("$%.2f withdrawn from account %d.\n", amount, account->account_number);
  } else {
    printf("Insufficient funds in account %d.\n", account->account_number);
  }
}

// Transfer money from one account to another
void transfer(account *from_account, account *to_account, double amount) {
  if (amount <= from_account->balance) {
    from_account->balance -= amount;
    to_account->balance += amount;
    printf("$%.2f transferred from account %d to account %d.\n", amount, from_account->account_number, to_account->account_number);
  } else {
    printf("Insufficient funds in account %d.\n", from_account->account_number);
  }
}

// Print the account statement
void print_statement(account *account) {
  printf("Account Statement\n");
  printf("Account Number: %d\n", account->account_number);
  printf("Name: %s\n", account->name);
  printf("Balance: $%.2f\n", account->balance);
}

// Main function
int main() {
  // Create some accounts
  account *account1 = create_account(123456, "John Doe", 1000.00);
  account *account2 = create_account(654321, "Jane Smith", 2000.00);

  // Deposit money into account1
  deposit(account1, 500.00);

  // Withdraw money from account2
  withdraw(account2, 300.00);

  // Transfer money from account1 to account2
  transfer(account1, account2, 200.00);

  // Print the account statements
  print_statement(account1);
  print_statement(account2);

  return 0;
}