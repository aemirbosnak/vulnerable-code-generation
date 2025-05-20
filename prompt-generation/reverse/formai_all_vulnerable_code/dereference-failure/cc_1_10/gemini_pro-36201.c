//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts and the maximum balance for each account
#define MAX_ACCOUNTS 100
#define MAX_BALANCE 1000000

// Define the account structure
typedef struct {
    char name[50];       // The account holder's name
    int account_number;  // The account number
    double balance;       // The account balance
} account;

// Define the bank structure
typedef struct {
    account accounts[MAX_ACCOUNTS];  // The array of accounts
    int num_accounts;                // The number of accounts
} bank;

// Create a new bank
bank* create_bank() {
    bank* new_bank = malloc(sizeof(bank));
    new_bank->num_accounts = 0;
    return new_bank;
}

// Add an account to the bank
void add_account(bank* bank, char* name, int account_number, double balance) {
    // Check if the bank is full
    if (bank->num_accounts >= MAX_ACCOUNTS) {
        printf("Error: The bank is full!\n");
        return;
    }

    // Check if the account number is already in use
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            printf("Error: The account number is already in use!\n");
            return;
        }
    }

    // Add the account to the bank
    strcpy(bank->accounts[bank->num_accounts].name, name);
    bank->accounts[bank->num_accounts].account_number = account_number;
    bank->accounts[bank->num_accounts].balance = balance;
    bank->num_accounts++;
}

// Find an account by account number
account* find_account(bank* bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }

    return NULL;
}

// Deposit money into an account
void deposit_money(bank* bank, int account_number, double amount) {
    account* account = find_account(bank, account_number);
    if (account == NULL) {
        printf("Error: The account number is not found!\n");
        return;
    }

    // Check if the amount is valid
    if (amount <= 0) {
        printf("Error: The amount must be greater than 0!\n");
        return;
    }

    // Deposit the money
    account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(bank* bank, int account_number, double amount) {
    account* account = find_account(bank, account_number);
    if (account == NULL) {
        printf("Error: The account number is not found!\n");
        return;
    }

    // Check if the amount is valid
    if (amount <= 0) {
        printf("Error: The amount must be greater than 0!\n");
        return;
    }

    // Withdraw the money
    account->balance -= amount;
}

// Print the bank statement
void print_bank_statement(bank* bank) {
    printf("Bank Statement\n");
    printf("---------------------\n");
    for (int i = 0; i < bank->num_accounts; i++) {
        printf("%s (%d): $%.2f\n", bank->accounts[i].name, bank->accounts[i].account_number, bank->accounts[i].balance);
    }
}

// Main function
int main() {
    // Create a new bank
    bank* bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, "John Smith", 123456789, 1000.00);
    add_account(bank, "Jane Doe", 987654321, 5000.00);

    // Deposit money into an account
    deposit_money(bank, 123456789, 100.00);

    // Withdraw money from an account
    withdraw_money(bank, 987654321, 200.00);

    // Print the bank statement
    print_bank_statement(bank);

    return 0;
}