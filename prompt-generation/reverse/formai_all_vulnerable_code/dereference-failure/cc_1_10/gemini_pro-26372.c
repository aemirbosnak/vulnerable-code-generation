//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the account structure
typedef struct {
  char *name;
  double balance;
} account;

// Create an account
account *create_account(char *name, double balance) {
  account *new_account = malloc(sizeof(account));
  new_account->name = name;
  new_account->balance = balance;
  return new_account;
}

// Deposit money into an account
void deposit(account *account, double amount) {
  account->balance += amount;
}

// Withdraw money from an account
void withdraw(account *account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Transfer money from one account to another
void transfer(account *from_account, account *to_account, double amount) {
  if (amount <= from_account->balance) {
    from_account->balance -= amount;
    to_account->balance += amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Print the account information
void print_account(account *account) {
  printf("%s: $%.2f\n", account->name, account->balance);
}

// Main function
int main() {
  // Create accounts
  account *checking_account = create_account("Checking", 1000);
  account *savings_account = create_account("Savings", 2000);

  // Deposit money into checking account
  deposit(checking_account, 500);
  
  // Withdraw money from savings account
  withdraw(savings_account, 300);

  // Transfer money from checking account to savings account
  transfer(checking_account, savings_account, 200);

  // Print account information
  print_account(checking_account);
  print_account(savings_account);

  return 0;
}