//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 100

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
            } else if (strcmp(newNode->key, current->key) == 0) {
                return NULL;
            }
        }
        previous->next = newNode;
    }

    return head;
}

void printIndex(IndexNode* head) {
    IndexNode* current = head;
    while (current) {
        printf("%s ", current->key);
        current = current->next;
    }
    printf("\n");
}

int main() {
    IndexNode* head = NULL;

    // Insert some data
    insertIndexNode(head, "John Doe");
    insertIndexNode(head, "Jane Doe");
    insertIndexNode(head, "Peter Pan");
    insertIndexNode(head, "Mary Poppins");

    // Print the index
    printIndex(head);

    return 0;
}