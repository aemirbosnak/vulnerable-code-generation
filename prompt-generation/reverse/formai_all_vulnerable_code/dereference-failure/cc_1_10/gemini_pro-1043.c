//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct account {
    char name[50];
    int account_number;
    double balance;
} account_t;

// Define the transaction structure
typedef struct transaction {
    int account_number;
    double amount;
    char type[50];
} transaction_t;

// Define the banking record system structure
typedef struct banking_record_system {
    account_t accounts[MAX_ACCOUNTS];
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_accounts;
    int num_transactions;
} banking_record_system_t;

// Create a new banking record system
banking_record_system_t* create_banking_record_system() {
    banking_record_system_t* system = (banking_record_system_t*)malloc(sizeof(banking_record_system_t));
    system->num_accounts = 0;
    system->num_transactions = 0;
    return system;
}

// Add an account to the banking record system
void add_account(banking_record_system_t* system, account_t account) {
    system->accounts[system->num_accounts] = account;
    system->num_accounts++;
}

// Add a transaction to the banking record system
void add_transaction(banking_record_system_t* system, transaction_t transaction) {
    system->transactions[system->num_transactions] = transaction;
    system->num_transactions++;
}

// Get the account balance for a given account number
double get_account_balance(banking_record_system_t* system, int account_number) {
    for (int i = 0; i < system->num_accounts; i++) {
        if (system->accounts[i].account_number == account_number) {
            return system->accounts[i].balance;
        }
    }
    return -1;
}

// Print the banking record system
void print_banking_record_system(banking_record_system_t* system) {
    printf("Accounts:\n");
    for (int i = 0; i < system->num_accounts; i++) {
        printf("  %s (%d): %.2f\n", system->accounts[i].name, system->accounts[i].account_number, system->accounts[i].balance);
    }
    printf("Transactions:\n");
    for (int i = 0; i < system->num_transactions; i++) {
        printf("  %d: %.2f (%s)\n", system->transactions[i].account_number, system->transactions[i].amount, system->transactions[i].type);
    }
}

// Free the memory allocated for the banking record system
void free_banking_record_system(banking_record_system_t* system) {
    free(system);
}

// Main function
int main() {
    // Create a new banking record system
    banking_record_system_t* system = create_banking_record_system();

    // Add some accounts to the system
    account_t account1 = {"John Doe", 123456789, 1000.00};
    add_account(system, account1);
    account_t account2 = {"Jane Doe", 987654321, 500.00};
    add_account(system, account2);

    // Add some transactions to the system
    transaction_t transaction1 = {123456789, 100.00, "Deposit"};
    add_transaction(system, transaction1);
    transaction_t transaction2 = {987654321, 50.00, "Withdrawal"};
    add_transaction(system, transaction2);

    // Print the banking record system
    print_banking_record_system(system);

    // Free the memory allocated for the banking record system
    free_banking_record_system(system);

    return 0;
}