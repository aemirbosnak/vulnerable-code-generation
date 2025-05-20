//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <crypt.h>

#define MAX_ACCOUNTS 1000
#define MAX_TXNS 100000

struct account {
  char number[10];
  char name[50];
  double balance;
  int num_txns;
  int txns[MAX_TXNS];
  char password[50];
};

struct bank {
  int num_accounts;
  int num_txns;
  struct account accounts[MAX_ACCOUNTS];
  char password[50];
};

struct bank *
bank_new(const char *password) {
  struct bank *bank;

  bank = malloc(sizeof(struct bank));
  if (!bank) {
    return NULL;
  }

  bank->num_accounts = 0;
  bank->num_txns = 0;
  strcpy(bank->password, password);

  return bank;
}

int
bank_add_account(struct bank *bank, const char *number, const char *name, double balance, const char *password) {
  struct account *account;

  if (bank->num_accounts >= MAX_ACCOUNTS) {
    return -1;
  }

  account = &bank->accounts[bank->num_accounts++];
  strcpy(account->number, number);
  strcpy(account->name, name);
  account->balance = balance;
  account->num_txns = 0;
  strcpy(account->password, password);

  return 0;
}

int
bank_add_txn(struct bank *bank, const char *account_number, double amount) {
  struct account *account;
  int i;

  for (i = 0; i < bank->num_accounts; i++) {
    account = &bank->accounts[i];
    if (!strcmp(account->number, account_number)) {
      break;
    }
  }

  if (i == bank->num_accounts) {
    return -1;
  }

  account->txns[account->num_txns++] = amount;
  bank->num_txns++;

  return 0;
}

int
bank_print(struct bank *bank) {
  int i, j;
  struct account *account;

  for (i = 0; i < bank->num_accounts; i++) {
    account = &bank->accounts[i];
    printf("Account number: %s\n", account->number);
    printf("Account name: %s\n", account->name);
    printf("Account balance: %f\n", account->balance);
    printf("Account transactions:\n");
    for (j = 0; j < account->num_txns; j++) {
      printf("  %d: %f\n", j, account->txns[j]);
    }
    printf("\n");
  }

  return 0;
}

int
main(int argc, char *argv[]) {
  struct bank *bank;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <password>\n", argv[0]);
    return -1;
  }

  bank = bank_new(argv[1]);
  if (!bank) {
    fprintf(stderr, "Error creating bank: %s\n", strerror(errno));
    return -1;
  }

  if (bank_add_account(bank, "1234567890", "John Doe", 1000.00, "password") != 0) {
    fprintf(stderr, "Error adding account: %s\n", strerror(errno));
    return -1;
  }

  if (bank_add_txn(bank, "1234567890", 100.00) != 0) {
    fprintf(stderr, "Error adding transaction: %s\n", strerror(errno));
    return -1;
  }

  if (bank_add_txn(bank, "1234567890", -50.00) != 0) {
    fprintf(stderr, "Error adding transaction: %s\n", strerror(errno));
    return -1;
  }

  if (bank_print(bank) != 0) {
    fprintf(stderr, "Error printing bank: %s\n", strerror(errno));
    return -1;
  }

  return 0;
}