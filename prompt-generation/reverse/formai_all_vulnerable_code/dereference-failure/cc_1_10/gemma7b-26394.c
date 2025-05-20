//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 10

struct Transaction {
    char name[50];
    double amount;
    char type;
    struct Transaction* next;
};

struct BankRecord {
    struct Transaction* head;
    struct BankRecord* next;
};

int main() {
    struct BankRecord* record = NULL;
    struct Transaction* transaction = NULL;

    // Create a new bank record
    record = malloc(sizeof(struct BankRecord));
    record->head = NULL;

    // Create a new transaction
    transaction = malloc(sizeof(struct Transaction));
    strcpy(transaction->name, "John Doe");
    transaction->amount = 100.0;
    transaction->type = 'D';
    transaction->next = NULL;

    // Add the transaction to the bank record
    if (record->head == NULL) {
        record->head = transaction;
    } else {
        record->head->next = transaction;
    }

    // Print the bank record
    struct Transaction* currentTransaction = record->head;
    while (currentTransaction) {
        printf("Name: %s\n", currentTransaction->name);
        printf("Amount: %.2lf\n", currentTransaction->amount);
        printf("Type: %c\n", currentTransaction->type);
        printf("\n");
        currentTransaction = currentTransaction->next;
    }

    return 0;
}