//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_ACCOUNT_NUMBER 9

typedef struct Account {
  char name[MAX_NAME_LENGTH];
  int account_number;
  double balance;
  struct Account* next;
} Account;

Account* createAccount(char* name, int account_number, double balance) {
  Account* newAccount = malloc(sizeof(Account));
  strcpy(newAccount->name, name);
  newAccount->account_number = account_number;
  newAccount->balance = balance;
  newAccount->next = NULL;
  return newAccount;
}

void deposit(Account* account, double amount) {
  account->balance += amount;
}

void withdraw(Account* account, double amount) {
  if (amount <= account->balance) {
    account->balance -= amount;
  } else {
    printf("Insufficient funds");
  }
}

void transfer(Account* account1, Account* account2, double amount) {
  if (amount <= account1->balance) {
    deposit(account2, amount);
    withdraw(account1, amount);
  } else {
    printf("Insufficient funds");
  }
}

int main() {
  Account* head = NULL;
  head = createAccount("John Doe", 123456, 1000);
  deposit(head, 500);
  withdraw(head, 200);
  transfer(head, createAccount("Jane Doe", 654321, 2000), 300);
  printf("Balance: %f", head->balance);
  return 0;
}