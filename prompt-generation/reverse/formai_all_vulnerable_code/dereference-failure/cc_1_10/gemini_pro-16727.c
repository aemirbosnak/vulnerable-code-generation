//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the bank account structure
typedef struct {
  int account_number;
  char *name;
  double balance;
} bank_account;

// Define the bank database structure
typedef struct {
  bank_account *accounts;
  int num_accounts;
} bank_database;

// Create a new bank account
bank_account *create_account(int account_number, char *name, double balance) {
  bank_account *account = malloc(sizeof(bank_account));
  account->account_number = account_number;
  account->name = name;
  account->balance = balance;
  return account;
}

// Add an account to the bank database
void add_account(bank_database *database, bank_account *account) {
  database->accounts = realloc(database->accounts, (database->num_accounts + 1) * sizeof(bank_account));
  database->accounts[database->num_accounts++] = *account;
}

// Find an account by account number
bank_account *find_account(bank_database *database, int account_number) {
  for (int i = 0; i < database->num_accounts; i++) {
    if (database->accounts[i].account_number == account_number) {
      return &database->accounts[i];
    }
  }
  return NULL;
}

// Deposit money into an account
void deposit_money(bank_account *account, double amount) {
  account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(bank_account *account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
  }
}

// Print the bank database
void print_database(bank_database *database) {
  for (int i = 0; i < database->num_accounts; i++) {
    printf("Account Number: %d\n", database->accounts[i].account_number);
    printf("Name: %s\n", database->accounts[i].name);
    printf("Balance: %.2f\n\n", database->accounts[i].balance);
  }
}

// Main function
int main() {
  // Create a new bank database
  bank_database *database = malloc(sizeof(bank_database));
  database->accounts = NULL;
  database->num_accounts = 0;

  // Create some bank accounts
  bank_account *account1 = create_account(123456, "John Doe", 1000.00);
  bank_account *account2 = create_account(654321, "Jane Doe", 2000.00);

  // Add the accounts to the database
  add_account(database, account1);
  add_account(database, account2);

  // Deposit money into account1
  deposit_money(account1, 500.00);

  // Withdraw money from account2
  withdraw_money(account2, 1000.00);

  // Print the bank database
  print_database(database);

  // Free the memory allocated for the bank accounts and the database
  free(account1);
  free(account2);
  free(database->accounts);
  free(database);

  return 0;
}