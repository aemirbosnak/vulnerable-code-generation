//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
struct account {
    char name[50];
    int account_number;
    double balance;
};

// Function to create a new account
struct account* create_account(char* name, int account_number, double balance) {
    struct account* new_account = (struct account*)malloc(sizeof(struct account));
    strcpy(new_account->name, name);
    new_account->account_number = account_number;
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit(struct account* account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(struct account* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to print account details
void print_account(struct account* account) {
    printf("Name: %s\n", account->name);
    printf("Account number: %d\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create an array of accounts
    struct account* accounts[100];

    // Create a new account
    accounts[0] = create_account("John Doe", 123456789, 1000.00);

    // Deposit money into the account
    deposit(accounts[0], 500.00);

    // Withdraw money from the account
    withdraw(accounts[0], 200.00);

    // Print account details
    print_account(accounts[0]);

    return 0;
}