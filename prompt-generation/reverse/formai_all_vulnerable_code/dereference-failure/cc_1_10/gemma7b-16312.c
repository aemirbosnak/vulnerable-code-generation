//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[20];
    struct Node* next;
} Node;

struct Index {
    char keyword[20];
    struct Index* next;
    Node* head;
};

void insertNode(struct Index* index, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        insertNode(index->head, data);
    }
}

void searchNode(struct Index* index, char* keyword) {
    if (index->head == NULL) {
        return;
    }

    if (strcmp(index->keyword, keyword) == 0) {
        printf("Data: %s\n", index->head->data);
    } else {
        searchNode(index->head, keyword);
    }
}

int main() {
    struct Index* index = (struct Index*)malloc(sizeof(struct Index));
    index->head = NULL;
    index->next = NULL;

    insertNode(index, "John Doe");
    insertNode(index, "Jane Doe");
    insertNode(index, "Peter Pan");

    searchNode(index, "Jane Doe");

    return 0;
}