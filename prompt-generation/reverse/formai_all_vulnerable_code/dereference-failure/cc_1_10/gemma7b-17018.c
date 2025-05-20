//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int account_no;
    double balance;
    struct Record* next;
} Record;

Record* createRecord(char* name, int account_no, double balance) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->account_no = account_no;
    newRecord->balance = balance;
    newRecord->next = NULL;
    return newRecord;
}

void insertRecord(Record* head, Record* newRecord) {
    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
        head = newRecord;
    }
}

void printRecords(Record* head) {
    while (head) {
        printf("Name: %s, Account No: %d, Balance: %.2lf\n", head->name, head->account_no, head->balance);
        head = head->next;
    }
}

int main() {
    Record* head = NULL;

    // Create some records
    Record* newRecord1 = createRecord("John Doe", 123456, 1000.0);
    insertRecord(head, newRecord1);

    Record* newRecord2 = createRecord("Jane Doe", 654321, 500.0);
    insertRecord(head, newRecord2);

    Record* newRecord3 = createRecord("Peter Pan", 984123, 200.0);
    insertRecord(head, newRecord3);

    // Print the records
    printRecords(head);

    return 0;
}