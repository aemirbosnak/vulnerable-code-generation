//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
    int account_number;
    char *name;
    double balance;
} account;

// Define the bank structure
typedef struct bank {
    account accounts[MAX_ACCOUNTS];
    int num_accounts;
} bank;

// Create a new bank
bank *create_bank() {
    bank *new_bank = (bank *)malloc(sizeof(bank));
    new_bank->num_accounts = 0;
    return new_bank;
}

// Add an account to the bank
void add_account(bank *bank, int account_number, char *name, double balance) {
    // Check if the bank is full
    if (bank->num_accounts == MAX_ACCOUNTS) {
        printf("Error: Bank is full.\n");
        return;
    }

    // Create a new account
    account new_account = {account_number, name, balance};

    // Add the account to the bank
    bank->accounts[bank->num_accounts] = new_account;
    bank->num_accounts++;
}

// Get an account from the bank
account *get_account(bank *bank, int account_number) {
    // Iterate over the accounts in the bank
    for (int i = 0; i < bank->num_accounts; i++) {
        // Check if the account number matches
        if (bank->accounts[i].account_number == account_number) {
            // Return the account
            return &bank->accounts[i];
        }
    }

    // Return NULL if the account was not found
    return NULL;
}

// Deposit money into an account
void deposit_money(account *account, double amount) {
    // Check if the amount is valid
    if (amount <= 0) {
        printf("Error: Invalid amount.\n");
        return;
    }

    // Deposit the money into the account
    account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(account *account, double amount) {
    // Check if the amount is valid
    if (amount <= 0 || amount > account->balance) {
        printf("Error: Invalid amount.\n");
        return;
    }

    // Withdraw the money from the account
    account->balance -= amount;
}

// Transfer money between two accounts
void transfer_money(bank *bank, int from_account_number, int to_account_number, double amount) {
    // Check if the amount is valid
    if (amount <= 0) {
        printf("Error: Invalid amount.\n");
        return;
    }

    // Get the accounts
    account *from_account = get_account(bank, from_account_number);
    account *to_account = get_account(bank, to_account_number);

    // Check if the accounts exist
    if (from_account == NULL || to_account == NULL) {
        printf("Error: Account not found.\n");
        return;
    }

    // Check if the from account has enough money
    if (from_account->balance < amount) {
        printf("Error: Insufficient funds.\n");
        return;
    }

    // Transfer the money
    from_account->balance -= amount;
    to_account->balance += amount;
}

// Print the bank statement
void print_bank_statement(bank *bank) {
    // Iterate over the accounts in the bank
    for (int i = 0; i < bank->num_accounts; i++) {
        // Get the account
        account *account = &bank->accounts[i];

        // Print the account number, name, and balance
        printf("Account Number: %d\n", account->account_number);
        printf("Name: %s\n", account->name);
        printf("Balance: %.2f\n\n", account->balance);
    }
}

// Main function
int main() {
    // Create a new bank
    bank *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 12345, "John Doe", 1000.00);
    add_account(bank, 54321, "Jane Doe", 2000.00);
    add_account(bank, 98765, "Bob Smith", 3000.00);

    // Deposit money into an account
    deposit_money(get_account(bank, 12345), 500.00);

    // Withdraw money from an account
    withdraw_money(get_account(bank, 54321), 1000.00);

    // Transfer money between two accounts
    transfer_money(bank, 98765, 12345, 1500.00);

    // Print the bank statement
    print_bank_statement(bank);

    // Free the memory allocated for the bank
    free(bank);

    return 0;
}