//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a bank account
struct BankAccount {
    int accountNumber;
    char ownerName[50];
    float balance;
};

// Function to create a new bank account
struct BankAccount* createAccount() {
    struct BankAccount* account = (struct BankAccount*)malloc(sizeof(struct BankAccount));
    account->accountNumber = 0;
    account->ownerName[0] = '\0';
    account->balance = 0.0;
    return account;
}

// Function to deposit money into an account
void deposit(struct BankAccount* account, float amount) {
    if (amount > 0) {
        account->balance += amount;
    } else {
        printf("Invalid deposit amount!\n");
    }
}

// Function to withdraw money from an account
void withdraw(struct BankAccount* account, float amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Invalid withdrawal amount!\n");
    }
}

// Function to display account details
void displayAccount(struct BankAccount* account) {
    printf("Account Number: %d\n", account->accountNumber);
    printf("Owner Name: %s\n", account->ownerName);
    printf("Balance: %.2f\n", account->balance);
}

// Main function
int main() {
    struct BankAccount* account1 = createAccount();
    deposit(account1, 1000);
    withdraw(account1, 500);
    displayAccount(account1);

    struct BankAccount* account2 = createAccount();
    deposit(account2, 2000);
    withdraw(account2, 1500);
    displayAccount(account2);

    return 0;
}