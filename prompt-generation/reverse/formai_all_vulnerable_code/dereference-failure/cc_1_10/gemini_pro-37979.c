//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct account {
    int account_number;
    char name[50];
    double balance;
} account_t;

// Define the transaction structure
typedef struct transaction {
    int transaction_id;
    int account_number;
    double amount;
    char type; // 'D' for deposit, 'W' for withdrawal
} transaction_t;

// Define the bank structure
typedef struct bank {
    account_t accounts[MAX_ACCOUNTS];
    int num_accounts;
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_transactions;
} bank_t;

// Create a new bank
bank_t *create_bank() {
    bank_t *bank = malloc(sizeof(bank_t));
    bank->num_accounts = 0;
    bank->num_transactions = 0;
    return bank;
}

// Add a new account to the bank
void add_account(bank_t *bank, int account_number, char *name, double balance) {
    account_t *account = &bank->accounts[bank->num_accounts++];
    account->account_number = account_number;
    strcpy(account->name, name);
    account->balance = balance;
}

// Add a new transaction to the bank
void add_transaction(bank_t *bank, int transaction_id, int account_number, double amount, char type) {
    transaction_t *transaction = &bank->transactions[bank->num_transactions++];
    transaction->transaction_id = transaction_id;
    transaction->account_number = account_number;
    transaction->amount = amount;
    transaction->type = type;
}

// Process a deposit transaction
void process_deposit(bank_t *bank, int account_number, double amount) {
    account_t *account = &bank->accounts[account_number];
    account->balance += amount;
}

// Process a withdrawal transaction
void process_withdrawal(bank_t *bank, int account_number, double amount) {
    account_t *account = &bank->accounts[account_number];
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Print the bank statement
void print_statement(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        account_t *account = &bank->accounts[i];
        printf("Account %d: %s, Balance: %f\n", account->account_number, account->name, account->balance);
    }
}

// Main function
int main() {
    // Create a new bank
    bank_t *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 1, "John Doe", 1000.0);
    add_account(bank, 2, "Jane Doe", 2000.0);

    // Add some transactions to the bank
    add_transaction(bank, 1, 1, 500.0, 'D');
    add_transaction(bank, 2, 2, 1000.0, 'W');

    // Process the transactions
    process_deposit(bank, 1, 500.0);
    process_withdrawal(bank, 2, 1000.0);

    // Print the bank statement
    print_statement(bank);

    return 0;
}