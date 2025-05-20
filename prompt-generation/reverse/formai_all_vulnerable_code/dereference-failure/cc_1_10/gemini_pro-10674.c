//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare account structure
typedef struct account {
  char name[50];
  int accountNumber;
  int balance;
} account;

// Declare bank structure
typedef struct bank {
  int numAccounts;
  account accounts[100];
} bank;

// Create a new bank
bank *createBank() {
  bank *newBank = (bank *)malloc(sizeof(bank));
  if (newBank == NULL) {
    printf("Error: Could not allocate memory for bank.\n");
    exit(1);
  }
  newBank->numAccounts = 0;
  return newBank;
}

// Add an account to the bank
void addAccount(bank *b, char *name, int accountNumber, int balance) {
  if (b->numAccounts >= 100) {
    printf("Error: The bank is full.\n");
    return;
  }
  strcpy(b->accounts[b->numAccounts].name, name);
  b->accounts[b->numAccounts].accountNumber = accountNumber;
  b->accounts[b->numAccounts].balance = balance;
  b->numAccounts++;
}

// Find an account by account number
account *findAccount(bank *b, int accountNumber) {
  for (int i = 0; i < b->numAccounts; i++) {
    if (b->accounts[i].accountNumber == accountNumber) {
      return &b->accounts[i];
    }
  }
  return NULL;
}

// Deposit money into an account
void depositMoney(bank *b, int accountNumber, int amount) {
  account *account = findAccount(b, accountNumber);
  if (account == NULL) {
    printf("Error: Account not found.\n");
    return;
  }
  account->balance += amount;
}

// Withdraw money from an account
void withdrawMoney(bank *b, int accountNumber, int amount) {
  account *account = findAccount(b, accountNumber);
  if (account == NULL) {
    printf("Error: Account not found.\n");
    return;
  }
  if (amount > account->balance) {
    printf("Error: Insufficient funds.\n");
    return;
  }
  account->balance -= amount;
}

// Print the details of all accounts in the bank
void printBankDetails(bank *b) {
  for (int i = 0; i < b->numAccounts; i++) {
    printf("Account %d: %s, %d, %d\n", i + 1, b->accounts[i].name, b->accounts[i].accountNumber, b->accounts[i].balance);
  }
}

// Main function
int main() {
  // Create a new bank
  bank *b = createBank();

  // Add some accounts to the bank
  addAccount(b, "Alice", 12345, 1000);
  addAccount(b, "Bob", 23456, 2000);
  addAccount(b, "Eve", 34567, 3000);

  // Print the details of all accounts in the bank
  printBankDetails(b);

  // Deposit money into an account
  depositMoney(b, 23456, 500);

  // Withdraw money from an account
  withdrawMoney(b, 34567, 1000);

  // Print the details of all accounts in the bank
  printBankDetails(b);

  return 0;
}