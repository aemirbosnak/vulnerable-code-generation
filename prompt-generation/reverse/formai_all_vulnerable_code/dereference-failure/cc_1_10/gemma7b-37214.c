//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
    char name[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
};

void insertIndex(struct Index* index, char name[]) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* tempNode = index->head;
        while (tempNode->next) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }

    index->size++;
}

void searchIndex(struct Index* index, char name[]) {
    Node* tempNode = index->head;
    while (tempNode) {
        if (strcmp(tempNode->name, name) == 0) {
            printf("Found: %s\n", tempNode->name);
            return;
        }
        tempNode = tempNode->next;
    }

    printf("Not found: %s\n", name);
}

int main() {
    struct Index* index = malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;

    insertIndex(index, "John");
    insertIndex(index, "Alice");
    insertIndex(index, "Bob");

    searchIndex(index, "Alice");
    searchIndex(index, "Tom");

    return 0;
}