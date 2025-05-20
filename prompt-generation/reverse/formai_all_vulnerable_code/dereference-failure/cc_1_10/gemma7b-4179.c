//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 255

typedef struct Record {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Record* next;
} Record;

Record* InsertRecord(Record* head, char* name, int age) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }

    return head;
}

int SearchRecord(Record* head, char* name) {
    Record* currentRecord = head;

    while (currentRecord) {
        if (strcmp(currentRecord->name, name) == 0) {
            return 1;
        }

        currentRecord = currentRecord->next;
    }

    return 0;
}

int main() {
    Record* head = NULL;

    InsertRecord(head, "John Doe", 25);
    InsertRecord(head, "Jane Doe", 30);
    InsertRecord(head, "Jack Doe", 40);

    if (SearchRecord(head, "Jane Doe") == 1) {
        printf("Record found.\n");
    } else {
        printf("Record not found.\n");
    }

    return 0;
}