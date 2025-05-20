//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double balance;
    char *notes;
} account_t;

typedef struct {
    char *name;
    double amount;
    char *notes;
} transaction_t;

void print_account(account_t *account) {
    printf("Name: %s\n", account->name);
    printf("Balance: %f\n", account->balance);
    printf("Notes: %s\n\n", account->notes);
}

void print_transaction(transaction_t *transaction) {
    printf("Name: %s\n", transaction->name);
    printf("Amount: %f\n", transaction->amount);
    printf("Notes: %s\n\n", transaction->notes);
}

int main() {
    account_t *accounts = malloc(sizeof(account_t) * 3);
    accounts[0].name = "Checking";
    accounts[0].balance = 1000.00;
    accounts[0].notes = "This is my primary checking account.";
    accounts[1].name = "Savings";
    accounts[1].balance = 5000.00;
    accounts[1].notes = "This is my savings account for emergencies.";
    accounts[2].name = "Investment";
    accounts[2].balance = 10000.00;
    accounts[2].notes = "This is my investment account for long-term growth.";

    transaction_t *transactions = malloc(sizeof(transaction_t) * 5);
    transactions[0].name = "Rent";
    transactions[0].amount = -1000.00;
    transactions[0].notes = "Monthly rent payment.";
    transactions[1].name = "Groceries";
    transactions[1].amount = -200.00;
    transactions[1].notes = "Weekly grocery shopping.";
    transactions[2].name = "Salary";
    transactions[2].amount = 3000.00;
    transactions[2].notes = "Monthly salary deposit.";
    transactions[3].name = "Transfer to Savings";
    transactions[3].amount = 500.00;
    transactions[3].notes = "Transfer to savings account for emergency fund.";
    transactions[4].name = "Investment Income";
    transactions[4].amount = 100.00;
    transactions[4].notes = "Monthly investment income.";

    // Print the initial state of the accounts and transactions.
    printf("Accounts:\n");
    for (int i = 0; i < 3; i++) {
        print_account(&accounts[i]);
    }
    printf("Transactions:\n");
    for (int i = 0; i < 5; i++) {
        print_transaction(&transactions[i]);
    }

    // Process the transactions.
    for (int i = 0; i < 5; i++) {
        account_t *account = NULL;
        for (int j = 0; j < 3; j++) {
            if (strcmp(transactions[i].name, accounts[j].name) == 0) {
                account = &accounts[j];
                break;
            }
        }
        if (account) {
            account->balance += transactions[i].amount;
        } else {
            printf("Error: No account found for transaction: %s\n", transactions[i].name);
        }
    }

    // Print the final state of the accounts.
    printf("Accounts:\n");
    for (int i = 0; i < 3; i++) {
        print_account(&accounts[i]);
    }

    // Free the memory allocated for the accounts and transactions.
    free(accounts);
    free(transactions);

    return 0;
}