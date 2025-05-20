//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a struct to store banking information
typedef struct {
    int accountNumber;
    char accountHolderName[50];
    int balance;
} Account;

// Function to create a new account
Account* createAccount(int accountNumber, char accountHolderName[], int balance) {
    Account* newAccount = (Account*)malloc(sizeof(Account));
    if (newAccount == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    strcpy(newAccount->accountHolderName, accountHolderName);
    newAccount->accountNumber = accountNumber;
    newAccount->balance = balance;

    return newAccount;
}

// Function to add money to an account
void deposit(Account* account, int amount) {
    account->balance += amount;
    printf("Deposited $%d. New balance: $%d\n", amount, account->balance);
}

// Function to withdraw money from an account
void withdraw(Account* account, int amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrew $%d. New balance: $%d\n", amount, account->balance);
    } else {
        printf("Insufficient funds\n");
    }
}

// Function to display account information
void displayAccount(Account* account) {
    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder Name: %s\n", account->accountHolderName);
    printf("Balance: $%d\n", account->balance);
}

// Main function
int main() {
    Account* account = createAccount(1234567890, "John Doe", 1000);
    deposit(account, 500);
    withdraw(account, 200);
    displayAccount(account);

    return 0;
}