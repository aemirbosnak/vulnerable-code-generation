//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the account structure
typedef struct account {
    int account_number;
    char *name;
    double balance;
} account_t;

// Define the bank structure
typedef struct bank {
    int num_accounts;
    account_t *accounts;
} bank_t;

// Create a new bank
bank_t *create_bank() {
    bank_t *bank = malloc(sizeof(bank_t));
    bank->num_accounts = 0;
    bank->accounts = NULL;
    return bank;
}

// Add a new account to the bank
void add_account(bank_t *bank, int account_number, char *name, double balance) {
    // Create a new account
    account_t *account = malloc(sizeof(account_t));
    account->account_number = account_number;
    account->name = name;
    account->balance = balance;

    // Add the account to the bank
    ++bank->num_accounts;
    bank->accounts = realloc(bank->accounts, bank->num_accounts * sizeof(account_t));
    bank->accounts[bank->num_accounts - 1] = *account;
}

// Get an account by account number
account_t *get_account(bank_t *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; ++i) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }

    return NULL;
}

// Print the bank
void print_bank(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; ++i) {
        printf("Account %d:\n", bank->accounts[i].account_number);
        printf("  Name: %s\n", bank->accounts[i].name);
        printf("  Balance: %.2f\n", bank->accounts[i].balance);
    }
}

// Free the bank
void free_bank(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; ++i) {
        free(bank->accounts[i].name);
    }
    free(bank->accounts);
    free(bank);
}

// Main function
int main() {
    // Create a new bank
    bank_t *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 12345, "John Doe", 1000.00);
    add_account(bank, 54321, "Jane Doe", 2000.00);

    // Print the bank
    print_bank(bank);

    // Get an account by account number
    account_t *account = get_account(bank, 12345);

    // Print the account
    printf("\nAccount %d:\n", account->account_number);
    printf("  Name: %s\n", account->name);
    printf("  Balance: %.2f\n", account->balance);

    // Free the bank
    free_bank(bank);

    return 0;
}