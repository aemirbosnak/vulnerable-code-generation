//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    char accountNumber[10];
    char customerName[50];
    int balance;
} Account;

Account* createAccount(char accountNumber[10], char customerName[50], int balance) {
    Account* account = (Account*)malloc(sizeof(Account));
    strcpy(account->accountNumber, accountNumber);
    strcpy(account->customerName, customerName);
    account->balance = balance;
    return account;
}

void displayAccount(Account* account) {
    printf("Account Number: %s\n", account->accountNumber);
    printf("Customer Name: %s\n", account->customerName);
    printf("Balance: %d\n", account->balance);
}

void deposit(Account* account, int amount) {
    account->balance += amount;
}

void withdraw(Account* account, int amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

int main() {
    char accountNumber[10] = "123456789";
    char customerName[50] = "John Doe";
    int balance = 1000;

    Account* account = createAccount(accountNumber, customerName, balance);

    displayAccount(account);

    deposit(account, 500);

    displayAccount(account);

    withdraw(account, 1000);

    displayAccount(account);

    free(account);

    return 0;
}