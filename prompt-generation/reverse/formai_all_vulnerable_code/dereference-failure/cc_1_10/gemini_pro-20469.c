//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct bank_account {
    int account_number;
    char *account_holder;
    double balance;
};

struct bank_database {
    struct bank_account *accounts;
    int num_accounts;
};

struct bank_database *create_database(int num_accounts) {
    struct bank_database *db = malloc(sizeof(struct bank_database));
    db->accounts = malloc(sizeof(struct bank_account) * num_accounts);
    db->num_accounts = num_accounts;
    return db;
}

void destroy_database(struct bank_database *db) {
    free(db->accounts);
    free(db);
}

void add_account(struct bank_database *db, int account_number, char *account_holder, double balance) {
    db->accounts[db->num_accounts].account_number = account_number;
    db->accounts[db->num_accounts].account_holder = account_holder;
    db->accounts[db->num_accounts].balance = balance;
    db->num_accounts++;
}

struct bank_account *get_account(struct bank_database *db, int account_number) {
    for (int i = 0; i < db->num_accounts; i++) {
        if (db->accounts[i].account_number == account_number) {
            return &db->accounts[i];
        }
    }
    return NULL;
}

void deposit(struct bank_account *account, double amount) {
    account->balance += amount;
}

void withdraw(struct bank_account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    }
}

void print_account(struct bank_account *account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Account Holder: %s\n", account->account_holder);
    printf("Balance: %.2f\n", account->balance);
}

int main() {
    struct bank_database *db = create_database(10);

    add_account(db, 123456, "John Doe", 1000.00);
    add_account(db, 654321, "Jane Doe", 2000.00);

    struct bank_account *account = get_account(db, 123456);
    deposit(account, 500.00);
    withdraw(account, 200.00);

    print_account(account);

    destroy_database(db);

    return 0;
}