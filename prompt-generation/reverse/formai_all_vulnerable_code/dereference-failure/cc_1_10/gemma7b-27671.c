//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INDEX_SIZE 1024

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
    Node* node = malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = NULL;

    if (index->head == NULL) {
        index->head = node;
    } else {
        Node* temp = index->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

char* searchNode(Index* index, char* key) {
    Node* node = index->head;
    while (node) {
        if (strcmp(key, node->data) == 0) {
            return node->data;
        }
        node = node->next;
    }
    return NULL;
}

int main() {
    Index* index = createIndex("John Doe");
    insertNode(index, "123 Main St.");
    insertNode(index, "456 Oak Ave.");
    insertNode(index, "789 Oak St.");

    char* data = searchNode(index, "456 Oak Ave.");
    if (data) {
        printf("Data: %s\n", data);
    } else {
        printf("Data not found.\n");
    }

    return 0;
}