//FormAI DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for bank record
typedef struct BankRecord {
    char name[50];
    int account_number;
    float balance;
    struct BankRecord* next;
} BankRecord;

// Function to create new bank record
BankRecord* createBankRecord(char name[], int account_number, float balance) {
    BankRecord* newRecord = (BankRecord*) malloc(sizeof(BankRecord));
    strcpy(newRecord->name, name);
    newRecord->account_number = account_number;
    newRecord->balance = balance;
    newRecord->next = NULL;
    return newRecord;
}

// Function to add new bank record to linked list
void addBankRecordToList(BankRecord** head, BankRecord* newRecord) {
    if (*head == NULL) {
        *head = newRecord;
    } else {
        BankRecord* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newRecord;
    }
}

// Function to print all bank records in linked list
void printBankRecords(BankRecord* head) {
    BankRecord* current = head;
    while (current != NULL) {
        printf("Name: %s, Account Number: %d, Balance: %.2f\n", current->name, current->account_number, current->balance);
        current = current->next;
    }
}

int main() {
    BankRecord* head = NULL;

    // Creating and adding new bank records
    BankRecord* record1 = createBankRecord("John", 1001, 5000.50);
    addBankRecordToList(&head, record1);

    BankRecord* record2 = createBankRecord("Jane", 1002, 10000.75);
    addBankRecordToList(&head, record2);

    BankRecord* record3 = createBankRecord("Bob", 1003, 2500.25);
    addBankRecordToList(&head, record3);

    // Printing all bank records
    printBankRecords(head);

    return 0;
}