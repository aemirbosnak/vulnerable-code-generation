//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdbool.h>

typedef struct Account {
  int account_number;
  char *name;
  double balance;
} Account;

Account *accounts[100];
int num_accounts = 0;

void create_account(char *name, double initial_balance) {
  accounts[num_accounts] = malloc(sizeof(Account));
  accounts[num_accounts]->account_number = num_accounts + 1;
  accounts[num_accounts]->name = name;
  accounts[num_accounts]->balance = initial_balance;
  num_accounts++;
}

void deposit(int account_number, double amount) {
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i]->account_number == account_number) {
      accounts[i]->balance += amount;
      break;
    }
  }
}

void withdraw(int account_number, double amount) {
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i]->account_number == account_number) {
      if (accounts[i]->balance >= amount) {
        accounts[i]->balance -= amount;
      } else {
        printf("Insufficient funds\n");
      }
      break;
    }
  }
}

void transfer(int from_account_number, int to_account_number, double amount) {
  for (int i = 0; i < num_accounts; i++) {
    if (accounts[i]->account_number == from_account_number) {
      if (accounts[i]->balance >= amount) {
        accounts[i]->balance -= amount;
        for (int j = 0; j < num_accounts; j++) {
          if (accounts[j]->account_number == to_account_number) {
            accounts[j]->balance += amount;
            break;
          }
        }
      } else {
        printf("Insufficient funds\n");
      }
      break;
    }
  }
}

void print_accounts() {
  for (int i = 0; i < num_accounts; i++) {
    printf("Account %d: %s, balance: %.2f\n", accounts[i]->account_number, accounts[i]->name, accounts[i]->balance);
  }
}

int main() {
  create_account("John Doe", 1000.00);
  create_account("Jane Doe", 2000.00);

  deposit(1, 500.00);
  withdraw(2, 300.00);
  transfer(1, 2, 200.00);

  print_accounts();

  return 0;
}