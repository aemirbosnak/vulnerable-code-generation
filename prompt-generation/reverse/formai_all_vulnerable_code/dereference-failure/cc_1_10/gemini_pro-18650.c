//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
    int account_number;
    char name[50];
    double balance;
} account_t;

// Define the bank structure
typedef struct bank {
    account_t accounts[MAX_ACCOUNTS];
    int num_accounts;
} bank_t;

// Create a new bank
bank_t *create_bank() {
    bank_t *bank = malloc(sizeof(bank_t));
    bank->num_accounts = 0;
    return bank;
}

// Add an account to the bank
void add_account(bank_t *bank, int account_number, char *name, double balance) {
    // Check if the bank is full
    if (bank->num_accounts >= MAX_ACCOUNTS) {
        printf("Error: Bank is full\n");
        return;
    }

    // Add the account to the bank
    bank->accounts[bank->num_accounts].account_number = account_number;
    strcpy(bank->accounts[bank->num_accounts].name, name);
    bank->accounts[bank->num_accounts].balance = balance;
    bank->num_accounts++;
}

// Get an account from the bank
account_t *get_account(bank_t *bank, int account_number) {
    // Iterate over the accounts in the bank
    for (int i = 0; i < bank->num_accounts; i++) {
        // If the account number matches, return the account
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }

    // If the account number was not found, return NULL
    return NULL;
}

// Deposit money into an account
void deposit_money(bank_t *bank, int account_number, double amount) {
    // Get the account
    account_t *account = get_account(bank, account_number);

    // If the account was not found, return
    if (account == NULL) {
        printf("Error: Account not found\n");
        return;
    }

    // Deposit the money
    account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(bank_t *bank, int account_number, double amount) {
    // Get the account
    account_t *account = get_account(bank, account_number);

    // If the account was not found, return
    if (account == NULL) {
        printf("Error: Account not found\n");
        return;
    }

    // Withdraw the money
    account->balance -= amount;
}

// Print the bank statement
void print_bank_statement(bank_t *bank) {
    // Iterate over the accounts in the bank
    for (int i = 0; i < bank->num_accounts; i++) {
        // Print the account number, name, and balance
        printf("Account Number: %d\n", bank->accounts[i].account_number);
        printf("Name: %s\n", bank->accounts[i].name);
        printf("Balance: %.2f\n", bank->accounts[i].balance);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new bank
    bank_t *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 123456, "John Doe", 1000.00);
    add_account(bank, 654321, "Jane Doe", 2000.00);
    add_account(bank, 789012, "Bob Smith", 3000.00);

    // Deposit money into an account
    deposit_money(bank, 123456, 500.00);

    // Withdraw money from an account
    withdraw_money(bank, 654321, 250.00);

    // Print the bank statement
    print_bank_statement(bank);

    // Free the bank
    free(bank);

    return 0;
}