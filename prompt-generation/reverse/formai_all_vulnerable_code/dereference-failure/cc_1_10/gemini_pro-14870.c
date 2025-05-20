//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the bank account structure
typedef struct BankAccount {
    char *name;
    int account_number;
    double balance;
} BankAccount;

// Define the bank database
BankAccount accounts[100];
int num_accounts = 0;

// Function to create a new bank account
void create_account(char *name, int account_number, double balance) {
    accounts[num_accounts].name = strdup(name);
    accounts[num_accounts].account_number = account_number;
    accounts[num_accounts].balance = balance;
    num_accounts++;
}

// Function to deposit money into an account
void deposit_money(int account_number, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money from an account
void withdraw_money(int account_number, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                return;
            } else {
                printf("Insufficient funds!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

// Function to print the bank database
void print_database() {
    printf("Bank Database:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s %d %.2f\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }
}

// Main function
int main() {
    // Create some bank accounts
    create_account("John Doe", 123456, 1000.00);
    create_account("Jane Smith", 234567, 2000.00);
    create_account("Bill Jones", 345678, 3000.00);

    // Deposit money into an account
    deposit_money(123456, 500.00);

    // Withdraw money from an account
    withdraw_money(234567, 1000.00);

    // Print the bank database
    print_database();

    return 0;
}