//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
typedef struct Account {
    char name[50];
    char account_number[20];
    double balance;
} Account;

// Function to create a new account
Account* create_account(char* name, char* account_number, double balance) {
    Account* account = (Account*)malloc(sizeof(Account));
    strcpy(account->name, name);
    strcpy(account->account_number, account_number);
    account->balance = balance;
    return account;
}

// Function to deposit money into an account
void deposit_money(Account* account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(Account* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to print account details
void print_account_details(Account* account) {
    printf("Name: %s\n", account->name);
    printf("Account number: %s\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create an array of accounts
    Account* accounts[100];
    int num_accounts = 0;

    // Create a new account and add it to the array
    accounts[num_accounts++] = create_account("John Doe", "1234567890", 1000.0);

    // Deposit money into the account
    deposit_money(accounts[0], 500.0);

    // Withdraw money from the account
    withdraw_money(accounts[0], 300.0);

    // Print the account details
    print_account_details(accounts[0]);

    return 0;
}