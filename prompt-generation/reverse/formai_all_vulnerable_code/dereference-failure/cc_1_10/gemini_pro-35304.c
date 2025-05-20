//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int account_number;
    char type;
    double amount;
} transaction_t;

// Define the bank structure
typedef struct bank {
    account_t accounts[MAX_ACCOUNTS];
    transaction_t transactions[MAX_TRANSACTIONS];
    int num_accounts;
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
    bank->accounts[bank->num_accounts].account_number = account_number;
    strcpy(bank->accounts[bank->num_accounts].name, name);
    bank->accounts[bank->num_accounts].balance = balance;
    bank->num_accounts++;
}

// Add a new transaction to the bank
void add_transaction(bank_t *bank, int account_number, char type, double amount) {
    bank->transactions[bank->num_transactions].account_number = account_number;
    bank->transactions[bank->num_transactions].type = type;
    bank->transactions[bank->num_transactions].amount = amount;
    bank->num_transactions++;
}

// Print the bank's accounts
void print_accounts(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        printf("Account: %d  Name: %s  Balance: %f\n", bank->accounts[i].account_number, bank->accounts[i].name, bank->accounts[i].balance);
    }
}

// Print the bank's transactions
void print_transactions(bank_t *bank) {
    for (int i = 0; i < bank->num_transactions; i++) {
        printf("Transaction: %d  Account: %d  Type: %c  Amount: %f\n", i, bank->transactions[i].account_number, bank->transactions[i].type, bank->transactions[i].amount);
    }
}

// Free the memory allocated to the bank
void free_bank(bank_t *bank) {
    free(bank);
}

// Main function
int main() {
    // Create a new bank
    bank_t *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 12345, "John Doe", 1000.00);
    add_account(bank, 54321, "Jane Doe", 2000.00);
    add_account(bank, 67890, "Bob Smith", 3000.00);

    // Add some transactions to the bank
    add_transaction(bank, 12345, 'D', 100.00);
    add_transaction(bank, 54321, 'W', 200.00);
    add_transaction(bank, 67890, 'T', 300.00);

    // Print the bank's accounts
    printf("Accounts:\n");
    print_accounts(bank);

    // Print the bank's transactions
    printf("\nTransactions:\n");
    print_transactions(bank);

    // Free the memory allocated to the bank
    free_bank(bank);

    return 0;
}