//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the transaction structure
typedef struct {
    char description[50];
    float amount;
    char type[10]; // Income or Expense
} transaction;

// Define the account structure
typedef struct {
    float balance;
    transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} account;

// Create a new account
account* create_account() {
    account* acct = malloc(sizeof(account));
    acct->balance = 0.0;
    acct->num_transactions = 0;
    return acct;
}

// Add a transaction to an account
void add_transaction(account* acct, transaction trans) {
    if (acct->num_transactions < MAX_TRANSACTIONS) {
        acct->transactions[acct->num_transactions] = trans;
        acct->num_transactions++;
    } else {
        printf("Error: Too many transactions\n");
    }
}

// Print the account balance
void print_balance(account* acct) {
    printf("Account balance: $%.2f\n", acct->balance);
}

// Print the account transactions
void print_transactions(account* acct) {
    for (int i = 0; i < acct->num_transactions; i++) {
        printf("%s: $%.2f (%s)\n", acct->transactions[i].description, acct->transactions[i].amount, acct->transactions[i].type);
    }
}

// Main function
int main() {
    // Create a new account
    account* acct = create_account();

    // Add some transactions to the account
    transaction trans1 = {"Salary", 1000.0, "Income"};
    add_transaction(acct, trans1);
    transaction trans2 = {"Rent", -500.0, "Expense"};
    add_transaction(acct, trans2);
    transaction trans3 = {"Groceries", -100.0, "Expense"};
    add_transaction(acct, trans3);
    transaction trans4 = {"Savings", 200.0, "Income"};
    add_transaction(acct, trans4);

    // Print the account balance
    print_balance(acct);

    // Print the account transactions
    print_transactions(acct);

    // Free the account
    free(acct);

    return 0;
}