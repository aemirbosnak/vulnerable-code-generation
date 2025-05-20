//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double amount;
} transaction_t;

typedef struct {
    char *name;
    double balance;
    double income;
    double expenses;
    transaction_t *transactions;
    int num_transactions;
} account_t;

account_t *create_account(char *name) {
    account_t *account = malloc(sizeof(account_t));
    account->name = strdup(name);
    account->balance = 0.0;
    account->income = 0.0;
    account->expenses = 0.0;
    account->transactions = NULL;
    account->num_transactions = 0;
    return account;
}

void destroy_account(account_t *account) {
    free(account->name);
    free(account->transactions);
    free(account);
}

void add_transaction(account_t *account, char *name, double amount) {
    account->transactions = realloc(account->transactions, (account->num_transactions + 1) * sizeof(transaction_t));
    account->transactions[account->num_transactions].name = strdup(name);
    account->transactions[account->num_transactions].amount = amount;
    account->num_transactions++;
    account->balance += amount;
}

void print_account(account_t *account) {
    printf("Account: %s\n", account->name);
    printf("  Balance: $%.2f\n", account->balance);
    printf("  Income: $%.2f\n", account->income);
    printf("  Expenses: $%.2f\n", account->expenses);
    printf("  Transactions:\n");
    for (int i = 0; i < account->num_transactions; i++) {
        printf("    %s: $%.2f\n", account->transactions[i].name, account->transactions[i].amount);
    }
}

int main() {
    account_t *checking = create_account("Checking");
    add_transaction(checking, "Deposit", 1000.00);
    add_transaction(checking, "Withdrawal", 200.00);
    add_transaction(checking, "Interest", 10.00);

    account_t *savings = create_account("Savings");
    add_transaction(savings, "Deposit", 500.00);
    add_transaction(savings, "Interest", 5.00);

    print_account(checking);
    printf("\n");
    print_account(savings);

    destroy_account(checking);
    destroy_account(savings);

    return 0;
}