//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_RECORD_LENGTH 255

typedef struct Record {
    char name[MAX_RECORD_LENGTH];
    int age;
    struct Record* next;
} Record;

Record* insertRecord(Record* head) {
    Record* newRecord = (Record*)malloc(sizeof(Record));

    printf("Enter name: ");
    scanf("%s", newRecord->name);

    printf("Enter age: ");
    scanf("%d", &newRecord->age);

    newRecord->next = head;
    head = newRecord;

    return head;
}

void searchRecord(Record* head, char* name) {
    Record* currentRecord = head;

    while (currentRecord) {
        if (strcmp(currentRecord->name, name) == 0) {
            printf("Name: %s\n", currentRecord->name);
            printf("Age: %d\n", currentRecord->age);
            return;
        }
        currentRecord = currentRecord->next;
    }

    printf("Record not found.\n");
}

int main() {
    Record* head = NULL;

    // Insert records
    head = insertRecord(head);
    insertRecord(head);
    insertRecord(head);

    // Search for a record
    searchRecord(head, "John Doe");

    return 0;
}