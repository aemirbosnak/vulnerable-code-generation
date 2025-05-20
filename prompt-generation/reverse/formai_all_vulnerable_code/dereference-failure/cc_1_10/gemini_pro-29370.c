//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Account types
enum AccountType {
  CHECKING,
  SAVINGS,
  INVESTMENT
};

// Transaction types
enum TransactionType {
  DEPOSIT,
  WITHDRAWAL,
  TRANSFER
};

// Account struct
typedef struct Account {
  char *name;
  enum AccountType type;
  double balance;
} Account;

// Transaction struct
typedef struct Transaction {
  enum TransactionType type;
  double amount;
  char *description;
} Transaction;

// Create a new account
Account *create_account(char *name, enum AccountType type, double balance) {
  Account *account = malloc(sizeof(Account));
  account->name = name;
  account->type = type;
  account->balance = balance;
  return account;
}

// Create a new transaction
Transaction *create_transaction(enum TransactionType type, double amount, char *description) {
  Transaction *transaction = malloc(sizeof(Transaction));
  transaction->type = type;
  transaction->amount = amount;
  transaction->description = description;
  return transaction;
}

// Deposit money into an account
void deposit(Account *account, double amount) {
  account->balance += amount;
}

// Withdraw money from an account
void withdraw(Account *account, double amount) {
  if (account->balance >= amount) {
    account->balance -= amount;
  }
}

// Transfer money between accounts
void transfer(Account *from_account, Account *to_account, double amount) {
  if (from_account->balance >= amount) {
    from_account->balance -= amount;
    to_account->balance += amount;
  }
}

// Print account information
void print_account(Account *account) {
  printf("Account: %s\n", account->name);
  printf("Type: ");
  switch (account->type) {
    case CHECKING:
      printf("Checking\n");
      break;
    case SAVINGS:
      printf("Savings\n");
      break;
    case INVESTMENT:
      printf("Investment\n");
      break;
  }
  printf("Balance: %.2f\n", account->balance);
}

// Print transaction information
void print_transaction(Transaction *transaction) {
  printf("Transaction: ");
  switch (transaction->type) {
    case DEPOSIT:
      printf("Deposit\n");
      break;
    case WITHDRAWAL:
      printf("Withdrawal\n");
      break;
    case TRANSFER:
      printf("Transfer\n");
      break;
  }
  printf("Amount: %.2f\n", transaction->amount);
  printf("Description: %s\n", transaction->description);
}

int main() {
  // Create some accounts
  Account *checking_account = create_account("Checking Account", CHECKING, 1000.00);
  Account *savings_account = create_account("Savings Account", SAVINGS, 2000.00);
  Account *investment_account = create_account("Investment Account", INVESTMENT, 5000.00);

  // Create some transactions
  Transaction *deposit_transaction = create_transaction(DEPOSIT, 500.00, "Deposit from paycheck");
  Transaction *withdrawal_transaction = create_transaction(WITHDRAWAL, 200.00, "Withdrawal for groceries");
  Transaction *transfer_transaction = create_transaction(TRANSFER, 1000.00, "Transfer to investment account");

  // Deposit money into checking account
  deposit(checking_account, deposit_transaction->amount);

  // Withdraw money from checking account
  withdraw(checking_account, withdrawal_transaction->amount);

  // Transfer money from checking account to investment account
  transfer(checking_account, investment_account, transfer_transaction->amount);

  // Print account information
  printf("Checking Account:\n");
  print_account(checking_account);
  printf("\n");

  printf("Savings Account:\n");
  print_account(savings_account);
  printf("\n");

  printf("Investment Account:\n");
  print_account(investment_account);
  printf("\n");

  // Print transaction information
  printf("Deposit Transaction:\n");
  print_transaction(deposit_transaction);
  printf("\n");

  printf("Withdrawal Transaction:\n");
  print_transaction(withdrawal_transaction);
  printf("\n");

  printf("Transfer Transaction:\n");
  print_transaction(transfer_transaction);
  printf("\n");

  return 0;
}