//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 100
#define MAX_RECORD_SIZE 200

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    int age;
    struct Record* next;
} Record;

typedef struct IndexNode {
    char key[MAX_INDEX_SIZE];
    struct IndexNode* next;
} IndexNode;

Record* insertRecord(Record* head, char* name, int age) {
    Record* newRecord = malloc(sizeof(Record));
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

IndexNode* insertIndexNode(IndexNode* head, char* key) {
    IndexNode* newIndexNode = malloc(sizeof(IndexNode));
    strcpy(newIndexNode->key, key);
    newIndexNode->next = NULL;

    if (head == NULL) {
        head = newIndexNode;
    } else {
        head->next = insertIndexNode(head->next, key);
    }

    return head;
}

void searchRecord(Record* head, char* name) {
    Record* currentRecord = head;

    while (currentRecord) {
        if (strcmp(currentRecord->name, name) == 0) {
            printf("Name: %s, Age: %d\n", currentRecord->name, currentRecord->age);
            return;
        }

        currentRecord = currentRecord->next;
    }

    printf("Record not found.\n");
}

int main() {
    Record* head = NULL;
    IndexNode* indexHead = NULL;

    insertRecord(head, "John Doe", 25);
    insertRecord(head, "Jane Doe", 30);
    insertRecord(head, "Peter Pan", 12);

    insertIndexNode(indexHead, "John Doe");
    insertIndexNode(indexHead, "Jane Doe");

    searchRecord(head, "John Doe");

    return 0;
}