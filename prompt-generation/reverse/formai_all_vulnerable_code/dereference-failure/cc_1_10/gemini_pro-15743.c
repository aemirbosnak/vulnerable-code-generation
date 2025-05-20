//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  double balance;
} account_t;

typedef struct {
  char *description;
  double amount;
} transaction_t;

typedef struct {
  char *name;
  account_t *accounts;
  int num_accounts;
  transaction_t *transactions;
  int num_transactions;
} user_t;

user_t *create_user(char *name) {
  user_t *user = malloc(sizeof(user_t));
  user->name = name;
  user->accounts = NULL;
  user->num_accounts = 0;
  user->transactions = NULL;
  user->num_transactions = 0;
  return user;
}

void add_account(user_t *user, char *name, double balance) {
  user->accounts = realloc(user->accounts, sizeof(account_t) * (user->num_accounts + 1));
  user->accounts[user->num_accounts].name = name;
  user->accounts[user->num_accounts].balance = balance;
  user->num_accounts++;
}

void add_transaction(user_t *user, char *description, double amount) {
  user->transactions = realloc(user->transactions, sizeof(transaction_t) * (user->num_transactions + 1));
  user->transactions[user->num_transactions].description = description;
  user->transactions[user->num_transactions].amount = amount;
  user->num_transactions++;
}

void print_user(user_t *user) {
  printf("User: %s\n", user->name);
  for (int i = 0; i < user->num_accounts; i++) {
    printf("  Account: %s, Balance: %f\n", user->accounts[i].name, user->accounts[i].balance);
  }
  for (int i = 0; i < user->num_transactions; i++) {
    printf("  Transaction: %s, Amount: %f\n", user->transactions[i].description, user->transactions[i].amount);
  }
}

int main() {
  user_t *user = create_user("John Doe");
  add_account(user, "Checking", 1000.00);
  add_account(user, "Savings", 2000.00);
  add_transaction(user, "Deposit", 500.00);
  add_transaction(user, "Withdraw", 200.00);
  print_user(user);
  return 0;
}