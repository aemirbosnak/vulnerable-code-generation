//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 20

typedef struct Record {
    char **fields;
    int numFields;
    struct Record *next;
} Record;

Record *insertRecord(Record *head, char **fields, int numFields);
void printRecord(Record *record);

int main() {
    Record *head = NULL;
    char **fields = NULL;
    int numFields = 0;

    // Insert some records
    fields = malloc(MAX_FIELD_SIZE * numFields);
    insertRecord(head, fields, numFields);
    insertRecord(head, fields, numFields);

    // Print the records
    printRecord(head);

    return 0;
}

Record *insertRecord(Record *head, char **fields, int numFields) {
    Record *newRecord = malloc(sizeof(Record));
    newRecord->fields = malloc(MAX_FIELD_SIZE * numFields);

    // Copy the fields from the input
    memcpy(newRecord->fields, fields, MAX_FIELD_SIZE * numFields);
    newRecord->numFields = numFields;

    // Insert the new record into the head
    if (head == NULL) {
        head = newRecord;
    } else {
        newRecord->next = head;
        head = newRecord;
    }

    return head;
}

void printRecord(Record *record) {
    printf("Record:\n");
    for (int i = 0; i < record->numFields; i++) {
        printf("  Field %d: %s\n", i + 1, record->fields[i]);
    }
    printf("\n");
}