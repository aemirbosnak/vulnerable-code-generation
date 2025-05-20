//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100
#define MAX_RECORD_SIZE 20

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
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        Record* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRecord;
    }

    return head;
}

IndexNode* insertIndexNode(IndexNode* head, char* key) {
    IndexNode* newIndexNode = (IndexNode*)malloc(sizeof(IndexNode));
    strcpy(newIndexNode->key, key);
    newIndexNode->next = NULL;

    if (head == NULL) {
        head = newIndexNode;
    } else {
        IndexNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newIndexNode;
    }

    return head;
}

void searchRecord(Record* head, char* name) {
    Record* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Name: %s, Age: %d\n", temp->name, temp->age);
            return;
        }
        temp = temp->next;
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
    searchRecord(head, "Peter Pan");

    return 0;
}