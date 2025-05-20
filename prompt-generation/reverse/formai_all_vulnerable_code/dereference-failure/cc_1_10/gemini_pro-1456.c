//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
    int account_number;
    char *name;
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
        printf("Error: the bank is full\n");
        return;
    }

    // Create a new account
    account_t *account = malloc(sizeof(account_t));
    account->account_number = account_number;
    account->name = name;
    account->balance = balance;

    // Add the account to the bank
    bank->accounts[bank->num_accounts++] = *account;
}

// Find an account by account number
account_t *find_account(bank_t *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }

    // Account not found
    return NULL;
}

// Deposit money into an account
void deposit_money(bank_t *bank, int account_number, double amount) {
    // Find the account
    account_t *account = find_account(bank, account_number);
    if (account == NULL) {
        printf("Error: account not found\n");
        return;
    }

    // Deposit the money
    account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(bank_t *bank, int account_number, double amount) {
    // Find the account
    account_t *account = find_account(bank, account_number);
    if (account == NULL) {
        printf("Error: account not found\n");
        return;
    }

    // Withdraw the money
    account->balance -= amount;
}

// Print the bank statement
void print_bank_statement(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        account_t *account = &bank->accounts[i];
        printf("Account number: %d\n", account->account_number);
        printf("Name: %s\n", account->name);
        printf("Balance: %.2f\n\n", account->balance);
    }
}

// Main function
int main() {
    // Create a new bank
    bank_t *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 12345, "John Doe", 1000.00);
    add_account(bank, 54321, "Jane Smith", 2000.00);

    // Deposit some money into an account
    deposit_money(bank, 12345, 500.00);

    // Withdraw some money from an account
    withdraw_money(bank, 54321, 300.00);

    // Print the bank statement
    print_bank_statement(bank);

    return 0;
}