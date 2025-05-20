//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank account information
typedef struct bank_account {
    char name[50];
    int account_number;
    double balance;
} bank_account;

// Function to create a new bank account
bank_account *create_account(char *name, int account_number, double balance) {
    bank_account *new_account = (bank_account *)malloc(sizeof(bank_account));
    strcpy(new_account->name, name);
    new_account->account_number = account_number;
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into a bank account
void deposit(bank_account *account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from a bank account
void withdraw(bank_account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds");
    }
}

// Function to display bank account information
void display_account(bank_account *account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Balance: %.2lf\n", account->balance);
}

int main() {
    // Create a new bank account
    bank_account *account = create_account("John Doe", 123456, 1000.0);

    // Deposit money into the account
    deposit(account, 500.0);

    // Withdraw money from the account
    withdraw(account, 200.0);

    // Display bank account information
    display_account(account);

    return 0;
}