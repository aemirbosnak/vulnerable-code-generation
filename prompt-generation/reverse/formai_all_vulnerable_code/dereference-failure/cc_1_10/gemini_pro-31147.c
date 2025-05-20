//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
    char *name;
    char *password;
    int balance;
} account;

// Define the bank structure
typedef struct bank {
    account accounts[MAX_ACCOUNTS];
    int num_accounts;
} bank;

// Create a new bank
bank *new_bank() {
    bank *b = malloc(sizeof(bank));
    b->num_accounts = 0;
    return b;
}

// Add an account to the bank
void add_account(bank *b, char *name, char *password, int balance) {
    if (b->num_accounts >= MAX_ACCOUNTS) {
        printf("Error: cannot add more than %d accounts to the bank\n", MAX_ACCOUNTS);
        return;
    }

    // Allocate memory for the new account
    b->accounts[b->num_accounts].name = malloc(strlen(name) + 1);
    b->accounts[b->num_accounts].password = malloc(strlen(password) + 1);

    // Copy the account information into the new account
    strcpy(b->accounts[b->num_accounts].name, name);
    strcpy(b->accounts[b->num_accounts].password, password);
    b->accounts[b->num_accounts].balance = balance;

    // Increment the number of accounts
    b->num_accounts++;
}

// Find an account by name
account *find_account(bank *b, char *name) {
    for (int i = 0; i < b->num_accounts; i++) {
        if (strcmp(b->accounts[i].name, name) == 0) {
            return &b->accounts[i];
        }
    }

    return NULL;
}

// Withdraw money from an account
void withdraw_money(account *a, int amount) {
    if (amount <= 0) {
        printf("Error: cannot withdraw a non-positive amount of money\n");
        return;
    }

    if (amount > a->balance) {
        printf("Error: cannot withdraw more money than the account balance\n");
        return;
    }

    // Decrement the account balance
    a->balance -= amount;
}

// Deposit money into an account
void deposit_money(account *a, int amount) {
    if (amount <= 0) {
        printf("Error: cannot deposit a non-positive amount of money\n");
        return;
    }

    // Increment the account balance
    a->balance += amount;
}

// Print the account information
void print_account(account *a) {
    printf("Name: %s\n", a->name);
    printf("Password: %s\n", a->password);
    printf("Balance: %d\n", a->balance);
}

// Main function
int main() {
    // Create a new bank
    bank *b = new_bank();

    // Add some accounts to the bank
    add_account(b, "Alice", "password1", 1000);
    add_account(b, "Bob", "password2", 2000);
    add_account(b, "Charlie", "password3", 3000);

    // Find an account by name
    account *a = find_account(b, "Alice");

    // Print the account information
    print_account(a);

    // Withdraw money from the account
    withdraw_money(a, 500);

    // Print the account information again
    print_account(a);

    // Deposit money into the account
    deposit_money(a, 1000);

    // Print the account information one last time
    print_account(a);

    return 0;
}