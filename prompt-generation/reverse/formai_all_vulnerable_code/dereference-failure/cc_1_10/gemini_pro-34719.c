//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: romantic
#include <stdio.h>
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
    bank *new_bank = malloc(sizeof(bank));
    new_bank->num_accounts = 0;
    return new_bank;
}

// Add an account to the bank
void add_account(bank *bank, account *new_account) {
    bank->accounts[bank->num_accounts] = *new_account;
    bank->num_accounts++;
}

// Find an account by account number
account *find_account_by_number(bank *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
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
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Print the bank statement
void print_bank_statement(bank *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        printf("Account number: %d\n", bank->accounts[i].account_number);
        printf("Account name: %s\n", bank->accounts[i].name);
        printf("Account balance: %.2f\n\n", bank->accounts[i].balance);
    }
}

// Main function
int main() {
    // Create a new bank
    bank *bank = create_bank();

    // Add some accounts to the bank
    account account1 = {"John Smith", 123456, 1000.00};
    add_account(bank, &account1);
    account account2 = {"Jane Doe", 654321, 2000.00};
    add_account(bank, &account2);

    // Deposit money into account 1
    deposit_money(&account1, 500.00);

    // Withdraw money from account 2
    withdraw_money(&account2, 300.00);

    // Print the bank statement
    print_bank_statement(bank);

    return 0;
}