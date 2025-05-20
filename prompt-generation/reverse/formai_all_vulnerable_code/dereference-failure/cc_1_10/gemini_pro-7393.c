//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct bank_account {
    char *name;
    int account_number;
    double balance;
} bank_account;

void create_account(bank_account **accounts, int *num_accounts, char *name, int account_number, double balance) {
    *accounts = realloc(*accounts, (*num_accounts + 1) * sizeof(bank_account));
    (*accounts)[*num_accounts].name = name;
    (*accounts)[*num_accounts].account_number = account_number;
    (*accounts)[*num_accounts].balance = balance;
    (*num_accounts)++;
}

void deposit(bank_account *accounts, int num_accounts, int account_number, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(bank_account *accounts, int num_accounts, int account_number, double amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                return;
            } else {
                printf("Insufficient funds.\n");
                return;
            }
        }
    }
    printf("Account not found.\n");
}

void print_accounts(bank_account *accounts, int num_accounts) {
    for (int i = 0; i < num_accounts; i++) {
        printf("Account %d: %s, %d, %.2f\n", i + 1, accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }
}

int main() {
    bank_account *accounts = NULL;
    int num_accounts = 0;

    create_account(&accounts, &num_accounts, "John Doe", 123456789, 1000.00);
    create_account(&accounts, &num_accounts, "Jane Doe", 987654321, 500.00);

    deposit(accounts, num_accounts, 123456789, 200.00);
    withdraw(accounts, num_accounts, 987654321, 300.00);

    print_accounts(accounts, num_accounts);

    return 0;
}