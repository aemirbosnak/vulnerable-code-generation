//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct {
    int account_number;
    char name[50];
    double balance;
} account_t;

// Define the transaction structure
typedef struct {
    int account_number;
    char type[10];
    double amount;
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
    banking_record_system_t *brs = (banking_record_system_t *)malloc(sizeof(banking_record_system_t));
    brs->num_accounts = 0;
    brs->num_transactions = 0;
    return brs;
}

// Add a new account to the banking record system
void add_account(banking_record_system_t *brs, int account_number, char *name, double balance) {
    brs->accounts[brs->num_accounts].account_number = account_number;
    strcpy(brs->accounts[brs->num_accounts].name, name);
    brs->accounts[brs->num_accounts].balance = balance;
    brs->num_accounts++;
}

// Add a new transaction to the banking record system
void add_transaction(banking_record_system_t *brs, int account_number, char *type, double amount) {
    brs->transactions[brs->num_transactions].account_number = account_number;
    strcpy(brs->transactions[brs->num_transactions].type, type);
    brs->transactions[brs->num_transactions].amount = amount;
    brs->num_transactions++;
}

// Print the banking record system
void print_banking_record_system(banking_record_system_t *brs) {
    printf("Accounts:\n");
    for (int i = 0; i < brs->num_accounts; i++) {
        printf("%d %s %.2f\n", brs->accounts[i].account_number, brs->accounts[i].name, brs->accounts[i].balance);
    }

    printf("\nTransactions:\n");
    for (int i = 0; i < brs->num_transactions; i++) {
        printf("%d %s %.2f\n", brs->transactions[i].account_number, brs->transactions[i].type, brs->transactions[i].amount);
    }
}

// Destroy the banking record system
void destroy_banking_record_system(banking_record_system_t *brs) {
    free(brs);
}

// Main function
int main() {
    // Create a new banking record system
    banking_record_system_t *brs = create_banking_record_system();

    // Add some accounts to the banking record system
    add_account(brs, 12345, "John Doe", 1000.00);
    add_account(brs, 54321, "Jane Doe", 2000.00);

    // Add some transactions to the banking record system
    add_transaction(brs, 12345, "deposit", 500.00);
    add_transaction(brs, 12345, "withdrawal", 200.00);
    add_transaction(brs, 54321, "deposit", 1000.00);
    add_transaction(brs, 54321, "withdrawal", 500.00);

    // Print the banking record system
    print_banking_record_system(brs);

    // Destroy the banking record system
    destroy_banking_record_system(brs);

    return 0;
}