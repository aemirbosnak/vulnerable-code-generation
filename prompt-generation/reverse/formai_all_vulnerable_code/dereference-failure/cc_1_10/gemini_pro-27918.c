//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct account {
    int account_number;
    char name[50];
    double balance;
} account_t;

// Function to create a new account
account_t* create_account(int account_number, char *name, double balance) {
    account_t *account = (account_t*)malloc(sizeof(account_t));
    account->account_number = account_number;
    strcpy(account->name, name);
    account->balance = balance;
    return account;
}

// Function to deposit money into an account
void deposit_money(account_t *account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(account_t *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to print the account details
void print_account(account_t *account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create an array of accounts
    account_t *accounts[MAX_ACCOUNTS];

    // Create a few accounts
    accounts[0] = create_account(123456, "John Doe", 1000.00);
    accounts[1] = create_account(654321, "Jane Doe", 2000.00);
    accounts[2] = create_account(789012, "John Smith", 3000.00);

    // Deposit money into an account
    deposit_money(accounts[0], 500.00);

    // Withdraw money from an account
    withdraw_money(accounts[1], 1000.00);

    // Print the account details
    print_account(accounts[0]);
    print_account(accounts[1]);
    print_account(accounts[2]);

    return 0;
}