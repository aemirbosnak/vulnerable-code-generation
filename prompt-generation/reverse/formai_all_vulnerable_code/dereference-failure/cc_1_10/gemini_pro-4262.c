//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct {
    char name[50];
    int account_number;
    double balance;
} account;

// Define the transaction structure
typedef struct {
    int account_number;
    double amount;
    char type; // 'D' for deposit, 'W' for withdrawal
} transaction;

// Define the banking record system structure
typedef struct {
    account accounts[MAX_ACCOUNTS];
    transaction transactions[MAX_TRANSACTIONS];
    int num_accounts;
    int num_transactions;
} banking_record_system;

// Create a new banking record system
banking_record_system* create_banking_record_system() {
    banking_record_system* system = (banking_record_system*) malloc(sizeof(banking_record_system));
    system->num_accounts = 0;
    system->num_transactions = 0;
    return system;
}

// Add an account to the banking record system
void add_account(banking_record_system* system, char* name, int account_number, double balance) {
    account new_account;
    strcpy(new_account.name, name);
    new_account.account_number = account_number;
    new_account.balance = balance;
    system->accounts[system->num_accounts] = new_account;
    system->num_accounts++;
}

// Add a transaction to the banking record system
void add_transaction(banking_record_system* system, int account_number, double amount, char type) {
    transaction new_transaction;
    new_transaction.account_number = account_number;
    new_transaction.amount = amount;
    new_transaction.type = type;
    system->transactions[system->num_transactions] = new_transaction;
    system->num_transactions++;
}

// Print the banking record system
void print_banking_record_system(banking_record_system* system) {
    printf("Banking Record System\n");
    printf("---------------------\n");
    printf("Accounts:\n");
    for (int i = 0; i < system->num_accounts; i++) {
        account account = system->accounts[i];
        printf("  %s (%d): $%.2f\n", account.name, account.account_number, account.balance);
    }
    printf("Transactions:\n");
    for (int i = 0; i < system->num_transactions; i++) {
        transaction transaction = system->transactions[i];
        printf("  %d: $%.2f (%c)\n", transaction.account_number, transaction.amount, transaction.type);
    }
}

// Free the memory allocated for the banking record system
void free_banking_record_system(banking_record_system* system) {
    free(system);
}

// Main function
int main() {
    // Create a new banking record system
    banking_record_system* system = create_banking_record_system();

    // Add some accounts to the banking record system
    add_account(system, "Ada Lovelace", 123456789, 1000.00);
    add_account(system, "Charles Babbage", 987654321, 500.00);

    // Add some transactions to the banking record system
    add_transaction(system, 123456789, 100.00, 'D');
    add_transaction(system, 123456789, 50.00, 'W');
    add_transaction(system, 987654321, 250.00, 'D');

    // Print the banking record system
    print_banking_record_system(system);

    // Free the memory allocated for the banking record system
    free_banking_record_system(system);

    return 0;
}