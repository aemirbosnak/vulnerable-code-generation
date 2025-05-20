//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
    time_t timestamp;
};

void insertIndex(struct Index* index, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        index->head->next = newNode;
    }

    index->size++;
    index->timestamp = time(NULL);
}

void searchIndex(struct Index* index, char* query) {
    Node* current = index->head;

    while (current) {
        if (strcmp(current->data, query) == 0) {
            printf("Data: %s\n", current->data);
        }
        current = current->next;
    }
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;
    index->timestamp = time(NULL);

    insertIndex(index, "Alice");
    insertIndex(index, "Bob");
    insertIndex(index, "Charlie");

    searchIndex(index, "Bob");

    return 0;
}