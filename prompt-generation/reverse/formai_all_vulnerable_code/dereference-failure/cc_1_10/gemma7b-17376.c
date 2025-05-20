//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 10

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

struct Index {
    char index[MAX_INDEX][20];
    int size;
    Node* head;
    Node* tail;
};

void insert(struct Index* idx, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (idx->head == NULL) {
        idx->head = newNode;
        idx->tail = newNode;
    } else {
        idx->tail->next = newNode;
        idx->tail = newNode;
    }

    for (int i = 0; i < idx->size; i++) {
        if (strcmp(newNode->name, idx->index[i]) == 0) {
            return;
        }
    }

    strcpy(idx->index[idx->size], name);
    idx->size++;
}

void search(struct Index* idx, char* name) {
    for (Node* current = idx->head; current != NULL; current = current->next) {
        if (strcmp(current->name, name) == 0) {
            printf("Found: %s\n", current->name);
            return;
        }
    }

    printf("Not found: %s\n", name);
}

int main() {
    struct Index* idx = malloc(sizeof(struct Index));
    idx->size = 0;
    idx->head = NULL;
    idx->tail = NULL;

    insert(idx, "John Doe");
    insert(idx, "Jane Doe");
    insert(idx, "Bill Smith");
    insert(idx, "Alice White");

    search(idx, "Bill Smith");
    search(idx, "John Doe");
    search(idx, "Bob White");

    return 0;
}