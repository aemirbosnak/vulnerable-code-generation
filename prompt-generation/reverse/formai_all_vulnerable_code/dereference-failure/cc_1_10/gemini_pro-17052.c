//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: interoperable
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

// Add a new account to the bank
void add_account(bank_t *bank, account_t account) {
    bank->accounts[bank->num_accounts] = account;
    bank->num_accounts++;
}

// Find an account by account number
account_t *find_account(bank_t *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }
    return NULL;
}

// Deposit money into an account
void deposit_money(bank_t *bank, int account_number, double amount) {
    account_t *account = find_account(bank, account_number);
    if (account != NULL) {
        account->balance += amount;
    }
}

// Withdraw money from an account
void withdraw_money(bank_t *bank, int account_number, double amount) {
    account_t *account = find_account(bank, account_number);
    if (account != NULL) {
        if (account->balance >= amount) {
            account->balance -= amount;
        }
    }
}

// Print the bank statement
void print_bank_statement(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        account_t account = bank->accounts[i];
        printf("Account number: %d\n", account.account_number);
        printf("Name: %s\n", account.name);
        printf("Balance: %.2f\n\n", account.balance);
    }
}

// Main function
int main() {
    // Create a new bank
    bank_t *bank = create_bank();

    // Add some accounts to the bank
    account_t account1 = {"John Doe", 123456789, 1000.00};
    add_account(bank, account1);

    account_t account2 = {"Jane Doe", 987654321, 2000.00};
    add_account(bank, account2);

    // Deposit money into an account
    deposit_money(bank, 123456789, 500.00);

    // Withdraw money from an account
    withdraw_money(bank, 987654321, 1000.00);

    // Print the bank statement
    print_bank_statement(bank);

    return 0;
}