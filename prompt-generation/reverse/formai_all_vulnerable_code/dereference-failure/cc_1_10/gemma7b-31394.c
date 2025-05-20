//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store banking records
typedef struct BankRecord {
    char name[50];
    int account_number;
    float balance;
    struct BankRecord* next;
} BankRecord;

// Function to insert a new record into the linked list
void insertRecord(BankRecord* head, BankRecord* newRecord) {
    if (head == NULL) {
        head = newRecord;
    } else {
        newRecord->next = head;
        head = newRecord;
    }
}

// Function to search for a record by account number
BankRecord* searchRecord(BankRecord* head, int account_number) {
    BankRecord* currentRecord = head;
    while (currentRecord) {
        if (currentRecord->account_number == account_number) {
            return currentRecord;
        } else {
            currentRecord = currentRecord->next;
        }
    }
    return NULL;
}

// Function to update the balance of a record
void updateBalance(BankRecord* record, float newBalance) {
    record->balance = newBalance;
}

// Main function
int main() {
    // Create a new linked list to store banking records
    BankRecord* head = NULL;

    // Insert some sample records
    insertRecord(head, malloc(sizeof(BankRecord)));
    insertRecord(head, malloc(sizeof(BankRecord)));
    insertRecord(head, malloc(sizeof(BankRecord)));

    // Search for a record by account number and update its balance
    BankRecord* record = searchRecord(head, 1234);
    if (record) {
        updateBalance(record, 1000);
    }

    // Print the updated record
    record = searchRecord(head, 1234);
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %f\n", record->balance);
    }

    return 0;
}