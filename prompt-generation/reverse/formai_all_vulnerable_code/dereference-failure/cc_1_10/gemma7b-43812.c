//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <string.h>

// Define a Banking Record Structure
typedef struct BankingRecord {
    char name[50];
    int accountNo;
    double balance;
    struct BankingRecord* next;
} BankingRecord;

// Create a Banking Record Node
BankingRecord* createRecord() {
    BankingRecord* newRecord = (BankingRecord*)malloc(sizeof(BankingRecord));
    newRecord->next = NULL;
    return newRecord;
}

// Insert a Banking Record at the end
void insertRecord(BankingRecord* head, BankingRecord* newRecord) {
    if (head == NULL) {
        head = newRecord;
    } else {
        newRecord->next = head;
        head = newRecord;
    }
}

// Search for a Banking Record by Account Number
BankingRecord* searchRecord(BankingRecord* head, int accountNo) {
    BankingRecord* currentRecord = head;
    while (currentRecord) {
        if (currentRecord->accountNo == accountNo) {
            return currentRecord;
        }
        currentRecord = currentRecord->next;
    }
    return NULL;
}

// Update a Banking Record Balance
void updateBalance(BankingRecord* record, double newBalance) {
    record->balance = newBalance;
}

// Print Banking Records
void printRecords(BankingRecord* head) {
    BankingRecord* currentRecord = head;
    while (currentRecord) {
        printf("Name: %s\n", currentRecord->name);
        printf("Account No: %d\n", currentRecord->accountNo);
        printf("Balance: %.2lf\n", currentRecord->balance);
        printf("\n");
        currentRecord = currentRecord->next;
    }
}

int main() {
    BankingRecord* head = NULL;

    // Create some Banking Records
    BankingRecord* newRecord1 = createRecord();
    strcpy(newRecord1->name, "John Doe");
    newRecord1->accountNo = 12345;
    newRecord1->balance = 1000.0;
    insertRecord(head, newRecord1);

    BankingRecord* newRecord2 = createRecord();
    strcpy(newRecord2->name, "Jane Doe");
    newRecord2->accountNo = 67890;
    newRecord2->balance = 2000.0;
    insertRecord(head, newRecord2);

    // Search for a Banking Record by Account Number
    BankingRecord* foundRecord = searchRecord(head, 12345);
    if (foundRecord) {
        printf("Found record: \n");
        printRecords(foundRecord);
    } else {
        printf("Record not found.\n");
    }

    // Update a Banking Record Balance
    updateBalance(foundRecord, 3000.0);

    // Print updated Banking Records
    printRecords(head);

    return 0;
}