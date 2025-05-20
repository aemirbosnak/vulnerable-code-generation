//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_ENTRIES 1024
#define MAX_RECORD_SIZE 1024

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    int age;
    struct Record* next;
} Record;

typedef struct IndexEntry {
    char key[MAX_RECORD_SIZE];
    int offset;
    struct IndexEntry* next;
} IndexEntry;

IndexEntry* insertIndexEntry(IndexEntry* head, char* key, int offset) {
    IndexEntry* newEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
    strcpy(newEntry->key, key);
    newEntry->offset = offset;
    newEntry->next = NULL;

    if (head == NULL) {
        head = newEntry;
    } else {
        IndexEntry* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newEntry;
    }

    return head;
}

Record* insertRecord(Record* head, char* name, int age) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        Record* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newRecord;
    }

    return head;
}

void searchRecord(IndexEntry* head, char* key) {
    IndexEntry* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            printf("Record found: name = %s, age = %d\n", current->offset);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Record not found\n");
    }
}

int main() {
    Record* head = insertRecord(NULL, "John Doe", 30);
    insertRecord(head, "Jane Doe", 25);
    insertRecord(head, "Peter Pan", 12);

    IndexEntry* indexHead = insertIndexEntry(NULL, "John Doe", 0);
    insertIndexEntry(indexHead, "Jane Doe", 1);
    insertIndexEntry(indexHead, "Peter Pan", 2);

    searchRecord(indexHead, "John Doe");
    searchRecord(indexHead, "Jane Doe");
    searchRecord(indexHead, "Peter Pan");

    return 0;
}