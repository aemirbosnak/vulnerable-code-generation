//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the account structure
typedef struct account {
  char name[50];
  char account_number[20];
  double balance;
} account;

// Define the bank structure
typedef struct bank {
  char name[50];
  int num_accounts;
  account accounts[100];
} bank;

// Create a new bank
bank* create_bank(char* name) {
  bank* new_bank = (bank*)malloc(sizeof(bank));
  strcpy(new_bank->name, name);
  new_bank->num_accounts = 0;
  return new_bank;
}

// Add a new account to the bank
void add_account(bank* bank, account* new_account) {
  bank->accounts[bank->num_accounts] = *new_account;
  bank->num_accounts++;
}

// Find an account by account number
account* find_account(bank* bank, char* account_number) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (strcmp(bank->accounts[i].account_number, account_number) == 0) {
      return &bank->accounts[i];
    }
  }
  return NULL;
}

// Deposit money into an account
void deposit_money(account* account, double amount) {
  account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(account* account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
  }
}

// Print the bank's records
void print_bank_records(bank* bank) {
  printf("Bank: %s\n", bank->name);
  for (int i = 0; i < bank->num_accounts; i++) {
    printf("Account %d:\n", i + 1);
    printf("Name: %s\n", bank->accounts[i].name);
    printf("Account number: %s\n", bank->accounts[i].account_number);
    printf("Balance: %.2f\n\n", bank->accounts[i].balance);
  }
}

// Main function
int main() {
  // Create a new bank
  bank* bank = create_bank("First National Bank");

  // Add some accounts to the bank
  account account1 = {"John Doe", "1234567890", 1000.00};
  add_account(bank, &account1);

  account account2 = {"Jane Doe", "0987654321", 2000.00};
  add_account(bank, &account2);

  // Deposit money into an account
  deposit_money(&account1, 500.00);

  // Withdraw money from an account
  withdraw_money(&account2, 300.00);

  // Print the bank's records
  print_bank_records(bank);

  return 0;
}