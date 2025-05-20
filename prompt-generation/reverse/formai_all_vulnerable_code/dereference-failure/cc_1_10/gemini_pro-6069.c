//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bank_account {
    char *name;
    char *account_number;
    double balance;
} bank_account;

void create_account(bank_account **account, char *name, char *account_number) {
    *account = malloc(sizeof(bank_account));
    (*account)->name = malloc(strlen(name) + 1);
    strcpy((*account)->name, name);
    (*account)->account_number = malloc(strlen(account_number) + 1);
    strcpy((*account)->account_number, account_number);
    (*account)->balance = 0.0;
}

void deposit(bank_account *account, double amount) {
    account->balance += amount;
}

void withdraw(bank_account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    }
}

void transfer(bank_account *from_account, bank_account *to_account, double amount) {
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    }
}

void print_account(bank_account *account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %s\n", account->account_number);
    printf("Balance: %.2f\n", account->balance);
}

int main() {
    bank_account *accounts[10];

    create_account(&accounts[0], "John Doe", "1234567890");
    deposit(accounts[0], 1000.0);

    create_account(&accounts[1], "Jane Doe", "9876543210");
    deposit(accounts[1], 500.0);

    transfer(accounts[0], accounts[1], 200.0);

    print_account(accounts[0]);
    print_account(accounts[1]);

    return 0;
}