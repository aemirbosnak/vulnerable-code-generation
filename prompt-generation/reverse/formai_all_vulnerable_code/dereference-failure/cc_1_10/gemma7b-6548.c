//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Account {
    char name[50];
    int account_number;
    double balance;
    struct Account* next;
} Account;

Account* createAccount(char* name, int account_number, double balance) {
    Account* newAccount = (Account*)malloc(sizeof(Account));
    strcpy(newAccount->name, name);
    newAccount->account_number = account_number;
    newAccount->balance = balance;
    newAccount->next = NULL;
    return newAccount;
}

void deposit(Account* account, double amount) {
    account->balance += amount;
}

void withdraw(Account* account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void transfer(Account* fromAccount, Account* toAccount, double amount) {
    if (amount <= fromAccount->balance) {
        fromAccount->balance -= amount;
        toAccount->balance += amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

void printAccount(Account* account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Balance: %.2lf\n", account->balance);
}

int main() {
    Account* head = NULL;
    head = createAccount("John Doe", 123456, 1000.0);
    deposit(head, 500.0);
    withdraw(head, 200.0);
    transfer(head, createAccount("Jane Doe", 654321, 2000.0), 300.0);
    printAccount(head);

    return 0;
}