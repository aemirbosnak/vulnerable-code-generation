//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold customer account details
typedef struct account {
    int account_number;
    char name[51];
    double balance;
} account;

// Function to create a new customer account
account* create_account(int account_number, char* name, double balance) {
    account* new_account = (account*) malloc(sizeof(account));
    new_account->account_number = account_number;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit(account* account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(account* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    }
    else {
        printf("Insufficient funds!\n");
    }
}

// Function to display account details
void display_account(account* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create an array of accounts
    account* accounts[100];

    // Create a few sample accounts
    accounts[0] = create_account(12345, "John Doe", 1000.00);
    accounts[1] = create_account(67890, "Jane Smith", 2000.00);
    accounts[2] = create_account(111222, "Bob Jones", 3000.00);

    // Deposit money into John Doe's account
    deposit(accounts[0], 500.00);

    // Withdraw money from Jane Smith's account
    withdraw(accounts[1], 1000.00);

    // Display account details for all accounts
    for (int i = 0; i < 3; i++) {
        display_account(accounts[i]);
        printf("\n");
    }

    return 0;
}