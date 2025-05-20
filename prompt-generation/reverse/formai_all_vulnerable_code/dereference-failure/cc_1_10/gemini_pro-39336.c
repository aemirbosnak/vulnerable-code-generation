//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    double balance;
} Account;

typedef struct {
    char *name;
    double amount;
    char *date;
} Transaction;

// Function prototypes
Account *create_account(char *name, double balance);
Transaction *create_transaction(char *name, double amount, char *date);
void print_account(Account *account);
void print_transaction(Transaction *transaction);
void add_transaction(Account *account, Transaction *transaction);
double get_balance(Account *account);

// Main function
int main() {
    // Create some accounts
    Account *checking = create_account("Checking", 1000.00);
    Account *savings = create_account("Savings", 2000.00);

    // Create some transactions
    Transaction *deposit = create_transaction("Deposit", 500.00, "2023-03-08");
    Transaction *withdrawal = create_transaction("Withdrawal", 200.00, "2023-03-10");

    // Add transactions to accounts
    add_transaction(checking, deposit);
    add_transaction(checking, withdrawal);

    // Print account balances
    printf("Checking balance: $%.2f\n", get_balance(checking));
    printf("Savings balance: $%.2f\n", get_balance(savings));

    // Free memory
    free(checking->name);
    free(checking);
    free(savings->name);
    free(savings);
    free(deposit->name);
    free(deposit->date);
    free(deposit);
    free(withdrawal->name);
    free(withdrawal->date);
    free(withdrawal);

    return 0;
}

// Function definitions
Account *create_account(char *name, double balance) {
    Account *account = malloc(sizeof(Account));
    account->name = malloc(strlen(name) + 1);
    strcpy(account->name, name);
    account->balance = balance;
    return account;
}

Transaction *create_transaction(char *name, double amount, char *date) {
    Transaction *transaction = malloc(sizeof(Transaction));
    transaction->name = malloc(strlen(name) + 1);
    strcpy(transaction->name, name);
    transaction->amount = amount;
    transaction->date = malloc(strlen(date) + 1);
    strcpy(transaction->date, date);
    return transaction;
}

void print_account(Account *account) {
    printf("Account: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
}

void print_transaction(Transaction *transaction) {
    printf("Transaction: %s\n", transaction->name);
    printf("Amount: $%.2f\n", transaction->amount);
    printf("Date: %s\n", transaction->date);
}

void add_transaction(Account *account, Transaction *transaction) {
    if (strcmp(transaction->name, "Deposit") == 0) {
        account->balance += transaction->amount;
    } else if (strcmp(transaction->name, "Withdrawal") == 0) {
        account->balance -= transaction->amount;
    }
}

double get_balance(Account *account) {
    return account->balance;
}