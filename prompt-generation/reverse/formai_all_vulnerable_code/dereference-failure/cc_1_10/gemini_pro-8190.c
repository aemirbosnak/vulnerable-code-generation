//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// What's this? A Personal Finance Planner? In C? You don't say!

// Let's define some data structures to keep track of our finances
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

// And a function to print our finances in a nice and tidy format
void print_finances(Account *accounts, int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        printf("%s:\n", accounts[i].name);
        printf("  Balance: $%.2f\n", accounts[i].balance);
        for (int j = 0; j < accounts[i].num_transactions; j++) {
            printf("  %s: $%.2f\n", accounts[i].transactions[j].name, accounts[i].transactions[j].amount);
        }
    }
}

// And now, the main event!
int main() {
    // Let's create some accounts
    Account checking = {"Checking", 1000.00};
    Account savings = {"Savings", 500.00};
    Account credit_card = {"Credit Card", -100.00};
    Account *accounts[] = {&checking, &savings, &credit_card};
    const int num_accounts = sizeof(accounts) / sizeof(Account *);

    // Let's add some transactions
    Transaction groceries = {"Groceries", -50.00};
    Transaction gas = {"Gas", -20.00};
    Transaction paycheck = {"Paycheck", 2000.00};
    checking.transactions = malloc(3 * sizeof(Transaction));
    checking.transactions[0] = groceries;
    checking.transactions[1] = gas;
    checking.transactions[2] = paycheck;
    checking.num_transactions = 3;

    savings.transactions = malloc(1 * sizeof(Transaction));
    savings.transactions[0] = paycheck;
    savings.num_transactions = 1;

    credit_card.transactions = malloc(1 * sizeof(Transaction));
    credit_card.transactions[0] = groceries;
    credit_card.num_transactions = 1;

    // And finally, let's print our finances
    print_finances(accounts, num_accounts);

    // Clean up our memory
    for (int i = 0; i < num_accounts; i++) {
        free(accounts[i]->name);
        free(accounts[i]->transactions);
    }

    return 0;
}