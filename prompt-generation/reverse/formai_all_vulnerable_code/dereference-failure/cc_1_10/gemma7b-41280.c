//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct IndexNode {
    char key[MAX_INDEX_SIZE];
    struct IndexNode* next;
} IndexNode;

IndexNode* insertIndexNode(IndexNode* head, char key) {
    IndexNode* newNode = malloc(sizeof(IndexNode));
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
    head = insertIndexNode(head, 'a');
    head = insertIndexNode(head, 'b');
    head = insertIndexNode(head, 'c');
    head = insertIndexNode(head, 'd');

    IndexNode* current = head;
    while (current) {
        printf("%s ", current->key);
        current = current->next;
    }

    return 0;
}