//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the account structure
typedef struct account {
    int account_number;
    char *name;
    double balance;
} account;

// Define the bank structure
typedef struct bank {
    int num_accounts;
    account *accounts;
} bank;

// Create a new account
account *create_account(int account_number, char *name, double balance) {
    account *new_account = malloc(sizeof(account));
    new_account->account_number = account_number;
    new_account->name = name;
    new_account->balance = balance;
    return new_account;
}

// Create a new bank
bank *create_bank(int num_accounts) {
    bank *new_bank = malloc(sizeof(bank));
    new_bank->num_accounts = num_accounts;
    new_bank->accounts = malloc(sizeof(account) * num_accounts);
    return new_bank;
}

// Add an account to a bank
void add_account(bank *bank, account *account) {
    bank->accounts[bank->num_accounts++] = *account;
}

// Print the details of an account
void print_account(account *account) {
    printf("Account number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %f\n", account->balance);
}

// Print the details of a bank
void print_bank(bank *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        print_account(&bank->accounts[i]);
    }
}

// Withdraw money from an account
void withdraw_money(account *account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient funds\n");
    } else {
        account->balance -= amount;
    }
}

// Deposit money into an account
void deposit_money(account *account, double amount) {
    account->balance += amount;
}

// Transfer money between two accounts
void transfer_money(account *from_account, account *to_account, double amount) {
    if (amount > from_account->balance) {
        printf("Insufficient funds\n");
    } else {
        from_account->balance -= amount;
        to_account->balance += amount;
    }
}

// Close an account
void close_account(bank *bank, int account_number) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (bank->accounts[i].account_number == account_number) {
            bank->accounts[i] = bank->accounts[bank->num_accounts - 1];
            bank->num_accounts--;
        }
    }
}

// Main function
int main() {
    // Create a new bank
    bank *bank = create_bank(5);

    // Add some accounts to the bank
    add_account(bank, create_account(12345, "John Doe", 1000.00));
    add_account(bank, create_account(23456, "Jane Doe", 2000.00));
    add_account(bank, create_account(34567, "John Smith", 3000.00));
    add_account(bank, create_account(45678, "Jane Smith", 4000.00));
    add_account(bank, create_account(56789, "John Jones", 5000.00));

    // Print the details of the bank
    print_bank(bank);

    // Withdraw money from an account
    withdraw_money(&bank->accounts[0], 200.00);

    // Deposit money into an account
    deposit_money(&bank->accounts[1], 300.00);

    // Transfer money between two accounts
    transfer_money(&bank->accounts[2], &bank->accounts[3], 400.00);

    // Close an account
    close_account(bank, 34567);

    // Print the details of the bank
    print_bank(bank);

    return 0;
}