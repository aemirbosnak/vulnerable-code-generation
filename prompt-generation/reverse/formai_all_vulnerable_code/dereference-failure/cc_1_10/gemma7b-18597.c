//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

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

void searchIndexNode(IndexNode* head, char* key) {
    IndexNode* current = head;
    while (current) {
        if (strcmp(key, current->key) == 0) {
            printf("Key found: %s\n", current->key);
            break;
        } else if (strcmp(key, current->key) < 0) {
            current = current->next;
        } else {
            break;
        }
    }

    if (current == NULL) {
        printf("Key not found.\n");
    }
}

int main() {
    IndexNode* head = NULL;

    insertIndexNode(head, "a");
    insertIndexNode(head, "b");
    insertIndexNode(head, "c");
    insertIndexNode(head, "d");

    searchIndexNode(head, "b");
    searchIndexNode(head, "e");

    return 0;
}