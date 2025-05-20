//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_RECORD_SIZE 1024
#define MAX_INDEX_SIZE 1024

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    int age;
    struct Record* next;
} Record;

typedef struct Index {
    int key;
    struct Index* next;
} Index;

Record* insertRecord(Record* head, char* name, int age) {
    Record* newRecord = malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        Record* currentRecord = head;
        while (currentRecord->next) {
            currentRecord = currentRecord->next;
        }
        currentRecord->next = newRecord;
    }

    return head;
}

Index* insertIndex(Index* head, int key) {
    Index* newIndex = malloc(sizeof(Index));
    newIndex->key = key;
    newIndex->next = NULL;

    if (head == NULL) {
        head = newIndex;
    } else {
        Index* currentIndex = head;
        while (currentIndex->next) {
            currentIndex = currentIndex->next;
        }
        currentIndex->next = newIndex;
    }

    return head;
}

void searchRecord(Record* head, char* name) {
    Record* currentRecord = head;
    while (currentRecord) {
        if (strcmp(currentRecord->name, name) == 0) {
            printf("Name: %s, Age: %d\n", currentRecord->name, currentRecord->age);
            break;
        }
        currentRecord = currentRecord->next;
    }

    if (currentRecord == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    Record* head = NULL;
    Index* indexHead = NULL;

    insertRecord(head, "John Doe", 25);
    insertRecord(head, "Jane Doe", 30);
    insertRecord(head, "Peter Pan", 12);
    insertRecord(head, "Mary Poppins", 20);

    insertIndex(indexHead, 25);
    insertIndex(indexHead, 30);
    insertIndex(indexHead, 12);

    searchRecord(head, "John Doe");
    searchRecord(head, "Mary Poppins");

    return 0;
}