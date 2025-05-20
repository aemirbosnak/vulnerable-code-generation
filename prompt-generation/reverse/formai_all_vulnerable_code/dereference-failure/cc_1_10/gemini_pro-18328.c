//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100

struct account {
  int account_number;
  char *name;
  double balance;
};

struct bank {
  struct account accounts[MAX_ACCOUNTS];
  int num_accounts;
};

struct bank *create_bank() {
  struct bank *bank = malloc(sizeof(struct bank));
  bank->num_accounts = 0;
  return bank;
}

void destroy_bank(struct bank *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    free(bank->accounts[i].name);
  }
  free(bank);
}

struct account *create_account(struct bank *bank, char *name, double balance) {
  if (bank->num_accounts >= MAX_ACCOUNTS) {
    return NULL;
  }
  struct account *account = &bank->accounts[bank->num_accounts++];
  account->account_number = bank->num_accounts;
  account->name = strdup(name);
  account->balance = balance;
  return account;
}

void destroy_account(struct bank *bank, struct account *account) {
  int index = account->account_number - 1;
  bank->num_accounts--;
  free(bank->accounts[index].name);
  bank->accounts[index] = bank->accounts[bank->num_accounts];
}

double get_balance(struct account *account) {
  return account->balance;
}

void deposit(struct account *account, double amount) {
  account->balance += amount;
}

void withdraw(struct account *account, double amount) {
  if (amount > account->balance) {
    return;
  }
  account->balance -= amount;
}

void transfer(struct bank *bank, struct account *from, struct account *to, double amount) {
  if (amount > from->balance) {
    return;
  }
  from->balance -= amount;
  to->balance += amount;
}

void print_statement(struct account *account) {
  printf("Account number: %d\n", account->account_number);
  printf("Name: %s\n", account->name);
  printf("Balance: %f\n", account->balance);
}

int main() {
  struct bank *bank = create_bank();
  struct account *account1 = create_account(bank, "John Doe", 1000.0);
  struct account *account2 = create_account(bank, "Jane Doe", 2000.0);

  deposit(account1, 500.0);
  withdraw(account2, 300.0);
  transfer(bank, account1, account2, 200.0);

  print_statement(account1);
  print_statement(account2);

  destroy_account(bank, account1);
  destroy_account(bank, account2);
  destroy_bank(bank);

  return 0;
}