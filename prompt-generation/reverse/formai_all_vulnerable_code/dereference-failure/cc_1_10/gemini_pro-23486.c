//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    char *name;
    int balance;
} account_t;

typedef struct bank {
    account_t *accounts;
    int num_accounts;
} bank_t;

bank_t *create_bank(void) {
    bank_t *bank = malloc(sizeof(bank_t));
    bank->accounts = NULL;
    bank->num_accounts = 0;
    return bank;
}

void destroy_bank(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        free(bank->accounts[i].name);
    }
    free(bank->accounts);
    free(bank);
}

account_t *create_account(char *name, int balance) {
    account_t *account = malloc(sizeof(account_t));
    account->name = strdup(name);
    account->balance = balance;
    return account;
}

void destroy_account(account_t *account) {
    free(account->name);
    free(account);
}

void add_account(bank_t *bank, account_t *account) {
    bank->accounts = realloc(bank->accounts, (bank->num_accounts + 1) * sizeof(account_t));
    bank->accounts[bank->num_accounts] = *account;
    bank->num_accounts++;
}

account_t *find_account(bank_t *bank, char *name) {
    for (int i = 0; i < bank->num_accounts; i++) {
        if (strcmp(bank->accounts[i].name, name) == 0) {
            return &bank->accounts[i];
        }
    }
    return NULL;
}

void deposit(account_t *account, int amount) {
    account->balance += amount;
}

void withdraw(account_t *account, int amount) {
    account->balance -= amount;
}

void transfer(account_t *from, account_t *to, int amount) {
    withdraw(from, amount);
    deposit(to, amount);
}

void print_bank(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        printf("%s: %d\n", bank->accounts[i].name, bank->accounts[i].balance);
    }
}

int main(void) {
    bank_t *bank = create_bank();

    account_t *alice = create_account("Alice", 100);
    account_t *bob = create_account("Bob", 200);
    account_t *charlie = create_account("Charlie", 300);

    add_account(bank, alice);
    add_account(bank, bob);
    add_account(bank, charlie);

    deposit(alice, 100);
    withdraw(bob, 50);
    transfer(charlie, alice, 150);

    print_bank(bank);

    destroy_account(alice);
    destroy_account(bob);
    destroy_account(charlie);
    destroy_bank(bank);

    return 0;
}