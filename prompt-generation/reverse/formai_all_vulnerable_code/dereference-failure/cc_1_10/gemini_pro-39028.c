//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int balance;
} account_t;

typedef struct {
    account_t *accounts;
    int num_accounts;
} bank_t;

bank_t *bank_create() {
    bank_t *bank = malloc(sizeof(bank_t));
    bank->accounts = NULL;
    bank->num_accounts = 0;
    return bank;
}

void bank_destroy(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        free(bank->accounts[i].name);
    }
    free(bank->accounts);
    free(bank);
}

account_t *bank_create_account(bank_t *bank, char *name) {
    bank->accounts = realloc(bank->accounts, sizeof(account_t) * (bank->num_accounts + 1));
    bank->accounts[bank->num_accounts].name = strdup(name);
    bank->accounts[bank->num_accounts].balance = 0;
    bank->num_accounts++;
    return &bank->accounts[bank->num_accounts - 1];
}

void bank_deposit(account_t *account, int amount) {
    account->balance += amount;
}

void bank_withdraw(account_t *account, int amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds\n");
    }
}

void bank_print_accounts(bank_t *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        printf("%s: %d\n", bank->accounts[i].name, bank->accounts[i].balance);
    }
}

int main() {
    bank_t *bank = bank_create();

    account_t *account1 = bank_create_account(bank, "Peasant John");
    bank_deposit(account1, 100);

    account_t *account2 = bank_create_account(bank, "Lady Mary");
    bank_deposit(account2, 500);

    account_t *account3 = bank_create_account(bank, "Lord William");
    bank_deposit(account3, 1000);

    bank_print_accounts(bank);

    bank_withdraw(account1, 50);
    bank_withdraw(account2, 100);
    bank_withdraw(account3, 200);

    printf("\nAfter withdrawals:\n");
    bank_print_accounts(bank);

    bank_destroy(bank);

    return 0;
}