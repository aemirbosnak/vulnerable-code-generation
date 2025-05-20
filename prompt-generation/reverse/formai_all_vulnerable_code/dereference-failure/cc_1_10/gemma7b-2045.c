//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    Node* head;
    int size;
} Index;

Index* createIndex() {
    Index* index = malloc(sizeof(Index));
    index->head = NULL;
    index->size = 0;
    return index;
}

void insertIndex(Index* index, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data[0] = data;
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

void searchIndex(Index* index, char data) {
    Node* temp = index->head;
    while (temp) {
        if (temp->data[0] == data) {
            printf("Data found: %c\n", data);
            return;
        }
        temp = temp->next;
    }

    printf("Data not found: %c\n", data);
}

int main() {
    Index* index = createIndex();
    insertIndex(index, 'a');
    insertIndex(index, 'b');
    insertIndex(index, 'c');
    insertIndex(index, 'd');

    searchIndex(index, 'b');
    searchIndex(index, 'e');

    return 0;
}