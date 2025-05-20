//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

struct Index {
    Node* head;
    int size;
};

void insertIndex(struct Index* index, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data[0] = data;
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
        if (current->data[0] == data) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->head = NULL;
    index->size = 0;

    insertIndex(index, 'a');
    insertIndex(index, 'b');
    insertIndex(index, 'c');
    insertIndex(index, 'd');

    if (searchIndex(index, 'b')) {
        printf("Data found!\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}