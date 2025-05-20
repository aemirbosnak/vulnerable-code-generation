//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: automated
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
    void (*print)(const void*);
};

void insertIndex(struct Index* index, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* temp = index->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    index->size++;
}

int compareNames(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}

void printNames(const void* data) {
    printf("%s\n", (char*)data);
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;
    index->compare = compareNames;
    index->print = printNames;

    insertIndex(index, "John Doe");
    insertIndex(index, "Jane Doe");
    insertIndex(index, "Peter Pan");

    printf("Index size: %d\n", index->size);
    printf("Index contents:\n");
    index->print(NULL);

    return 0;
}