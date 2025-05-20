//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account structure
typedef struct account {
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

// Function to print account details
void print_account_details(account* account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %s\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create a new account
    account* account1 = create_account("John Doe", "1234567890", 1000.00);

    // Deposit money into the account
    deposit_money(account1, 500.00);

    // Withdraw money from the account
    withdraw_money(account1, 300.00);

    // Print account details
    print_account_details(account1);

    return 0;
}