//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
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
} account_t;

// Define the transaction structure
typedef struct {
    int account_number;
    double amount;
    char *type;
} transaction_t;

// Define the banking record system structure
typedef struct {
    account_t accounts[MAX_ACCOUNTS];
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_accounts;
    int num_transactions;
} banking_record_system_t;

// Create a new banking record system
banking_record_system_t *create_banking_record_system() {
    banking_record_system_t *brs = malloc(sizeof(banking_record_system_t));
    brs->num_accounts = 0;
    brs->num_transactions = 0;
    return brs;
}

// Add an account to the banking record system
void add_account(banking_record_system_t *brs, int account_number, char *name, double balance) {
    brs->accounts[brs->num_accounts].account_number = account_number;
    brs->accounts[brs->num_accounts].name = strdup(name);
    brs->accounts[brs->num_accounts].balance = balance;
    brs->num_accounts++;
}

// Add a transaction to the banking record system
void add_transaction(banking_record_system_t *brs, int account_number, double amount, char *type) {
    brs->transactions[brs->num_transactions].account_number = account_number;
    brs->transactions[brs->num_transactions].amount = amount;
    brs->transactions[brs->num_transactions].type = strdup(type);
    brs->num_transactions++;
}

// Print the banking record system
void print_banking_record_system(banking_record_system_t *brs) {
    for (int i = 0; i < brs->num_accounts; i++) {
        printf("Account %d:\n", brs->accounts[i].account_number);
        printf("  Name: %s\n", brs->accounts[i].name);
        printf("  Balance: %.2f\n", brs->accounts[i].balance);
    }

    for (int i = 0; i < brs->num_transactions; i++) {
        printf("Transaction %d:\n", i);
        printf("  Account number: %d\n", brs->transactions[i].account_number);
        printf("  Amount: %.2f\n", brs->transactions[i].amount);
        printf("  Type: %s\n", brs->transactions[i].type);
    }
}

// Free the memory allocated for the banking record system
void free_banking_record_system(banking_record_system_t *brs) {
    for (int i = 0; i < brs->num_accounts; i++) {
        free(brs->accounts[i].name);
    }

    for (int i = 0; i < brs->num_transactions; i++) {
        free(brs->transactions[i].type);
    }

    free(brs);
}

// Main function
int main() {
    // Create a new banking record system
    banking_record_system_t *brs = create_banking_record_system();

    // Add some accounts to the banking record system
    add_account(brs, 123456, "John Smith", 1000.00);
    add_account(brs, 654321, "Jane Doe", 2000.00);

    // Add some transactions to the banking record system
    add_transaction(brs, 123456, 100.00, "deposit");
    add_transaction(brs, 654321, 200.00, "deposit");
    add_transaction(brs, 123456, 50.00, "withdrawal");
    add_transaction(brs, 654321, 100.00, "withdrawal");

    // Print the banking record system
    print_banking_record_system(brs);

    // Free the memory allocated for the banking record system
    free_banking_record_system(brs);

    return 0;
}