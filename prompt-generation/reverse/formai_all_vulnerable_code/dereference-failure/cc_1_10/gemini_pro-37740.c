//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

struct account {
  char name[100];
  int account_number;
  int balance;
};

struct transaction {
  int account_number;
  int amount;
  char type; //'D' for deposit, 'W' for withdrawal
};

struct bank {
  struct account accounts[MAX_ACCOUNTS];
  struct transaction transactions[MAX_TRANSACTIONS];
  int num_accounts;
  int num_transactions;
};

struct bank* create_bank() {
  struct bank* bank = malloc(sizeof(struct bank));
  bank->num_accounts = 0;
  bank->num_transactions = 0;
  return bank;
}

void destroy_bank(struct bank* bank) {
  free(bank);
}

int add_account(struct bank* bank, char* name, int account_number, int balance) {
  if (bank->num_accounts >= MAX_ACCOUNTS) {
    return -1;
  }
  struct account* account = &bank->accounts[bank->num_accounts++];
  strcpy(account->name, name);
  account->account_number = account_number;
  account->balance = balance;
  return 0;
}

int add_transaction(struct bank* bank, int account_number, int amount, char type) {
  if (bank->num_transactions >= MAX_TRANSACTIONS) {
    return -1;
  }
  struct transaction* transaction = &bank->transactions[bank->num_transactions++];
  transaction->account_number = account_number;
  transaction->amount = amount;
  transaction->type = type;
  return 0;
}

int get_balance(struct bank* bank, int account_number) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == account_number) {
      return bank->accounts[i].balance;
    }
  }
  return -1;
}

int deposit(struct bank* bank, int account_number, int amount) {
  if (amount <= 0) {
    return -1;
  }
  int balance = get_balance(bank, account_number);
  if (balance == -1) {
    return -1;
  }
  balance += amount;
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == account_number) {
      bank->accounts[i].balance = balance;
      return 0;
    }
  }
  return -1;
}

int withdraw(struct bank* bank, int account_number, int amount) {
  if (amount <= 0) {
    return -1;
  }
  int balance = get_balance(bank, account_number);
  if (balance == -1) {
    return -1;
  }
  if (balance < amount) {
    return -1;
  }
  balance -= amount;
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == account_number) {
      bank->accounts[i].balance = balance;
      return 0;
    }
  }
  return -1;
}

void print_bank(struct bank* bank) {
  printf("Accounts:\n");
  for (int i = 0; i < bank->num_accounts; i++) {
    printf("  %s %d %d\n", bank->accounts[i].name, bank->accounts[i].account_number, bank->accounts[i].balance);
  }
  printf("Transactions:\n");
  for (int i = 0; i < bank->num_transactions; i++) {
    printf("  %d %d %c\n", bank->transactions[i].account_number, bank->transactions[i].amount, bank->transactions[i].type);
  }
}

int main() {
  struct bank* bank = create_bank();
  add_account(bank, "Alice", 12345, 1000);
  add_account(bank, "Bob", 67890, 2000);

  deposit(bank, 12345, 100);
  withdraw(bank, 67890, 500);

  print_bank(bank);

  destroy_bank(bank);
  return 0;
}