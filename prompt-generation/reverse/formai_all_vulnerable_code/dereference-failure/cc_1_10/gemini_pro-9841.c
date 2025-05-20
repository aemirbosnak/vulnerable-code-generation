//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    bank *bank = malloc(sizeof(bank));
    bank->num_accounts = 0;
    return bank;
}

// Add an account to the bank
void add_account(bank *bank, int account_number, char *name, double balance) {
    if (bank->num_accounts >= MAX_ACCOUNTS) {
        printf("Error: cannot add more than %d accounts to the bank.\n", MAX_ACCOUNTS);
        return;
    }

    account *account = &bank->accounts[bank->num_accounts];
    account->account_number = account_number;
    account->name = strdup(name);
    account->balance = balance;
    bank->num_accounts++;
}

// Get an account by its account number
account *get_account(bank *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        account *account = &bank->accounts[i];
        if (account->account_number == account_number) {
            return account;
        }
    }
    return NULL;
}

// Deposit money into an account
void deposit_money(account *account, double amount) {
    account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(account *account, double amount) {
    if (amount > account->balance) {
        printf("Error: cannot withdraw more money than the account balance.\n");
        return;
    }
    account->balance -= amount;
}

// Print the bank's account information
void print_bank(bank *bank) {
    printf("Bank account information:\n");
    for (int i = 0; i < bank->num_accounts; i++) {
        account *account = &bank->accounts[i];
        printf("Account number: %d\n", account->account_number);
        printf("Name: %s\n", account->name);
        printf("Balance: %.2f\n", account->balance);
        printf("\n");
    }
}

// Free the memory used by the bank
void free_bank(bank *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        account *account = &bank->accounts[i];
        free(account->name);
    }
    free(bank);
}

// Main function
int main() {
    // Create a new bank
    bank *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 123456, "John Doe", 1000.00);
    add_account(bank, 654321, "Jane Doe", 2000.00);
    add_account(bank, 987654, "John Smith", 3000.00);

    // Deposit money into an account
    account *account = get_account(bank, 123456);
    deposit_money(account, 500.00);

    // Withdraw money from an account
    withdraw_money(account, 300.00);

    // Print the bank's account information
    print_bank(bank);

    // Free the memory used by the bank
    free_bank(bank);

    return 0;
}