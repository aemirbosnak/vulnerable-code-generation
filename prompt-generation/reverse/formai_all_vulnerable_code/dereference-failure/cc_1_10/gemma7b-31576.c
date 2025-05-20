//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
    int (*compare)(const void*, const void*);
    void (*insert)(const void*);
    void (*delete)(const void*);
};

void insertIndex(struct Index* index, const char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        index->head->next = newNode;
    }

    index->size++;
}

void deleteIndex(struct Index* index, const char* name) {
    Node* prevNode = NULL;
    Node* currentNode = index->head;

    while (currentNode) {
        if (strcmp(currentNode->name, name) == 0) {
            if (prevNode) {
                prevNode->next = currentNode->next;
            } else {
                index->head = currentNode->next;
            }

            free(currentNode);
            index->size--;
            return;
        }

        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    printf("Error: name not found.\n");
}

int compareIndex(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

int main() {
    struct Index* index = malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;
    index->compare = compareIndex;
    index->insert = insertIndex;
    index->delete = deleteIndex;

    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Peter Pan");

    deleteIndex(index, "Jane Doe");

    for (Node* node = index->head; node; node = node->next) {
        printf("%s\n", node->name);
    }

    return 0;
}