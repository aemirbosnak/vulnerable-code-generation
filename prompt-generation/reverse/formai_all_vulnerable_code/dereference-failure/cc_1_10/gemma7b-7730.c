//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexNode {
    char key[MAX_INDEX_SIZE];
    struct IndexNode* next;
} IndexNode;

typedef struct IndexList {
    IndexNode* head;
    int size;
} IndexList;

IndexList* CreateIndexList() {
    IndexList* list = (IndexList*)malloc(sizeof(IndexList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void InsertIndexNode(IndexList* list, char key) {
    IndexNode* newNode = (IndexNode*)malloc(sizeof(IndexNode));
    newNode->key[0] = key;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        IndexNode* tempNode = list->head;
        while (tempNode->next) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }

    list->size++;
}

void SearchIndexList(IndexList* list, char key) {
    IndexNode* tempNode = list->head;
    while (tempNode) {
        if (strcmp(tempNode->key, key) == 0) {
            printf("Key found: %s\n", key);
            return;
        }
        tempNode = tempNode->next;
    }

    printf("Key not found: %s\n", key);
}

int main() {
    IndexList* list = CreateIndexList();

    InsertIndexNode(list, "John Doe");
    InsertIndexNode(list, "Jane Doe");
    InsertIndexNode(list, "Jack Doe");

    SearchIndexList(list, "John Doe");
    SearchIndexList(list, "Jane Doe");
    SearchIndexList(list, "Jack Doe");
    SearchIndexList(list, "Peter Pan");

    return 0;
}