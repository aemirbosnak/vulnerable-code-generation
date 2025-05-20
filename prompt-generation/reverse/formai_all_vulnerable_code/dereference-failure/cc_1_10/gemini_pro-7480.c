//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: systematic
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
} account;

// Define the bank structure
typedef struct bank {
    account accounts[MAX_ACCOUNTS];
    int num_accounts;
} bank;

// Create a new bank
bank *create_bank() {
    bank *b = malloc(sizeof(bank));
    b->num_accounts = 0;
    return b;
}

// Add an account to the bank
void add_account(bank *b, int account_number, char *name, double balance) {
    account *a = &b->accounts[b->num_accounts++];
    a->account_number = account_number;
    strcpy(a->name, name);
    a->balance = balance;
}

// Find an account by its account number
account *find_account(bank *b, int account_number) {
    for (int i = 0; i < b->num_accounts; i++) {
        if (b->accounts[i].account_number == account_number) {
            return &b->accounts[i];
        }
    }
    return NULL;
}

// Deposit money into an account
void deposit_money(account *a, double amount) {
    a->balance += amount;
}

// Withdraw money from an account
void withdraw_money(account *a, double amount) {
    if (amount <= a->balance) {
        a->balance -= amount;
    }
}

// Transfer money from one account to another
void transfer_money(bank *b, int from_account_number, int to_account_number, double amount) {
    account *from_account = find_account(b, from_account_number);
    account *to_account = find_account(b, to_account_number);
    if (from_account && to_account) {
        if (amount <= from_account->balance) {
            withdraw_money(from_account, amount);
            deposit_money(to_account, amount);
        }
    }
}

// Print the bank statement
void print_bank_statement(bank *b) {
    for (int i = 0; i < b->num_accounts; i++) {
        account *a = &b->accounts[i];
        printf("Account number: %d\n", a->account_number);
        printf("Name: %s\n", a->name);
        printf("Balance: %.2f\n\n", a->balance);
    }
}

// Main function
int main() {
    bank *b = create_bank();

    // Add some accounts to the bank
    add_account(b, 12345, "John Doe", 1000.00);
    add_account(b, 54321, "Jane Doe", 2000.00);

    // Deposit money into an account
    deposit_money(find_account(b, 12345), 500.00);

    // Withdraw money from an account
    withdraw_money(find_account(b, 54321), 300.00);

    // Transfer money from one account to another
    transfer_money(b, 12345, 54321, 200.00);

    // Print the bank statement
    print_bank_statement(b);

    return 0;
}