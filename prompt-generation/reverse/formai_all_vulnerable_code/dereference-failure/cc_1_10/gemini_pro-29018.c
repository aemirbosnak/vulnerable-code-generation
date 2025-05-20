//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct {
    int account_number;
    char name[50];
    double balance;
} Account;

// Define the bank structure
typedef struct {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts;
} Bank;

// Create a new bank
Bank* create_bank() {
    Bank* bank = malloc(sizeof(Bank));
    bank->num_accounts = 0;
    return bank;
}

// Add an account to the bank
void add_account(Bank* bank, int account_number, char* name, double balance) {
    // Check if the bank is full
    if (bank->num_accounts == MAX_ACCOUNTS) {
        printf("The bank is full. Cannot add any more accounts.\n");
        return;
    }

    // Create a new account
    Account account;
    account.account_number = account_number;
    strcpy(account.name, name);
    account.balance = balance;

    // Add the account to the bank
    bank->accounts[bank->num_accounts] = account;
    bank->num_accounts++;
}

// Get an account by account number
Account* get_account_by_account_number(Bank* bank, int account_number) {
    // Iterate over the accounts
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
void deposit_money(Bank* bank, int account_number, double amount) {
    // Get the account
    Account* account = get_account_by_account_number(bank, account_number);

    // Check if the account was found
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    // Deposit the money
    account->balance += amount;

    // Print a success message
    printf("Money deposited successfully.\n");
}

// Withdraw money from an account
void withdraw_money(Bank* bank, int account_number, double amount) {
    // Get the account
    Account* account = get_account_by_account_number(bank, account_number);

    // Check if the account was found
    if (account == NULL) {
        printf("Account not found.\n");
        return;
    }

    // Check if the account has enough money
    if (account->balance < amount) {
        printf("Insufficient funds.\n");
        return;
    }

    // Withdraw the money
    account->balance -= amount;

    // Print a success message
    printf("Money withdrawn successfully.\n");
}

// Transfer money between accounts
void transfer_money(Bank* bank, int from_account_number, int to_account_number, double amount) {
    // Get the from account
    Account* from_account = get_account_by_account_number(bank, from_account_number);

    // Check if the from account was found
    if (from_account == NULL) {
        printf("From account not found.\n");
        return;
    }

    // Get the to account
    Account* to_account = get_account_by_account_number(bank, to_account_number);

    // Check if the to account was found
    if (to_account == NULL) {
        printf("To account not found.\n");
        return;
    }

    // Check if the from account has enough money
    if (from_account->balance < amount) {
        printf("Insufficient funds.\n");
        return;
    }

    // Transfer the money
    from_account->balance -= amount;
    to_account->balance += amount;

    // Print a success message
    printf("Money transferred successfully.\n");
}

// Print the bank's accounts
void print_accounts(Bank* bank) {
    // Iterate over the accounts
    for (int i = 0; i < bank->num_accounts; i++) {
        // Print the account information
        printf("Account number: %d\n", bank->accounts[i].account_number);
        printf("Name: %s\n", bank->accounts[i].name);
        printf("Balance: %f\n\n", bank->accounts[i].balance);
    }
}

// Main function
int main() {
    // Create a new bank
    Bank* bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 12345, "John Doe", 1000.00);
    add_account(bank, 67890, "Jane Doe", 2000.00);
    add_account(bank, 11111, "Jack Smith", 3000.00);

    // Print the bank's accounts
    print_accounts(bank);

    // Deposit money into an account
    deposit_money(bank, 12345, 500.00);

    // Withdraw money from an account
    withdraw_money(bank, 67890, 300.00);

    // Transfer money between accounts
    transfer_money(bank, 11111, 12345, 200.00);

    // Print the bank's accounts
    print_accounts(bank);

    // Free the bank
    free(bank);

    return 0;
}