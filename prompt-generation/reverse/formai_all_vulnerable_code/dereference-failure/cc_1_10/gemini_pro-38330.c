//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold account information
struct account {
    char name[50];
    char account_number[20];
    double balance;
};

// Function to create a new account
struct account* create_account(char* name, char* account_number, double balance) {
    struct account* new_account = (struct account*)malloc(sizeof(struct account));
    strcpy(new_account->name, name);
    strcpy(new_account->account_number, account_number);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit_money(struct account* account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(struct account* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to print account information
void print_account(struct account* account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %s\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create an array of accounts
    struct account* accounts[100];

    // Create a new account
    struct account* account1 = create_account("John Doe", "1234567890", 1000.00);
    accounts[0] = account1;

    // Deposit money into the account
    deposit_money(account1, 500.00);

    // Withdraw money from the account
    withdraw_money(account1, 300.00);

    // Print account information
    print_account(account1);

    return 0;
}