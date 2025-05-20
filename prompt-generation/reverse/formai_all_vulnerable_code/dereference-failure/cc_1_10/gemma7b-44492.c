//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
    char data[20];
    struct Node* next;
} Node;

struct Index {
    Node** arr;
    int size;
    int capacity;
};

void insert(struct Index* index, char data[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->size == index->capacity) {
        index->arr = (Node**)realloc(index->arr, index->capacity * 2);
        index->capacity *= 2;
    }

    if (index->size == 0) {
        index->arr = (Node**)malloc(sizeof(Node*) * index->capacity);
    }

    newNode->next = index->arr[index->size];
    index->arr[index->size] = newNode;
    index->size++;
}

int search(struct Index* index, char data[]) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->arr[i]->data, data) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->size = 0;
    index->capacity = MAX_INDEX_SIZE;
    index->arr = NULL;

    insert(index, "John Doe");
    insert(index, "Jane Doe");
    insert(index, "Peter Pan");

    int result = search(index, "Jane Doe");

    if (result != -1) {
        printf("Index of Jane Doe: %d\n", result);
    } else {
        printf("Data not found.\n");
    }

    return 0;
}