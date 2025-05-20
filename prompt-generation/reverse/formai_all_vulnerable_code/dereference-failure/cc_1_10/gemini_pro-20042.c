//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
    char name[50];
    char account_number[20];
    double balance;
} account;

// Define the bank structure
typedef struct bank {
    account accounts[MAX_ACCOUNTS];
    int num_accounts;
} bank;

// Create a new bank
bank* create_bank() {
    bank* new_bank = (bank*)malloc(sizeof(bank));
    new_bank->num_accounts = 0;
    return new_bank;
}

// Add an account to the bank
void add_account(bank* bank, account* account) {
    bank->accounts[bank->num_accounts] = *account;
    bank->num_accounts++;
}

// Find an account by account number
account* find_account(bank* bank, char* account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (strcmp(bank->accounts[i].account_number, account_number) == 0) {
            return &bank->accounts[i];
        }
    }
    return NULL;
}

// Deposit money into an account
void deposit_money(bank* bank, char* account_number, double amount) {
    account* account = find_account(bank, account_number);
    if (account != NULL) {
        account->balance += amount;
    }
}

// Withdraw money from an account
void withdraw_money(bank* bank, char* account_number, double amount) {
    account* account = find_account(bank, account_number);
    if (account != NULL) {
        if (account->balance >= amount) {
            account->balance -= amount;
        }
    }
}

// Print the balance of an account
void print_balance(bank* bank, char* account_number) {
    account* account = find_account(bank, account_number);
    if (account != NULL) {
        printf("The balance of account %s is %f\n", account->account_number, account->balance);
    }
}

// Print the bank's statement
void print_statement(bank* bank) {
    printf("Bank Statement\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("| Account Number | Name | Balance |\n");
    printf("-----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < bank->num_accounts; i++) {
        printf("| %s | %s | %f |\n", bank->accounts[i].account_number, bank->accounts[i].name, bank->accounts[i].balance);
    }
    printf("-----------------------------------------------------------------------------------------\n");
}

// Free the memory allocated for the bank
void free_bank(bank* bank) {
    free(bank);
}

// Main function
int main() {
    // Create a new bank
    bank* bank = create_bank();

    // Add some accounts to the bank
    account account1 = {"John Doe", "1234567890", 1000.00};
    add_account(bank, &account1);

    account account2 = {"Jane Doe", "0987654321", 2000.00};
    add_account(bank, &account2);

    // Deposit some money into an account
    deposit_money(bank, "1234567890", 500.00);

    // Withdraw some money from an account
    withdraw_money(bank, "0987654321", 300.00);

    // Print the balance of an account
    print_balance(bank, "1234567890");

    // Print the bank's statement
    print_statement(bank);

    // Free the memory allocated for the bank
    free_bank(bank);

    return 0;
}