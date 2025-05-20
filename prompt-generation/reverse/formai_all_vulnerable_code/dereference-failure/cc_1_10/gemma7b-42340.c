//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 1024

typedef struct IndexNode {
    char key[MAX_INDEX_SIZE];
    struct IndexNode* next;
} IndexNode;

IndexNode* InsertIndexNode(IndexNode* head, char key[]) {
    IndexNode* newNode = malloc(sizeof(IndexNode));
    strcpy(newNode->key, key);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        IndexNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    return head;
}

int SearchIndex(IndexNode* head, char key[]) {
    IndexNode* current = head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    IndexNode* head = NULL;
    InsertIndexNode(head, "John Doe");
    InsertIndexNode(head, "Jane Doe");
    InsertIndexNode(head, "Jack Doe");

    if (SearchIndex(head, "John Doe") == 1) {
        printf("John Doe found!");
    }

    return 0;
}