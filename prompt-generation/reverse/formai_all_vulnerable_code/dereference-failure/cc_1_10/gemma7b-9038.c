//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

struct Transaction {
    char *name;
    int amount;
    struct Transaction *next;
};

struct Account {
    char *name;
    int account_number;
    struct Transaction *transactions;
    struct Account *next;
};

void add_transaction(struct Account *account, char *name, int amount) {
    struct Transaction *new_transaction = malloc(sizeof(struct Transaction));
    new_transaction->name = strdup(name);
    new_transaction->amount = amount;
    new_transaction->next = NULL;

    if (account->transactions == NULL) {
        account->transactions = new_transaction;
    } else {
        struct Transaction *current_transaction = account->transactions;
        while (current_transaction->next != NULL) {
            current_transaction = current_transaction->next;
        }
        current_transaction->next = new_transaction;
    }
}

void print_account(struct Account *account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Transactions:\n");
    struct Transaction *current_transaction = account->transactions;
    while (current_transaction) {
        printf("  Name: %s\n", current_transaction->name);
        printf("  Amount: %d\n", current_transaction->amount);
        printf("\n");
        current_transaction = current_transaction->next;
    }
}

int main() {
    struct Account *accounts = NULL;

    // Add some accounts
    struct Account *new_account = malloc(sizeof(struct Account));
    new_account->name = strdup("John Doe");
    new_account->account_number = 123456;
    new_account->transactions = NULL;
    add_transaction(new_account, "Buy groceries", 50);
    add_transaction(new_account, "Pay rent", 200);
    accounts = new_account;

    // Add another account
    new_account = malloc(sizeof(struct Account));
    new_account->name = strdup("Jane Doe");
    new_account->account_number = 654321;
    new_account->transactions = NULL;
    add_transaction(new_account, "Eat out", 100);
    add_transaction(new_account, "Transfer money", 250);
    accounts = new_account;

    // Print the accounts
    struct Account *current_account = accounts;
    while (current_account) {
        print_account(current_account);
        current_account = current_account->next;
    }

    return 0;
}