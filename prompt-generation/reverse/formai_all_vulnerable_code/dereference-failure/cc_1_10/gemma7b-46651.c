//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store bank account information
typedef struct Account {
    char name[50];
    int account_number;
    double balance;
} Account;

// Function to create a new bank account
Account *create_account(char *name, int account_number, double balance) {
    Account *account = (Account *)malloc(sizeof(Account));
    strcpy(account->name, name);
    account->account_number = account_number;
    account->balance = balance;
    return account;
}

// Function to deposit money into a bank account
void deposit(Account *account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from a bank account
void withdraw(Account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds");
    }
}

// Function to transfer money between two bank accounts
void transfer(Account *account1, Account *account2, double amount) {
    if (amount <= account1->balance) {
        account1->balance -= amount;
        account2->balance += amount;
    } else {
        printf("Insufficient funds");
    }
}

int main() {
    // Create a new bank account
    Account *account = create_account("John Doe", 123456, 1000);

    // Deposit money into the account
    deposit(account, 500);

    // Withdraw money from the account
    withdraw(account, 200);

    // Transfer money between two accounts
    transfer(account, account, 200);

    // Print the account balance
    printf("Account balance: $%f", account->balance);

    return 0;
}