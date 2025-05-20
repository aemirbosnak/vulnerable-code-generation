//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct {
    int account_number;
    char *name;
    double balance;
} account;

// Define the bank structure
typedef struct {
    account accounts[MAX_ACCOUNTS];
    int num_accounts;
} bank;

// Create a new bank
bank *create_bank() {
    bank *new_bank = malloc(sizeof(bank));
    new_bank->num_accounts = 0;
    return new_bank;
}

// Add a new account to the bank
void add_account(bank *bank, int account_number, char *name, double balance) {
    // Check if the bank is full
    if (bank->num_accounts == MAX_ACCOUNTS) {
        printf("Error: Bank is full.\n");
        return;
    }

    // Create a new account
    account new_account;
    new_account.account_number = account_number;
    new_account.name = name;
    new_account.balance = balance;

    // Add the account to the bank
    bank->accounts[bank->num_accounts] = new_account;
    bank->num_accounts++;
}

// Get an account from the bank
account *get_account(bank *bank, int account_number) {
    // Find the account
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }

    // Account not found
    return NULL;
}

// Deposit money into an account
void deposit_money(bank *bank, int account_number, double amount) {
    // Get the account
    account *account = get_account(bank, account_number);

    // Check if the account exists
    if (account == NULL) {
        printf("Error: Account not found.\n");
        return;
    }

    // Deposit the money
    account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(bank *bank, int account_number, double amount) {
    // Get the account
    account *account = get_account(bank, account_number);

    // Check if the account exists
    if (account == NULL) {
        printf("Error: Account not found.\n");
        return;
    }

    // Withdraw the money
    account->balance -= amount;
}

// Transfer money between accounts
void transfer_money(bank *bank, int from_account_number, int to_account_number, double amount) {
    // Get the from account
    account *from_account = get_account(bank, from_account_number);

    // Check if the from account exists
    if (from_account == NULL) {
        printf("Error: From account not found.\n");
        return;
    }

    // Get the to account
    account *to_account = get_account(bank, to_account_number);

    // Check if the to account exists
    if (to_account == NULL) {
        printf("Error: To account not found.\n");
        return;
    }

    // Transfer the money
    from_account->balance -= amount;
    to_account->balance += amount;
}

// Print the bank statement
void print_bank_statement(bank *bank) {
    // Print the header
    printf("Bank Statement\n");
    printf("===================\n");

    // Print the accounts
    for (int i = 0; i < bank->num_accounts; i++) {
        account account = bank->accounts[i];
        printf("Account Number: %d\n", account.account_number);
        printf("Name: %s\n", account.name);
        printf("Balance: %f\n", account.balance);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new bank
    bank *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 12345, "John Smith", 1000.00);
    add_account(bank, 54321, "Jane Doe", 2000.00);
    add_account(bank, 67890, "Bill Jones", 3000.00);

    // Deposit some money into an account
    deposit_money(bank, 12345, 500.00);

    // Withdraw some money from an account
    withdraw_money(bank, 54321, 100.00);

    // Transfer some money between accounts
    transfer_money(bank, 12345, 67890, 200.00);

    // Print the bank statement
    print_bank_statement(bank);

    return 0;
}