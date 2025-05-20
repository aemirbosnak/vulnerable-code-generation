//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double amount;
} Transaction;

typedef struct {
    char *name;
    double balance;
    Transaction *transactions;
    int num_transactions;
} Account;

typedef struct {
    Account *accounts;
    int num_accounts;
} Budget;

void print_budget(Budget *budget) {
    for (int i = 0; i < budget->num_accounts; i++) {
        printf("%s: $%.2f\n", budget->accounts[i].name, budget->accounts[i].balance);
    }
}

void add_account(Budget *budget, char *name) {
    Account new_account = {
        .name = name,
        .balance = 0.0,
        .transactions = NULL,
        .num_transactions = 0,
    };
    budget->accounts = realloc(budget->accounts, (budget->num_accounts + 1) * sizeof(Account));
    budget->accounts[budget->num_accounts++] = new_account;
}

void add_transaction(Account *account, char *name, double amount) {
    Transaction new_transaction = {
        .name = name,
        .amount = amount,
    };
    account->transactions = realloc(account->transactions, (account->num_transactions + 1) * sizeof(Transaction));
    account->transactions[account->num_transactions++] = new_transaction;
    account->balance += amount;
}

int main() {
    Budget budget = {
        .accounts = NULL,
        .num_accounts = 0,
    };
    add_account(&budget, "Checking");
    add_account(&budget, "Savings");
    add_transaction(&budget.accounts[0], "Deposit", 1000.0);
    add_transaction(&budget.accounts[0], "Withdrawal", 500.0);
    add_transaction(&budget.accounts[1], "Interest", 20.0);
    print_budget(&budget);
    return 0;
}