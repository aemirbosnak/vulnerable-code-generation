//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct IndexNode {
    char key[MAX_INDEX_SIZE];
    struct IndexNode* next;
} IndexNode;

IndexNode* insertIndexNode(IndexNode* head, char* key) {
    IndexNode* newNode = malloc(sizeof(IndexNode));
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
            } else if (previous) {
                previous->next = newNode;
                break;
            } else {
                head = newNode;
                break;
            }
        }
    }

    return head;
}

int main() {
    IndexNode* head = NULL;

    insertIndexNode(head, "John Doe");
    insertIndexNode(head, "Jane Doe");
    insertIndexNode(head, "Peter Pan");
    insertIndexNode(head, "Mary Poppins");

    IndexNode* current = head;
    while (current) {
        printf("%s\n", current->key);
        current = current->next;
    }

    return 0;
}