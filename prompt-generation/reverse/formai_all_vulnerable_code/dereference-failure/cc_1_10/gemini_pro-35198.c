//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int account_number;
    char *name;
    double balance;
} account_t;

account_t accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void create_account(int account_number, char *name, double balance) {
    accounts[num_accounts].account_number = account_number;
    accounts[num_accounts].name = malloc(strlen(name) + 1);
    strcpy(accounts[num_accounts].name, name);
    accounts[num_accounts].balance = balance;
    num_accounts++;
}

account_t *get_account(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            return &accounts[i];
        }
    }
    return NULL;
}

void deposit(int account_number, double amount) {
    account_t *account = get_account(account_number);
    if (account != NULL) {
        account->balance += amount;
    }
}

void withdraw(int account_number, double amount) {
    account_t *account = get_account(account_number);
    if (account != NULL) {
        if (account->balance >= amount) {
            account->balance -= amount;
        }
    }
}

void transfer(int from_account_number, int to_account_number, double amount) {
    account_t *from_account = get_account(from_account_number);
    account_t *to_account = get_account(to_account_number);
    if (from_account != NULL && to_account != NULL) {
        if (from_account->balance >= amount) {
            from_account->balance -= amount;
            to_account->balance += amount;
        }
    }
}

void print_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n\n", accounts[i].balance);
    }
}

int main() {
    create_account(12345, "John Doe", 1000.00);
    create_account(54321, "Jane Doe", 2000.00);

    deposit(12345, 500.00);
    withdraw(54321, 300.00);
    transfer(12345, 54321, 200.00);

    print_accounts();

    return 0;
}