//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the maximum size of an account number
#define MAX_ACCOUNT_NUMBER_SIZE 10

// Define the maximum size of a customer name
#define MAX_CUSTOMER_NAME_SIZE 50

// Define the maximum size of a transaction amount
#define MAX_TRANSACTION_AMOUNT_SIZE 10

// Define the account structure
typedef struct account {
    char account_number[MAX_ACCOUNT_NUMBER_SIZE];
    char customer_name[MAX_CUSTOMER_NAME_SIZE];
    double balance;
} account;

// Define the transaction structure
typedef struct transaction {
    char account_number[MAX_ACCOUNT_NUMBER_SIZE];
    char transaction_type;
    double amount;
} transaction;

// Define the bank record system structure
typedef struct bank_record_system {
    account accounts[MAX_ACCOUNTS];
    transaction transactions[MAX_ACCOUNTS];
    int num_accounts;
    int num_transactions;
} bank_record_system;

// Create a new bank record system
bank_record_system* create_bank_record_system() {
    bank_record_system* brs = malloc(sizeof(bank_record_system));
    brs->num_accounts = 0;
    brs->num_transactions = 0;
    return brs;
}

// Add an account to the bank record system
void add_account(bank_record_system* brs, account* account) {
    brs->accounts[brs->num_accounts] = *account;
    brs->num_accounts++;
}

// Add a transaction to the bank record system
void add_transaction(bank_record_system* brs, transaction* transaction) {
    brs->transactions[brs->num_transactions] = *transaction;
    brs->num_transactions++;
}

// Get an account by account number
account* get_account_by_account_number(bank_record_system* brs, char* account_number) {
    for (int i = 0; i < brs->num_accounts; i++) {
        if (strcmp(brs->accounts[i].account_number, account_number) == 0) {
            return &brs->accounts[i];
        }
    }
    return NULL;
}

// Get a transaction by account number
transaction* get_transaction_by_account_number(bank_record_system* brs, char* account_number) {
    for (int i = 0; i < brs->num_transactions; i++) {
        if (strcmp(brs->transactions[i].account_number, account_number) == 0) {
            return &brs->transactions[i];
        }
    }
    return NULL;
}

// Print the bank record system
void print_bank_record_system(bank_record_system* brs) {
    printf("Accounts:\n");
    for (int i = 0; i < brs->num_accounts; i++) {
        printf("  %s %s %.2f\n", brs->accounts[i].account_number, brs->accounts[i].customer_name, brs->accounts[i].balance);
    }
    printf("Transactions:\n");
    for (int i = 0; i < brs->num_transactions; i++) {
        printf("  %s %c %.2f\n", brs->transactions[i].account_number, brs->transactions[i].transaction_type, brs->transactions[i].amount);
    }
}

// Free the bank record system
void free_bank_record_system(bank_record_system* brs) {
    free(brs);
}

// Main function
int main() {
    // Create a new bank record system
    bank_record_system* brs = create_bank_record_system();

    // Add some accounts to the bank record system
    account account1 = {"1234567890", "John Doe", 1000.00};
    add_account(brs, &account1);
    account account2 = {"0987654321", "Jane Doe", 2000.00};
    add_account(brs, &account2);

    // Add some transactions to the bank record system
    transaction transaction1 = {"1234567890", 'D', 100.00};
    add_transaction(brs, &transaction1);
    transaction transaction2 = {"0987654321", 'W', 200.00};
    add_transaction(brs, &transaction2);

    // Print the bank record system
    print_bank_record_system(brs);

    // Free the bank record system
    free_bank_record_system(brs);

    return 0;
}