//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the account structure
typedef struct {
  int account_number;
  char name[50];
  double balance;
} account;

// Declare the bank structure
typedef struct {
  int num_accounts;
  account accounts[100];
} bank;

// Create a new bank
bank *create_bank() {
  bank *new_bank = (bank *)malloc(sizeof(bank));
  new_bank->num_accounts = 0;
  return new_bank;
}

// Add an account to the bank
void add_account(bank *bank, int account_number, char *name, double balance) {
  bank->accounts[bank->num_accounts].account_number = account_number;
  strcpy(bank->accounts[bank->num_accounts].name, name);
  bank->accounts[bank->num_accounts].balance = balance;
  bank->num_accounts++;
}

// Get the account by account number
account *get_account(bank *bank, int account_number) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == account_number) {
      return &bank->accounts[i];
    }
  }
  return NULL;
}

// Deposit money into an account
void deposit(bank *bank, int account_number, double amount) {
  account *account = get_account(bank, account_number);
  if (account) {
    account->balance += amount;
    printf("Successfully deposited %.2f into account %d\n", amount, account_number);
  } else {
    printf("Account %d not found\n", account_number);
  }
}

// Withdraw money from an account
void withdraw(bank *bank, int account_number, double amount) {
  account *account = get_account(bank, account_number);
  if (account) {
    if (account->balance >= amount) {
      account->balance -= amount;
      printf("Successfully withdrew %.2f from account %d\n", amount, account_number);
    } else {
      printf("Insufficient funds in account %d\n", account_number);
    }
  } else {
    printf("Account %d not found\n", account_number);
  }
}

// Print the bank statement
void print_statement(bank *bank) {
  printf("Bank Statement\n");
  for (int i = 0; i < bank->num_accounts; i++) {
    printf("Account %d: %s, Balance: %.2f\n", bank->accounts[i].account_number, bank->accounts[i].name, bank->accounts[i].balance);
  }
}

// Main function
int main() {
  // Create a new bank
  bank *bank = create_bank();

  // Add some accounts to the bank
  add_account(bank, 12345, "John Smith", 1000.0);
  add_account(bank, 54321, "Jane Doe", 2000.0);

  // Deposit money into an account
  deposit(bank, 12345, 500.0);

  // Withdraw money from an account
  withdraw(bank, 54321, 300.0);

  // Print the bank statement
  print_statement(bank);

  // Free the memory allocated for the bank
  free(bank);

  return 0;
}