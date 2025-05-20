//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
    char data[MAX_INDEX_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    char key[MAX_INDEX_SIZE];
    struct Node* head;
} Index;

Index* createIndex(char* key) {
    Index* index = malloc(sizeof(Index));
    strcpy(index->key, key);
    index->head = NULL;
    return index;
}

void insertNode(Index* index, char* data) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->data, data);
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
}

void searchNode(Index* index, char* data) {
    Node* temp = index->head;
    while (temp) {
        if (strcmp(temp->data, data) == 0) {
            printf("Data found: %s\n", temp->data);
            return;
        }
        temp = temp->next;
    }
    printf("Data not found\n");
}

int main() {
    Index* index = createIndex("John Doe");
    insertNode(index, "Apple");
    insertNode(index, "Banana");
    insertNode(index, "Orange");

    searchNode(index, "Apple");
    searchNode(index, "Banana");
    searchNode(index, "Pear");

    return 0;
}