//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 100
#define MAX_RECORD_SIZE 256

typedef struct Record {
    char data[MAX_RECORD_SIZE];
    struct Record* next;
} Record;

typedef struct Index {
    char key[MAX_INDEX_SIZE];
    struct Index* next;
} Index;

Index* insertIndex(Index* head, char key) {
    Index* newNode = (Index*)malloc(sizeof(Index));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Index* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

Record* insertRecord(Record* head, char* data) {
    Record* newNode = (Record*)malloc(sizeof(Record));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Record* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

void searchRecord(Index* head, char* key) {
    Index* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            printf("Record found: %s\n", current->key);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    Index* head = NULL;
    Record* headRecord = NULL;

    insertIndex(head, "John Doe");
    insertIndex(head, "Jane Doe");
    insertIndex(head, "Jack Doe");

    insertRecord(headRecord, "John Doe's address");
    insertRecord(headRecord, "Jane Doe's address");
    insertRecord(headRecord, "Jack Doe's address");

    searchRecord(head, "Jane Doe");

    return 0;
}