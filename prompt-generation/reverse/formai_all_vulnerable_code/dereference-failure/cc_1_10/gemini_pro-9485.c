//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct {
  int account_number;
  char name[50];
  double balance;
} account_t;

// Define the bank structure
typedef struct {
  account_t accounts[MAX_ACCOUNTS];
  int num_accounts;
} bank_t;

// Create a new bank
bank_t *create_bank() {
  bank_t *bank = malloc(sizeof(bank_t));
  bank->num_accounts = 0;
  return bank;
}

// Add an account to the bank
void add_account(bank_t *bank, int account_number, char *name, double balance) {
  // Check if the bank is full
  if (bank->num_accounts >= MAX_ACCOUNTS) {
    printf("Error: Bank is full\n");
    return;
  }

  // Add the account to the bank
  bank->accounts[bank->num_accounts].account_number = account_number;
  strcpy(bank->accounts[bank->num_accounts].name, name);
  bank->accounts[bank->num_accounts].balance = balance;
  bank->num_accounts++;
}

// Find an account by account number
account_t *find_account(bank_t *bank, int account_number) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == account_number) {
      return &bank->accounts[i];
    }
  }

  return NULL;
}

// Deposit money into an account
void deposit_money(bank_t *bank, int account_number, double amount) {
  account_t *account = find_account(bank, account_number);

  if (account == NULL) {
    printf("Error: Account not found\n");
    return;
  }

  account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(bank_t *bank, int account_number, double amount) {
  account_t *account = find_account(bank, account_number);

  if (account == NULL) {
    printf("Error: Account not found\n");
    return;
  }

  if (amount > account->balance) {
    printf("Error: Insufficient funds\n");
    return;
  }

  account->balance -= amount;
}

// Print the bank statement
void print_bank_statement(bank_t *bank) {
  printf("Bank Statement\n");
  printf("---------------------\n");
  for (int i = 0; i < bank->num_accounts; i++) {
    printf("%d %s %.2f\n", bank->accounts[i].account_number, bank->accounts[i].name, bank->accounts[i].balance);
  }
}

// Main function
int main() {
  // Create a new bank
  bank_t *bank = create_bank();

  // Add some accounts to the bank
  add_account(bank, 12345, "John Smith", 1000.00);
  add_account(bank, 54321, "Jane Doe", 2000.00);

  // Deposit money into an account
  deposit_money(bank, 12345, 500.00);

  // Withdraw money from an account
  withdraw_money(bank, 54321, 300.00);

  // Print the bank statement
  print_bank_statement(bank);

  return 0;
}