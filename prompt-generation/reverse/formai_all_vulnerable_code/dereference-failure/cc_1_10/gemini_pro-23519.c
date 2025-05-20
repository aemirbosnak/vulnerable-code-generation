//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int account_number;
  char *name;
  double balance;
} account_t;

typedef struct {
  int num_accounts;
  account_t *accounts;
} bank_t;

bank_t *create_bank(int num_accounts) {
  bank_t *bank = malloc(sizeof(bank_t));
  bank->num_accounts = num_accounts;
  bank->accounts = malloc(sizeof(account_t) * num_accounts);
  return bank;
}

void free_bank(bank_t *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    free(bank->accounts[i].name);
  }
  free(bank->accounts);
  free(bank);
}

account_t *create_account(int account_number, char *name, double balance) {
  account_t *account = malloc(sizeof(account_t));
  account->account_number = account_number;
  account->name = strdup(name);
  account->balance = balance;
  return account;
}

void free_account(account_t *account) {
  free(account->name);
  free(account);
}

void deposit(bank_t *bank, int account_number, double amount) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == account_number) {
      bank->accounts[i].balance += amount;
      return;
    }
  }
  printf("Account not found\n");
}

void withdraw(bank_t *bank, int account_number, double amount) {
  for (int i = 0; i < bank->num_accounts; i++) {
    if (bank->accounts[i].account_number == account_number) {
      if (bank->accounts[i].balance >= amount) {
        bank->accounts[i].balance -= amount;
        return;
      } else {
        printf("Insufficient funds\n");
        return;
      }
    }
  }
  printf("Account not found\n");
}

void print_bank(bank_t *bank) {
  for (int i = 0; i < bank->num_accounts; i++) {
    printf("Account %d: %s, $%.2f\n", bank->accounts[i].account_number,
           bank->accounts[i].name, bank->accounts[i].balance);
  }
}

int main() {
  bank_t *bank = create_bank(3);
  bank->accounts[0] = *create_account(1234, "Alice", 1000.0);
  bank->accounts[1] = *create_account(5678, "Bob", 2000.0);
  bank->accounts[2] = *create_account(9876, "Carol", 3000.0);

  deposit(bank, 1234, 500.0);
  withdraw(bank, 5678, 1000.0);
  print_bank(bank);

  free_bank(bank);
  return 0;
}