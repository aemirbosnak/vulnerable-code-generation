//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 10

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

void add_transaction(struct Account *account, int amount, char *name) {
    struct Transaction *new_transaction = (struct Transaction *)malloc(sizeof(struct Transaction));
    new_transaction->name = strdup(name);
    new_transaction->amount = amount;
    new_transaction->next = NULL;

    if (account->transactions == NULL) {
        account->transactions = new_transaction;
    } else {
        account->transactions->next = new_transaction;
    }
}

void print_account(struct Account *account) {
    printf("Account Name: %s\n", account->name);
    printf("Account Number: %d\n", account->account_number);
    printf("Transactions:\n");

    struct Transaction *transaction = account->transactions;
    while (transaction) {
        printf("  - Name: %s, Amount: %d\n", transaction->name, transaction->amount);
        transaction = transaction->next;
    }
}

int main() {
    struct Account *account = (struct Account *)malloc(sizeof(struct Account));
    account->name = strdup("John Doe");
    account->account_number = 123456;
    account->transactions = NULL;

    add_transaction(account, 200, "Purchase of groceries");
    add_transaction(account, 50, "Payment to rent");
    add_transaction(account, 10, "Withdrawal of cash");

    print_account(account);

    return 0;
}