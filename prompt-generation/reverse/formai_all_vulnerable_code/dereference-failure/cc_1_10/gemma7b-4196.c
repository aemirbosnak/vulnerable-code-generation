//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 100
#define MAX_RECORD_SIZE 256

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    int age;
    struct Record* next;
} Record;

typedef struct IndexNode {
    char key[MAX_RECORD_SIZE];
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

Record* insertRecord(Record* head, char* name, int age) {
    Record* newNode = (Record*)malloc(sizeof(Record));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Record* current = head;
        Record* previous = NULL;
        while (current) {
            if (strcmp(newNode->name, current->name) < 0) {
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

void searchRecord(Record* head, char* name) {
    Record* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s, Age: %d\n", current->name, current->age);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    Record* head = NULL;
    IndexNode* indexHead = NULL;

    insertRecord(head, "John Doe", 30);
    insertRecord(head, "Jane Doe", 25);
    insertRecord(head, "Peter Pan", 12);

    insertIndexNode(indexHead, "John Doe");
    insertIndexNode(indexHead, "Jane Doe");

    searchRecord(head, "John Doe");
    searchRecord(head, "Jane Doe");

    return 0;
}