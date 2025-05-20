//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a banking record
typedef struct {
    int accountNumber;
    char name[50];
    int balance;
} BankingRecord;

// Function to create a new account
BankingRecord* createAccount(int accountNumber, char name[50], int initialBalance) {
    BankingRecord* account = (BankingRecord*)malloc(sizeof(BankingRecord));
    account->accountNumber = accountNumber;
    strcpy(account->name, name);
    account->balance = initialBalance;
    return account;
}

// Function to deposit money into an account
void deposit(BankingRecord* account, int amount) {
    if (amount > 0) {
        account->balance += amount;
    } else {
        printf("Invalid deposit amount\n");
    }
}

// Function to withdraw money from an account
void withdraw(BankingRecord* account, int amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Invalid withdrawal amount\n");
    }
}

// Function to display account information
void displayAccount(BankingRecord* account) {
    printf("Account Number: %d\n", account->accountNumber);
    printf("Name: %s\n", account->name);
    printf("Balance: $%.2f\n", account->balance);
}

int main() {
    // Create a new account with account number 12345, name John Doe, and initial balance of $1000
    BankingRecord* account1 = createAccount(12345, "John Doe", 1000);

    // Deposit $500 into the account
    deposit(account1, 500);

    // Display account information
    displayAccount(account1);

    // Withdraw $200 from the account
    withdraw(account1, 200);

    // Display account information again
    displayAccount(account1);

    // Free the memory allocated for the account
    free(account1);

    return 0;
}