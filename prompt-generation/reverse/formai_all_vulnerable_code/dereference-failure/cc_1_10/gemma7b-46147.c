//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10
#define MAX_RECORD_SIZE 20

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    int age;
} Record;

typedef struct IndexNode {
    char key[MAX_INDEX_SIZE];
    struct IndexNode* next;
} IndexNode;

IndexNode* insertIndexNode(IndexNode* head, char* key) {
    IndexNode* newNode = (IndexNode*)malloc(sizeof(IndexNode));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        IndexNode* current = head;
        IndexNode* previous = NULL;
        while (current) {
            if (strcmp(newNode->key, current->key) < 0) {
                previous = current;
                current = current->next;
            }
        }

        if (previous) {
            previous->next = newNode;
        } else {
            head = newNode;
        }
    }

    return head;
}

void searchRecord(IndexNode* head, char* name) {
    IndexNode* current = head;
    while (current) {
        Record* record = (Record*)malloc(sizeof(Record));
        strcpy(record->name, current->key);
        if (strcmp(record->name, name) == 0) {
            printf("Name: %s, Age: %d\n", record->name, record->age);
        }
    }
}

int main() {
    IndexNode* head = NULL;
    Record* record = (Record*)malloc(sizeof(Record));
    strcpy(record->name, "John Doe");
    record->age = 25;
    insertIndexNode(head, record->name);

    record = (Record*)malloc(sizeof(Record));
    strcpy(record->name, "Jane Doe");
    record->age = 30;
    insertIndexNode(head, record->name);

    record = (Record*)malloc(sizeof(Record));
    strcpy(record->name, "Peter Pan");
    record->age = 12;
    insertIndexNode(head, record->name);

    searchRecord(head, "Jane Doe");

    return 0;
}