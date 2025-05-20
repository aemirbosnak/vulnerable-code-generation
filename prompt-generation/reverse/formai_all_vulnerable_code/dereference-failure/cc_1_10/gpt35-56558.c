//FormAI DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record {
    char account_number[10];
    char name[50];
    float balance;
    struct record *next;
} Record;

Record *head = NULL;

void addRecord(char *account_number, char *name, float balance) {
    Record *newRecord = (Record*) malloc(sizeof(Record));
    strcpy(newRecord->account_number, account_number);
    strcpy(newRecord->name, name);
    newRecord->balance = balance;

    if (head == NULL) {
        head = newRecord;
        head->next = NULL;
    } else {
        Record *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newRecord;
        newRecord->next = NULL;
    }
}

void displayRecords() {
    Record *current = head;
    while (current != NULL) {
        printf("Account Number: %s\n", current->account_number);
        printf("Name: %s\n", current->name);
        printf("Balance: %.2f\n", current->balance);
        printf("----------------\n");
        current = current->next;
    }
}

int searchRecord(char *account_number) {
    Record *current = head;
    while (current != NULL) {
        if (strcmp(current->account_number, account_number) == 0) {
            printf("Account Number: %s\n", current->account_number);
            printf("Name: %s\n", current->name);
            printf("Balance: %.2f\n", current->balance);
            printf("----------------\n");
            return 1;
        }
        current = current->next;
    }
    printf("Record not found.\n");
    return 0;
}

void updateRecord(char *account_number, char *name, float balance) {
    Record *current = head;
    while (current != NULL) {
        if (strcmp(current->account_number, account_number) == 0) {
            strcpy(current->name, name);
            current->balance = balance;
            printf("Record updated successfully.\n");
            printf("Account Number: %s\n", current->account_number);
            printf("Name: %s\n", current->name);
            printf("Balance: %.2f\n", current->balance);
            printf("----------------\n");
            return;
        }
        current = current->next;
    }
    printf("Record not found.\n");
}

void deleteRecord(char *account_number) {
    Record *current = head;
    Record *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->account_number, account_number) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Record deleted successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Record not found.\n");
}

int main() {
    addRecord("1234", "John Smith", 1000.50);
    addRecord("5678", "Jane Doe", 500.75);
    addRecord("9101", "Bob Johnson", 750.25);

    displayRecords();

    printf("Searching for record with account number 1234...\n");
    searchRecord("1234");

    printf("Updating record with account number 5678...\n");
    updateRecord("5678", "Jane Smith", 1000.00);
    searchRecord("5678");

    printf("Deleting record with account number 9101...\n");
    deleteRecord("9101");
    displayRecords();

    return 0;
}