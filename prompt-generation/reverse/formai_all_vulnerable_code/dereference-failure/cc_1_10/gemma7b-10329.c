//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ACCOUNT_NUMBER_LENGTH 10
#define MAX_TRANSACTION_AMOUNT 1000

typedef struct Account {
    char name[MAX_NAME_LENGTH];
    int account_number;
    double balance;
} Account;

typedef struct Transaction {
    char description[MAX_NAME_LENGTH];
    double amount;
    struct Account *account;
} Transaction;

Account *create_account(char *name, int account_number, double balance) {
    Account *account = malloc(sizeof(Account));
    strcpy(account->name, name);
    account->account_number = account_number;
    account->balance = balance;
    return account;
}

Transaction *create_transaction(char *description, double amount, Account *account) {
    Transaction *transaction = malloc(sizeof(Transaction));
    strcpy(transaction->description, description);
    transaction->amount = amount;
    transaction->account = account;
    return transaction;
}

void print_account(Account *account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Balance: %.2lf\n", account->balance);
}

void print_transaction(Transaction *transaction) {
    printf("Description: %s\n", transaction->description);
    printf("Amount: %.2lf\n", transaction->amount);
    print_account(transaction->account);
}

int main() {
    Account *account = create_account("John Doe", 123456, 1000.0);
    Transaction *transaction = create_transaction("Buy groceries", 200.0, account);

    print_account(account);
    print_transaction(transaction);

    free(account);
    free(transaction);

    return 0;
}