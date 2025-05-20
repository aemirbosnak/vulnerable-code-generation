//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INDEX 10

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

struct Index {
    Node** arr;
    int size;
    int capacity;
};

void insert(struct Index* idx, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (idx->size == idx->capacity) {
        idx->arr = (Node**)realloc(idx->arr, idx->capacity * 2);
        idx->capacity *= 2;
    }

    if (idx->size == 0) {
        idx->arr = (Node**)malloc(sizeof(Node*) * idx->capacity);
        idx->size = 0;
    }

    newNode->next = idx->arr[idx->size];
    idx->arr[idx->size++] = newNode;
}

int search(struct Index* idx, char* name) {
    for (int i = 0; i < idx->size; i++) {
        if (strcmp(idx->arr[i]->name, name) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    struct Index* idx = (struct Index*)malloc(sizeof(struct Index));
    idx->size = 0;
    idx->capacity = MAX_INDEX;
    idx->arr = (Node**)malloc(sizeof(Node*) * idx->capacity);

    insert(idx, "John Doe");
    insert(idx, "Jane Doe");
    insert(idx, "Peter Pan");

    int result = search(idx, "Jane Doe");

    if (result == -1) {
        printf("Name not found\n");
    } else {
        printf("Name found at index %d\n", result);
    }

    return 0;
}