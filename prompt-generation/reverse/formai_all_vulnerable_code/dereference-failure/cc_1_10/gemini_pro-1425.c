//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int account_number;
  double balance;
} account_t;

typedef struct {
  account_t *accounts;
  int num_accounts;
} bank_t;

// Create a new bank
bank_t *create_bank() {
  bank_t *bank = malloc(sizeof(bank_t));
  bank->accounts = NULL;
  bank->num_accounts = 0;
  return bank;
}

// Free the memory associated with a bank
void free_bank(bank_t *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    free(bank->accounts[i].name);
  }
  free(bank->accounts);
  free(bank);
}

// Add an account to a bank
void add_account(bank_t *bank, char *name, int account_number, double balance) {
  bank->accounts = realloc(bank->accounts, (bank->num_accounts + 1) * sizeof(account_t));
  bank->accounts[bank->num_accounts].name = strdup(name);
  bank->accounts[bank->num_accounts].account_number = account_number;
  bank->accounts[bank->num_accounts].balance = balance;
  bank->num_accounts++;
}

// Find an account by account number
account_t *find_account_by_number(bank_t *bank, int account_number) {
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
  }
}

// Print the details of an account
void print_account(account_t *account) {
  printf("Name: %s\n", account->name);
  printf("Account number: %d\n", account->account_number);
  printf("Balance: %.2f\n", account->balance);
}

// Print the details of all accounts in a bank
void print_bank(bank_t *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    print_account(&bank->accounts[i]);
    printf("\n");
  }
}

int main() {
  // Create a new bank
  bank_t *bank = create_bank();

  // Add some accounts to the bank
  add_account(bank, "John Doe", 123456789, 1000.00);
  add_account(bank, "Jane Doe", 987654321, 2000.00);

  // Find an account by account number
  account_t *account = find_account_by_number(bank, 123456789);

  // Deposit money into the account
  deposit_money(account, 100.00);

  // Withdraw money from the account
  withdraw_money(account, 50.00);

  // Print the details of the account
  print_account(account);

  // Print the details of all accounts in the bank
  print_bank(bank);

  // Free the memory associated with the bank
  free_bank(bank);

  return 0;
}