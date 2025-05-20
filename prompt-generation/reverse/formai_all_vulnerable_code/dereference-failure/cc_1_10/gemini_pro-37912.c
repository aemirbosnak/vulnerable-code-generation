//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
  char name[256];
  double balance;
  struct Account *next;
} Account;

Account *accounts = NULL;

void createAccount(char *name, double balance) {
  Account *newAccount = malloc(sizeof(Account));
  strcpy(newAccount->name, name);
  newAccount->balance = balance;
  newAccount->next = accounts;
  accounts = newAccount;
}

Account *findAccount(char *name) {
  Account *current = accounts;
  while (current != NULL) {
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void deposit(char *name, double amount) {
  Account *account = findAccount(name);
  if (account != NULL) {
    account->balance += amount;
  } else {
    printf("Account not found.\n");
  }
}

void withdraw(char *name, double amount) {
  Account *account = findAccount(name);
  if (account != NULL) {
    if (account->balance >= amount) {
      account->balance -= amount;
    } else {
      printf("Insufficient funds.\n");
    }
  } else {
    printf("Account not found.\n");
  }
}

void printAccount(char *name) {
  Account *account = findAccount(name);
  if (account != NULL) {
    printf("%s: %.2f\n", account->name, account->balance);
  } else {
    printf("Account not found.\n");
  }
}

void printAllAccounts() {
  Account *current = accounts;
  while (current != NULL) {
    printf("%s: %.2f\n", current->name, current->balance);
    current = current->next;
  }
}

int main() {
    // Initialize the system with test data
    createAccount("John Doe", 1000.0);
    createAccount("Jane Smith", 2000.0);
    createAccount("Peter Johnson", 3000.0);

    // Immersive Banking Operations
    printf("Welcome to the Immersive Banking System!\n");

    // Deposit funds into John Doe's account
    printf("John Doe deposits $500.\n");
    deposit("John Doe", 500.0);

    // Withdraw funds from Jane Smith's account
    printf("Jane Smith withdraws $300.\n");
    withdraw("Jane Smith", 300.0);

    // Print the updated account balances
    printf("Current account balances:\n");
    printAllAccounts();

    // Transfer funds from Peter Johnson to Jane Smith
    printf("Peter Johnson transfers $200 to Jane Smith.\n");
    withdraw("Peter Johnson", 200.0);
    deposit("Jane Smith", 200.0);

    return 0;
}