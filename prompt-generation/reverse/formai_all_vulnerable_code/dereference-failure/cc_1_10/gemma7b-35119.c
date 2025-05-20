//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char data[20];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
    int capacity;
    time_t timestamp;
};

void insertIndex(struct Index* index, char data) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        index->head->next = newNode;
    }

    index->size++;
}

int searchIndex(struct Index* index, char data) {
    Node* current = index->head;
    while (current) {
        if (strcmp(current->data, data) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    struct Index* index = malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;
    index->capacity = MAX_INDEX_SIZE;
    index->timestamp = time(NULL);

    insertIndex(index, "John");
    insertIndex(index, "Alice");
    insertIndex(index, "Bob");
    insertIndex(index, "Tom");

    if (searchIndex(index, "Bob") == 1) {
        printf("Bob is in the index.\n");
    }

    return 0;
}