//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexNode {
    char key[20];
    struct IndexNode* next;
} IndexNode;

IndexNode* InsertIndexNode(IndexNode* head, char* key) {
    IndexNode* newNode = (IndexNode*)malloc(sizeof(IndexNode));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        IndexNode* tempNode = head;
        while (tempNode->next) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }

    return head;
}

void SearchIndexNode(IndexNode* head, char* key) {
    IndexNode* tempNode = head;
    while (tempNode) {
        if (strcmp(tempNode->key, key) == 0) {
            printf("Key found: %s\n", tempNode->key);
            return;
        }
        tempNode = tempNode->next;
    }

    printf("Key not found.\n");
}

int main() {
    IndexNode* head = NULL;

    InsertIndexNode(head, "John Doe");
    InsertIndexNode(head, "Jane Doe");
    InsertIndexNode(head, "Peter Pan");

    SearchIndexNode(head, "Jane Doe");

    return 0;
}