//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Node {
    void* key;
    void* value;
    struct Node* next;
} Node;

typedef struct Index {
    uint64_t size;
    Node* head;
    Node* tail;
} Index;

Index* createIndex() {
    Index* index = malloc(sizeof(Index));
    index->size = 0;
    index->head = NULL;
    index->tail = NULL;
    return index;
}

void insertIndex(Index* index, void* key, void* value) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    if (index->size == 0) {
        index->head = node;
        index->tail = node;
    } else {
        index->tail->next = node;
        index->tail = node;
    }
    index->size++;
}

void* getIndex(Index* index, void* key) {
    Node* node = index->head;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void deleteIndex(Index* index) {
    Node* node = index->head;
    while (node != NULL) {
        Node* next = node->next;
        free(node);
        node = next;
    }
    free(index);
}

int main() {
    Index* index = createIndex();
    insertIndex(index, "name", "John Doe");
    insertIndex(index, "age", "30");
    insertIndex(index, "occupation", "Software Engineer");

    char* name = getIndex(index, "name");
    char* age = getIndex(index, "age");
    char* occupation = getIndex(index, "occupation");

    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    printf("Occupation: %s\n", occupation);

    deleteIndex(index);

    return 0;
}