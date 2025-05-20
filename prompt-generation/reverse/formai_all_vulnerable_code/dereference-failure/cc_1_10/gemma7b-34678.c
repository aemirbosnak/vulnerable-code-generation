//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    char address[100];
    char phone[20];
    struct Record* next;
} Record;

Record* insertRecord(Record* head, char* name, char* address, char* phone) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    strcpy(newRecord->address, address);
    strcpy(newRecord->phone, phone);
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }

    return head;
}

Record* searchRecord(Record* head, char* name) {
    Record* currentRecord = head;

    while (currentRecord) {
        if (strcmp(currentRecord->name, name) == 0) {
            return currentRecord;
        }

        currentRecord = currentRecord->next;
    }

    return NULL;
}

int main() {
    Record* head = NULL;

    // Insert some records
    insertRecord(head, "Sherlock Holmes", "221B Baker St.", "020 123 456");
    insertRecord(head, "John Watson", "221B Baker St.", "020 456 789");
    insertRecord(head, "Mrs. Hudson", "221B Baker St.", "020 567 892");

    // Search for a record
    Record* record = searchRecord(head, "John Watson");

    // Print the record
    if (record) {
        printf("Name: %s\n", record->name);
        printf("Address: %s\n", record->address);
        printf("Phone: %s\n", record->phone);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}