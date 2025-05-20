//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

// Define the account and transaction structures
typedef struct account {
    char name[50];
    double balance;
    int num_transactions;
    struct transaction *transactions;
} account;

typedef struct transaction {
    char description[100];
    double amount;
    int date;
} transaction;

// Function to create a new account
account *create_account(char *name) {
    account *new_account = malloc(sizeof(account));
    strcpy(new_account->name, name);
    new_account->balance = 0.0;
    new_account->num_transactions = 0;
    new_account->transactions = NULL;
    return new_account;
}

// Function to add a transaction to an account
void add_transaction(account *account, transaction *transaction) {
    // Reallocate the transactions array if necessary
    if (account->num_transactions >= MAX_TRANSACTIONS) {
        account->transactions = realloc(account->transactions, (account->num_transactions + 1) * sizeof(transaction));
    }
    // Add the transaction to the array
    account->transactions[account->num_transactions] = *transaction;
    account->num_transactions++;
}

// Function to print an account statement
void print_statement(account *account) {
    // Print the account name and balance
    printf("Account: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);

    // Print the transactions
    for (int i = 0; i < account->num_transactions; i++) {
        printf("  %s %.2f\n", account->transactions[i].description, account->transactions[i].amount);
    }
}

// Function to free the memory allocated for an account
void free_account(account *account) {
    free(account->transactions);
    free(account);
}

// Main function
int main() {
    // Create a new account
    account *my_account = create_account("My Account");

    // Add some transactions to the account
    transaction transaction1 = {"Deposit", 100.0, 20230101};
    add_transaction(my_account, &transaction1);
    transaction transaction2 = {"Withdrawal", 50.0, 20230105};
    add_transaction(my_account, &transaction2);

    // Print the account statement
    print_statement(my_account);

    // Free the memory allocated for the account
    free_account(my_account);

    return 0;
}