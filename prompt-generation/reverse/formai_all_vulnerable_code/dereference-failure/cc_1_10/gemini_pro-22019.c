//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  double balance;
} Account;

typedef struct {
  Account *accounts;
  size_t count;
} Bank;

Bank *create_bank() {
  Bank *bank = malloc(sizeof(Bank));
  bank->accounts = NULL;
  bank->count = 0;
  return bank;
}

void destroy_bank(Bank *bank) {
  for (size_t i = 0; i < bank->count; i++) {
    free(bank->accounts[i].name);
  }
  free(bank->accounts);
  free(bank);
}

Account *create_account(Bank *bank, char *name) {
  Account *account = malloc(sizeof(Account));
  account->name = strdup(name);
  account->balance = 0.0;
  bank->accounts = realloc(bank->accounts, sizeof(Account) * (bank->count + 1));
  bank->accounts[bank->count] = *account;
  bank->count++;
  return account;
}

void deposit(Account *account, double amount) {
  account->balance += amount;
}

void withdraw(Account *account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
  }
}

double get_balance(Account *account) {
  return account->balance;
}

void print_bank(Bank *bank) {
  for (size_t i = 0; i < bank->count; i++) {
    printf("%s: $%.2f\n", bank->accounts[i].name, bank->accounts[i].balance);
  }
}

int main() {
  Bank *bank = create_bank();
  Account *alice = create_account(bank, "Alice");
  Account *bob = create_account(bank, "Bob");
  deposit(alice, 100.0);
  withdraw(bob, 50.0);
  print_bank(bank);
  destroy_bank(bank);
  return 0;
}