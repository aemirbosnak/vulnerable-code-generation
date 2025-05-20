//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
  char name[50];
  int account_number;
  double balance;
} account;

// Define the bank structure
typedef struct bank {
  account accounts[MAX_ACCOUNTS];
  int num_accounts;
} bank;

// Create a new bank
bank* create_bank() {
  bank* b = (bank*)malloc(sizeof(bank));
  b->num_accounts = 0;
  return b;
}

// Add an account to the bank
void add_account(bank* b, account* a) {
  b->accounts[b->num_accounts] = *a;
  b->num_accounts++;
}

// Get an account by account number
account* get_account(bank* b, int account_number) {
  for (int i = 0; i < b->num_accounts; i++) {
    if (b->accounts[i].account_number == account_number) {
      return &b->accounts[i];
    }
  }
  return NULL;
}

// Deposit money into an account
void deposit(bank* b, int account_number, double amount) {
  account* a = get_account(b, account_number);
  if (a == NULL) {
    printf("Account not found.\n");
    return;
  }
  a->balance += amount;
}

// Withdraw money from an account
void withdraw(bank* b, int account_number, double amount) {
  account* a = get_account(b, account_number);
  if (a == NULL) {
    printf("Account not found.\n");
    return;
  }
  if (a->balance < amount) {
    printf("Insufficient funds.\n");
    return;
  }
  a->balance -= amount;
}

// Print the balance of an account
void print_balance(bank* b, int account_number) {
  account* a = get_account(b, account_number);
  if (a == NULL) {
    printf("Account not found.\n");
    return;
  }
  printf("Balance: $%.2f\n", a->balance);
}

// Print all accounts in the bank
void print_all_accounts(bank* b) {
  for (int i = 0; i < b->num_accounts; i++) {
    printf("Account %d: %s, $%.2f\n", b->accounts[i].account_number, b->accounts[i].name, b->accounts[i].balance);
  }
}

// Main function
int main() {
  // Create a new bank
  bank* b = create_bank();

  // Add some accounts to the bank
  account a1 = {"John Doe", 12345, 1000.00};
  add_account(b, &a1);
  account a2 = {"Jane Doe", 54321, 2000.00};
  add_account(b, &a2);

  // Deposit money into an account
  deposit(b, 12345, 500.00);

  // Withdraw money from an account
  withdraw(b, 54321, 300.00);

  // Print the balance of an account
  print_balance(b, 12345);

  // Print all accounts in the bank
  print_all_accounts(b);

  return 0;
}