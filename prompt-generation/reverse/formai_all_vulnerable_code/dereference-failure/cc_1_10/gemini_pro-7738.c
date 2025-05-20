//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ACCOUNTS 100
#define MAX_ACCOUNT_NUMBER_LENGTH 10
#define MAX_ACCOUNT_HOLDER_NAME_LENGTH 50
#define MAX_ACCOUNT_BALANCE 1000000

// Account structure
typedef struct Account {
  char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH + 1];
  char accountHolderName[MAX_ACCOUNT_HOLDER_NAME_LENGTH + 1];
  double accountBalance;
} Account;

// Function to create a new account
Account* createAccount(char* accountNumber, char* accountHolderName, double accountBalance) {
  Account* account = (Account*)malloc(sizeof(Account));
  strcpy(account->accountNumber, accountNumber);
  strcpy(account->accountHolderName, accountHolderName);
  account->accountBalance = accountBalance;
  return account;
}

// Function to deposit money into an account
void depositMoney(Account* account, double amount) {
  account->accountBalance += amount;
}

// Function to withdraw money from an account
void withdrawMoney(Account* account, double amount) {
  if (amount <= account->accountBalance) {
    account->accountBalance -= amount;
  } else {
    printf("Insufficient funds\n");
  }
}

// Function to print account details
void printAccountDetails(Account* account) {
  printf("Account Number: %s\n", account->accountNumber);
  printf("Account Holder Name: %s\n", account->accountHolderName);
  printf("Account Balance: %f\n", account->accountBalance);
}

// Main function
int main() {
  // Create an array of accounts
  Account* accounts[MAX_ACCOUNTS];

  // Initialize the array of accounts to NULL
  for (int i = 0; i < MAX_ACCOUNTS; i++) {
    accounts[i] = NULL;
  }

  // Create a new account
  Account* account1 = createAccount("1234567890", "John Doe", 1000.00);

  // Deposit money into the account
  depositMoney(account1, 500.00);

  // Withdraw money from the account
  withdrawMoney(account1, 300.00);

  // Print account details
  printAccountDetails(account1);

  return 0;
}