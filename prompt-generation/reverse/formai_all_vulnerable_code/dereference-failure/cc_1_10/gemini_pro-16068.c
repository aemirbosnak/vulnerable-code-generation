//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account structure
struct Account {
    char *name;
    int account_number;
    double balance;
};

// Function to create a new account
struct Account* create_account(char *name, int account_number, double balance) {
    struct Account *account = (struct Account*)malloc(sizeof(struct Account));
    account->name = (char*)malloc(strlen(name) + 1);
    strcpy(account->name, name);
    account->account_number = account_number;
    account->balance = balance;
    return account;
}

// Function to deposit money into an account
void deposit(struct Account *account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(struct Account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    }
}

// Function to print account information
void print_account(struct Account *account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create a new account
    struct Account *account = create_account("John Doe", 123456, 1000.0);

    // Deposit money into the account
    deposit(account, 500.0);

    // Withdraw money from the account
    withdraw(account, 300.0);

    // Print account information
    print_account(account);

    // Free the memory allocated for the account
    free(account->name);
    free(account);

    return 0;
}