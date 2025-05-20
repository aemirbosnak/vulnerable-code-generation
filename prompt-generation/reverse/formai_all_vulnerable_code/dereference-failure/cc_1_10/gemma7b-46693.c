//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Index {
    Node *head;
    Node *tail;
    int size;
    char *key;
} Index;

Index *createIndex(char *key) {
    Index *index = malloc(sizeof(Index));
    index->head = NULL;
    index->tail = NULL;
    index->size = 0;
    index->key = key;
    return index;
}

void addToIndex(Index *index, char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (index->head == NULL) {
        index->head = newNode;
        index->tail = newNode;
    } else {
        index->tail->next = newNode;
        index->tail = newNode;
    }

    index->size++;
}

void searchIndex(Index *index, char *key) {
    Node *node = index->head;
    while (node) {
        if (strcmp(node->data, key) == 0) {
            printf("Data: %s\n", node->data);
            break;
        }
        node = node->next;
    }

    if (node == NULL) {
        printf("Data not found.\n");
    }
}

int main() {
    char *key = "Paranoia";
    Index *index = createIndex(key);

    addToIndex(index, "Secret Message");
    addToIndex(index, "Hidden Treasure");
    addToIndex(index, "Top Secret");

    searchIndex(index, "Secret Message");
    searchIndex(index, "Top Secret");

    return 0;
}