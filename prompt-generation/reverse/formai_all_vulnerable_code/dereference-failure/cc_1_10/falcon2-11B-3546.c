//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the bank account
typedef struct {
    char accountNumber[20];
    float balance;
    int accountType;
} BankAccount;

// Function to create a new bank account
BankAccount* createAccount(char* accountNumber, float initialBalance, int accountType) {
    BankAccount* newAccount = (BankAccount*)malloc(sizeof(BankAccount));
    if (newAccount == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newAccount->accountNumber, accountNumber);
    newAccount->balance = initialBalance;
    newAccount->accountType = accountType;
    return newAccount;
}

// Function to display the details of a bank account
void displayAccountDetails(BankAccount* account) {
    printf("Account Number: %s\n", account->accountNumber);
    printf("Balance: $%.2f\n", account->balance);
    printf("Account Type: %d\n", account->accountType);
}

// Function to deposit money into a bank account
void deposit(BankAccount* account, float amount) {
    if (amount <= 0) {
        printf("Invalid deposit amount\n");
        return;
    }
    account->balance += amount;
    printf("Deposit successful. New balance: $%.2f\n", account->balance);
}

// Function to withdraw money from a bank account
void withdraw(BankAccount* account, float amount) {
    if (amount <= 0) {
        printf("Invalid withdrawal amount\n");
        return;
    }
    if (amount > account->balance) {
        printf("Insufficient funds\n");
        return;
    }
    account->balance -= amount;
    printf("Withdrawal successful. New balance: $%.2f\n", account->balance);
}

// Function to transfer money from one bank account to another
void transfer(BankAccount* account, float amount, BankAccount* recipient) {
    if (amount <= 0) {
        printf("Invalid transfer amount\n");
        return;
    }
    if (amount > account->balance) {
        printf("Insufficient funds\n");
        return;
    }
    account->balance -= amount;
    recipient->balance += amount;
    printf("Transfer successful. New balances: $%.2f and $%.2f\n", account->balance, recipient->balance);
}

int main() {
    // Create a new bank account
    char accountNumber[20] = "123456789";
    float initialBalance = 1000.00;
    int accountType = 1;
    BankAccount* account = createAccount(accountNumber, initialBalance, accountType);
    if (account == NULL) {
        return 1;
    }
    
    // Display the details of the bank account
    displayAccountDetails(account);
    
    // Deposit money into the bank account
    deposit(account, 500.00);
    
    // Withdraw money from the bank account
    withdraw(account, 200.00);
    
    // Transfer money from the bank account to another
    BankAccount* recipient = createAccount("987654321", 500.00, 2);
    if (recipient == NULL) {
        return 1;
    }
    transfer(account, 300.00, recipient);
    
    // Display the details of the bank account again
    displayAccountDetails(account);
    
    free(account);
    free(recipient);
    return 0;
}