//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct {
    char name[50];
    int account_number;
    double balance;
} account;

// Define the bank structure
typedef struct {
    account accounts[MAX_ACCOUNTS];
    int num_accounts;
} bank;

// Create a new bank
bank* new_bank() {
    bank* b = malloc(sizeof(bank));
    b->num_accounts = 0;
    return b;
}

// Add an account to the bank
void add_account(bank* b, char* name, int account_number, double balance) {
    // Check if the bank is full
    if (b->num_accounts >= MAX_ACCOUNTS) {
        printf("Error: Bank is full\n");
        return;
    }

    // Add the account to the bank
    strcpy(b->accounts[b->num_accounts].name, name);
    b->accounts[b->num_accounts].account_number = account_number;
    b->accounts[b->num_accounts].balance = balance;
    b->num_accounts++;
}

// Get an account from the bank
account* get_account(bank* b, int account_number) {
    // Iterate over the accounts
    for (int i = 0; i < b->num_accounts; i++) {
        // Check if the account number matches
        if (b->accounts[i].account_number == account_number) {
            // Return the account
            return &b->accounts[i];
        }
    }

    // Return NULL if the account was not found
    return NULL;
}

// Deposit money into an account
void deposit_money(bank* b, int account_number, double amount) {
    // Get the account
    account* a = get_account(b, account_number);

    // Check if the account was found
    if (a == NULL) {
        printf("Error: Account not found\n");
        return;
    }

    // Deposit the money
    a->balance += amount;
}

// Withdraw money from an account
void withdraw_money(bank* b, int account_number, double amount) {
    // Get the account
    account* a = get_account(b, account_number);

    // Check if the account was found
    if (a == NULL) {
        printf("Error: Account not found\n");
        return;
    }

    // Withdraw the money
    a->balance -= amount;
}

// Print the bank statement
void print_bank_statement(bank* b) {
    // Iterate over the accounts
    for (int i = 0; i < b->num_accounts; i++) {
        // Print the account information
        printf("%s %d %f\n", b->accounts[i].name, b->accounts[i].account_number, b->accounts[i].balance);
    }
}

// Main function
int main() {
    // Create a new bank
    bank* b = new_bank();

    // Add some accounts to the bank
    add_account(b, "Linus Torvalds", 123456789, 1000000.00);
    add_account(b, "Bill Gates", 987654321, 1000000000.00);
    add_account(b, "Jeff Bezos", 1122334455, 10000000000.00);

    // Print the bank statement
    print_bank_statement(b);

    // Deposit money into an account
    deposit_money(b, 123456789, 10000.00);

    // Withdraw money from an account
    withdraw_money(b, 987654321, 100000.00);

    // Print the bank statement
    print_bank_statement(b);

    return 0;
}