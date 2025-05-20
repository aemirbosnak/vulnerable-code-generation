//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the account structure
typedef struct account {
    int account_number;
    char *name;
    double balance;
} account;

// Create a new account
account *create_account(int account_number, char *name, double balance) {
    // Allocate memory for the account
    account *new_account = malloc(sizeof(account));

    // Set the account's properties
    new_account->account_number = account_number;
    new_account->name = name;
    new_account->balance = balance;

    // Return the new account
    return new_account;
}

// Deposit money into an account
void deposit(account *account, double amount) {
    // Add the amount to the account's balance
    account->balance += amount;
}

// Withdraw money from an account
void withdraw(account *account, double amount) {
    // Subtract the amount from the account's balance
    account->balance -= amount;
}

// Print the account's information
void print_account(account *account) {
    // Print the account's properties
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create an array of accounts
    account *accounts[10];

    // Create a new account for John Doe with account number 1000 and balance 1000.00
    accounts[0] = create_account(1000, "John Doe", 1000.00);

    // Create a new account for Jane Doe with account number 1001 and balance 2000.00
    accounts[1] = create_account(1001, "Jane Doe", 2000.00);

    // Deposit 500.00 into John Doe's account
    deposit(accounts[0], 500.00);

    // Withdraw 200.00 from Jane Doe's account
    withdraw(accounts[1], 200.00);

    // Print the account information for both accounts
    print_account(accounts[0]);
    printf("\n");
    print_account(accounts[1]);

    // Free the memory allocated for the accounts
    free(accounts[0]);
    free(accounts[1]);

    return 0;
}