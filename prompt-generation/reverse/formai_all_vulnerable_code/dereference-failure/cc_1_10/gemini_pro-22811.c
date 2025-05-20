//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
    int account_number;
    char *name;
    double balance;
} account;

// Function to create a new account
account *create_account(int account_number, char *name, double balance) {
    // Allocate memory for the new account
    account *new_account = malloc(sizeof(account));

    // Set the account number, name, and balance
    new_account->account_number = account_number;
    new_account->name = strdup(name);
    new_account->balance = balance;

    // Return the new account
    return new_account;
}

// Function to deposit money into an account
void deposit_money(account *account, double amount) {
    // Add the amount to the account balance
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(account *account, double amount) {
    // Subtract the amount from the account balance
    account->balance -= amount;
}

// Function to print the account details
void print_account(account *account) {
    // Print the account number, name, and balance
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create an array of accounts
    account *accounts[MAX_ACCOUNTS];

    // Initialize the accounts
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        accounts[i] = NULL;
    }

    // Create a new account
    account *new_account = create_account(123456, "John Doe", 1000.00);

    // Add the new account to the array of accounts
    accounts[0] = new_account;

    // Deposit money into the new account
    deposit_money(new_account, 500.00);

    // Withdraw money from the new account
    withdraw_money(new_account, 200.00);

    // Print the account details
    print_account(new_account);

    // Free the memory allocated for the account
    free(new_account->name);
    free(new_account);

    return 0;
}