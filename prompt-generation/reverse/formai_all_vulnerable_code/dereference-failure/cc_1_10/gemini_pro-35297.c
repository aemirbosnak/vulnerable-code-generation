//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
struct account {
    char name[50];
    char account_number[20];
    float balance;
};

// Function to create a new account
struct account* create_account(char* name, char* account_number, float balance) {
    struct account* new_account = (struct account*)malloc(sizeof(struct account));
    strcpy(new_account->name, name);
    strcpy(new_account->account_number, account_number);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit_money(struct account* account, float amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(struct account* account, float amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient balance\n");
    }
}

// Function to print account details
void print_account_details(struct account* account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %s\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create a new account
    struct account* account = create_account("John Doe", "1234567890", 1000.0);

    // Deposit money into the account
    deposit_money(account, 500.0);

    // Withdraw money from the account
    withdraw_money(account, 300.0);

    // Print account details
    print_account_details(account);

    return 0;
}