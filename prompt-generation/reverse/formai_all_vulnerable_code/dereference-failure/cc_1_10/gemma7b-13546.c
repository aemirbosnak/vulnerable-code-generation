//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_RECORDS 100
#define MAX_INDEX_ENTRIES 10

typedef struct Record {
    char name[50];
    int age;
    struct Record* next;
} Record;

typedef struct IndexEntry {
    char key[20];
    struct IndexEntry* next;
} IndexEntry;

Record* head = NULL;
IndexEntry* indexHead = NULL;

void insertRecord(char* name, int age) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = head;
    head = newRecord;
}

void insertIndexEntry(char* key) {
    IndexEntry* newIndexEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
    strcpy(newIndexEntry->key, key);
    newIndexEntry->next = indexHead;
    indexHead = newIndexEntry;
}

void searchRecord(char* key) {
    IndexEntry* currentIndexEntry = indexHead;
    while (currentIndexEntry) {
        if (strcmp(currentIndexEntry->key, key) == 0) {
            Record* currentRecord = head;
            while (currentRecord) {
                if (strcmp(currentRecord->name, key) == 0) {
                    printf("Name: %s, Age: %d\n", currentRecord->name, currentRecord->age);
                    return;
                }
                currentRecord = currentRecord->next;
            }
            printf("Record not found.\n");
            return;
        }
        currentIndexEntry = currentIndexEntry->next;
    }
    printf("Record not found.\n");
}

int main() {
    insertRecord("John Doe", 25);
    insertRecord("Jane Doe", 22);
    insertRecord("Peter Pan", 12);
    insertRecord("Captain Hook", 45);

    searchRecord("Jane Doe");
    searchRecord("Peter Pan");
    searchRecord("Captain Hook");

    return 0;
}