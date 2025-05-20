//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store bank account details
struct BankAccount {
    char name[50];
    char accountNumber[20];
    float balance;
};

// Function to create a new bank account
struct BankAccount* createAccount(char* name, char* accountNumber, float balance) {
    struct BankAccount* account = malloc(sizeof(struct BankAccount));
    strcpy(account->name, name);
    strcpy(account->accountNumber, accountNumber);
    account->balance = balance;
    return account;
}

// Function to deposit money into an account
void depositMoney(struct BankAccount* account, float amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdrawMoney(struct BankAccount* account, float amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to print the details of an account
void printAccountDetails(struct BankAccount* account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %s\n", account->accountNumber);
    printf("Balance: %f\n", account->balance);
}

// Main function
int main() {
    // Create two bank accounts
    struct BankAccount* account1 = createAccount("John Doe", "1234567890", 1000.0);
    struct BankAccount* account2 = createAccount("Jane Doe", "0987654321", 2000.0);

    // Deposit money into account1
    depositMoney(account1, 500.0);

    // Withdraw money from account2
    withdrawMoney(account2, 300.0);

    // Print the details of both accounts
    printAccountDetails(account1);
    printAccountDetails(account2);

    // Free the memory allocated for the bank accounts
    free(account1);
    free(account2);

    return 0;
}