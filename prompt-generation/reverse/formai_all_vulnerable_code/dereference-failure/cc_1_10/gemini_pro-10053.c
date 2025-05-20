//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and transactions
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the account structure
typedef struct account {
    int account_number;
    char *name;
    double balance;
} account_t;

// Define the transaction structure
typedef struct transaction {
    int account_number;
    char *type; // "deposit" or "withdrawal"
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

// Add an account to the bank
void add_account(bank_t *bank, int account_number, char *name, double balance) {
    // Check if the account number is already in use
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            printf("Error: Account number %d is already in use.\n", account_number);
            return;
        }
    }

    // Create the new account
    account_t account;
    account.account_number = account_number;
    account.name = strdup(name);
    account.balance = balance;

    // Add the account to the bank
    bank->accounts[bank->num_accounts++] = account;
}

// Deposit money into an account
void deposit(bank_t *bank, int account_number, double amount) {
    // Find the account
    int index = -1;
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    // Check if the account was found
    if (index == -1) {
        printf("Error: Account number %d not found.\n", account_number);
        return;
    }

    // Deposit the money
    bank->accounts[index].balance += amount;

    // Create a transaction record
    transaction_t transaction;
    transaction.account_number = account_number;
    transaction.type = "deposit";
    transaction.amount = amount;

    // Add the transaction to the bank
    bank->transactions[bank->num_transactions++] = transaction;
}

// Withdraw money from an account
void withdraw(bank_t *bank, int account_number, double amount) {
    // Find the account
    int index = -1;
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    // Check if the account was found
    if (index == -1) {
        printf("Error: Account number %d not found.\n", account_number);
        return;
    }

    // Check if the account has enough money
    if (bank->accounts[index].balance < amount) {
        printf("Error: Account number %d does not have enough money.\n", account_number);
        return;
    }

    // Withdraw the money
    bank->accounts[index].balance -= amount;

    // Create a transaction record
    transaction_t transaction;
    transaction.account_number = account_number;
    transaction.type = "withdrawal";
    transaction.amount = amount;

    // Add the transaction to the bank
    bank->transactions[bank->num_transactions++] = transaction;
}

// Print the bank statement
void print_statement(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        account_t account = bank->accounts[i];
        printf("Account number: %d\n", account.account_number);
        printf("Name: %s\n", account.name);
        printf("Balance: %.2f\n", account.balance);
        printf("\n");
    }
}

// Free the memory allocated by the bank
void free_bank(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        free(bank->accounts[i].name);
    }
    free(bank);
}

// Main function
int main() {
    // Create a new bank
    bank_t *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 12345, "John Doe", 1000.00);
    add_account(bank, 67890, "Jane Doe", 500.00);

    // Deposit some money into an account
    deposit(bank, 12345, 200.00);

    // Withdraw some money from an account
    withdraw(bank, 67890, 100.00);

    // Print the bank statement
    print_statement(bank);

    // Free the memory allocated by the bank
    free_bank(bank);

    return 0;
}