//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 100

typedef struct BankRecord {
    char name[50];
    char account_number[20];
    int account_balance;
    struct BankRecord* next;
} BankRecord;

BankRecord* createBankRecord() {
    BankRecord* new_record = (BankRecord*)malloc(sizeof(BankRecord));
    new_record->next = NULL;
    return new_record;
}

void addBankRecord(BankRecord* head, char* name, char* account_number, int account_balance) {
    BankRecord* new_record = createBankRecord();
    strcpy(new_record->name, name);
    strcpy(new_record->account_number, account_number);
    new_record->account_balance = account_balance;

    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }
}

void printBankRecords(BankRecord* head) {
    while (head) {
        printf("%s (%s) - Balance: %d\n", head->name, head->account_number, head->account_balance);
        head = head->next;
    }
}

int main() {
    BankRecord* head = NULL;
    addBankRecord(head, "John Doe", "123456", 1000);
    addBankRecord(head, "Jane Doe", "789012", 2000);
    addBankRecord(head, "Mike Smith", "412369", 3000);

    printBankRecords(head);

    return 0;
}