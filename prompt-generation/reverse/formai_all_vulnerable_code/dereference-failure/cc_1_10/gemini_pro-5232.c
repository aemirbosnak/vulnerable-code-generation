//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char *name;
    double balance;
} account_t;

account_t *accounts;
int num_accounts = 0;

void create_account(int account_number, char *name, double balance) {
    accounts = realloc(accounts, (num_accounts + 1) * sizeof(account_t));
    accounts[num_accounts].account_number = account_number;
    accounts[num_accounts].name = strdup(name);
    accounts[num_accounts].balance = balance;
    num_accounts++;
}

account_t *find_account(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            return &accounts[i];
        }
    }
    return NULL;
}

void deposit(int account_number, double amount) {
    account_t *account = find_account(account_number);
    if (account) {
        account->balance += amount;
    }
}

void withdraw(int account_number, double amount) {
    account_t *account = find_account(account_number);
    if (account && account->balance >= amount) {
        account->balance -= amount;
    }
}

void transfer(int from_account_number, int to_account_number, double amount) {
    account_t *from_account = find_account(from_account_number);
    account_t *to_account = find_account(to_account_number);
    if (from_account && to_account && from_account->balance >= amount) {
        from_account->balance -= amount;
        to_account->balance += amount;
    }
}

void print_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("Account %d: %s, %.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
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