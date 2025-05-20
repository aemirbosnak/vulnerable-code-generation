//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct TransactionNode {
    char type[50];
    int amount;
    char date[50];
    struct TransactionNode *next;
} TransactionNode;

typedef struct BankRecord {
    TransactionNode *head;
    TransactionNode *tail;
    int count;
} BankRecord;

BankRecord *createBankRecord() {
    BankRecord *record = (BankRecord *)malloc(sizeof(BankRecord));
    record->head = NULL;
    record->tail = NULL;
    record->count = 0;
    return record;
}

void addTransaction(BankRecord *record, char *type, int amount, char *date) {
    TransactionNode *newNode = (TransactionNode *)malloc(sizeof(TransactionNode));
    strcpy(newNode->type, type);
    newNode->amount = amount;
    strcpy(newNode->date, date);
    newNode->next = NULL;

    if (record->head == NULL) {
        record->head = newNode;
        record->tail = newNode;
    } else {
        record->tail->next = newNode;
        record->tail = newNode;
    }

    record->count++;
}

void deleteTransaction(BankRecord *record, char *type) {
    TransactionNode *current = record->head;
    TransactionNode *prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->type, type) == 0) {
            if (prev == NULL) {
                record->head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            record->count--;
            break;
        }

        prev = current;
        current = current->next;
    }
}

void displayTransactions(BankRecord *record) {
    TransactionNode *current = record->head;

    printf("Transactions:\n");
    while (current!= NULL) {
        printf("Type: %s, Amount: %d, Date: %s\n", current->type, current->amount, current->date);
        current = current->next;
    }
}

int main() {
    BankRecord *record = createBankRecord();

    addTransaction(record, "Deposit", 1000, "2022-01-01");
    addTransaction(record, "Withdrawal", 500, "2022-01-02");
    addTransaction(record, "Deposit", 2000, "2022-01-03");

    deleteTransaction(record, "Withdrawal");
    displayTransactions(record);

    return 0;
}