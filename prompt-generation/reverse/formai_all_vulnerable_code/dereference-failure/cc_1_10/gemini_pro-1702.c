//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  double balance;
} account_t;

typedef struct {
  char *name;
  double amount;
  char *category;
} transaction_t;

account_t *accounts;
int num_accounts;

transaction_t *transactions;
int num_transactions;

void add_account(char *name, double balance) {
  accounts = realloc(accounts, (num_accounts + 1) * sizeof(account_t));
  accounts[num_accounts].name = strdup(name);
  accounts[num_accounts].balance = balance;
  num_accounts++;
}

void add_transaction(char *name, double amount, char *category) {
  transactions = realloc(transactions, (num_transactions + 1) * sizeof(transaction_t));
  transactions[num_transactions].name = strdup(name);
  transactions[num_transactions].amount = amount;
  transactions[num_transactions].category = strdup(category);
  num_transactions++;
}

void print_accounts() {
  for (int i = 0; i < num_accounts; i++) {
    printf("%s: $%.2f\n", accounts[i].name, accounts[i].balance);
  }
}

void print_transactions() {
  for (int i = 0; i < num_transactions; i++) {
    printf("%s: $%.2f (%s)\n", transactions[i].name, transactions[i].amount, transactions[i].category);
  }
}

int main() {
  // Add some sample accounts
  add_account("Checking", 1000.00);
  add_account("Savings", 2000.00);
  add_account("Credit Card", -100.00);

  // Add some sample transactions
  add_transaction("Bought groceries", -50.00, "Groceries");
  add_transaction("Received paycheck", 2000.00, "Income");
  add_transaction("Paid rent", -1500.00, "Housing");

  // Print the accounts
  printf("Accounts:\n");
  print_accounts();

  // Print the transactions
  printf("\nTransactions:\n");
  print_transactions();

  return 0;
}