//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct {
    int account_number;
    char *name;
    double balance;
} account;

// Define the transaction structure
typedef struct {
    int transaction_id;
    int account_number;
    char *type;
    double amount;
} transaction;

// Create an array of accounts
account accounts[MAX_ACCOUNTS];

// Create an array of transactions
transaction transactions[MAX_TRANSACTIONS];

// Initialize the number of accounts and transactions
int num_accounts = 0;
int num_transactions = 0;

// Get the account by account number
account *get_account(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            return &accounts[i];
        }
    }

    return NULL;
}

// Add a new account
void add_account(int account_number, char *name, double balance) {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    accounts[num_accounts].account_number = account_number;
    accounts[num_accounts].name = strdup(name);
    accounts[num_accounts].balance = balance;

    num_accounts++;
}

// Add a new transaction
void add_transaction(int transaction_id, int account_number, char *type, double amount) {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    transactions[num_transactions].transaction_id = transaction_id;
    transactions[num_transactions].account_number = account_number;
    transactions[num_transactions].type = strdup(type);
    transactions[num_transactions].amount = amount;

    num_transactions++;
}

// Print the details of all accounts
void print_accounts() {
    printf("Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("    %d %s %f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

// Print the details of all transactions
void print_transactions() {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("    %d %d %s %f\n", transactions[i].transaction_id, transactions[i].account_number, transactions[i].type, transactions[i].amount);
    }
}

// Main function
int main() {
    // Add some sample accounts
    add_account(123456, "John Doe", 1000.00);
    add_account(654321, "Jane Doe", 2000.00);

    // Add some sample transactions
    add_transaction(1, 123456, "Deposit", 500.00);
    add_transaction(2, 654321, "Withdrawal", 300.00);

    // Print the details of all accounts
    print_accounts();

    // Print the details of all transactions
    print_transactions();

    return 0;
}