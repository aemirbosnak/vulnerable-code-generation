//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char *name;
  int balance;
};

struct bank {
  struct account *accounts;
  int num_accounts;
};

struct bank *create_bank() {
  struct bank *bank = malloc(sizeof(struct bank));
  bank->accounts = NULL;
  bank->num_accounts = 0;
  return bank;
}

void destroy_bank(struct bank *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    free(bank->accounts[i].name);
  }
  free(bank->accounts);
  free(bank);
}

struct account *create_account(struct bank *bank, char *name, int balance) {
  struct account *account = malloc(sizeof(struct account));
  account->name = strdup(name);
  account->balance = balance;
  bank->accounts = realloc(bank->accounts, (bank->num_accounts + 1) * sizeof(struct account));
  bank->accounts[bank->num_accounts++] = *account;
  return account;
}

void destroy_account(struct bank *bank, struct account *account) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (&bank->accounts[i] == account) {
      free(bank->accounts[i].name);
      memmove(&bank->accounts[i], &bank->accounts[i + 1], (bank->num_accounts - i - 1) * sizeof(struct account));
      bank->num_accounts--;
      break;
    }
  }
}

int get_balance(struct bank *bank, char *name) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (strcmp(bank->accounts[i].name, name) == 0) {
      return bank->accounts[i].balance;
    }
  }
  return -1;
}

void deposit(struct bank *bank, char *name, int amount) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (strcmp(bank->accounts[i].name, name) == 0) {
      bank->accounts[i].balance += amount;
      break;
    }
  }
}

void withdraw(struct bank *bank, char *name, int amount) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (strcmp(bank->accounts[i].name, name) == 0) {
      bank->accounts[i].balance -= amount;
      break;
    }
  }
}

void print_bank(struct bank *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    printf("%s: %d\n", bank->accounts[i].name, bank->accounts[i].balance);
  }
}

int main() {
  struct bank *bank = create_bank();
  create_account(bank, "Alice", 100);
  create_account(bank, "Bob", 200);
  create_account(bank, "Carol", 300);
  print_bank(bank);
  deposit(bank, "Alice", 50);
  withdraw(bank, "Bob", 100);
  print_bank(bank);
  destroy_account(bank, bank->accounts);
  destroy_bank(bank);
  return 0;
}