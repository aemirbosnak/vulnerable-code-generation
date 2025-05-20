//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexNode {
    char key[MAX_INDEX_SIZE];
    struct IndexNode* next;
} IndexNode;

IndexNode* insertIndexNode(IndexNode* head, char key) {
    IndexNode* newNode = (IndexNode*)malloc(sizeof(IndexNode));
    newNode->key[0] = key;
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
            } else {
                break;
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

int main() {
    IndexNode* head = NULL;

    insertIndexNode(head, "a");
    insertIndexNode(head, "c");
    insertIndexNode(head, "e");
    insertIndexNode(head, "g");

    IndexNode* current = head;
    while (current) {
        printf("%s ", current->key);
        current = current->next;
    }

    return 0;
}