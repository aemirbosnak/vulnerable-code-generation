//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[50];
    char account_number[20];
    double balance;
} account;

// Function to create a new account
account* create_account(char* name, char* account_number, double balance) {
    account* new_account = malloc(sizeof(account));
    strcpy(new_account->name, name);
    strcpy(new_account->account_number, account_number);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit_money(account* account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(account* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to print the details of an account
void print_account(account* account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %s\n", account->account_number);
    printf("Balance: %lf\n", account->balance);
}

// Main function
int main() {
    // Create an array of accounts
    account* accounts[100];

    // Create a new account
    accounts[0] = create_account("John Doe", "1234567890", 1000.0);

    // Deposit money into the account
    deposit_money(accounts[0], 500.0);

    // Withdraw money from the account
    withdraw_money(accounts[0], 300.0);

    // Print the details of the account
    print_account(accounts[0]);

    return 0;
}