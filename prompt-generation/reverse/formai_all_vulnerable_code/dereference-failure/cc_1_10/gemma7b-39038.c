//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct Record {
    char name[50];
    char account_number[20];
    int account_balance;
    struct Record* next;
} Record;

Record* createRecord(char* name, char* account_number, int account_balance) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    strcpy(newRecord->account_number, account_number);
    newRecord->account_balance = account_balance;
    newRecord->next = NULL;

    return newRecord;
}

void addRecord(Record* head, char* name, char* account_number, int account_balance) {
    Record* newRecord = createRecord(name, account_number, account_balance);

    if (head == NULL) {
        head = newRecord;
    } else {
        newRecord->next = head;
        head = newRecord;
    }
}

void searchRecord(Record* head, char* account_number) {
    while (head) {
        if (strcmp(head->account_number, account_number) == 0) {
            printf("Name: %s\n", head->name);
            printf("Account Balance: %d\n", head->account_balance);
            return;
        }
        head = head->next;
    }

    printf("Record not found.\n");
}

int main() {
    Record* head = NULL;

    // Add some records
    addRecord(head, "Sherlock Holmes", "123456", 1000);
    addRecord(head, "John Watson", "456789", 2000);
    addRecord(head, "Dr. Watson", "698234", 3000);

    // Search for a record
    searchRecord(head, "123456");

    return 0;
}