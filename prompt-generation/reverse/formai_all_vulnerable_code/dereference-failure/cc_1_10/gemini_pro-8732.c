//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account structure
typedef struct {
    char name[256];
    char address[256];
    int account_number;
    double balance;
} Account;

// Create a new account
Account* create_account(char* name, char* address, int account_number, double balance) {
    Account* account = malloc(sizeof(Account));
    strcpy(account->name, name);
    strcpy(account->address, address);
    account->account_number = account_number;
    account->balance = balance;
    return account;
}

// Deposit money into an account
void deposit(Account* account, double amount) {
    account->balance += amount;
}

// Withdraw money from an account
void withdraw(Account* account, double amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Transfer money between accounts
void transfer(Account* from_account, Account* to_account, double amount) {
    if (from_account->balance >= amount) {
        from_account->balance -= amount;
        to_account->balance += amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Print an account statement
void print_statement(Account* account) {
    printf("Account Statement\n");
    printf("Name: %s\n", account->name);
    printf("Address: %s\n", account->address);
    printf("Account Number: %d\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    // Create three accounts
    Account* account1 = create_account("John Doe", "123 Main Street", 123456, 1000.00);
    Account* account2 = create_account("Jane Doe", "456 Oak Street", 234567, 2000.00);
    Account* account3 = create_account("Bill Smith", "789 Elm Street", 345678, 3000.00);

    // Deposit money into account1
    deposit(account1, 500.00);

    // Withdraw money from account2
    withdraw(account2, 300.00);

    // Transfer money from account3 to account1
    transfer(account3, account1, 200.00);

    // Print the account statements
    print_statement(account1);
    print_statement(account2);
    print_statement(account3);

    return 0;
}