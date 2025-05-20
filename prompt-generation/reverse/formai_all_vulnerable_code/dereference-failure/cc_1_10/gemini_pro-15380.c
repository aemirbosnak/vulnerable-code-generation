//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_account {
    char *name;
    int account_number;
    double balance;
};

struct bank {
    struct bank_account *accounts;
    int num_accounts;
};

struct bank *create_bank() {
    struct bank *bank = malloc(sizeof(struct bank));
    bank->accounts = NULL;
    bank->num_accounts = 0;
    return bank;
}

void destroy_bank(struct bank *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        free(bank->accounts[i].name);
    }
    free(bank->accounts);
    free(bank);
}

struct bank_account *create_account(struct bank *bank, char *name, int account_number, double balance) {
    struct bank_account *account = malloc(sizeof(struct bank_account));
    account->name = strdup(name);
    account->account_number = account_number;
    account->balance = balance;
    bank->accounts = realloc(bank->accounts, (bank->num_accounts + 1) * sizeof(struct bank_account));
    bank->accounts[bank->num_accounts] = *account;
    bank->num_accounts++;
    return account;
}

void deposit(struct bank_account *account, double amount) {
    account->balance += amount;
}

void withdraw(struct bank_account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    }
}

double get_balance(struct bank_account *account) {
    return account->balance;
}

void print_account(struct bank_account *account) {
    printf("%s: %d %f\n", account->name, account->account_number, account->balance);
}

int main() {
    struct bank *bank = create_bank();

    struct bank_account *account1 = create_account(bank, "John Doe", 12345, 1000.0);
    struct bank_account *account2 = create_account(bank, "Jane Doe", 23456, 2000.0);

    deposit(account1, 500.0);
    withdraw(account2, 300.0);

    print_account(account1);
    print_account(account2);

    destroy_bank(bank);

    return 0;
}