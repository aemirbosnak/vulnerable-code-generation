//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *type;
    float amount;
} Transaction;

typedef struct {
    char *name;
    float balance;
    Transaction *transactions;
    int num_transactions;
} Account;

Account *accounts;
int num_accounts;

void add_account(char *name) {
    accounts = realloc(accounts, sizeof(Account) * (num_accounts + 1));
    accounts[num_accounts].name = strdup(name);
    accounts[num_accounts].balance = 0.0;
    accounts[num_accounts].transactions = NULL;
    accounts[num_accounts].num_transactions = 0;
    num_accounts++;
}

void add_transaction(char *account_name, char *type, float amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, account_name) == 0) {
            accounts[i].transactions = realloc(accounts[i].transactions, sizeof(Transaction) * (accounts[i].num_transactions + 1));
            accounts[i].transactions[accounts[i].num_transactions].name = strdup(type);
            accounts[i].transactions[accounts[i].num_transactions].amount = amount;
            accounts[i].num_transactions++;
            accounts[i].balance += amount;
            break;
        }
    }
}

void print_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("%s:", accounts[i].name);
        printf("\tBalance: %.2f\n", accounts[i].balance);
        for (int j = 0; j < accounts[i].num_transactions; j++) {
            printf("\t%s: %.2f\n", accounts[i].transactions[j].name, accounts[i].transactions[j].amount);
        }
    }
}

void free_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        free(accounts[i].name);
        for (int j = 0; j < accounts[i].num_transactions; j++) {
            free(accounts[i].transactions[j].name);
        }
        free(accounts[i].transactions);
    }
    free(accounts);
}

int main() {
    // Add some accounts
    add_account("Checking");
    add_account("Savings");

    // Add some transactions
    add_transaction("Checking", "Deposit", 100.0);
    add_transaction("Checking", "Withdrawal", 50.0);
    add_transaction("Savings", "Deposit", 200.0);

    // Print the accounts
    print_accounts();

    // Free the accounts
    free_accounts();

    return 0;
}