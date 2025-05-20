//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct {
    char name[50];
    char account_number[20];
    double balance;
} account_t;

// Define the bank structure
typedef struct {
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
void add_account(bank_t *bank, char *name, char *account_number, double balance) {
    // Check if the bank is full
    if (bank->num_accounts == MAX_ACCOUNTS) {
        printf("Error: The bank is full.\n");
        return;
    }

    // Add the new account to the bank
    strcpy(bank->accounts[bank->num_accounts].name, name);
    strcpy(bank->accounts[bank->num_accounts].account_number, account_number);
    bank->accounts[bank->num_accounts].balance = balance;
    bank->num_accounts++;
}

// Find an account by its account number
account_t *find_account(bank_t *bank, char *account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (strcmp(bank->accounts[i].account_number, account_number) == 0) {
            return &bank->accounts[i];
        }
    }

    return NULL;
}

// Deposit money into an account
void deposit(bank_t *bank, char *account_number, double amount) {
    account_t *account = find_account(bank, account_number);

    if (account == NULL) {
        printf("Error: Account not found.\n");
        return;
    }

    account->balance += amount;
}

// Withdraw money from an account
void withdraw(bank_t *bank, char *account_number, double amount) {
    account_t *account = find_account(bank, account_number);

    if (account == NULL) {
        printf("Error: Account not found.\n");
        return;
    }

    if (account->balance < amount) {
        printf("Error: Insufficient funds.\n");
        return;
    }

    account->balance -= amount;
}

// Print the bank statement
void print_statement(bank_t *bank) {
    printf("Bank Statement\n");
    printf("=====================\n");
    for (int i = 0; i < bank->num_accounts; i++) {
        printf("Name: %s\n", bank->accounts[i].name);
        printf("Account Number: %s\n", bank->accounts[i].account_number);
        printf("Balance: %.2f\n", bank->accounts[i].balance);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new bank
    bank_t *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, "John Doe", "1234567890", 1000.00);
    add_account(bank, "Jane Doe", "0987654321", 500.00);

    // Deposit some money into an account
    deposit(bank, "1234567890", 100.00);

    // Withdraw some money from an account
    withdraw(bank, "0987654321", 50.00);

    // Print the bank statement
    print_statement(bank);

    return 0;
}