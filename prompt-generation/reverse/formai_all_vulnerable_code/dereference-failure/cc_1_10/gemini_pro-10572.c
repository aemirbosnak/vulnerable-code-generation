//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double balance;
} account;

typedef struct {
    char *name;
    double amount;
    char *date;
} transaction;

account *accounts = NULL;
int num_accounts = 0;

transaction *transactions = NULL;
int num_transactions = 0;

void add_account(char *name, double balance) {
    accounts = realloc(accounts, (num_accounts + 1) * sizeof(account));
    accounts[num_accounts].name = strdup(name);
    accounts[num_accounts].balance = balance;
    num_accounts++;
}

void add_transaction(char *name, double amount, char *date) {
    transactions = realloc(transactions, (num_transactions + 1) * sizeof(transaction));
    transactions[num_transactions].name = strdup(name);
    transactions[num_transactions].amount = amount;
    transactions[num_transactions].date = strdup(date);
    num_transactions++;
}

void print_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: $%.2f\n", accounts[i].name, accounts[i].balance);
    }
}

void print_transactions() {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: $%.2f (%s)\n", transactions[i].name, transactions[i].amount, transactions[i].date);
    }
}

int main() {
    add_account("Checking", 1000.00);
    add_account("Savings", 2000.00);

    add_transaction("Checking", -50.00, "2023-01-01");
    add_transaction("Savings", 100.00, "2023-01-02");

    print_accounts();
    printf("\n");
    print_transactions();

    return 0;
}