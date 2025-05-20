//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Data structures
typedef struct {
    char *name;
    double balance;
} Account;

typedef struct {
    char *name;
    double amount;
} Transaction;

// Function prototypes
void add_account(Account **accounts, int *num_accounts, char *name, double balance);
void add_transaction(Transaction **transactions, int *num_transactions, char *name, double amount);
void print_accounts(Account *accounts, int num_accounts);
void print_transactions(Transaction *transactions, int num_transactions);

int main() {
    // Initialize data structures
    Account *accounts = NULL;
    int num_accounts = 0;

    Transaction *transactions = NULL;
    int num_transactions = 0;

    // Add accounts
    add_account(&accounts, &num_accounts, "Checking", 1000.00);
    add_account(&accounts, &num_accounts, "Savings", 2000.00);

    // Add transactions
    add_transaction(&transactions, &num_transactions, "Checking", -50.00);
    add_transaction(&transactions, &num_transactions, "Savings", 100.00);

    // Print accounts
    printf("Accounts:\n");
    print_accounts(accounts, num_accounts);

    // Print transactions
    printf("Transactions:\n");
    print_transactions(transactions, num_transactions);

    // Free memory
    for (int i = 0; i < num_accounts; i++) {
        free(accounts[i].name);
    }
    free(accounts);

    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].name);
    }
    free(transactions);

    return 0;
}

void add_account(Account **accounts, int *num_accounts, char *name, double balance) {
    // Allocate memory for the new account
    *accounts = realloc(*accounts, (*num_accounts + 1) * sizeof(Account));

    // Initialize the new account
    (*accounts)[*num_accounts].name = strdup(name);
    (*accounts)[*num_accounts].balance = balance;

    // Increment the number of accounts
    (*num_accounts)++;
}

void add_transaction(Transaction **transactions, int *num_transactions, char *name, double amount) {
    // Allocate memory for the new transaction
    *transactions = realloc(*transactions, (*num_transactions + 1) * sizeof(Transaction));

    // Initialize the new transaction
    (*transactions)[*num_transactions].name = strdup(name);
    (*transactions)[*num_transactions].amount = amount;

    // Increment the number of transactions
    (*num_transactions)++;
}

void print_accounts(Account *accounts, int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: $%.2f\n", accounts[i].name, accounts[i].balance);
    }
}

void print_transactions(Transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: $%.2f\n", transactions[i].name, transactions[i].amount);
    }
}