//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 50
#define MAX_ACCOUNT_NUMBER_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    float balance;
} Account;

typedef struct {
    char type;
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    float amount;
} Transaction;

Account accounts[MAX_ACCOUNTS];
Transaction transactions[MAX_TRANSACTIONS];
int numAccounts = 0;
int numTransactions = 0;

void createAccount(char* name, char* accountNumber) {
    strcpy(accounts[numAccounts].name, name);
    strcpy(accounts[numAccounts].accountNumber, accountNumber);
    accounts[numAccounts].balance = 0.0;
    numAccounts++;
}

int findAccount(char* accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            return i;
        }
    }
    return -1;
}

void deposit(char* accountNumber, float amount) {
    int accountIndex = findAccount(accountNumber);
    if (accountIndex!= -1) {
        accounts[accountIndex].balance += amount;
        strcpy(transactions[numTransactions].type, "Deposit");
        strcpy(transactions[numTransactions].accountNumber, accounts[accountIndex].accountNumber);
        transactions[numTransactions].amount = amount;
        numTransactions++;
    } else {
        printf("Account not found.\n");
    }
}

void withdraw(char* accountNumber, float amount) {
    int accountIndex = findAccount(accountNumber);
    if (accountIndex!= -1) {
        if (accounts[accountIndex].balance >= amount) {
            accounts[accountIndex].balance -= amount;
            strcpy(transactions[numTransactions].type, "Withdrawal");
            strcpy(transactions[numTransactions].accountNumber, accounts[accountIndex].accountNumber);
            transactions[numTransactions].amount = amount;
            numTransactions++;
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

void printAccounts() {
    for (int i = 0; i < numAccounts; i++) {
        printf("Name: %s\nAccount Number: %s\nBalance: $%.2f\n", accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }
}

void printTransactions() {
    for (int i = 0; i < numTransactions; i++) {
        printf("Transaction Type: %s\nAccount Number: %s\nAmount: $%.2f\n", transactions[i].type, transactions[i].accountNumber, transactions[i].amount);
    }
}

int main() {
    createAccount("John Doe", "123456789");
    createAccount("Jane Smith", "987654321");
    deposit("123456789", 1000.00);
    withdraw("123456789", 500.00);
    printAccounts();
    printTransactions();
    return 0;
}