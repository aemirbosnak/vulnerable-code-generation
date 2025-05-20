//FormAI DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int accountNumber;
    char accountName[100];
    float balance;
    struct Record *next;
};

struct Record *head = NULL;

// Function to add a new record to the banking records system
void addRecord(int accountNumber, char *accountName, float balance) {
    struct Record *newRecord = (struct Record*)malloc(sizeof(struct Record));
    newRecord->accountNumber = accountNumber;
    strcpy(newRecord->accountName, accountName);
    newRecord->balance = balance;
    newRecord->next = NULL;

    if(head == NULL) {
        head = newRecord;
    } else {
        struct Record *current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newRecord;
    }
}

// Function to print the banking records system
void printRecords(struct Record *current) {
    if(current == NULL) {
        return;
    }
    printf("Account Number: %d\nAccount Name: %s\nBalance: %.2f\n\n", current->accountNumber, current->accountName, current->balance);
    printRecords(current->next);
}

// Function to search for a record by account number
struct Record *searchRecord(int accountNumber, struct Record *current) {
    if(current == NULL) {
        return NULL;
    }
    if(current->accountNumber == accountNumber) {
        return current;
    } else {
        return searchRecord(accountNumber, current->next);
    }
}

// Function to update the balance of a record
void updateBalance(int accountNumber, float newBalance) {
    struct Record *recordToUpdate = searchRecord(accountNumber, head);
    if(recordToUpdate == NULL) {
        printf("Record with account number %d not found!\n\n", accountNumber);
        return;
    }
    recordToUpdate->balance = newBalance;

    printf("Balance for account number %d successfully updated to %.2f\n\n", accountNumber, newBalance);
}

int main() {
    // Adding some sample records
    addRecord(1001, "Alice Johnson", 5200.50);
    addRecord(1002, "Bob Smith", 3400.00);
    addRecord(1003, "Charlie Brown", 1250.75);
    addRecord(1004, "David Martin", 9800.25);

    // Printing the records
    printf("Printing Records...\n\n");
    printRecords(head);

    // Updating the balance of a record
    updateBalance(1002, 4000.00);

    // Printing the records again to check if the balance got updated
    printf("Printing Records after update...\n\n");
    printRecords(head);

    return 0;
}