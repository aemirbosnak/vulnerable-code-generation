//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the Banking Record System structure
typedef struct BankingRecordSystem {
    int accountNo;
    char accountHolderName[50];
    double accountBalance;
    struct BankingRecordSystem* next;
} BankingRecordSystem;

// Function to insert a new record into the banking record system
BankingRecordSystem* insertRecord(BankingRecordSystem* head, int accountNo, char* accountHolderName, double accountBalance) {
    BankingRecordSystem* newRecord = malloc(sizeof(BankingRecordSystem));
    newRecord->accountNo = accountNo;
    strcpy(newRecord->accountHolderName, accountHolderName);
    newRecord->accountBalance = accountBalance;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        newRecord->next = head;
        head = newRecord;
    }

    return head;
}

// Function to search for a record in the banking record system
BankingRecordSystem* searchRecord(BankingRecordSystem* head, int accountNo) {
    BankingRecordSystem* currentRecord = head;

    while (currentRecord) {
        if (currentRecord->accountNo == accountNo) {
            return currentRecord;
        }
        currentRecord = currentRecord->next;
    }

    return NULL;
}

// Function to update a record in the banking record system
BankingRecordSystem* updateRecord(BankingRecordSystem* head, int accountNo, double newBalance) {
    BankingRecordSystem* currentRecord = searchRecord(head, accountNo);

    if (currentRecord) {
        currentRecord->accountBalance = newBalance;
        return currentRecord;
    }

    return NULL;
}

// Function to delete a record from the banking record system
BankingRecordSystem* deleteRecord(BankingRecordSystem* head, int accountNo) {
    BankingRecordSystem* currentRecord = head;
    BankingRecordSystem* previousRecord = NULL;

    while (currentRecord) {
        if (currentRecord->accountNo == accountNo) {
            if (previousRecord) {
                previousRecord->next = currentRecord->next;
            } else {
                head = currentRecord->next;
            }
            free(currentRecord);
            return head;
        }
        previousRecord = currentRecord;
        currentRecord = currentRecord->next;
    }

    return NULL;
}

int main() {
    BankingRecordSystem* head = NULL;

    // Insert some records
    insertRecord(head, 1001, "John Doe", 1000);
    insertRecord(head, 1002, "Jane Doe", 2000);
    insertRecord(head, 1003, "Peter Pan", 3000);

    // Search for a record
    BankingRecordSystem* record = searchRecord(head, 1002);
    if (record) {
        printf("Account No: %d\n", record->accountNo);
        printf("Account Holder Name: %s\n", record->accountHolderName);
        printf("Account Balance: %.2lf\n", record->accountBalance);
    }

    // Update a record
    updateRecord(head, 1001, 1500);
    record = searchRecord(head, 1001);
    if (record) {
        printf("Account No: %d\n", record->accountNo);
        printf("Account Holder Name: %s\n", record->accountHolderName);
        printf("Account Balance: %.2lf\n", record->accountBalance);
    }

    // Delete a record
    deleteRecord(head, 1003);
    record = searchRecord(head, 1003);
    if (record) {
        printf("Error: Record not found.\n");
    }

    return 0;
}