//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_DATA_SIZE 1024

typedef struct Node {
    char data[MAX_DATA_SIZE];
    struct Node* next;
} Node;

typedef struct Index {
    char key[MAX_DATA_SIZE];
    struct Node* head;
} Index;

Index* createIndex(char* key) {
    Index* index = (Index*)malloc(sizeof(Index));
    strcpy(index->key, key);
    index->head = NULL;
    return index;
}

void addToIndex(Index* index, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (index->head == NULL) {
        index->head = newNode;
    } else {
        Node* lastNode = index->head;
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void searchIndex(Index* index, char* key) {
    if (strcmp(index->key, key) == 0) {
        Node* node = index->head;
        while (node) {
            printf("%s\n", node->data);
            node = node->next;
        }
    } else {
        printf("Key not found\n");
    }
}

int main() {
    Index* myIndex = createIndex("John Doe");
    addToIndex(myIndex, "123 Main St.");
    addToIndex(myIndex, "456 Oak Ave.");
    addToIndex(myIndex, "789 Oak St.");

    searchIndex(myIndex, "John Doe");

    return 0;
}