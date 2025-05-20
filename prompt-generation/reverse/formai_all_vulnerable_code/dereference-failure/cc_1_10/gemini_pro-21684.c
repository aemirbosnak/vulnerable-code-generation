//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct bank_account {
    int account_number;
    char *name;
    double balance;
};

struct bank {
    struct bank_account *accounts;
    int num_accounts;
};

struct bank *create_bank(int num_accounts) {
    struct bank *bank = malloc(sizeof(struct bank));
    bank->accounts = malloc(sizeof(struct bank_account) * num_accounts);
    bank->num_accounts = num_accounts;
    return bank;
}

void destroy_bank(struct bank *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        free(bank->accounts[i].name);
    }
    free(bank->accounts);
    free(bank);
}

struct bank_account *create_account(struct bank *bank, int account_number, char *name, double balance) {
    struct bank_account *account = &bank->accounts[account_number];
    account->account_number = account_number;
    account->name = malloc(strlen(name) + 1);
    strcpy(account->name, name);
    account->balance = balance;
    return account;
}

void destroy_account(struct bank_account *account) {
    free(account->name);
}

double get_balance(struct bank_account *account) {
    return account->balance;
}

void deposit(struct bank_account *account, double amount) {
    account->balance += amount;
}

void withdraw(struct bank_account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    }
}

void transfer(struct bank *bank, int from_account_number, int to_account_number, double amount) {
    struct bank_account *from_account = &bank->accounts[from_account_number];
    struct bank_account *to_account = &bank->accounts[to_account_number];
    if (amount <= from_account->balance) {
        from_account->balance -= amount;
        to_account->balance += amount;
    }
}

void print_bank(struct bank *bank) {
    for (int i = 0; i < bank->num_accounts; i++) {
        struct bank_account *account = &bank->accounts[i];
        printf("Account %d: %s, $%.2f\n", account->account_number, account->name, account->balance);
    }
}

int main() {
    struct bank *bank = create_bank(3);

    struct bank_account *account1 = create_account(bank, 0, "Alice", 1000.0);
    struct bank_account *account2 = create_account(bank, 1, "Bob", 2000.0);
    struct bank_account *account3 = create_account(bank, 2, "Charlie", 3000.0);

    deposit(account1, 500.0);
    withdraw(account2, 1000.0);
    transfer(bank, 1, 2, 500.0);

    print_bank(bank);

    destroy_account(account1);
    destroy_account(account2);
    destroy_account(account3);
    destroy_bank(bank);

    return 0;
}