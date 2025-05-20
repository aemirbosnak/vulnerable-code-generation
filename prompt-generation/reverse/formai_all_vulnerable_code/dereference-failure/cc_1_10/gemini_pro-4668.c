//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
    char name[50];
    int account_number;
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
void add_account(bank *bank, account new_account) {
    bank->accounts[bank->num_accounts] = new_account;
    bank->num_accounts++;
}

// Find an account by account number
account *find_account(bank *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }
    return NULL;
}

// Deposit money into an account
void deposit_money(bank *bank, int account_number, double amount) {
    account *account = find_account(bank, account_number);
    if (account != NULL) {
        account->balance += amount;
    }
}

// Withdraw money from an account
void withdraw_money(bank *bank, int account_number, double amount) {
    account *account = find_account(bank, account_number);
    if (account != NULL) {
        if (account->balance >= amount) {
            account->balance -= amount;
        }
    }
}

// Print the bank's records
void print_records(bank *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        printf("Account %d:\n", bank->accounts[i].account_number);
        printf("Name: %s\n", bank->accounts[i].name);
        printf("Balance: %.2f\n", bank->accounts[i].balance);
        printf("\n");
    }
}

// Free the memory allocated for the bank
void free_bank(bank *bank) {
    free(bank);
}

int main() {
    // Create a new bank
    bank *bank = create_bank();

    // Add some accounts to the bank
    account account1 = {"John Doe", 123456789, 1000.00};
    add_account(bank, account1);
    account account2 = {"Jane Doe", 987654321, 2000.00};
    add_account(bank, account2);

    // Deposit money into an account
    deposit_money(bank, 123456789, 500.00);

    // Withdraw money from an account
    withdraw_money(bank, 987654321, 1000.00);

    // Print the bank's records
    print_records(bank);

    // Free the memory allocated for the bank
    free_bank(bank);

    return 0;
}