//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_account {
    int account_number;
    char *account_holder_name;
    double account_balance;
};

struct bank_database {
    struct bank_account *accounts;
    int num_accounts;
};

struct bank_database *create_bank_database() {
    struct bank_database *database = malloc(sizeof(struct bank_database));
    database->accounts = NULL;
    database->num_accounts = 0;
    return database;
}

void destroy_bank_database(struct bank_database *database) {
    for (int i = 0; i < database->num_accounts; i++) {
        free(database->accounts[i].account_holder_name);
    }
    free(database->accounts);
    free(database);
}

int add_account(struct bank_database *database, int account_number, const char *account_holder_name, double account_balance) {
    database->accounts = realloc(database->accounts, (database->num_accounts + 1) * sizeof(struct bank_account));
    database->accounts[database->num_accounts].account_number = account_number;
    database->accounts[database->num_accounts].account_holder_name = strdup(account_holder_name);
    database->accounts[database->num_accounts].account_balance = account_balance;
    database->num_accounts++;
    return 0;
}

int get_account_balance(struct bank_database *database, int account_number) {
    for (int i = 0; i < database->num_accounts; i++) {
        if (database->accounts[i].account_number == account_number) {
            return database->accounts[i].account_balance;
        }
    }
    return -1;
}

int withdraw_money(struct bank_database *database, int account_number, double amount) {
    for (int i = 0; i < database->num_accounts; i++) {
        if (database->accounts[i].account_number == account_number) {
            if (database->accounts[i].account_balance >= amount) {
                database->accounts[i].account_balance -= amount;
                return 0;
            } else {
                return -1;  // Insufficient funds
            }
        }
    }
    return -2;  // Account not found
}

int deposit_money(struct bank_database *database, int account_number, double amount) {
    for (int i = 0; i < database->num_accounts; i++) {
        if (database->accounts[i].account_number == account_number) {
            database->accounts[i].account_balance += amount;
            return 0;
        }
    }
    return -1;  // Account not found
}

int main() {
    struct bank_database *database = create_bank_database();
    add_account(database, 123456, "John Doe", 1000.00);
    add_account(database, 654321, "Jane Doe", 2000.00);
    printf("John Doe's account balance: $%.2f\n", get_account_balance(database, 123456));
    withdraw_money(database, 123456, 500.00);
    printf("John Doe's account balance after withdrawal: $%.2f\n", get_account_balance(database, 123456));
    deposit_money(database, 654321, 1000.00);
    printf("Jane Doe's account balance after deposit: $%.2f\n", get_account_balance(database, 654321));
    destroy_bank_database(database);
    return 0;
}