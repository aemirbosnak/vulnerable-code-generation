//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BankAccount {
    char *name;
    long account_number;
    double balance;
} BankAccount;

BankAccount *create_account(char *name, long account_number, double balance) {
    BankAccount *account = (BankAccount *)malloc(sizeof(BankAccount));
    account->name = (char *)malloc(strlen(name) + 1);
    strcpy(account->name, name);
    account->account_number = account_number;
    account->balance = balance;
    return account;
}

void close_account(BankAccount *account) {
    free(account->name);
    free(account);
}

void deposit(BankAccount *account, double amount) {
    account->balance += amount;
}

void withdraw(BankAccount *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

void print_account(BankAccount *account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %ld\n", account->account_number);
    printf("Balance: %f\n", account->balance);
}

int main() {
    BankAccount *account1 = create_account("John Doe", 123456789, 1000.00);
    BankAccount *account2 = create_account("Jane Doe", 987654321, 2000.00);

    deposit(account1, 500.00);
    withdraw(account2, 300.00);

    print_account(account1);
    printf("\n");
    print_account(account2);
    printf("\n");

    close_account(account1);
    close_account(account2);

    return 0;
}