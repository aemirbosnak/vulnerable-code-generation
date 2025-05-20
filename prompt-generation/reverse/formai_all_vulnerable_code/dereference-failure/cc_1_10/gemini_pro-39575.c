//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: mathematical
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

// Destroy a bank
void destroy_bank(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        free(bank->accounts[i].name);
    }
    free(bank->accounts);
    free(bank);
}

// Add an account to a bank
void add_account(bank_t *bank, int account_number, char *name, double balance) {
    bank->num_accounts++;
    bank->accounts = realloc(bank->accounts, bank->num_accounts * sizeof(account_t));
    bank->accounts[bank->num_accounts - 1].account_number = account_number;
    bank->accounts[bank->num_accounts - 1].name = strdup(name);
    bank->accounts[bank->num_accounts - 1].balance = balance;
}

// Get an account from a bank
account_t *get_account(bank_t *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            return &bank->accounts[i];
        }
    }
    return NULL;
}

// Deposit money into an account
void deposit_money(account_t *account, double amount) {
    account->balance += amount;
}

// Withdraw money from an account
void withdraw_money(account_t *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    }
}

// Transfer money from one account to another
void transfer_money(bank_t *bank, int from_account_number, int to_account_number, double amount) {
    account_t *from_account = get_account(bank, from_account_number);
    account_t *to_account = get_account(bank, to_account_number);
    if (from_account && to_account) {
        if (amount <= from_account->balance) {
            from_account->balance -= amount;
            to_account->balance += amount;
        }
    }
}

// Print the bank statement
void print_bank_statement(bank_t *bank) {
    printf("Bank Statement\n");
    printf("------------------------------\n");
    for (int i = 0; i < bank->num_accounts; i++) {
        printf("Account Number: %d\n", bank->accounts[i].account_number);
        printf("Name: %s\n", bank->accounts[i].name);
        printf("Balance: %.2f\n\n", bank->accounts[i].balance);
    }
}

// Main function
int main() {
    // Create a new bank
    bank_t *bank = create_bank();

    // Add some accounts to the bank
    add_account(bank, 123456, "John Doe", 1000.00);
    add_account(bank, 654321, "Jane Doe", 2000.00);
    add_account(bank, 987654, "Bob Smith", 3000.00);

    // Deposit money into an account
    deposit_money(get_account(bank, 123456), 500.00);

    // Withdraw money from an account
    withdraw_money(get_account(bank, 654321), 300.00);

    // Transfer money from one account to another
    transfer_money(bank, 987654, 123456, 400.00);

    // Print the bank statement
    print_bank_statement(bank);

    // Destroy the bank
    destroy_bank(bank);

    return 0;
}