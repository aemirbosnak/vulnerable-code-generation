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
  char *date;
} transaction_t;

typedef struct {
  account_t *accounts[10];
  transaction_t *transactions[100];
  int num_accounts;
  int num_transactions;
} planner_t;

planner_t *create_planner() {
  planner_t *planner = malloc(sizeof(planner_t));
  memset(planner, 0, sizeof(planner_t));
  return planner;
}

void destroy_planner(planner_t *planner) {
  for (int i = 0; i < planner->num_accounts; i++) {
    free(planner->accounts[i]->name);
    free(planner->accounts[i]);
  }
  for (int i = 0; i < planner->num_transactions; i++) {
    free(planner->transactions[i]->name);
    free(planner->transactions[i]->date);
    free(planner->transactions[i]);
  }
  free(planner);
}

account_t *create_account(char *name, double balance) {
  account_t *account = malloc(sizeof(account_t));
  account->name = strdup(name);
  account->balance = balance;
  return account;
}

transaction_t *create_transaction(char *name, double amount, char *date) {
  transaction_t *transaction = malloc(sizeof(transaction_t));
  transaction->name = strdup(name);
  transaction->amount = amount;
  transaction->date = strdup(date);
  return transaction;
}

void add_account(planner_t *planner, account_t *account) {
  planner->accounts[planner->num_accounts++] = account;
}

void add_transaction(planner_t *planner, transaction_t *transaction) {
  planner->transactions[planner->num_transactions++] = transaction;
}

void print_planner(planner_t *planner) {
  printf("Accounts:\n");
  for (int i = 0; i < planner->num_accounts; i++) {
    printf("  %s: %.2f\n", planner->accounts[i]->name, planner->accounts[i]->balance);
  }
  printf("Transactions:\n");
  for (int i = 0; i < planner->num_transactions; i++) {
    printf("  %s: %.2f (%s)\n", planner->transactions[i]->name, planner->transactions[i]->amount, planner->transactions[i]->date);
  }
}

int main() {
  planner_t *planner = create_planner();
  add_account(planner, create_account("Checking", 1000.00));
  add_account(planner, create_account("Savings", 2000.00));
  add_transaction(planner, create_transaction("Deposit", 500.00, "2020-01-01"));
  add_transaction(planner, create_transaction("Withdrawal", 200.00, "2020-01-02"));
  print_planner(planner);
  destroy_planner(planner);
  return 0;
}