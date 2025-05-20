//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    double amount;
} transaction_t;

typedef struct {
    char *name;
    double balance;
    transaction_t *transactions;
    int num_transactions;
} account_t;

// Functions
void add_transaction(account_t *account, transaction_t transaction) {
    account->transactions = realloc(account->transactions, sizeof(transaction_t) * (account->num_transactions + 1));
    account->transactions[account->num_transactions] = transaction;
    account->num_transactions++;
    account->balance += transaction.amount;
}

void print_account(account_t account) {
    printf("Account: %s\n", account.name);
    printf("Balance: %f\n", account.balance);
    for (int i = 0; i < account.num_transactions; i++) {
        printf("  %s %f\n", account.transactions[i].name, account.transactions[i].amount);
    }
}

int main() {
    // Create accounts
    account_t checking_account = {"Checking", 0.0, NULL, 0};
    account_t savings_account = {"Savings", 0.0, NULL, 0};

    // Add transactions
    transaction_t transaction1 = {"Deposit", 100.0};
    add_transaction(&checking_account, transaction1);

    transaction_t transaction2 = {"Withdrawal", 50.0};
    add_transaction(&checking_account, transaction2);

    transaction_t transaction3 = {"Transfer", -25.0};
    add_transaction(&checking_account, transaction3);

    transaction_t transaction4 = {"Interest", 10.0};
    add_transaction(&savings_account, transaction4);

    // Print accounts
    print_account(checking_account);
    print_account(savings_account);

    return 0;
}