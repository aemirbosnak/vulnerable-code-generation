//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: complex
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
  account_t *accounts;
  int num_accounts;
  transaction_t *transactions;
  int num_transactions;
} personal_finance_t;

personal_finance_t *create_personal_finance() {
  personal_finance_t *pf = malloc(sizeof(personal_finance_t));
  pf->accounts = NULL;
  pf->num_accounts = 0;
  pf->transactions = NULL;
  pf->num_transactions = 0;
  return pf;
}

void destroy_personal_finance(personal_finance_t *pf) {
  for (int i = 0; i < pf->num_accounts; i++) {
    free(pf->accounts[i].name);
  }
  free(pf->accounts);
  for (int i = 0; i < pf->num_transactions; i++) {
    free(pf->transactions[i].name);
    free(pf->transactions[i].date);
  }
  free(pf->transactions);
  free(pf);
}

account_t *create_account(char *name, double balance) {
  account_t *account = malloc(sizeof(account_t));
  account->name = strdup(name);
  account->balance = balance;
  return account;
}

void destroy_account(account_t *account) {
  free(account->name);
  free(account);
}

transaction_t *create_transaction(char *name, double amount, char *date) {
  transaction_t *transaction = malloc(sizeof(transaction_t));
  transaction->name = strdup(name);
  transaction->amount = amount;
  transaction->date = strdup(date);
  return transaction;
}

void destroy_transaction(transaction_t *transaction) {
  free(transaction->name);
  free(transaction->date);
  free(transaction);
}

void add_account(personal_finance_t *pf, account_t *account) {
  pf->accounts = realloc(pf->accounts, (pf->num_accounts + 1) * sizeof(account_t));
  pf->accounts[pf->num_accounts++] = *account;
}

void add_transaction(personal_finance_t *pf, transaction_t *transaction) {
  pf->transactions = realloc(pf->transactions, (pf->num_transactions + 1) * sizeof(transaction_t));
  pf->transactions[pf->num_transactions++] = *transaction;
}

int main() {
  personal_finance_t *pf = create_personal_finance();

  account_t *checking_account = create_account("Checking", 1000.0);
  add_account(pf, checking_account);

  account_t *savings_account = create_account("Savings", 2000.0);
  add_account(pf, savings_account);

  transaction_t *transaction1 = create_transaction("Deposit", 500.0, "2023-01-01");
  add_transaction(pf, transaction1);

  transaction_t *transaction2 = create_transaction("Withdrawal", 200.0, "2023-01-02");
  add_transaction(pf, transaction2);

  printf("Personal Finance Report\n");
  printf("======================\n");
  for (int i = 0; i < pf->num_accounts; i++) {
    printf("Account: %s\n", pf->accounts[i].name);
    printf("Balance: $%.2f\n", pf->accounts[i].balance);
  }
  printf("\n");
  for (int i = 0; i < pf->num_transactions; i++) {
    printf("Transaction: %s\n", pf->transactions[i].name);
    printf("Amount: $%.2f\n", pf->transactions[i].amount);
    printf("Date: %s\n", pf->transactions[i].date);
  }

  destroy_personal_finance(pf);
  return 0;
}