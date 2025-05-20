//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the account structure
typedef struct account {
  int account_number;
  char *name;
  double balance;
} account_t;

// Declare the bank structure
typedef struct bank {
  int num_accounts;
  account_t *accounts;
} bank_t;

// Create a new bank
bank_t *create_bank() {
  bank_t *bank = (bank_t *)malloc(sizeof(bank_t));
  bank->num_accounts = 0;
  bank->accounts = NULL;
  return bank;
}

// Add an account to the bank
void add_account(bank_t *bank, int account_number, char *name, double balance) {
  // Reallocate the accounts array to make space for the new account
  bank->accounts = (account_t *)realloc(bank->accounts, sizeof(account_t) * (bank->num_accounts + 1));

  // Add the new account to the array
  bank->accounts[bank->num_accounts].account_number = account_number;
  bank->accounts[bank->num_accounts].name = strdup(name);
  bank->accounts[bank->num_accounts].balance = balance;

  // Increment the number of accounts
  bank->num_accounts++;
}

// Find an account by its account number
account_t *find_account(bank_t *bank, int account_number) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == account_number) {
      return &bank->accounts[i];
    }
  }
  return NULL;
}

// Deposit money into an account
void deposit_money(account_t *account, double amount) {
  account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(account_t *account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Print the details of an account
void print_account(account_t *account) {
  printf("Account number: %d\n", account->account_number);
  printf("Name: %s\n", account->name);
  printf("Balance: %.2f\n", account->balance);
}

// Print the details of all accounts in the bank
void print_bank(bank_t *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    print_account(&bank->accounts[i]);
    printf("\n");
  }
}

// Free the memory allocated for the bank and its accounts
void free_bank(bank_t *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    free(bank->accounts[i].name);
  }
  free(bank->accounts);
  free(bank);
}

int main() {
  // Create a new bank
  bank_t *bank = create_bank();

  // Add some accounts to the bank
  add_account(bank, 12345, "John Doe", 1000.00);
  add_account(bank, 67890, "Jane Doe", 2000.00);

  // Find an account by its account number
  account_t *account = find_account(bank, 12345);

  // Deposit money into the account
  deposit_money(account, 500.00);

  // Withdraw money from the account
  withdraw_money(account, 300.00);

  // Print the details of the updated account
  print_account(account);

  // Print the details of all accounts in the bank
  print_bank(bank);

  // Free the memory allocated for the bank and its accounts
  free_bank(bank);

  return 0;
}