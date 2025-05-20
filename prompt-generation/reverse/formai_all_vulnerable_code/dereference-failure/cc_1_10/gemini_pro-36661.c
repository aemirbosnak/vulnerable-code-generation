//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    double balance;
    double interest_rate;
} account_t;

typedef struct {
    char *name;
    double amount;
    char *description;
} transaction_t;

// Function prototypes
account_t *create_account(char *name, double balance, double interest_rate);
void delete_account(account_t *account);
transaction_t *create_transaction(char *name, double amount, char *description);
void delete_transaction(transaction_t *transaction);
void print_account(account_t *account);
void print_transaction(transaction_t *transaction);

// Main function
int main() {
    // Create a new account
    account_t *account = create_account("My Account", 1000.00, 0.05);

    // Add a few transactions
    transaction_t *transaction1 = create_transaction("Deposit", 500.00, "Paycheck");
    transaction_t *transaction2 = create_transaction("Withdrawal", 200.00, "Rent");

    // Print the account and transaction information
    print_account(account);
    print_transaction(transaction1);
    print_transaction(transaction2);

    // Delete the account and transactions
    delete_account(account);
    delete_transaction(transaction1);
    delete_transaction(transaction2);

    return 0;
}

// Function definitions
account_t *create_account(char *name, double balance, double interest_rate) {
    account_t *account = malloc(sizeof(account_t));
    account->name = strdup(name);
    account->balance = balance;
    account->interest_rate = interest_rate;
    return account;
}

void delete_account(account_t *account) {
    free(account->name);
    free(account);
}

transaction_t *create_transaction(char *name, double amount, char *description) {
    transaction_t *transaction = malloc(sizeof(transaction_t));
    transaction->name = strdup(name);
    transaction->amount = amount;
    transaction->description = strdup(description);
    return transaction;
}

void delete_transaction(transaction_t *transaction) {
    free(transaction->name);
    free(transaction->description);
    free(transaction);
}

void print_account(account_t *account) {
    printf("Account: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
    printf("Interest Rate: %.2f%%\n", account->interest_rate * 100);
}

void print_transaction(transaction_t *transaction) {
    printf("Transaction: %s\n", transaction->name);
    printf("Amount: $%.2f\n", transaction->amount);
    printf("Description: %s\n", transaction->description);
}