//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  char account_number[20];
  double balance;
} account;

account *accounts;
int num_accounts = 0;

void create_account() {
  account new_account;

  printf("Enter name: ");
  scanf(" %[^\n]", new_account.name);

  printf("Enter account number: ");
  scanf(" %s", new_account.account_number);

  printf("Enter balance: ");
  scanf(" %lf", &new_account.balance);

  accounts = realloc(accounts, sizeof(account) * (num_accounts + 1));
  accounts[num_accounts] = new_account;
  num_accounts++;
}

void deposit() {
  char account_number[20];
  double amount;

  printf("Enter account number: ");
  scanf(" %s", account_number);

  printf("Enter amount to deposit: ");
  scanf(" %lf", &amount);

  for (int i = 0; i < num_accounts; i++) {
    if (strcmp(accounts[i].account_number, account_number) == 0) {
      accounts[i].balance += amount;
      printf("Deposit successful\n");
      return;
    }
  }

  printf("Account not found\n");
}

void withdraw() {
  char account_number[20];
  double amount;

  printf("Enter account number: ");
  scanf(" %s", account_number);

  printf("Enter amount to withdraw: ");
  scanf(" %lf", &amount);

  for (int i = 0; i < num_accounts; i++) {
    if (strcmp(accounts[i].account_number, account_number) == 0) {
      if (accounts[i].balance >= amount) {
        accounts[i].balance -= amount;
        printf("Withdrawal successful\n");
        return;
      } else {
        printf("Insufficient funds\n");
        return;
      }
    }
  }

  printf("Account not found\n");
}

void print_accounts() {
  for (int i = 0; i < num_accounts; i++) {
    printf("%-20s %-20s $%.2f\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
  }
}

int main() {
  int choice;

  while (1) {
    printf("1. Create account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Print accounts\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf(" %d", &choice);

    switch (choice) {
      case 1:
        create_account();
        break;
      case 2:
        deposit();
        break;
      case 3:
        withdraw();
        break;
      case 4:
        print_accounts();
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}