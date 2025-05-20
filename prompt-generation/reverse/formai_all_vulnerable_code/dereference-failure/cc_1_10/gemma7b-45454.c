//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INDEX_SIZE 1024

typedef struct Record {
    char name[255];
    int age;
    struct Record* next;
} Record;

typedef struct Index {
    char key[255];
    struct Index* next;
} Index;

Record* insertRecord(Record* head, char* name, int age) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = insertRecord(head->next, name, age);
    }

    return head;
}

Index* insertIndex(Index* head, char* key) {
    Index* newIndex = (Index*)malloc(sizeof(Index));
    strcpy(newIndex->key, key);
    newIndex->next = NULL;

    if (head == NULL) {
        head = newIndex;
    } else {
        head->next = insertIndex(head->next, key);
    }

    return head;
}

Record* searchRecord(Record* head, char* name) {
    for (Record* currentRecord = head; currentRecord; currentRecord = currentRecord->next) {
        if (strcmp(currentRecord->name, name) == 0) {
            return currentRecord;
        }
    }

    return NULL;
}

void main() {
    Record* head = NULL;
    Index* indexHead = NULL;

    insertRecord(head, "John Doe", 30);
    insertRecord(head, "Jane Doe", 25);
    insertRecord(head, "Peter Pan", 12);

    insertIndex(indexHead, "John Doe");
    insertIndex(indexHead, "Jane Doe");

    Record* foundRecord = searchRecord(head, "Jane Doe");

    if (foundRecord) {
        printf("Name: %s, Age: %d\n", foundRecord->name, foundRecord->age);
    } else {
        printf("Record not found.\n");
    }
}