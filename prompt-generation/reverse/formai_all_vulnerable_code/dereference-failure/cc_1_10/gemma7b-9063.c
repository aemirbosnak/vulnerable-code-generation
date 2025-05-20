//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

struct Transaction {
    char *name;
    int amount;
    struct Transaction *next;
};

struct BankRecord {
    char *account_number;
    struct Transaction *transactions;
    struct BankRecord *next;
};

void insert_transaction(struct BankRecord *record, char *name, int amount) {
    struct Transaction *new_transaction = malloc(sizeof(struct Transaction));
    new_transaction->name = strdup(name);
    new_transaction->amount = amount;
    new_transaction->next = NULL;

    if (record->transactions == NULL) {
        record->transactions = new_transaction;
    } else {
        struct Transaction *last_transaction = record->transactions;
        last_transaction->next = new_transaction;
    }
}

int main() {
    struct BankRecord *records = NULL;

    // Insert some transactions
    insert_transaction(records, "John Doe", 100);
    insert_transaction(records, "Jane Doe", 200);
    insert_transaction(records, "Bill Smith", 300);

    // Print all transactions
    struct BankRecord *current_record = records;
    while (current_record) {
        struct Transaction *current_transaction = current_record->transactions;
        while (current_transaction) {
            printf("Name: %s, Amount: %d\n", current_transaction->name, current_transaction->amount);
        }
        current_record = current_record->next;
    }

    return 0;
}