//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct BankingRecord {
    char name[50];
    int accountNo;
    double balance;
    struct BankingRecord* next;
};

void insertRecord(struct BankingRecord* head, struct BankingRecord* newRecord) {
    if (head == NULL) {
        head = newRecord;
    } else {
        insertRecord(head->next, newRecord);
    }
}

void searchRecord(struct BankingRecord* head, char* name) {
    if (head == NULL) {
        return;
    } else if (strcmp(head->name, name) == 0) {
        printf("Account No: %d\n", head->accountNo);
        printf("Balance: %.2lf\n", head->balance);
    } else {
        searchRecord(head->next, name);
    }
}

int main() {
    struct BankingRecord* head = NULL;
    struct BankingRecord* newRecord;

    // Inserting records
    newRecord = (struct BankingRecord*)malloc(sizeof(struct BankingRecord));
    strcpy(newRecord->name, "John Doe");
    newRecord->accountNo = 12345;
    newRecord->balance = 1000.0;
    insertRecord(head, newRecord);

    newRecord = (struct BankingRecord*)malloc(sizeof(struct BankingRecord));
    strcpy(newRecord->name, "Jane Doe");
    newRecord->accountNo = 65432;
    newRecord->balance = 2000.0;
    insertRecord(head, newRecord);

    // Searching for a record
    searchRecord(head, "John Doe");

    return 0;
}