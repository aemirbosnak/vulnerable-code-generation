//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int account_number;
    double balance;
    struct Record* next;
} Record;

Record* createRecord() {
    Record* new_record = malloc(sizeof(Record));
    new_record->next = NULL;
    return new_record;
}

void addRecord(Record* head, char* name, int account_number, double balance) {
    Record* new_record = createRecord();
    strcpy(new_record->name, name);
    new_record->account_number = account_number;
    new_record->balance = balance;
    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }
}

void printRecords(Record* head) {
    Record* current_record = head;
    while (current_record) {
        printf("Name: %s\n", current_record->name);
        printf("Account Number: %d\n", current_record->account_number);
        printf("Balance: %.2lf\n", current_record->balance);
        printf("\n");
        current_record = current_record->next;
    }
}

int main() {
    Record* head = NULL;
    addRecord(head, "John Doe", 123456, 1000.0);
    addRecord(head, "Jane Doe", 543214, 2000.0);
    addRecord(head, "Bill Smith", 324681, 3000.0);
    printRecords(head);

    return 0;
}